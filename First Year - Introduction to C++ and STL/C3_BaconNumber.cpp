#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
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
              for(int i=0;i<V+E+1;i++){
                      distanc[i]=0;
                      visited[i]=0;
                      G[i].clear();
              }

              //n=v
              //m=e
      //              cout << "da" << endl;
              for(int i=1;i<E+1;i++){
                      int a;
                      cin >> a;
                      for(int ii=0;ii<a;ii++){
                            int b;
                            cin >> b;
                            G[i+V].push_back(b);
                            G[b].push_back(i+V);
                      }
              }

              int start=1;
                        queue<int> k;
              k.push(start);
              visited[start]=true;

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
              }


                      for(int i=1;i<V+1;i++){
                                        if(distanc[i]==0 && i!=1) cout << "-1 ";
                              else cout << distanc[i]/2 << " ";
                      }

cout << endl;
      }
}
