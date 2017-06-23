#include <iostream>
#include <vector>

using namespace std;

vector <int> G[500000];
int in[500000];
int out[500000];
char col[500000];
int i;

void dfs(int a){

	col[a]='G';
	in[a]=i;
	i++;
	
	int liczba=G[a].size();
	for(int ii=0;ii<liczba;ii++){
		if(col[G[a][ii]]=='W') dfs(G[a][ii]);
	}
	
	col[a]='B';
	out[a]=i;	
	i++;
}

int main(){
	
	int a;
	cin >> a;
	while(a--){
		int b;
		cin >> b;
		
		for(int y=0;y<b;y++){
			col[y]='W';
			G[y].clear();
			in[y]=0;
			out[y]=0;

		}

		
		for(int r=1;r<b;r++){
			int c;
            cin >> c;
            G[c].push_back(r);
		}
		
		i=0;
		//dfs
		dfs(0);
		
		int taka;
		cin >> taka;
		
		for(int i=0;i<taka;i++){
			int a,b;
			cin >> a >> b;
			
			/*cout << "+==============+" << endl;
			cout << in[a] << " " << out[a] << endl;
			cout << in[b] << " " << out[b] << endl;
			cout << "+==============6" << endl;*/
			
			
			if(in[a] < in[b] && in[b] < out[b] && out[b] < out[a]){
				cout << "TAK" << endl;
				
			}	 else cout << "NIE" << endl;		
			
		}
		
	}
}
