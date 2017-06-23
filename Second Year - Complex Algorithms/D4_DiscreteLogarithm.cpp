#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

pair <long long, long long> tab[32000];
long long tab2[32000];
vector <long long> tab3;

bool my (pair<long long,long long> a,pair<long long,long long> b) { return (a.first<b.first); }

long long x=1,y=0,nwd=0;

void gcd(long long a, long long b){
      if(b==0){
              nwd=a;
              return;
      }
      else{
      gcd(b, a%b);
      }

      long long zmienna = y;
      y = x  - floor(a/b)*y;
      x = zmienna;
}

int main(){
	long long z;
	cin >> z;
	while(z--){
		long long a ,b ,p;
		cin >> a >> b >> p;
	
		long long M=ceil(sqrt(p));
		
		long long zmienna = 1;
		for(int i=0;i<M;i++){
			tab[i].first=zmienna;
			tab[i].second=i;
			tab2[i]=zmienna;
			zmienna*=a;
			zmienna%=p;
			while(zmienna<0) zmienna+=p;
		}
	
		/*cout << "DEBUG 1 TABLICY:" << endl;
		for(int i=0;i<M;i++) cout << tab[i].first << " " << tab[i].second << endl;
		cout << "DEBUG OFF" << endl;
		*/
		sort(tab,tab+M,my);
		sort(tab2,tab2+M);
		
	/*	cout << "DEBUG 1 TABLICY po sorcie:" << endl;
		for(int i=0;i<M;i++) cout << tab[i].first << " " << tab[i].second << endl;
		cout << "DEBUG OFF" << endl;*/
		
		x=1;
		y=0;
		nwd=0;
		
		gcd(zmienna,p);
	//	cout << "x z euklidesa:" << endl;
		while(x<0) x+=p;
	//	cout << x << endl;
		
		zmienna=b;
		long long heh=0;
		
		for(int i=0;i<M;i++){
			long long odp=lower_bound(tab2,tab2+M,zmienna)-tab2;
			//cout << odp << endl;
		//	cout << zmienna << " " << tab[odp].first << "porownanie" << endl;
			if(tab[odp].first==zmienna){
				//cout << tab[odp].second << " " << i << " " << M << endl;
				tab3.push_back(tab[odp].second + i*M);
				heh++;
				//cout << "bylem tu" << endl;
			}
			
			zmienna*=x;
			zmienna%=p;
			while(zmienna<0) zmienna+=p;
		}
		
		sort(tab3.begin(),tab3.end());
		if(tab3.empty()==1) cout << "-1" << endl;
		else cout << tab3[0] << endl;
		
		tab3.clear();
	}
}
