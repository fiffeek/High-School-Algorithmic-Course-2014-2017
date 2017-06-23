#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct ps{
    int a,b;
};

vector <int> G[1000005];
vector <int> T[1000005];
vector <int> SP[1000005];
bool visited[1000005];
int spojne[1000005];
int odp[10000005];
vector <int> V;
int tab[1000005];
stack <int> S;
vector <int> op;

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

              int a , b;

              cin >> a >> b;

              V.clear();

              for(int i=0;i<b;i++){
                      int temp,temp2;
                      cin >> temp >> temp2;

                      G[temp].push_back(temp2);
                      T[temp2].push_back(temp);
              }

              for(int j=1;j<=a;j++) if(visited[j]==0) dfs(j);

              for(int j=0;j<=a;j++) visited[j] = 0;

                int liczba = 0;
                int ha = 0;
              while(S.empty()==false){
                      int a = S.top();
                      S.pop();
                      if(visited[a]==true) goto k;
                      dfs2(a);
                        //cout <<  "SCC: ";
                      for(int u=0;u<V.size();u++){
                              //cout << V[u] << " ";
                              spojne[V[u]] = liczba;
                              SP[liczba].push_back(V[u]);
                      }

                      //cout << endl;
                      V.clear();
                      liczba++;
                      k:;
              }

              for(int j=0;j<=100;j++) odp[j] = 0;

              for(int j=liczba;j>=0;j--){
                for(int y=0;y<SP[j].size();y++){
                    int l = SP[j][y];
                   // if(G[l].size()==0) odp[spojne[l]] = 0;
                    for(int u=0;u<G[l].size();u++){
                        if(spojne[G[l][u]]!=spojne[l]){
                            odp[spojne[l]] = max(odp[spojne[G[l][u]]] + 1,odp[spojne[l]]);
                           /* cout << "spojjne l " << spojne[l] << endl;
                            cout << "ODPDPD" << odp[spojne[l]] << endl;
                            cout << spojne[G[l][u]] << "to psojna " << endl;
                            cout << l << " "<< odp[G[l][u]] + 1<<endl;*/
                        }
                    }
                }

              }
                int maax=0;
              for(int j=0;j<liczba;j++){
                    //cout<< "WYNIK DLA SCC: " << odp[j] << endl;
                    if(odp[j]>maax){
                        maax = odp[j];
                        op.clear();

                        for(int p=0;p<SP[j].size();p++){
                            op.push_back(SP[j][p]);
                        }

                    }else if(odp[j]==maax){

                        for(int p=0;p<SP[j].size();p++){
                            op.push_back(SP[j][p]);
                        }

                    }
              }

              cout << maax << endl;
              cout << op.size() << endl;
              //int o = op.size();
              sort(op.begin(), op.end());
              for(int j=0;j<op.size();j++){
                cout << op[j] << " ";
              }
                cout << endl;

}
