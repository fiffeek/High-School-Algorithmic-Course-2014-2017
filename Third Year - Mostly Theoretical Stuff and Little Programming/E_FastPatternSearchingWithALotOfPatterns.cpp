#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int ruch[1000000][4];
int il=1;

vector <int> tab[1000000];
bool wynik[1000000];
bool visited[1000000];
int suf[1000000];

stack <int> S;


int graf(int liczba, char znak){
	int zn= 0;
	if(znak=='A') zn=0;
	else if(znak=='C') zn=1;
	else if(znak=='G') zn=2;
	else zn=3;
	if(ruch[liczba][zn] != (-1)) return ruch[liczba][zn];
	ruch[liczba][zn]= il; 
	
	ruch[il][0]=(-1);
	ruch[il][1]=(-1);
	ruch[il][2]=(-1);
	ruch[il][3]=(-1);
	
	il++;
	
	return ruch[liczba][zn];
	
	
}

void dodaj(string c, int numer){
	int a=0;
	for(int i=0;i<c.length();i++){
		a = graf(a,c[i]);
	
	}
	
	tab[a].push_back(numer);

}

void bfs(int s, int koniec){
	
	suf[s] = 0;
	for(int i=0;i<4;i++){
		if(ruch[s][i]!=(-1)) suf[ruch[s][i]]=s;
		else ruch[s][i]=0;
	}

	
	
	for(int i=0;i<koniec;i++){
		visited[i] = 0;
	}
	
	queue <int> Q;
	visited[s]=1;
	Q.push(s);
	
	while(Q.empty()==false){
		
		int top = Q.front();
		S.push(top);
		Q.pop();
		
		for(int i=0;i<4;i++){
			if(ruch[top][i]==(-1)) goto p;
			if(visited[ruch[top][i]]==false){
				visited[ruch[top][i]]=true;
				Q.push(ruch[top][i]);
					for(int j=0;j<4;j++){
						
						if(ruch[ruch[top][i]][j]==(-1)) ruch[ruch[top][i]][j] = ruch[suf[ruch[top][i]]][j];
						else suf[ruch[ruch[top][i]][j]] = ruch[suf[ruch[top][i]]][j];
					
				}
			p:;
			}
		}
		
	}

	
}

int mecz(string a, int k, int s){
	for(int i=0;i<k;i++){
		visited[i]=0;
	}
	for(int i=0;i<a.length();i++){
		char znak=a[i];
		int zn= 0;
		if(znak=='A') zn=0;
		else if(znak=='C') zn=1;
		else if(znak=='G') zn=2;
		else zn=3;
		
		s = ruch[s][zn];
		visited[s] = 1;
	}
	
	while(S.empty()==false){
		if(visited[S.top()]==1){
			if(suf[S.top()]!=0) visited[suf[S.top()]] = 1;
		}
		S.pop();
	}

	for(int i=0;i<k;i++){
		if(visited[i]==1){
			for(int j=0;j<tab[i].size();j++){
				if(tab[i][j]>-1) wynik[tab[i][j]] = 1;
			}
		}
	}
}

int main(){
	int z; cin >> z;
	while(z--){
		
		for(int i=0;i<S.size();i++){
			S.pop();
		}
		
		
		il=1;
		string a; cin >> a;
		int b; cin >> b;
		
		ruch[0][0]=(-1);
		ruch[0][1]=(-1);
		ruch[0][2]=(-1);
		ruch[0][3]=(-1);
		
		for(int i=0;i<1000000;i++){
			tab[i].clear();
			wynik[i]=0;
		}
		
		for(int i=0;i<b;i++){
			string c; cin >> c;
			dodaj(c,i);
		}
		
		bfs(0,il);
		mecz(a,il,0);
		
		for(int i=0;i<b;i++){
			if(wynik[i]==1) cout << "TAK" << endl;
			else cout << "NIE" << endl;
		}
		
	}
}
