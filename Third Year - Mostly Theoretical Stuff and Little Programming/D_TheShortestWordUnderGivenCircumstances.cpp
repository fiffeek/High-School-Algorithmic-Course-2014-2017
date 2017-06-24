#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int ruch[1000000][2];
int il=1;

vector <int> tab;
bool wynik[1000000];
bool visited[1000000];
int suf[1000000];
int pietro[1000000];


int graf(int liczba, int zn){
      if(ruch[liczba][zn] != (-1)) return ruch[liczba][zn];
      ruch[liczba][zn]= il;

      ruch[il][0]=(-1);
      ruch[il][1]=(-1);

      il++;

      return ruch[liczba][zn];


}

void dodaj(int numer,int b){
      //cout << "Wczytanie linii" << endl;
      int a=0;
      for(int i=0;i<b;i++){
              char x;
              cin >> x;
              int x2=0;
              if(x=='1') x2=1;
              a = graf(a,x2);

      }

      tab.push_back(il-1);
      //cout << il << endl;

}

void bfs(int s, int koniec){

      suf[s] = 0;
      for(int i=0;i<2;i++){
              if(ruch[s][i]!=(-1)) suf[ruch[s][i]]=s;
              else ruch[s][i]=0;
      }



      for(int i=0;i<koniec;i++){
              visited[i] = 0;
      }

      queue <int> Q;
      visited[s]=1;
      Q.push(s);
      pietro[s]=0;

      while(Q.empty()==false){

              int top = Q.front();
              //S.push(top);
              Q.pop();

              for(int i=0;i<2;i++){
                      if(ruch[top][i]==(-1)) goto p;
                      if(visited[ruch[top][i]]==false){
                              pietro[ruch[top][i]]=pietro[top]+1;
                              visited[ruch[top][i]]=true;
                              Q.push(ruch[top][i]);
                                      for(int j=0;j<2;j++){

                                              if(ruch[ruch[top][i]][j]==(-1)) ruch[ruch[top][i]][j] = ruch[suf[ruch[top][i]]][j];
                                              else suf[ruch[ruch[top][i]][j]] = ruch[suf[ruch[top][i]]][j];

                              }
                      p:;
                      }
              }

      }

      /*    cout << "SPR TABL RUCHOW" << endl;
      for(int i=0;i<koniec;i++){
              for(int j=0;j<4;j++){
                      cout << ruch[i][j] << " ";
              }
              cout << endl;
      }

      cout << "SPR TAB PREFSUF" << endl;
      for(int i=0;i<koniec;i++){
              cout << suf[i] << endl;
      }*/

      //cout << pietro[11] << endl;
}

int mecz(){
      int odp=0;
      for(int i=0;i<tab.size();i++){
              odp=max(odp,pietro[suf[tab[i]]]);
      }
      return odp;
}

int main(){
      int z; cin >> z;
      while(z--){

      /*      for(int i=0;i<S.size();i++){
                      S.pop();
              }*/


              il=1;
              tab.clear();
              //string a; cin >> a;
              int a,b; cin  >> a >> b;

              ruch[0][0]=(-1);
              ruch[0][1]=(-1);

      /*      for(int i=0;i<1000000;i++){
                      tab[i].clear();
                      //wynik[i]=0;
              }*/

              for(int i=0;i<a;i++){
                      dodaj(i,b);
              }

              bfs(0,il);
              int w = mecz();
              //cout << 2*b - mecz() << endl;
              int f = 2*b - w;
              cout << f << endl;


      }
}
