 #include <iostream>

using namespace std;
int tab[2005][2005], sum[2005], tort[2005];

unsigned long long n;

unsigned long long sums(int s, int e){
      if(s<=e) return sum[e+1]-sum[s];
	  else return sum[n] - (sum[s]-sum[e+1]);
}

int rek(int s, int e){
//	cout << s << " " << e << endl;
      if(tab[s][e]>0) return tab[s][e];
      if(s!=e) tab[s][e]=max(sums(s,e) - rek((s+1)%n,e), sums(s,e) - rek(s,(e-1+n)%n));
      else tab[s][e]=tort[s];

      return tab[s][e];
}



void f(){
      for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                      cout << tab[i][j] << " ";
              }
              cout << endl;
      }

}

int main(){
      int z;
      cin >> z;
      while (z--){

              unsigned long long a;
              cin >> a;
              n=a;

              for(int i=0;i<a;i++){
                      for(int j=0;j<a;j++){
                              tab[i][j]=0;
                      }
                      sum[a]=0;
              }


              for(int i=0;i<a;i++){
                      int liczba;
                      cin >> liczba;

                      tort[i]=liczba;

                      sum[i+1]=tort[i] + sum[i];
              }

              unsigned long long s=0;
              a--;

              rek(s,a);
              for(int i=1;i<=a;i++){
              	rek(i,i-1);
			  }
        
              //f();
              unsigned long long m=sum[n];
              //cout << m << endl;
              unsigned long long max=0;
              for(int i=0;i<=a;i++){
              		if(( m-tab[i][(i+a-1)%n] ) > max) max = m - tab[i][(i+a-1)%n];
              	/*	cout << "------" << endl;
              		cout << max << endl;
              		cout << m-tab[i][(i+a-1)%n] << endl;
              		cout << tab[i][(i+a-1)%n] << endl;
              		cout << (i+a-1)%n << endl;
              		cout << "------" << endl;*/
              		
			  }
			  
			  cout << max << " ";
			  cout << m - max << endl;

      }
}
