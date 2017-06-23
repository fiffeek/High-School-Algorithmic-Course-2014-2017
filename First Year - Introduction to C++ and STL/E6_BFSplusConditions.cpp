#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

unsigned long long koszt[50005];

struct ps{
      int waga,wierzcholek,okres,a,l;
};

struct qs{
      int p,c;
};

struct cs{
      bool operator()(qs a,qs b){
              return a.p>b.p;
      }
};

vector < ps > G[50005];

int main(){
      ios_base::sync_with_stdio(0);
      int z;
      cin >> z;
      while(z--){
              int a,b;
              cin >> a >> b;


              for(int j=0;j<=a;j++){
                      koszt[j] = 1844674407370955161;
                      G[j].clear();
              }

              koszt[1] = 0;
                        qs uno;
              for(int j=0;j<b;j++){
                      ps P;
                      int temp;
                      //if(temp == 1) uno = P;
                      cin >> temp >> P.wierzcholek >> P.waga >> P.okres >> P.a >> P.l;
                      if(P.l + P.a > P.okres) P.l = P.l + P.a - P.okres;
                      else P.l = P.l + P.a;
                      
                      G[temp].push_back(P);
              }


              priority_queue <qs, vector<qs>, cs > Q;

                        uno.c = 1;
                        uno.p = koszt[1];

              Q.push(uno);

              while(Q.empty()==false){
                      int w = Q.top().c;
                      Q.pop();
                      //cout << "PRR" << endl;
                      //cout << w << endl;

                      for(int j=0;j<G[w].size();j++){


                                                                        unsigned long long zmienna1 = koszt[w];
                                                                        
                                                                                if(G[w][j].a ==0 && G[w][j].okres ==0 && G[w][j].l ==0) zmienna1=koszt[w];
                                                                                else if(G[w][j].l > G[w][j].a){
                                                                                	if(koszt[w]%G[w][j].okres < (G[w][j].a)) zmienna1 = koszt[w] + (G[w][j].a - koszt[w]%G[w][j].okres);
																					else if(koszt[w]%G[w][j].okres > (G[w][j].l)) zmienna1 = koszt[w] +  (G[w][j].okres - (koszt[w]%G[w][j].okres)) + G[w][j].a;
																					else if(koszt[w]%(G[w][j].okres) == G[w][j].a) zmienna1 = koszt[w];
																					else if(koszt[w]%G[w][j].okres == (G[w][j].l)) zmienna1 = koszt[w] +  (G[w][j].okres - (G[w][j].l)) + G[w][j].a;
																					else zmienna1 = koszt[w];
																				}
																				else if(G[w][j].l < G[w][j].a){
																					if(koszt[w]%G[w][j].okres >= (G[w][j].l) && koszt[w]%G[w][j].okres < G[w][j].a) zmienna1 = koszt[w] + (G[w][j].a - koszt[w]%G[w][j].okres);
																					else zmienna1 = koszt[w];
																				}
                                                                        

                                      if(koszt[G[w][j].wierzcholek] > zmienna1 + G[w][j].waga){
                                              koszt[G[w][j].wierzcholek] = zmienna1 + G[w][j].waga;
                                             // cout << "koszt[G[w][j].wierzcholek] " << koszt[G[w][j].wierzcholek] << endl;
                                              qs para;
                                              para.p = koszt[G[w][j].wierzcholek];
                                              para.c = G[w][j].wierzcholek;
                                              Q.push(para);

                                      }

                      }

              }

              if(koszt[a]==1844674407370955161) cout << "NIE" << endl;
                        else cout << koszt[a] << endl;

      }

}
