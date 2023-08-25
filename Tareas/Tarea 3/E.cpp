#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

ll kruskal(int n, vector<tuple<ll,int,int>> &edges){
	DSU dsu(n);
	sort(edges.begin(), edges.end());
	ll ans = 0;
	for(auto [w, u, v] : edges){
		if(dsu.find_set(u) != dsu.find_set(v)){
			ans += w;
			dsu.union_set(u, v);
		}
	}
	return ans;
}


struct Antenna {
    ll x, y, r;

    ll distance(const Antenna& other) const {
        ll dx = x - other.x;
        ll dy = y - other.y;
        ll distance = dx*dx + dy*dy;
        ll radius = (r + other.r) * (r + other.r);
        if (radius >= distance) return 0;
        return distance - radius;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Antenna> antennas(n);
    for (int i = 0; i < n; i++)
        cin >> antennas[i].x >> antennas[i].y >> antennas[i].r;

    vector<tuple<ll, int, int>> edges;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            edges.emplace_back(antennas[i].distance(antennas[j]), i, j);

    cout << fixed << setprecision(6) << sqrt(kruskal(n, edges))/2 << '\n';
    return 0;
}
