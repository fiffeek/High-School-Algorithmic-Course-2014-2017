#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


struct tangens{
      long long p,q;
};

tangens w;
bool sortowanie (tangens a,tangens b) {
      tangens A;
	  A.p =(a.p-w.p);
      A.q =(a.q-w.q);
	 tangens B;
	  B.p =(b.p-w.p);
      B.q =(b.q-w.q);
	  if(A.p*B.q==A.q*B.p){
              return ((A.p)*(A.p) + (A.q)*(A.q)) < ((B.q)*(B.q) + (B.p)*(B.p));
      }else{
              return (A.p*B.q ) > (A.q*B.p);
      }
}


stack <tangens> S;
tangens tab[1000005];
tangens tab2[1000005];

long long wyznacznik(tangens a, tangens b, tangens c){
	return a.p*b.q + b.p*c.q + c.p*a.q - c.p*b.q - a.p*c.q - b.p*a.q;
}


bool wektor(tangens punkt){
	tangens punkt2 = S.top();
	S.pop();
	tangens punkt1 = S.top();
	S.push(punkt2);
//	cout << "gdzies sie psujeee" << endl;
//	cout << S.size() << "WOWO" << endl;
//	cout << wyznacznik(punkt1,punkt2,punkt) << "jaki?" << endl;
	if(wyznacznik(punkt1,punkt2,punkt)>=0) return 0;
	if(wyznacznik(punkt1,punkt2,punkt)<0) return 1;
//	cout << " ???" << endl;
}

int main(){
	long long z;
	cin >> z;
	while(z--){
		long long a;
		cin >> a;
		
		long long wynik = 0; 
		w.p=1000000001;
		w.q=1000000001;
		tab[a].p=10000000001;
		tab[a].q=10000000001;
		
		for(long long i=0;i<a;i++){
			cin >> tab[i].p >> tab[i].q;
			if(tab[i].q<w.q){
				w.q=tab[i].q;
				w.p=tab[i].p;
			}else if(tab[i].q==w.q){
				if(tab[i].p<w.p) w.p=tab[i].p;
			}
		}
	//	cout << w.p<< " punkt obrotu " << w.q << endl;
		
		sort(tab,tab+a,sortowanie);
		//usuwanietych samych
		int j=0;
		for(int i=0;i<a;i++){
			//cout << tab[i].p << " " << tab[i].q << " " << tab[i+1].p << " " << tab[i+1].q << endl;
			if((tab[i].p - w.p)*(tab[i+1].q- w.q)!=(tab[i].q- w.q)*(tab[i+1].p - w.p)){
				tab2[j].p = tab[i].p;
				tab2[j].q = tab[i].q;
				j++;
			}
		}
		
		//cout << "pozn" << endl;
		
		
		S.push(w);
		S.push(tab2[0]);
		S.push(tab2[1]);
		
	/*	for(int i=0;i<j;i++){
			cout << tab2[i].p << " " << tab2[i].q << endl;
		}*/
		
		for(long long i=2;i<j;i++){
		//	cout << "OBROT" << i << endl;
			while(wektor(tab2[i])) S.pop();
			S.push(tab2[i]);
		}
		
	//	cout << S.size() << " OTOCZKAAA!" << endl;
		
		long long L = S.size();
		
		for(long long i=L-1;i>=0;i--){
			tab[i]=S.top();
			S.pop();
		}
		
		//for(long long i=0;i<L;i++) cout << tab[i].p << " " << tab[i].q << endl;
		
		
		for(long long i=0;i<L;i++){
			if(i==0) wynik+=(tab[i].p*(tab[1].q - tab[L-1].q));
			else if(i==(L-1)) wynik+=(tab[L-1].p*(tab[0].q - tab[L-2].q));
			else wynik+=(tab[i].p*(tab[i+1].q - tab[i-1].q));
		}
		
		cout << wynik << endl;
				
	}
}
