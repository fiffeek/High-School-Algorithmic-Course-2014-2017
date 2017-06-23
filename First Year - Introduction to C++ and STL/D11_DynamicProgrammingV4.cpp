#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l,k;
int a;
int v[1000002];
int G[1000002];
long long tab[1000002];





int main(){
        ios_base::sync_with_stdio(0);
      int z;
      cin >> z;
      while(z--){
              a=0;
              cin >> a;
              l=0;
              k=0;

              for(int i=0;i<a+1;i++){
                       tab[i]=0;
                       v[i]=0;
                       G[i]=0;
              }

              for (int i=0;i<a;i++){
                      long long temp1, temp2;
                      cin >> temp1 >> temp2;
                      v[i]=temp1;
                      G[i]=temp2;

              }
                        int x = 0;
                       bool czy=0;
                       int druga;

              // dlugosc - l , k - kwota latki kurdy
              cin >> l >> k;
long long y=0;

                      for(int i=0;i<a;i++){
                               if(i==0) tab[i] = min(k,G[i]);
                               else{
                                              while(v[x] + l < v[i]) ++x;
                                              x--;
                                              
                                              if(x<0) y=0;
                                              else y=tab[x];


                                              tab[i] = min( G[i] + tab[i-1], k + y);
                                              czy=0;
                                      }
                      }

                      cout << tab[a-1] << endl;

      }

}
