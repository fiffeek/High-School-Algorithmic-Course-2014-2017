#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int P[10005];

struct qs{
      int w1,w2,waga;
};

struct cs{
      bool operator()(qs a,qs b){
              return a.waga>b.waga;
      }
};

int Find(int a){
      if(P[a]==a) return a;
      P[a] = Find(P[a]);
      return P[a];
}

void Union(int a, int b){
      int A = Find(a);
      int B = Find(b);
      P[A] = B;
}

int main(){
      int z;
      cin >> z;
      while(z--){
              int n,m;
              cin >> n >> m;
              
              priority_queue <qs, vector<qs>, cs > Q;

              for(int i=1;i<=n;i++){
                      P[i] = i;
              }

              for(int i=0;i<m;i++){
                      int p1,p2,k;
                      cin >> p1 >> p2 >> k;

                   	  qs A;
                   	  A.w1 = p1;
                   	  A.w2 = p2;
                   	  A.waga = k;
                   	  Q.push(A);
              }

              unsigned long long wynik = 0;

              while(!Q.empty()){
                      qs A = Q.top();
                      Q.pop();
                      if(Find(A.w1)==Find(A.w2)){
                              goto pocz;
                      }
                      wynik+=A.waga;
                      Union(A.w1,A.w2);
                      pocz:;
              }

              cout << wynik << endl;
      }

}
