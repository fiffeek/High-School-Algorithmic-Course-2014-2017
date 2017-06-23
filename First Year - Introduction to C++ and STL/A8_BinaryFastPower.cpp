#include <iostream>
using namespace std;

unsigned long long c;

//FilipMikina
//FirstYear
//BinaryFastPower

int potegowaniebinarne(unsigned long long a,unsigned long long k)
{
              if(k==0) return 1%c;
              if(k%2==1 && k>0) return (a*(potegowaniebinarne(a,k-1)))%c;
       		  if(k%2==0 && k>0){
	              unsigned long long t = ((potegowaniebinarne(a,k/2)))%c;
	              return (t*t)%c;
              }
}

int main()
{
      int r;
      cin >> r;
      for(int i=0;i<r;i++){
	      unsigned long long a,k;
	      cin >> a;
	      cin >> k;
	      cin >> c;
	      cout << (potegowaniebinarne(a,k))%c << endl;
      }

}
