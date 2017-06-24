#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct pole{
      long long a,b,wiersz;
};

bool sort1 (pole c,pole d) {
      if(c.a==d.a) return (c.b < d.b);
      return (c.a < d.a);
}

long long tab[50000][20];
pole bufor[50000];

set<pair <long long, long long> > S;

bool algorytm(long long liczba,long long a){
	//cout << "START Z : " << liczba << endl;
	
	S.clear();
	
 	int x=1;
 	int y=0;
 	while(x<=liczba){
 		x*=2;
 		y++;
	 }
 	x/=2;
 	y--;
 //	cout << "LICZBELKA 2 " << x << " tab -> " << y << endl;
 	
 	
		int z=0;
		for(int i=0;(i+liczba-1)<a;i++){
		//	cout << "op : " << i << " "<< (i+liczba-x) << endl;
			pair <long long, long long > P;
			P.first=tab[i][y];
			P.second=tab[i+liczba-x][y];
		//	cout << "sprawedzana : " << P.first << " " << P.second << endl;
			S.insert(P);
			z++;
		}
		
	//	cout << "KWA" << S.size() << endl;
		if(S.size()==z){
		 	//	cout << "inne" <<endl;
		 		return false;
			}else{
		 	//	cout << "takiesamewszystkie" << endl;
		 		return true;
		}
 	
 	
}


long long bajnary(long long s, long long k, long long a){

      while(s<k){
      //	cout << s << " " << k << endl;
              if (algorytm(((s+k)/2),a)) s=((s+k)/2)+1;
              else k = ((s + k )/ 2);
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
                      cin >> tab[i][0];
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
			
			 cout << bajnary(1,a,a) << endl;
      }
}
