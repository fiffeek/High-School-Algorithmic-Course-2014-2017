#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a,h;

    cin >> a >> h;
    int tablica[100005];

    int n;
    for(int i=0;i<a;i++){
        cin >> n;
        tablica[i]=n;
    }

     sort(tablica,tablica + a);
     a--;


    int iloscpolek=0;
    int i=0;

    while(i<a){
        if(tablica[a]+tablica[i]<=h){
            i++;
            iloscpolek++;
        }
        else{
            iloscpolek++;
        }
        a--;
    }
if(i==a) iloscpolek++;
cout << iloscpolek << endl;

}