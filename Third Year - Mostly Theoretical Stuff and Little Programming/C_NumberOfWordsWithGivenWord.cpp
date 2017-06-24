#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int ruch[10005][2];
int il=1;

//vector <int> tab;
//bool wynik[1000000];
long long wyn[10005][2];
bool visited[10005];
int suf[10005];
long long modul= 1000000007;
//int pietro[1000000];


int graf(int liczba, int zn){
      if(ruch[liczba][zn] != (-1)) return ruch[liczba][zn];
      ruch[liczba][zn]= il;

      ruch[il][0]=(-1);
      ruch[il][1]=(-1);

      il++;

      return ruch[liczba][zn];


}

void dodaj(){
      int a=0;
      string c;
      cin >> c;
      
      int b=c.length();
      
      
      for(int i=0;i<b;i++){
              char x;
              x=c[i];
              
              int x2=0;
              if(x=='b') x2=1;
              a = graf(a,x2);

      }

      //tab.push_back(il-1);

}

void bfs(int s, int koniec){

      suf[s] = 0;
      for(int i=0;i<2;i++){
              if(ruch[s][i]!=(-1)) suf[ruch[s][i]]=s;
              else ruch[s][i]=0;
      }



      for(int i=0;i<koniec;i++){
              visited[i] = 0;
      }

      queue <int> Q;
      visited[s]=1;
      Q.push(s);
      //pietro[s]=0;

      while(Q.empty()==false){

              int top = Q.front();
              Q.pop();

              for(int i=0;i<2;i++){
                      if(ruch[top][i]==(-1)) goto p;
                      if(visited[ruch[top][i]]==false){
                              //pietro[ruch[top][i]]=pietro[top]+1;
                              visited[ruch[top][i]]=true;
                              Q.push(ruch[top][i]);
                                      for(int j=0;j<2;j++){

                                              if(ruch[ruch[top][i]][j]==(-1)) ruch[ruch[top][i]][j] = ruch[suf[ruch[top][i]]][j];
                                              else suf[ruch[ruch[top][i]][j]] = ruch[suf[ruch[top][i]]][j];

                              }
                      p:;
                      }
              }

      }
}


int main(){
      int z; cin >> z;
      while(z--){


              il=1;
              //tab.clear();
              int a; cin >> a;

              ruch[0][0]=(-1);
              ruch[0][1]=(-1);

              dodaj();

              bfs(0,il);
              
              
              for(int i=0;i<il;i++){
              	for(int j=0;j<2;j++){
              		wyn[i][j]=0;
				  }
			  }
			  
			  wyn[0][0]=1;
 				
 			  for(int i=0;i<a;i++){
 			  	for(int j=0;j<(il-1);j++){
 			  		wyn[ruch[j][0]][(i+1)%2]+=wyn[j][i%2];
 			  		(wyn[ruch[j][0]][(i+1)%2]%=modul);
 			  		if(wyn[ruch[j][0]][(i+1)%2]<0) wyn[ruch[j][0]][(i+1)%2]+=modul;
 			  		wyn[ruch[j][1]][(i+1)%2]+=wyn[j][i%2];
 			  		(wyn[ruch[j][1]][(i+1)%2]%=modul);
 			  		if(wyn[ruch[j][1]][(i+1)%2]<0) wyn[ruch[j][1]][(i+1)%2]+=modul;
 			  		
 			  	/*	cout << "TEST" << endl;
 			  		cout << i%2 << endl;
 			  		cout << ruch[j][0] << endl;
 			  		cout << ruch[j][1] << endl;*/
				   }
				   //	cout << "TAB " << endl;
				   	
				   /*	for(int i=0;i<2;i++){
			  		cout << "poziom" << endl;
              		for(int j=0;j<il;j++){
              			cout << wyn[j][i] << " ";
				  	}
				  	cout << endl;
			 	 }*/
			 	 for(int j=0;j<il;j++){
			 	 	wyn[j][i%2]=0;
				  }
			  }
			  
			  /*for(int i=0;i<2;i++){
			  	cout << "poziom" << endl;
              	for(int j=0;j<il;j++){
              		cout << wyn[j][i] << " ";
				  }
				  cout << endl;
			  }*/
			  long long sum = 0;
			  for(int k=0;k<(il-1);k++){
			   sum+= wyn[k][a%2];
			   sum%=modul;
			   if(sum < 0) sum+=modul;
			  }
			  long long t=1;
			  while(a--){
			  	 t*=2;
			  	 t%=modul;
			  	 if(t<0) t+=modul;
			  }
			  t-=sum;
			  t%=modul;
			  if(t<0) t+=modul;
			  
			  cout << t << endl; 


      }
}
