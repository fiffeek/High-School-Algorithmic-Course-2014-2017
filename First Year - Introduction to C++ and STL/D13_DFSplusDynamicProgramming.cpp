#include <iostream>
#include <vector>

using namespace std;

vector <int> G[200005];
int w[200005];
long long d[200005], e[200005];
char col[200005];

void dfs(int a){
	
	  col[a]='G';
	
	
	  e[a]=w[a];
	  d[a]=0;
      
      int liczba=G[a].size();
      for(int ii=0;ii<liczba;ii++) {
      	
	  	if('W'==col[G[a][ii]]){
	  		
      		dfs(G[a][ii]);
      		
      		e[a]+=min(e[G[a][ii]],d[G[a][ii]]);
      		d[a]+=e[G[a][ii]];
      		
	  	}
	  	
	  }
	  
	  col[a]='B';    
}

int main(){

      int a;
      cin >> a;
      while(a--){
              int b;
              cin >> b;

              for(int y=0;y<b+5;y++){
                      G[y].clear();
                      w[y]=0;
                      d[y]=0;
                      e[y]=0;
                      col[y]='W';
              }
              
              w[0]=10000000;
              for(int i=1;i<=b;i++){
              	int temp;
              	cin >> temp;
              	w[i]=temp;
			  }
              


              for(int r=1;r<b;r++){
              	int liczba=0,liczba1=0;
              	cin >> liczba >> liczba1;
           			 G[liczba].push_back(liczba1);
           			 G[liczba1].push_back(liczba);
              }
              
             dfs(1);
			 
			 cout << min(e[1],d[1]) << endl;
      }
}
