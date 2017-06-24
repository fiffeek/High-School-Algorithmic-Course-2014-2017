#include <iostream>

using namespace std;

struct p{
	long long punkt,krow;
}; 

p tab[1000005];

int main(){
	long long z;
	cin >> z;
	while(z--){
		long long a;
		cin >> a;
		
		long long o = 0;
		long long load = 0;
		for(long long i=0;i<a;i++){
			long long x,y,w;
			cin >> x >> y >> w; x--; y--;
			if(x<0) o+=w;
			if(y<0) o+=w;
			
			tab[load].punkt = x; tab[load].krow = w; load++;
			tab[load].krow = w; tab[load].punkt = y; load++;
		}
		
		if(o!=0){
			cout << o << endl;
		}else{
			long long xort = 0;
			for(long long i=0;i<load;i++){		
				if(tab[i].krow%2==1) xort = (xort ^ tab[i].punkt);
				
			//	cout << "AAA" << xort << endl;
			}
			//cout << xort << endl;
			
			for(long long i=0;i<load;i++){
				if((xort ^ tab[i].punkt) < tab[i].punkt){
					 o += tab[i].krow;
					// cout << "A "  << tab[i].punkt << " "<< tab[i].krow<< endl;
				}
			}
			cout << o << endl;
		}
	}
}
