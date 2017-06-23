#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[500005];
bool czyswap[500005];
vector<pair<int,bool> > G[500005];

int main(){
      int ilosc;
      cin >> ilosc;
      while(ilosc--){
            bool noprzeciez;

              int E, V;
              cin >> V >> E;
              for(int i=0;i<500005;i++){
                      visited[i]=0;
                      czyswap[i]=0;
                      G[i].clear();
              }
                bool tu=0;
              for(int i=0;i<E;i++){
                      int a,b;
                      char c;
                      bool aa;
                      cin >> a >> b >> c;

                      if(c=='+') aa=1;
                      else aa=0;

                      if((a==1 || b==1) && tu==0){
                            noprzeciez=aa;
                            tu=1;
                      }
                      G[a].push_back(make_pair(b,aa));
                      G[b].push_back(make_pair(a,aa));
              }

                queue<pair<int,bool> > k;
                priority_queue<int,vector<int>,greater<int> > wynik;
                pair<int,bool> start;

                start.first=1;
                start.second=noprzeciez;

              int lecimy=0;
              bool problem=0;
              bool czy=0;
              k.push(start);
              visited[start.first]=true;

              while(k.size()>0){
                      pair<int,bool> przejsciowa;
                      przejsciowa.first=k.front().first;
                      //przejsciowa.second=k.front().second;
                      //cout << "Tu przejsciowa : " << przejsciowa.first << " " << przejsciowa.second << " " << czyswap[przejsciowa.first] << endl;

                      k.pop();

                      for(int i=0;i<G[przejsciowa.first].size();i++){
                              pair<int,bool> a;
                              a.first=G[przejsciowa.first][i].first;
                              a.second=G[przejsciowa.first][i].second;

                              //cout << "Tu a : " << a.first << " " << a.second << " " << czyswap[a.first] << endl;

                              if(visited[a.first]==false){
                                //cout << "przejsfirst => " << przejsciowa.first << " czyswap => " << czyswap[przejsciowa.first] << " przejsec => " << przejsciowa.second << endl;
                                      if((czyswap[przejsciowa.first]==1 && a.second==1) || (czyswap[przejsciowa.first]==0 && a.second==0)){
                                        //cout << "czyswap ?" << endl;
                                            czyswap[a.first]=1;
                                            wynik.push(a.first);
                                            lecimy++;
                                     }

                                      k.push(a);
                                      visited[a.first]=true;

                              }
                              else{
                                          if(a.second==1){
                                              if(czyswap[przejsciowa.first]!=czyswap[a.first]){
                                              	problem=1;
                                                goto koniec;
                                              }
                                          } else {
                                              if(czyswap[przejsciowa.first]==czyswap[a.first]){
                                                 problem=1;
												 goto koniec;
                                                }
                                          }

                              }
                                //cout << "Tu a, koniec for : " << a.first << " " << a.second << " " << czyswap[a.first] << endl;
                      }
              }

              koniec:
		   if(problem==1){
		   	   cout << "NIE" << endl;
		   }else {
	           while(wynik.empty()==false){
	           	if(wynik.top()!=1) cout << wynik.top() << " ";
	             wynik.pop();
	           }
	           cout << endl;
	       }
      }
}
