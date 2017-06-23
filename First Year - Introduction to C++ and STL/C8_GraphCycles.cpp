#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

vector <int> G[500000];
queue <int> Q;
int ilerazy[500000];
int wyjscie[500000];


int main(){
	int a;
	cin >> a;
	while(a--){
              int b,d;
              int ww=0;
              cin >> b >> d ;

              for(int y=0;y<=b;y++){
                      G[y].clear();
                      ilerazy[y]=0;
              }


              for(int r=0;r<d;r++){
                    int c,ce;
            		cin >> c >> ce;
            		G[c].push_back(ce);
            		ilerazy[ce]+=1;
              }

              for(int i=1;i<=b;i++){
              	if(ilerazy[i]==0) Q.push(i);
			  }

			  while(Q.empty()==false){
			  	int n=Q.front();
			  	Q.pop();
			  	wyjscie[ww]=n;
			  	ww++;

			  	for(int i=0;i<G[n].size();i++){
			  		int temp=G[n][i];

			  		ilerazy[temp]-=1;
			  		if(ilerazy[temp]==0) Q.push(temp);
				}
				G[n].clear();

			  }

			  bool czy=false;

			  for(int i=1;i<=b;i++){
			  	if(G[i].empty()==false){
			  		czy=true;
			  		break;
				  }
			  }

			  if(czy){
			  	cout << "CYKL" << endl;
			  }else{
				  cout << "OK" << endl;
				  for(int i=0;i<ww;i++){
	                cout << wyjscie[i] << " ";
				  }
				  cout << endl;
			  }
	}

}
