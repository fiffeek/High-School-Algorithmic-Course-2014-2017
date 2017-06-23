#include <iostream>
#include <vector>

using namespace std;

vector <int> G[1000005];
char col[1000005];
char wyj[1000005];
int i;

void dfs(int a){
//cout << "wbij" << endl;

      col[a]='G';
      char czy='P';

      int liczba=G[a].size();
      for(int ii=0;ii<liczba;ii++){
              if(col[G[a][ii]]=='W'){
                dfs(G[a][ii]);
              }
              if(wyj[G[a][ii]] == 'P' && czy!='W') czy = 'W';
      }

      col[a]='B';
        //cout << "to why " << why << endl;
      if(czy=='W') wyj[a]=czy;
      else wyj[a]='P';

      //cout << a << endl;
      //cout << wyj[a] << endl;
}

int main(){

      int a;
      cin >> a;
      while(a--){
              int b;
              cin >> b;

              for(int y=0;y<=b;y++){
                      col[y]='W';
                      G[y].clear();

              }


              for(int r=1;r<=b;r++){
                      int c,t;
                        cin >> c;

                        for(int i=0;i<c;i++){
                            cin >> t;
                            t++;
                            G[r].push_back(t);
                        }
              }

              i=0;
              //dfs
              dfs(1);

              for(int i=1;i<=b;i++){
                    if(col[i]=='W') dfs(i);
              }

              for(int i=1;i<=b;i++){
                    cout << wyj[i];
              }
              cout << endl;

      }
}
