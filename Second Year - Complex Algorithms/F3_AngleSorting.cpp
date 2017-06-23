#include <iostream>
#include <algorithm>

using namespace std;

struct tangens{
	long long p,q;
	long long numer;
};

bool sortowanie (tangens a,tangens b) { 
	if(a.p*b.q==a.q*b.p){
		return ((a.p)*(a.p) + (a.q)*(a.q))< ((b.q)*(b.q) + (b.p)*(b.p));
	}else{
		return (a.p*b.q ) < (a.q*b.p);
	}
}

tangens tab[1000005];

int main(){
	long long z;
	cin >> z;
	while(z--){
		long long a;
		cin >> a;
		for(int i=0;i<a;i++){
			tangens b;
			int d,e;
			cin >> d >> e;
			b.p=d; b.q=e; b.numer=i+1;
			tab[i]=b;
		}

		sort(tab,tab+a,sortowanie);
		
		for(int i=0;i<a;i++){
			cout << tab[i].numer << endl;
		}
		
	}
}
