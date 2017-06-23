#include <iostream>
#include <queue>
using namespace std;

bool visited[2005][2005];
int odleglosc[2005][2005];
int wejscie[2005][2005];

int main(){
      int ilosc;
      cin >> ilosc;
      while(ilosc--){

              int E, V;
              cin >> V >> E;

              for(int i=0;i<V;i++){

	              	for(int ii=0;ii<E;ii++){
	                      visited[i][ii]=0;
	                      odleglosc[i][ii]=0;
	                      wejscie[i][ii]=0;
	            	}

              }

              char znak;

              queue<int> kx;
              queue<int> ky;

              for(int i=0;i<V;i++){

						for(int ii=0;ii<E;ii++){
							cin >> znak;
							int taki = znak-48;
							wejscie[i][ii]=taki;

							if(taki==1){
                                    //cout << "wbijamy tu " << endl;
								visited[i][ii]=true;
                            //cout << i << " " << ii << endl;
								kx.push(i);
								ky.push(ii);
							}
						}
               // cout << "tutaj ! " << endl;
              }


              while(kx.size()>0 && ky.size()>0){
              	int x=kx.front();
              	kx.pop();
              	int y=ky.front();
              	ky.pop();

                //cout << kx.size() << endl;
                //cout << x << " " << y << endl;

              	int szybka=odleglosc[x][y];

              		if(visited[x-1][y]==false && x-1>=0){
              			visited[x-1][y]=true;
              			odleglosc[x-1][y]=szybka+1;
              			if(wejscie[x-1][y]==0){
              			    //cout << "push1" << endl;
                            kx.push(x-1);
                            ky.push(y);
              			}
					  }
					if(visited[x+1][y]==false && x+1<V){
              			visited[x+1][y]=true;
              			odleglosc[x+1][y]=szybka+1;
              			if(wejscie[x+1][y]==0){
              			    //cout << "push2" << endl;
                            kx.push(x+1);
                            ky.push(y);
              			}
					  }
					if(visited[x][y-1]==false && y-1>=0){
              			visited[x][y-1]=true;
              			odleglosc[x][y-1]=szybka+1;
              			if(wejscie[x][y-1]==0){
              			    //cout << "push3" << endl;
                            kx.push(x);
                            ky.push(y-1);
              			}
					  }
					if(visited[x][y+1]==false && y+1<E){
              			visited[x][y+1]=true;
              			odleglosc[x][y+1]=szybka+1;
              			//cout << x << " " << y+1 << endl;
              			//cout << wejscie[x][y+1] << endl;
              			if(wejscie[x][y+1]==0){
              			    //cout << "push4" << endl;
                            kx.push(x);
                            ky.push(y+1);
              			}
					  }
              }
              //cout << "ble" << endl;

			  for(int i=0;i<V;i++){
			  		for(int ii=0;ii<E;ii++){
                            if(visited[i][ii]) cout << odleglosc[i][ii] << " ";
                            else cout << "-1 ";
					  }
				cout << endl;
			  }
      }
}
