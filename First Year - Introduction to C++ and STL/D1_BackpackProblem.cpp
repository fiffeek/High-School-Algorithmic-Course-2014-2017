#include <iostream>
using namespace std;
int tab[10000];

int main(){
	int l;
	cin >> l;
	while(l--){
		int a,b;
		cin >> a >> b;
		
		for(int i=0;i<=b;i++) tab[i]=0;
		
		for(int i=0;i<a;i++){
			int w,v;
			cin >> w >> v;
			
			for(int j=b;(j-w)>=0;j--){
				tab[j]=max(tab[j],tab[j-w]+v);			
			}
		
		}
		
		cout << tab[b] << endl;
	
	}
}
