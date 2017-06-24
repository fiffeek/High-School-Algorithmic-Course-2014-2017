#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector <int> V;
stack <int> S;

int main(){
	int z;
	cin >> z;
	while(z--){
		int n;
		cin >> n;
		
		V.clear();
		while(S.empty()==0) S.pop();
		if(n==1){
			cout << "ab" << endl;
			goto koniec;
		}
		
		S.push(0);
		for(int i =0;i<=1050000;i++) V.push_back(0);
		
		//cout << "@@@@" << endl;
		while(S.empty()==0){
			int v = S.top();
			//cout << v << endl;
			if(V[v]==2){
				//cout << "ADA" << endl;
				//cout << S.top();
				if(S.top()%2 == 0) cout << 'a';
				else cout << 'b';
				
				S.pop();
			}else{
				//cout << "Aa" << endl;
				int nas = ((v << 1) & ((1 << (n-1)) - 1)) + V[v];
				V[v]++;
				S.push(nas);
			}
		}
		for(int i =0;(i+2)<n;i++) cout << 'a';
		cout << endl;
		
		koniec:;
		
	}
}
