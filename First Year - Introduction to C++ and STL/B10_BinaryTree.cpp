#include <iostream>
#include <cstdio>

using namespace std;
int tab[5000000];

int drzewonrek(int x){

	int liczba,liczba1;
	scanf("%d",&liczba);
	scanf("%d",&liczba1);
	int maax=0;
	liczba+=x-1;
	liczba1+=x-1;
	
	if(tab[liczba]>tab[liczba1]) maax = tab[liczba];
    else maax = tab[liczba1];
		
	//cout << liczba << " " << liczba1 << endl;

	while((liczba/2)!=(liczba1/2)){
		if(liczba%2==0) if(maax<tab[liczba+1]) maax=tab[liczba+1];
		//cout << tab[liczba+1] << endl;
		if(liczba1%2==1) if(maax<tab[liczba1-1]) maax=tab[liczba1-1];
		//cout << tab[liczba1-1] << endl;
		liczba/=2;
		liczba1/=2;
	}
		
	return maax;
}


int main(){
		int ill;
		scanf("%d",&ill);
			while(ill--){
		
			int n,a;
			scanf("%d",&n);
			int x=1;
			while(x<n)x*=2;
			
			//cout << x << endl;
			
			for(int i=0;i<2*x;i++) tab[i]=0;
			for(int i=x;i<=(2*x)-1;i++) if(i<x+n) cin >> tab[i];
			
			int taki=x-1,b=2*x-1;
			
			for(int i=b;i>=2;i-=2){
				if(tab[i] > tab[i-1]) tab[taki] = tab[i];
				else tab[taki] = tab[i-1];
				taki--;
			}
			
			//for(int i=0;i<2*x;i++) cout << tab[i] << " ";
			//cout << endl;
			
			int il;
			scanf("%d",&il);
			while(il--){
				a=drzewonrek(x);
				printf("%d\n",a);
			}
	}
}

