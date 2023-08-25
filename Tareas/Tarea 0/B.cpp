#include <iostream>

using namespace std;

int main(){
    int num1, num2;
    cin >> num1 >> num2;
    int suma = 0;
    int n = 1;
    while(n<=num1){
        int x;
        cin >> x;
        if(x>num2){
            suma += 2;
        }
        else{
            suma += 1;
        }
        n++;
    }
    cout << suma;
}