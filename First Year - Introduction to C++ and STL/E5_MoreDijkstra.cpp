#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

unsigned long long koszt[50005];
vector <pair <int, int> > G[50005];

struct ps{
	int p,c;
};

struct cs{
      bool operator()(ps a,ps b){
              return a.p>b.p;
      }
};

int main(){
	ios_base::sync_with_stdio(0);
	int z;
	cin >> z;
	while(z--){
		int a,b;
		cin >> a >> b;
		
		
		for(int j=0;j<=a;j++){
			koszt[j] = 1844674407370955161;
			G[j].clear();
		}
		
		koszt[1] = 0;
		
		for(int j=0;j<b;j++){
			int temp,temp2,k;
			cin >> temp >> temp2 >> k;
			pair <int , int > P;
			P.first = temp2;
			P.second = k;
			G[temp].push_back(P);
		}
		
		ps para;
		para.p = koszt[1];
		para.c = 1;
		
		priority_queue <ps, vector<ps>, cs > Q;
		
		Q.push(para);
		
		while(Q.empty()==false){
			int w = Q.top().c;
			Q.pop();		
			
			for(int j=0;j<G[w].size();j++){		
					
					if(koszt[G[w][j].first]> koszt[w] + G[w][j].second){
						koszt[G[w][j].first] = koszt[w] + G[w][j].second;
						
						ps para;
						para.p = koszt[G[w][j].first];
						para.c = G[w][j].first;
						Q.push(para);
						
					}		
				
			}
					
		}
		
		if(koszt[a]!=1844674407370955161) cout << koszt[a] << endl;
		else cout << "BRAK" << endl;
	
	}
	
}
