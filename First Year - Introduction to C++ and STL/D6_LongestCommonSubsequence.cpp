#include <iostream>
#include <stack>
using namespace std;
string A,T;
int wyn[3005][3005];


int NWP(int i, int j){
      if(i<0 || j<0) return 0;
      if(wyn[i][j]>=0) return wyn[i][j];
      if(A[i]!=T[j]){
              wyn[i][j] = max(NWP(i-1,j),NWP(i,j-1));
      } else {
              wyn[i][j] = 1 + NWP(i-1,j-1);
      }

      return wyn[i][j];

}


int main(){
      int z;
      cin >> z;
      while (z--){

//cout << "Da" << endl;
              cin >> A >> T;
              int i=A.length()-1;
              int j=T.length()-1;

              for(int a=0;a<A.length();a++){
                      for( int b=0;b<T.length();b++){
                              wyn[a][b]=-2;
                      }
              }
//cout << "rek" << endl;
              int liczba=NWP(i,j);
              cout << liczba << endl;

              stack<char> S;
//cout << "dupa" << endl;
           /* for(int a=0;a<=i;a++){
                      for(int b=0;b<=j;b++){
                              cout << wyn[a][b] << " ";
                      }
                      cout << endl;
              }*/
              //cout << "tu dane: " << endl;
              //cout << i << " " << j << endl;
//    if(wyn[i-1][j] < wyn[i][j] && wyn[i][j-1] < wyn[i][j] && wyn[i-1][j-1]<wyn[i][j]) S.push(T[j]);

              while(i>=0 && j>=0){
                      if(wyn[i][j-1] == wyn[i][j]){
                              j--;
                      }else if(wyn[i-1][j] == wyn[i][j]){
                              i--;
                      }
                      else{
                              S.push(A[i]);
                              i--;
                              j--;
                      }
              }

            while(!S.empty()){
                    cout << S.top();
                    S.pop();
            }
      cout << endl;
      }
}
