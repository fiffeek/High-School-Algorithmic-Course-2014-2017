#include <iostream>
#include <stack>

using namespace std;

int main(){
int rr;
cin >> rr;
for(int i=0;i<rr;i++){
    stack<int> s;
    int licznik;
    cin >> licznik;

    for(int i=0;i<licznik;i++){
        int liczba;
        cin >> liczba;
        if(s.empty()==false && s.top()==liczba) s.pop();
        else s.push(liczba);
    }

if(s.empty()) cout << "TAK" << endl;
else cout << "NIE" << endl;
}
}
