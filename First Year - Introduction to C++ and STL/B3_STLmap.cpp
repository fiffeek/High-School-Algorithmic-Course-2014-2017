#include <iostream>
#include <map>
using namespace std;

main(){
int rr;
cin >> rr;
while(rr--){
map<string,string> Mapa;
string a,b;
int n;
cin >> n;
cout << "- ";

for(int i=0;i<n-1;i++){
    if(i==0)cin >> a;
    cin >> b;
    if((a==b))
    Mapa[a]=="";
    else Mapa[a]=b;
    a=b;
    if(Mapa[a]=="") cout << "- ";
    else cout << Mapa[a] << " ";
}

cout << endl;
}

}
