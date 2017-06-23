#include <iostream>
#include <map>

using namespace std;

int G1[1000003];
int G2[1000003];

int Find(int a){
      if(G1[a]==a) return a;
      G1[a] = Find(G1[a]);
      return G1[a];
}

void Union(int a, int b){
      int A = Find(a);
      int B = Find(b);
      G1[A] = B;
}

int Find2(int a){
      if(G2[a]==a) return a;
      G2[a] = Find2(G2[a]);
      return G2[a];
}

void Union2(int a, int b){
//    cout << a << "  i " << b << endl;
      int A = Find2(a);
      int B = Find2(b);
     // cout << A << "  j " << B << endl;
      G2[A] = B;
}

int main(){
      int a;
/*    cin >> a;
      for(int i=0;i<a;i++){*/
      int m, n;
      cin >> n >> m;

      map < pair<int , int> , int > mapa;
      map < pair<int , int> , int > mapa2;
      mapa.clear();
      mapa2.clear();
      for(int i=0;i<m+2;i++){
              G1[i] = i;
              G2[i] = i;
        }
      G1[0] = 0;
      G1[1] = 1;
        G2[0] = 0;
      G2[1] = 1;

        int czykon = 0;
        int odp = 0;
        int klocek = 2;

      for(int i=0;i<m;i++){
              if(i%2==0 && i!=0) klocek++;
              if(i%2==0){
                      //cout << "G1" << endl;
                       odp++;
             pair <int , int > t;
             cin >> t.first >> t.second;

                        if(czykon==0){
                    mapa[t] = klocek;

                                G1[klocek] = klocek;
                    if(t.second==1) Union(klocek,0);
                    if(t.second==n) Union(klocek,1);


                    int x = t.first;
                    int y = t.second;
                    pair<int , int> O;

                    O.first=x;
                    O.second=y-1;
                    if(mapa.count(O)==1 && y>=1) Union(klocek,mapa[O]);
                    O.first=x;
                    O.second=y+1;
                    if(mapa.count(O)==1 && y<=n) Union(klocek,mapa[O]);
                    O.first=x+1;
                    O.second=y;
                    if(mapa.count(O)==1 && x<=n) Union(klocek,mapa[O]);
                    O.first=x-1;
                    O.second=y;
                    if(mapa.count(O)==1 && x>=1) Union(klocek,mapa[O]);
                    O.first=x+1;
                    O.second=y-1;
                    if(mapa.count(O)==1 && x<=n && y>=1) Union(klocek,mapa[O]);
                    O.first=x-1;
                    O.second=y+1;
                    if(mapa.count(O)==1 && x>=1 && y<=n) Union(klocek,mapa[O]);
              }

              if (G1[Find(0)] == G1[Find(1)] && czykon==0){
                      czykon = odp;
                     // cout << "wyjazd" << endl;
              }
          }else{
                                       pair <int , int > t;
                    cin >> t.first >> t.second;
                    odp++;

                    if(czykon==0){

                            mapa2[t] = klocek;
                            G2[klocek] = klocek;
                        if(t.first==1) Union2(klocek,0);
                        if(t.first==n) Union2(klocek,1);

                            int x = t.first;
                            int y = t.second;

                                        pair<int , int> O;
                            O.first=x;
                            O.second=y-1;
                            if(mapa2.count(O)==1 && y>=1) Union2(klocek,mapa2[O]);
                            O.first=x;
                            O.second=y+1;
                            if(mapa2.count(O)==1 && y<=n) Union2(klocek,mapa2[O]);
                            O.first=x+1;
                            O.second=y;
                            if(mapa2.count(O)==1 && x<=n) Union2(klocek,mapa2[O]);
                            O.first=x-1;
                            O.second=y;
                            if(mapa2.count(O)==1 && x>=1) Union2(klocek,mapa2[O]);
                            O.first=x+1;
                            O.second=y-1;
                            if(mapa2.count(O)==1 && x<=n && y>=1) Union2(klocek,mapa2[O]);
                            O.first=x-1;
                            O.second=y+1;
                            if(mapa2.count(O)==1 && x>=1 && y<=n) Union2(klocek,mapa2[O]);

               }

                    if (G2[Find2(0)] == G2[Find2(1)] && czykon==0){
                      //cout << G2[0] << " a " << G2[1] << endl;
                      czykon = odp;
                     // cout << "jazd" << endl;
                  }

                 // cout << "RUCH 2 TABLICA" << endl;
                 // for(int p=0;p<m+2;p++) cout << G2[p] << " ";
                 // cout << endl;

                      }

      }
      if(czykon==0) cout << "NIE" << endl;
      else cout << czykon << endl;
  //}


}
