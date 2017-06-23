#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[500005];
int distanc[500005];
vector<int> G[500005];

int main(){
	int ilosc;
	cin >> ilosc;
	while(ilosc--){
	//cout << "dsaads" << endl;

		int E, V;
		cin >> V >> E;
		for(int i=0;i<V+1;i++){
			distanc[i]=0;
			visited[i]=0;
			G[i].clear();
		}

		//n=v
		//m=e
	//		cout << "da" << endl;
		for(int i=0;i<E;i++){
			int a,b;
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
//	cout << "brr" << endl;
		int start;
		cin >> start;

		int pierwsze=start;

		int grupy=1;

		//bfs
		int ii=1;
        queue<int> k;
		miejsce:
		k.push(start);
		visited[start]=true;

		//cout << "2.1" << endl;

		while(k.size()>0){
			int przejsciowa=k.front();
			k.pop();

			for(int i=0;i<G[przejsciowa].size();i++){
				int a=G[przejsciowa][i];
				if(visited[a]==false){
					distanc[a]=distanc[przejsciowa] + 1;
					k.push(a);
					visited[a]=true;
				}
			}
		//	cout << "bebe" << endl;
		}

		if(grupy==1){
			cout << "Znajomi numeru " << pierwsze << ":" << endl;
			for(int i=1;i<V+1;i++){
				if(i!=pierwsze && distanc[i]!=0) cout << i << ": " << distanc[i] << endl;
			}
		}

		sprawdzanie:
        while(visited[ii]==true && ii < V +1) ii++;
		while(visited[ii]==false && ii<V +1){
			start=ii;
			grupy++;
			if(G[ii].empty()){
                visited[ii]=1;
                goto sprawdzanie;
			} else goto miejsce;
		}

		cout << "Grup znajomych jest " << grupy << "." << endl;

	}
}
