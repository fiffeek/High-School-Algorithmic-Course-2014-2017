#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> G[200000];
bool visited[200000];
long long wejscie[200000];
long long low[200000];
long long l = 0;
long long ilosc[200000];
long long pietro[200000];

void dfs(long long a,long long poprzedni){
	visited[a] = 1;
	wejscie[a] = l;
	low[a] = l++;
	for(long long i=0;i<G[a].size();i++){
		if(G[a][i]!=poprzedni){
			if(visited[G[a][i]]==0){
				dfs(G[a][i],a);
				low[a]=min(low[a],low[G[a][i]]);
			}else{
				low[a]=min(low[a],wejscie[G[a][i]]);
			}
		}
	}
}

void predfs(long long a,long long poprzedni,long long o){
	visited[a] = 1;
	pietro[a] = o;
	//cout << "WIERZ : " << a << " kup: " << G[a].size() << endl;
	for(long long i=0;i<G[a].size();i++){
		//cout << G[a][i] << " a poprz" << poprzedni << endl;
		if(G[a][i]!=poprzedni){
			if(visited[G[a][i]]==0){
				predfs(G[a][i],a,o+1);
				ilosc[a]+=ilosc[G[a][i]] + 1;
			}
			
		}
	}
}

int main(){
	long long z;
	cin >> z;
	while(z--){
		long long n,m;
		cin >> n >> m;
		l=0;
		
		for(long long i=0;i<=n;i++){
			 visited[i] = 0;
			 ilosc[i] = 0;
			 G[i].clear();
			 low[i] = 0;
			 wejscie[i]= 0;
		}
		
		long long s = 0;
		
		for(long long i=0;i<m;i++)
		{
			long long a , b;
			cin >> a >> b;
			
			G[a].push_back(b);
			G[b].push_back(a);
			
			s = a;
		}
		
		predfs(s,s,0);
		
	/*	cout << "PREHEHEH" << endl;
		for(long long i=1;i<=n;i++){
			cout << " PODRZEWO : " << i << " TO " << ilosc[i] << endl;
		}*/
		
		for(long long i=0;i<=n;i++) visited[i] = 0;
		
		dfs(s,s);
		
	/*	cout << "LOWEMJESTES" << endl;
		for(long long i=1;i<=n;i++){
			cout << "LOW DLA: " << i << " TO " << low[i] << " ORAZ wejscie to : " << wejscie[i] << endl;
		}*/
		
		
		for(long long i=1;i<=n;i++){
			//cout << "DLA WIERZ : " << i << endl;
			//long long odp = 0;
		//	if(i==s){
				
			//}else{
			//cout << i << " co? " << G[i].size() << endl;
			//	for(long long j=0;j<G[i].size();j++){
					//cout << "SPRAWDZANE WIERZ Z SYNEM : syn : " << G[i][j] << endl;
					//cout << wejscie[G[i][j]] << " wej " << wejscie[i] << endl;
					//if(wejscie[G[i][j]]>wejscie[i]){
						//cout << low[G[i][j]] << " loiu "<< low[i] << endl;
						//if(low[G[i][j]]<=low[i]){
							
						//}
					//}
			//	}	
		//	}
			
			//long long k = n - odp;
			//cout << "TO K " << k << endl;
			
			
			//cout << n*(n-1) - 2*k << endl;
			
			if(ilosc[i]==0) cout << (n-1)*(n-2) << endl;
			else if(i==s){
				long long odp = 0;
				for(long long j=0;j<G[i].size();j++){
					if(pietro[G[i][j]]==(pietro[i]+1))
					odp+=(ilosc[G[i][j]]*(ilosc[G[i][j]]+1));
				}
				cout << odp  << endl;
			}else{
				long long odp = 0;
				long long us = 1;
				for(long long j=0;j<G[i].size();j++){
				//	cout << "to i " << i << " to j" << G[i][j] << endl;
				//	cout << wejscie[G[i][j]] << " dafaq" << wejscie[i] << endl;
					if(low[G[i][j]]>=wejscie[i] && pietro[G[i][j]]==(pietro[i]+1)){
					//	cout << "wchodzzzeee" << endl;
						odp+=(ilosc[G[i][j]]*(ilosc[G[i][j]]+1));
						us+=ilosc[G[i][j]]+1;
					}
				}
				
			//	cout << "tylw usu" << us << endl;
				long long p = n-us;
				//cout << p << endl;
				cout << odp + (p)*(p-1) << endl;
			}
		}
		
	}
}
