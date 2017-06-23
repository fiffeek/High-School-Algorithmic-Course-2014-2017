#include <iostream>
#include <vector>

using namespace std;

vector <int> G[1000005];
char col[1000005];
pair <int , int> H;
int i;

void dfs(int a){

      col[a]='G';

      if(i>=H.first){
            H.first=i;
            H.second=a;
      }

      i++;

      int liczba=G[a].size();
      for(int ii=0;ii<liczba;ii++){
              if(col[G[a][ii]]=='W') dfs(G[a][ii]);
      }

      col[a]='B';
      i--;
}

int main(){

      int a;
      cin >> a;
      while(a--){
              int b;
              cin >> b;

              H.first=0;
              H.second=1;

              for(int y=0;y<=b;y++){
                      col[y]='W';
                      G[y].clear();

              }


              for(int r=1;r<b;r++){
                      int c,t;
                        cin >> c >> t;
                        G[c].push_back(t);
                        G[t].push_back(c);

              }

              i=0;
              //dfs
              dfs(1);
              H.first=0;
              for(int y=0;y<=b;y++) col[y]='W';
              dfs(H.second);

              cout << H.first << endl;

      }
}
