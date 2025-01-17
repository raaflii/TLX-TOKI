#include <iostream>
#include <cmath>
#include <list>

using namespace std;

list<int> faktor(int n){
    list<int> faktor;

    for (int i = 2; i <= floor(sqrt(n)); i++){
        if (n % i == 0) {
            faktor.push_back(i);
        }
    }

    return faktor;
}

int main (){
    int T;
    cin >> T;

    int N[T];
    for (int i = 0; i < T; i++){
        cin >> N[i];
    }

    for (int i = 0; i < T; i++){
        list<int> a = faktor(N[i]);
        if (a.size() >= 0 && a.size() <= 1){
            cout << "YA" << endl;
        } else {
            cout << "BUKAN" << endl;
        }
    }

    return 0;
}