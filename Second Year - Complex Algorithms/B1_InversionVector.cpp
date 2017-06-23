#include <iostream>
#include <vector>

using namespace std;

int tab[5000005];
int wej[5000005];
vector <int> V;

unsigned long long f(int n,int x){
	//cout << "1 wejscie"  << n << endl;
	int liczba = 1;
	while(liczba<x){
		tab[liczba]--;
	
		if(tab[liczba*2] >= n){
			liczba*=2;	
		}
		else{
			n-=tab[liczba*2];
			liczba=(liczba*2)+1;
		}
			
	}
	tab[liczba]--;
//	for(int i=0;i<=(2*x-1);i++) cout << tab[i] << " ";
     //   cout << endl;
	V.push_back(liczba-x+1);
}


int main(){
	int z;
	cin >> z;
	while(z--){
		int a;
		cin >> a;
		
		for(int i=0;i<a;i++) cin >> wej[i];
		
		int x=1;
        while(x<a)x*=2;
		
		
		for(int i=0;i<2*x;i++) tab[i]=0;
        for(int i=x;i<(x+a);i++) tab[i] = 1;
        
       // for(int i=0;i<=(2*x-1);i++) cout << tab[i] << " ";
      //  cout << endl;

        int taki=x-1,b=2*x-1;

        for(int i=b;i>=2;i-=2){
            tab[taki] = tab[i] + tab[i-1];
            taki--;
        }
        
       // for(int i=0;i<=(2*x-1);i++) cout << tab[i] << " ";
       // cout << endl;
        
        for(int i=a;i>0;i--) f((i - wej[i-1]),x);
        
        for(int i=V.size();i>0;i--){
        	cout << V[i-1] << " ";
		}
		cout << endl;
		V.clear();
		
	}
}
