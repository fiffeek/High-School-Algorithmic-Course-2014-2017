#include <iostream>
#include <queue>

using namespace std;

int main(){
int rr;
cin >> rr;
for(int i=0;i<rr;i++){
    int liczbakart;
    cin >> liczbakart;

    queue<int> a;
    queue<int> b;

    for(int i=0;i<liczbakart;i++){
        int liczba;
        cin >> liczba;
        a.push(liczba);
    }

    int liczbakart2;
    cin >> liczbakart2;

    for(int i=0;i<liczbakart2;i++){
        int liczba2;
        cin >> liczba2;
        b.push(liczba2);
    }

    int ilosctur;
    cin >> ilosctur;

    int licznik=0;
    for(int i=0;i<ilosctur;i++){
        if(a.empty() || b.empty()) break;
        int aa=a.front();
        int bb=b.front();
        if(aa>bb){
            a.push(bb);
            a.push(aa);
            a.pop();
            b.pop();
        }
        else{
            b.push(aa);
            b.push(bb);
            a.pop();
            b.pop();
        }
        licznik++;
    }

    if(a.empty()){
    cout << "B wygrywa w turze " << licznik << "." << endl;
    goto here;
    }
    if(b.empty()) {
    cout << "A wygrywa w turze " << licznik << "." << endl;
    goto here;
    }
    cout << "A: ";
    while(a.size()>0){
    cout << a.front() << " ";
    a.pop();
    }
    cout << endl;
    cout << "B: ";
    while(b.size()>0){
    cout << b.front() << " ";
    b.pop();
    }
    cout << endl;
    here:;
}
}
