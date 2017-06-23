#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

//FilipMikina
//FirstYear
//DecimalToBalancedTernary
//BalancedTernaryToDecimal

int funkcja1(string b,int n){

                      long long s=0;
                      for(int f=0;f<n;f++)
                      {
                              if(b[f]=='-') s=s-(pow(3,(n-1-f)));
                              if(b[f]=='+') s=s+(pow(3,(n-1-f)));
                              if(b[f]=='0') s=s+0;
                      }
                      return s;


}
        
string funkcja2(string b){
              string str = b;
              int y;
              istringstream iss(str);
              iss >> y;
              int c=b.length();
              int x=y,i=c;
              string q,n;
              if(x<0) x=x*(-1);

              while(x>0)
              {
                      if(x%3==0) q='0' + q;
                      if(x%3==1) q='1' + q;
                      if(x%3==2) q='2' + q;
                  x=(x/3);
                      i--;
              }


              c=q.length();
              i=c-1;
              string z;
              z=q;

              while(i>0)
               {
                      if(q[i]=='2' || z[i]=='2')
                      {
                              if(z[i-1]=='0') z[i-1]='1';
                              else
                              {
                                      if(z[i-1]=='1') z[i-1]='2';
                                      else if(z[i-1]=='2') z[i-1]='3';
                              }
                      }
                      i--;
               }
               q=z;
               int d=(q.length())-1;

               while(d!=-1)
               {
                      if(z[d]=='1') z[d]='+';
                      if(z[d]=='2') z[d]='-';
                      if(z[d]=='3') z[d]='0';
                  d--;
               }
              if(q[0]=='2')
               z= "+" + z;
			    if(q[0]=='3')
			    z= "+" + z;
				if(y>0) return z;
				else
				{
				      int e=z.length();
				      string o;
				      o=z;
				      for(int i=0;i<e;i++)
				      {
				              if(z[i]=='-') o[i]='+';
				              if(z[i]=='+') o[i]='-';
				      }
				      return o;
				}
}


int main()
{
      int licznik;
      cin >> licznik;
      for(int ll=0;ll<licznik;ll++)
      {

              string a;
              cin >> a;
              int i=0,f;
              char b;
              int c=a.length();
              f=0;

              if (a[0]=='+') cout << funkcja1(a,c);
              if (a[0]=='0') cout << funkcja1(a,c);
              if(a.length()==1)
              {
                      if(a[0]=='-') cout << funkcja1(a,c);
              }
              if(a[0]=='-')
              {
                      if(a[1]=='-') cout << funkcja1(a,c);
                      if(a[1]=='0') cout << funkcja1(a,c);
                      if(a[1]=='+') cout << funkcja1(a,c);
                      cout << funkcja2(a) << endl;

              i++;
              }
              else cout << funkcja2(a) << endl;
      }
}
