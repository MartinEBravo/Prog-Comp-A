#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    while(cin >> n){
        int bstack = 1; 
        int bqueue = 1; 
        int bpriority_queue = 1;
        
        queue<int> cola;
        stack<int> pila;
        priority_queue<int> cola_prioridad;

        while(n--){
            int num1, num2;
            cin >> num1 >> num2;
            
            if (num1 == 1){
                if (bqueue == 1){
                    cola.push(num2);
                }
                if (bstack == 1){
                    pila.push(num2);
                }
                if (bpriority_queue == 1){
                    cola_prioridad.push(num2);
                }
            }
            if (num1 == 2){
                if(cola.size() == 0){
                    bqueue = 0;
                    bstack = 0;
                    bpriority_queue = 0;
                }
                else{
                    if(cola.front() != num2){
                        bqueue = 0;
                    }
                    if (bqueue == 1){
                        cola.pop();
                    }
                    if(pila.top() != num2){
                        bstack = 0;
                    }
                    if(bstack == 1){
                        pila.pop();
                    }
                    if(cola_prioridad.top() != num2){
                        bpriority_queue = 0;
                    }
                    if(bpriority_queue == 1){
                        cola_prioridad.pop();
                    }
                }
            }
        }
        
        int suma = bstack + bqueue + bpriority_queue;
        
        if(suma == 0){
            cout << "impossible" << endl;
        }
        if(suma == 1){
            if(bstack == 1){
                cout << "stack" << endl;
            }
            else if (bqueue == 1){
                cout << "queue" << endl;
            }
            else{
                cout << "priority queue"  << endl;
            }
        }
        if(suma >= 2){
            cout << "not sure" << endl;
        }
    }
    return 0;
}
