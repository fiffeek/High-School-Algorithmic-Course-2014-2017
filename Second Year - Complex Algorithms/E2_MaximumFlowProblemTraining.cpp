#include <iostream>
#include <queue>
#include <vector>


using namespace std;

long long cap[205][205];
long long rezydualna[205][205];
long long parent[205];
long long aktualnacap[205];

vector <long long> siec[205];

void czyszczenie(long long n){
      for(long long i=0;i<=n;i++){
              siec[i].clear();
              for(long long j=0;j<=n;j++){
                      cap[i][j]=0;
                      rezydualna[i][j]=0;
              }
      }
}

long long przeplyw(long long s, long long t,long long n){
      long long odp = 0;

      while(true){
              for(long long i=0;i<=n;i++) parent[i]=(-1);
              parent[s]=(-2);

              for(long long j=0;j<=n;j++) aktualnacap[j]=0;
              aktualnacap[s]=1000000001;

              queue<long long> q;
              if(q.empty()==false) q.pop();
              
              q.push(s);
              while(q.empty()==false){
                      long long wierzch = q.front();
                      q.pop();
					//	cout << siec[wierzch].size() << "POLA"<< endl;
                      for(long long i=0;i<siec[wierzch].size();i++){
                              long long potomek = siec[wierzch][i];
                              //cout << potomek << "to potomek" << endl;
                              if(parent[potomek]==(-1) && ((cap[wierzch][potomek]-rezydualna[wierzch][potomek])>0)){
                                      parent[potomek]=wierzch;
                                      aktualnacap[potomek] = min(aktualnacap[wierzch],cap[wierzch][potomek]-rezydualna[wierzch][potomek]);
                                      if(potomek!=t) q.push(potomek);
                                      else goto wyjsc;
                              }
                      }
              }
              wyjsc:
              long long maksymalnyprzeplyw = aktualnacap[t];
              //cout << maksymalnyprzeplyw << "PRZEPLYWW"<< endl;
              if(maksymalnyprzeplyw==0) goto poza;

              odp+=maksymalnyprzeplyw;

              long long potomek=t;
              while(potomek!=s){
                      long long rodzic = parent[potomek];
                      rezydualna[rodzic][potomek]+=maksymalnyprzeplyw;
                      rezydualna[potomek][rodzic]-=maksymalnyprzeplyw;
                      potomek = rodzic;
              }

      }
      poza:

      return odp;
}



int main(){
      long long z;
      cin >> z;
      while(z--){
              long long n,m,s,t;
              cin >> n >> m;
              czyszczenie(n+m+1);
              for(long long i=1;i<=n;i++){
                      int a;
					  cin >> a;
					  
					  cap[0][i]=a;
					  siec[i].push_back(0);
					  siec[0].push_back(i);
				//	  cout << "wczytalem liczby" << endl;
              }
              //cout << "WTTT" << endl;
               for(long long i=(n+1);i<=(n+m);i++){
               	//cout << i << " " << n+m << endl;
                      int a;
					  cin >> a;
					  
					  cap[i][n+m+1]=a;
					  siec[i].push_back(n+m+1);
					  siec[n+m+1].push_back(i);
					  //cout << obrot << endl
              }
              //cout << "IHA"<< endl;
              for(int i=1;i<=n;i++){
              	//cout << "EN" << endl;
              	for(int j=(n+1);j<(n+m+1);j++){
              	//	cout << "JOT" << endl;
              		//cout << "obrr" << endl;
              		int a;
              		cin >> a;
              		if(a==1){
              			cap[i][j]=10000001;
              			siec[i].push_back(j);
              			siec[j].push_back(i);
					  }
				  }
			  }
              

              cout << przeplyw(0,n+m+1,n+m+1) << endl;
      }
}
