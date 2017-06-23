#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector <int> G[100005];
vector <int> T[100005];
bool visited[100005];
vector <int> V;
int tab[100005];
stack <int> S;

void dfs(int a){
	visited[a] = true;
	for(int j=0;j<G[a].size();j++){
		if(visited[G[a][j]]==0) dfs(G[a][j]);
	}
	S.push(a);
}

void dfs2(int a){
	visited[a] = true;
	V.push_back(a);
	for(int j=0;j<T[a].size();j++){
		if(visited[T[a][j]]==0) dfs2(T[a][j]);
	}	
}


int main(){
	int z;
	cin >> z;
	while(z--){
		
		int a , b;
		
		cin >> a >> b;
		
		V.clear();
		
		
		for(int j=0;j<=a;j++){
			 visited[j] = 0;
			 G[j].clear();
			 T[j].clear();
		}
		
		for(int i=0;i<b;i++){
			int temp,temp2;
			cin >> temp >> temp2;
			
			G[temp].push_back(temp2);
			T[temp2].push_back(temp);
		}
		
		for(int j=1;j<=a;j++) if(visited[j]==0) dfs(j);
		
		for(int j=0;j<=a;j++) visited[j] = 0;
		
		while(S.empty()==false){
			int a = S.top();
			S.pop();
			if(visited[a]==true) goto k;
			dfs2(a);
			
			for(int u=0;u<V.size();u++){
				int zmienna = V[u];
				tab[zmienna] = V.size()-1; 
			}
			
			V.clear();
			
			k:;
		}
		
		for(int j=1;j<=a;j++){
			cout << tab[j] << " ";
		}
		
		cout << endl;
	}
	
}
