#include <iostream>
#include <cmath>

using namespace std;

//FilipMikina
//FirstYear
//PrimeFactorisation

int fn(unsigned long long a,int g,int y)
{
      y=0;
      unsigned long long b=a;
      if(a>1)
      {

              for(int i=2;i*i<=b+1;i++)
              {
                      g=0;
                      if(a==1) return 0;
                      while(a%i==0)
                      {
                              a=a/i;
                              g++;

                      }
                      if(g>0) y++;
                      if(y==1)
                      {
                      if(g>1)
                      cout << i << "^" << g;
                      if(g==1)
                      cout << i;
                              y++;

                      }
                      else
                      {

                      if(g>1)
                      cout << "*" << i << "^" << g;
                      if(g==1)
                      cout <<  "*" << i;
                      }


         }
	if(y==0) cout << a;
	if(a>1 && y>0) cout << "*" << a;

 	}

}


int main()
{
      int t;
      cin >> t;
      for(int i=0;i<t;i++)
      {
              int y=0;
      unsigned long long a;
      cin >> a;
      int g=0;
      cout << a << " = ";
      fn(a,g,y);
      cout << endl;
      }
}
