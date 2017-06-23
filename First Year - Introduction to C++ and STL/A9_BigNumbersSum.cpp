#include <iostream>
using namespace std;

//FilipMikina
//FirstYear
//BigNumbersSum

int main(){

      int r;
      cin >>r;
      for(int i=0;i<r;i++)
      {
	  {

              int c[100000],d[100000],e[100005];
      string a,b;
      cin >> a;
      cin >> b;

  for(int i=0;i<100001;i++) c[i]=0;
  for(int i=0;i<100001;i++) d[i]=0;

      //reverse(a);
      int t=0,y=0;
      t=a.length();
      t=t-1;
       y=t;

      for(int i=0;i<y+50;i++)
      {
              int rr=a[t];
              rr=rr-48;
              if(i>y) rr=0;
              c[i]=rr;
              t--;
      }

      //reverse(b);

      t=b.length();
      t=t-1;
      y=t;

      for(int i=0;i<y+50;i++)
      {
              int rr=b[t];
              rr=rr-48;
              if(i>y) rr=0;
              d[i]=rr;
              t--;

      }

	int l=a.length();
	int ll=b.length();
	int pp=0;
	if(l>=ll) pp=l;
	else pp=ll;

	//dodawaaanie
	int ol=0;
	int op=0;
	for(int i=0;i<pp;i++)
	{
	      if(c[i]+d[i]>9)
	      {
	              if(l>=ll) c[i+1]=c[i+1]+1;
	              else d[i+1]= d[i+1]+1;
	              if(i==pp-1) ol=1;
	
	      }
	      e[i]=(c[i]+d[i])%10;
	      op++;
	}
	if(ol>0) cout << "1";
	for(int i=op-1;i>-1;i--)
	{
	cout << e[i];
	}
	cout << endl;
	ol =0 ;
	}
	}
}
