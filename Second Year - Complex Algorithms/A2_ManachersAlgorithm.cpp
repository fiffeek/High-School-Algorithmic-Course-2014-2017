#include <iostream>

using namespace std;

int wyn[2000006];

int main(){
	int a;
	cin >> a;
	while(a--){
		string z;
		cin >> z;
		
		int m = z.length();
		
		string l;
		l+='$';
		for(int i=0;i<z.length();i++){
		//	cout << z[i] << endl;
			l+= '#';
			l+=z[i];
		//	cout << l << endl;
		}
		l+='#';
		l+='@';
		
		int i=2;
		int j=0;
		
		wyn[0] = 0;
		for(int i=0;i<=l.length();i++) wyn[i] = 0;
		wyn[1] = 1;
		//cout << l << endl;
		//cout << l[4] << endl;
	//	cout << l.size() << "lsajt"<< endl;
		while(i<=(l.length())){
			while(l[i-j-1]==l[i+j+1]) j++;
			wyn[i] = j;
		/*	cout << i-j-1 << " liczby " << i+j+1 << endl;
			cout << l[i-j-1] << " litery " << l[i+j+1] << endl;
			cout << i << " i i jot " << j << endl;*/
			
			int k=1;
			while(k<=j && wyn[i-k]!=(wyn[i]-k)){
				wyn[i+k] = min(wyn[i-k],(wyn[i]-k));
				k++;
			}
			
			j=j-k;
			if(j<0) j=0;
			i+=k;

		}
		//cout << "po" << endl;
		//manacher
		
	/*	for(int i=0;i<l.size();i++){
			cout << wyn[i] << " ";
		}
		cout << endl;*/
		
		int liczba;
		cin >> liczba;
		
		while(liczba--){
			unsigned long long b,c;
			cin >> b >> c;
			//cout << (b+c)%2 << " " << wyn[(b+c)] << endl;
			if(b==c) cout << "TAK" << endl;
			else{
				if(wyn[(b+c)]>=(c-b)) cout << "TAK" << endl;
				else cout << "NIE" << endl;
			}
			
		}
	}
}
