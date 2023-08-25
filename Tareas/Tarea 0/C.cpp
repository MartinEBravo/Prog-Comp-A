#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    int i;
    int sumaA = 0;
    int sumaB = 0;
    for(i = 0; i < str.length(); i += 2){
        char letra = str[i];
        int numero = str[i+1];
        if(letra == 'A'){
            sumaA += numero-48;
        }
        else{
            sumaB += numero-48;
        }
    }
    if(sumaA>sumaB){
        cout << "A";
    }
    else{
        cout << "B";
    }
}