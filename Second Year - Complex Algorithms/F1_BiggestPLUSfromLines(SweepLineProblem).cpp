#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct Punkt{
	long long akcja;
	long long x1,y1;
	long long x2,y2;
	int co;
};

//
// co
// 1 = poczatek poziomej
// 2 = pionowa
// 3 = koniec poziomej

struct porownanie{
      bool operator()(Punkt a, Punkt b){
              if(a.akcja!=b.akcja) return a.akcja > b.akcja;
              else{
              	return a.co > b.co;	
			  }
      }
};

priority_queue<Punkt,vector<Punkt>, porownanie> Q;
set <long long> pocotokomu;
set <long long> ::iterator f;
Punkt pion[100000];
Punkt poz[100000];

bool algorytm(){
	while(Q.empty()==false){
		Punkt A;
		A = Q.top();
		if(A.co==1){
			pocotokomu.insert(A.y1);
		}else if(A.co==3){
			A.akcja=A.x1;
			pocotokomu.erase(A.y1);
		}else{
			if(pocotokomu.size()>0){
				f=pocotokomu.lower_bound(A.y1);
				long long B;
				if(f!=pocotokomu.end()) B= *f;
				if((f!=pocotokomu.end()) && B<=A.y2){
					goto dal;
				}   
			}
		}

		Q.pop();
	}
	pocotokomu.clear();
	return false;
	
	dal:
	pocotokomu.clear();
	while(Q.empty()==false) Q.pop();
	return true;
}

void dokolejki(long long n,long long m, long long ilosc){
	for(long long i=0;i<n;i++){
		Punkt A = pion[i];
		long long zmienna = (A.y2-A.y1) - 2*ilosc;
		if(zmienna>=0){
			A.y1+=ilosc;
			A.y2-=ilosc;
			Q.push(A);
		}
		
	}
	
	for(long long i=0;i<m;i++){
		Punkt A = poz[i];
		long long zmienna = (A.x2-A.x1) - 2*ilosc;
		if(zmienna>=0){
			A.x1+=ilosc; A.x2-=ilosc;
			A.akcja=A.x1;
			A.co=1;
			Q.push(A);
			A.akcja=A.x2;
			A.co=3;
			Q.push(A);
		}
	}
}

int main(){
	long long n,m;
	cin >> n >> m;
	long long p=0;
	
	for(long long i=0;i<n;i++){
		long long a,b,c;
		cin >> a >> b >> c;
		if(c>=p) p=c;
		
		Punkt liczba;
		liczba.x1=a;
		liczba.y1=b;
		liczba.x2=a;
		liczba.y2=b+c;
		liczba.akcja=a;
		liczba.co=2;
		pion[i]=liczba;
	}
	
	for(long long i=0;i<m;i++){
		long long a,b,c;
		cin >> a >> b >> c;
		if(c>=p) p=c;
		
		Punkt liczba;
		liczba.x1=a;
		liczba.y1=b;
		liczba.x2=a+c;
		liczba.y2=b;
		liczba.akcja=a;
		liczba.co=0;
		poz[i]=liczba;
	}
	
	long long s = 0;
	long long k=p+1;
    while(s<k){
    	dokolejki(n,m,((s+k)/2 + 1));
    	if (algorytm()){
    		 s=((s+k)/2)+1;
		}
        else{
			k = ((s + k )/ 2);
        }
	}
	cout << s << endl;
	
}
