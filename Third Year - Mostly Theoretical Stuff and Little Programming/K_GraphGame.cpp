#include <iostream>
#include <vector>

using namespace std;

long long tab[1005][4];
long long odp = 0;
vector <long long> w[1000005];
bool visited[1000005];
long long mapp[1005][1005];

void dfs(long long a){
	odp++;
	visited[a]=1;
	
	for(long long i=0;i<w[a].size();i++){
		if(visited[w[a][i]]==0){
			 dfs(w[a][i]);
		}
	}
}

int main(){
	long long z;
	cin >> z;
	while(z--){
		odp = 0;
		
		long long a;
		cin >> a;
		
		long long ob = 0;
		for(long long i=0;i<a;i++){
			for(long long j=0;j<a;j++){
				mapp[i][j]=ob;
				ob++;
			}
		}
		
		for(long long i=0;i<a*a;i++){
			 visited[i] = 0;
			 w[i].clear();
		}
		
		for(long long i=0;i<a;i++){
			cin >> tab[i][0] >> tab[i][1]>> tab[i][2] >> tab[i][3];
			
			tab[i][0]--;
			tab[i][1]--;
			tab[i][2]--;
			tab[i][3]--;
			
		}

		for(long long i=0;i<a;i++){
			for(long long j=0;j<a;j++){							
				for(long long k=0;k<4;k++){
					w[mapp[tab[i][k]][tab[j][k]]].push_back(mapp[i][j]);
				}

			}
		}
		
		for(long long i=0;i<a;i++){
			if(visited[mapp[i][i]]==0) dfs(mapp[i][i]);
		}
		
		if(odp==(a*a)) cout << "TAK" << endl;
		else cout << "NIE" << endl;
	}
}
