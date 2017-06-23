#include <iostream>
#include <algorithm>

using namespace std;

int orki[100005];
int elfy[100005];

long long odp=0;

long long f(int s1,int k1,int s2,int k2,int a){
      if(s1>k1 || s2>k2) return 0;
      while(s1<a && s2<a && orki[s1]>elfy[s2]){
              s1++;
              s2++;
              odp++;
              if(s1>k1 || s2>k2) return 0;
      }
      while(k1>=0 && k2>=0 && orki[k1]>elfy[k2]){
              k1--;
              k2--;
              odp++;
              if(s1>k1 || s2>k2) return 0;
      }
      if(orki[k1]>elfy[s2]) odp++;
      else if(orki[k1]<elfy[s2]) odp--;
      k1--;
      s2++;
      f(s1,k1,s2,k2,a);
}


int main(){
      int z;
      cin >> z;
      while(z--){
              int a;
              cin >> a;
              odp = 0;

              for(int i=0;i<a;i++){
                      cin >> orki[i];
              }

              for(int i=0;i<a;i++){
                      cin >> elfy[i];
              }

              sort(orki,orki+a,greater<int>());
              sort(elfy,elfy+a,greater<int>());
              f(0,a-1,0,a-1,a);
              odp*=200;
              cout << odp << endl;
      }
}
