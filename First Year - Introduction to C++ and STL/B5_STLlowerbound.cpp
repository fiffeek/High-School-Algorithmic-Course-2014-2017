#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int licznik;
	cin >> licznik;
	while(licznik--){
	    int a,b;
	
	    cin >> a;
	    int tablica[100005];
	
	    int n;
	    int potrzebny = a;
	    for(int i=0;i<a;i++){
	        cin >> n;
	        tablica[i]=n;
	    }
	    sort(tablica,tablica+a);
	    
	    cin >> b;
	    for(int i=0;i<b;i++){
	        cin >> n;
	        int x=lower_bound(tablica,tablica+a-1,n)-tablica;
	        int x2=x-1;
	
	        int liczba2=tablica[x];
	        int liczba3=tablica[x2];
	        
	        if(x==0) cout << liczba2 << " ";
	        else if(n==liczba2) cout << liczba2 << " ";
	        else if(n>tablica[a-1]) cout << tablica[a-1] << " "; 
	        else if(liczba2-n>=n-liczba3) cout << liczba3 << " ";
	        else if(liczba2-n<n-liczba3) cout << liczba2 << " ";
	
	
	    }
	    cout << endl;
   }


}
