#include <iostream>
#include <vector>

using namespace std;

vector <int> G[3005];
int m1[3005];
int m2[3005];
bool visited[3005];

bool dfs(int a){
	if(a==(-1)) return true;
	if(visited[a]==1) return false;
	visited[a]=1;
	for(int i=0;i<G[a].size();i++){
		if(dfs(m2[G[a][i]])){
			m1[a]=G[a][i];
			m2[G[a][i]]=a;
			//cout << " aaaa" << endl;
			//cout << a <<" " << G[a][i] << endl; 
			//cout << m1[a]<< " " << m2[G[a][i]] << endl;
			//cout << "aaaa" << endl;
			return true;
		}
	}
	return false;
}

int main(){
	int z;
	cin >> z;
	while(z--){
		int n,m;
		cin >> n >> m;
		
		for(int i=0;i<=2*n;i++){
			G[i].clear();
		}
		
		for(int i=0;i<m;i++){
			int a,b;
			cin >> a >> b;
			G[a].push_back(b+n);
		}
		
		for(int i=0;i<=2*n;i++){
			m1[i]=-1;
			m2[i]=-1;
		}
	
	
		while(true){
			for(int i=0;i<=2*n;i++) visited[i]=0;
			bool ok = 0;
			for(int i=1;i<=n;i++){
				if(m1[i]==(-1)){
					if(dfs(i)){
						ok = 1;
					}
				}
			}
			if(!ok) break;
		}
		
		//for(int i=0;i<=n;i++) cout << m1[i] << " ";
		//cout << endl;
		
		for(int i=1;i<=n;i++){
			if(m1[i]==(-1)){
				cout << "NIE" << endl;
				goto poza;
			}
		}
		cout << "TAK" << endl;
		poza:;
	}
}
