#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct ps{
    int a,b;
};

vector <int> G[250005];
vector <int> T[250005];
bool visited[250005];
int spojne[250005];

vector <int> V;
stack <int> S;

int dane[250005][2];


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
      //cout << T[a].size()  << "BAK"<< endl;
      for(int j=0;j<T[a].size();j++){
              if(visited[T[a][j]]==0) dfs2(T[a][j]);
      }
}


int main(){
			  int z;
			  cin >> z;
			  while(z--){
	              int n , m;
	
	              cin >> n >> m;
	
	              V.clear();
	              while(S.size()>0) S.pop();
	              
	              int c= 1,d = 2;
	              
	              for(int i=1;i<=n;i++){ 
				  	dane[i][0] = c;
					dane[i][1] = d;
					c+=2;d+=2;	
				  }
					//cout << c << " " << d << endl;
					
				  for(int j=0;j<=d;j++){
				  	 visited[j] = 0;
				  	 T[j].clear();
				  	 G[j].clear();
				  }
				  
	              for(int i=0;i<m;i++){
	                      int temp,temp3; char temp2,temp4;
	                      cin >> temp2 >> temp >> temp4 >> temp3;
						  int wart1,wart2;
						  
						  if(temp2 == '-') wart1 = 0;
						  else wart1 = 1;
						  
						  if(temp4 == '-') wart2 = 0;
						  else wart2 = 1;
						  
						  
						  
						  T[dane[temp][wart1]].push_back(dane[temp3][(wart2+1)%2]);
	                      T[dane[temp3][wart2]].push_back(dane[temp][(wart1+1)%2]);
	                      
	                      G[dane[temp3][(wart2+1)%2]].push_back(dane[temp][wart1]);
	                      G[dane[temp][(wart1+1)%2] ].push_back(dane[temp3][wart2]);
						
	                     
	                      
	                     /* cout << "POLACZYLEM : " << endl;
	                    cout << temp2 << temp << temp4 << temp3  << "PALUCH "<< endl;
							cout << "WARTOISCI" << wart1 << " " << wart2 << endl;
	                      cout << dane[temp3][(wart2+1)%2] << " z " << dane[temp][wart1] << endl;
	                    cout <<  dane[temp][(wart1+1)%2] << " z " <<dane[temp3][wart2]  << endl;*/

	                      //cout << dane[temp3][(wart2+1)%2] << " z " << dane[temp][wart1] << endl;
	                      
	                      
	                      
	
	              }
	
	              for(int j=1;j<=(d-2);j++) if(visited[j]==0) dfs(j);
	
	              for(int j=0;j<=d;j++) visited[j] = 0;
	
	                int liczba = 0;
	              while(S.empty()==false){
	                      int a = S.top();
	                      //cout << a << "WIERZCHOLA"<< endl;
	                      S.pop();
	                      if(visited[a]==true) goto k;
	                      dfs2(a);
	                     // cout << V.size()  << "WEKTORA"<< endl;
	                      for(int u=0;u<V.size();u++){
	               
	                              spojne[V[u]] = liczba;
	                              //SP[liczba].push_back(V[u]);
	                      }
	
	                      V.clear();
	                      liczba++;
	                      k:;
	              }
	
	            for(int j=1;j<=n;j++){ 
	            	/*cout << dane[j][0] << " wierzcholki " << dane[j][1] << endl;
	            	cout << spojne[dane[j][0]] << " spojne " << spojne[dane[j][1]] << endl; */
	            	if(spojne[dane[j][0]]==spojne[dane[j][1]]){
	            		 cout << "NIE" << endl;
	            		 goto koniec;
					}
				}
				cout << "TAK" << endl;
				 for(int j=1;j<=n;j++){
				 	//cout << spojne[dane[j][0]] << " " << spojne[dane[j][1]] << endl;
	            	if(spojne[dane[j][0]]>spojne[dane[j][1]]){
	            		cout << "0" <<" ";
					}else{
						cout << "1" <<" ";
					} 
				}
				cout << endl;
				koniec:;
       
		}
}
