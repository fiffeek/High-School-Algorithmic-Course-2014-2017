#include <iostream>
#include <algorithm>

using namespace std;

struct pole{
      long long a,b,wiersz;
};

struct pole2{
	long long a,b;
};

bool sort1 (pole c,pole d) {
      if(c.a==d.a) return (c.b < d.b);
      return (c.a < d.a);
}

bool jak (pole2 c,pole2 d) {
      return (c.a < d.a);
}

long long tab[500000][20];
pole bufor[500000];
pole2 tab2[500000];
long long tab3[500000];
long long odp[500000];

bool algorytm(long long liczba,long long a, long long poczatek1, long long poczatek2){
     // cout << "START Z : " << liczba << endl;
     // if(liczba==1) return false;

     // S.clear();

      int x=1;
      int y=0;
      while(x<=liczba){
              x*=2;
              y++;
       }
      x/=2;
      y--;
      
     /* cout << "LICZBELKA 2 " << x << " tab -> " << y << endl;
      cout << tab[poczatek2][y] << " r" << tab[poczatek1][y] << endl;
      cout << tab[poczatek1+liczba-x][y] << " w" << tab[poczatek2+liczba-x][y] << endl;
      cout << poczatek1 << " " << poczatek2 << " " << poczatek1+liczba-x  << " " << poczatek2+liczba-x<< endl; */
      if(tab[poczatek2][y]==tab[poczatek1][y] && tab[poczatek1+liczba-x][y]==tab[poczatek2+liczba-x][y]){
      	//cout << "dafaq" << endl;
      	return true;
	  }
      return false;
      
      
      
   


            /*  int z=0;
              for(int i=0;(i+liczba-1)<a;i++){
              //      cout << "op : " << i << " "<< (i+liczba-x) << endl;
                      pair <long long, long long > P;
                      P.first=tab[i][y];
                      P.second=tab[i+liczba-x][y];
              //      cout << "sprawedzana : " << P.first << " " << P.second << endl;
                      S.insert(P);
                      z++;
              }

      //      cout << "KWA" << S.size() << endl;
              if(S.size()==z){
                      //      cout << "inne" <<endl;
                              return false;
                      }else{
                      //      cout << "takiesamewszystkie" << endl;
                              return true;
              }*/


}


long long bajnary(long long s, long long k, long long a, long long poczatek1, long long poczatek2){
	//cout << "bajnary" << endl;
//	cout << poczatek1 << " poczatki " << poczatek2 << endl;
      while(s<k){
           // cout << s << "halo " << k << endl;
              if (algorytm(((s+k+1)/2),a,poczatek1,poczatek2)) s=((s+k+1)/2);
              else k = ((s + k + 1)/ 2)-1;
      }

      return s;
}


int main(){
      long long z;
      cin >> z;
      while(z--){
              long long a;
              cin >> a;

              for(long long i=0;i<a;i++){
              		  char g;
              		  cin >> g;
              		  if(g=='L') tab[i][0] = 1;
              		  else tab[i][0]=2;
              }

              long long pdwa=1;
              long long j=0;

              while(pdwa<=a){

                      for(long long i=0;i<a;i++){
                              bufor[i].a=tab[i][j];
                              if(i+pdwa>=a) bufor[i].b=0;
                              else bufor[i].b=tab[i+pdwa][j];
                              bufor[i].wiersz=i;
                      }

                      sort(bufor,bufor + a,sort1);


                      for(long long i=0;i<a;i++){
                              if(i>0){

                                      if(bufor[i].a==bufor[i-1].a && bufor[i].b==bufor[i-1].b){
                                              tab[bufor[i].wiersz][j+1]=tab[bufor[i-1].wiersz][j+1];
                                      }else{
                                              tab[bufor[i].wiersz][j+1]=(tab[bufor[i-1].wiersz][j+1] + 1);
                                      }

                              }else{
                                      tab[bufor[i].wiersz][j+1]=1;
                              }
                      }

                                        pdwa*=2;
                                        j++;
              }

             /* for(int i=0;i<=j;i++){
                      for(int b=0;b<a;b++){
                              cout << tab[b][i] << " ";
                                }
                                cout << endl;
                        }*/
                    
				for(int i=0;i<a;i++){
					tab2[i].a = tab[i][j];
					tab2[i].b = i;
				}	    
				
				sort(tab2,tab2 + a, jak);
				
			//	for(int i=0;i<a;i++) cout << tab2[i].b << " ";
			//	cout << endl;                        
                
				for(int i=0;i<(a-1);i++){
				//	cout << "porownuje : " << tab2[i].b << " " << tab2[i+1].b << endl;
					tab3[i] = bajnary(0,min(a-tab2[i].b,a-tab2[i+1].b),a,tab2[i].b,tab2[i+1].b);
					//cout << tab3[i] << endl;
				}
				
			//	for(int i=0;i<a-1;i++) cout << tab3[i] << " ";
			//	cout << endl;
				
				for(int i=0;i<a;i++){
					long long z1=tab3[i-1];
					long long z2=tab3[i];
					if(i-1<0) z1=0;
					if(i==(a-1)) z2=0;
					odp[tab2[i].b]=max(z1,z2);
				}
				
				for(int i=0;i<a;i++) cout << odp[i] << " ";
				cout << endl;
                
      }
}
