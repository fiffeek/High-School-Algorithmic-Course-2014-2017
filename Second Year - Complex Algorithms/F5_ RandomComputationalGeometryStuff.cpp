#include <iostream>
#include <algorithm>

using namespace std;

struct tangens{
      long long p,q;
};

tangens tab[500005];


long long nwd(long long a,long long b)
{
    long long c;           
    while(b!=0){
        c = a % b;         
		a = b;
        b = c;
    }
    return a; 
}

int main(){
	int z;
	cin >> z;
	while(z--){
		int a;
		cin >> a;
		
		for(int i=0;i<a;i++){
			tangens A;
			cin >> A.p >> A.q;
			tab[i]=A;
		}
		
		long long wynik = 0;
		
		for(long long i=0;i<a;i++){
                      if(i==0) wynik+=(tab[i].p*(tab[1].q - tab[a-1].q));
                      else if(i==(a-1)) wynik+=(tab[a-1].p*(tab[0].q - tab[a-2].q));
                      else wynik+=(tab[i].p*(tab[i+1].q - tab[i-1].q));
        }
        
        wynik/=2;
        if(wynik < 0) wynik*=(-1);
        
        //pole to wynik
        
        long long zew=0;
        
        for(int i=0;i<(a-1);i++){
        	long long c = tab[i+1].p - tab[i].p ;
        	if(c<0) c*=(-1);
			long long d = tab[i+1].q - tab[i].q ;
			if(d<0) d*=(-1); 
        	zew+=nwd(c,d);
        	//cout << tab[i+1].p - tab[i].p << " " << tab[i+1].q - tab[i].q << endl;
        	//cout << nwd(tab[i+1].p-tab[i].p,tab[i+1].q - tab[i].q) << endl;
		}
		
		long long c = tab[0].p - tab[a-1].p ;
        if(c<0) c*=(-1);
		long long d = tab[0].q - tab[a-1].q ;
		if(d<0) d*=(-1); 
        zew+=nwd(c,d);
		
		//cout << "POLE I ZEW" << wynik << " " << zew << endl;
		long long odp = 0;
		zew/=2;
		odp= wynik + 1 - zew;
		
		cout << odp << endl; 
	}
}
