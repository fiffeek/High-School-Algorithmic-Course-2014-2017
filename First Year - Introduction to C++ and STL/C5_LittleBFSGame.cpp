#include <iostream>
#include <queue>
using namespace std;

bool visited[1005][1005][2];
int odleglosc[1005][1005][2];
char wejscie[1005][1005][2];

int main(){

      /* TAK WIEM ZE X JEST ZAMIENIONY Z Y, ZAMIENILEM GO NA STARCIE A POZNIEJ MYSLALEM JUZ TYM TOREM*/
      /* TAK WIEM ZE X JEST ZAMIENIONY Z Y, ZAMIENILEM GO NA STARCIE A POZNIEJ MYSLALEM JUZ TYM TOREM*/
      /* TAK WIEM ZE X JEST ZAMIENIONY Z Y, ZAMIENILEM GO NA STARCIE A POZNIEJ MYSLALEM JUZ TYM TOREM*/



      int ilosc;
      cin >> ilosc;
      while(ilosc--){

              int E, V;
              cin >> V >> E;

              for(int i=0;i<V;i++){

                      for(int ii=0;ii<E;ii++){
                            visited[i][ii][0]=0;
                            odleglosc[i][ii][0]=0;
                            wejscie[i][ii][0]=0;

                            visited[i][ii][1]=0;
                            odleglosc[i][ii][1]=0;
                            wejscie[i][ii][1]=0;
                      }

              }

              char znak;

              queue<int> kx;
              queue<int> ky;
              queue<int> kz;

              for(int i=0;i<V;i++){

                                              for(int ii=0;ii<E;ii++){
                                                      cin >> znak;

                                                      if(znak=='#'){
                                                              visited[i][ii][0]=1;
                                                              visited[i][ii][1]=1;

                                                      }
                                                      else if(znak=='+'){
                                                              wejscie[i][ii][0]='.';
                                                              wejscie[i][ii][1]='#';
                                                              visited[i][ii][1]=1;
                                                      }
                                                      else if(znak=='o'){
                                                              wejscie[i][ii][0]='#';
                                                              wejscie[i][ii][1]='.';
                                                              visited[i][ii][0]=1;
                                                      }
                                                      else if(znak=='@'){
                                                      		  visited[i][ii][0]=1;
                                                      		  wejscie[i][ii][1]='.';
                                                              kx.push(i);
                                                              ky.push(ii);
                                                              kz.push(0);
                                                      }
                                                      else{
                                                              wejscie[i][ii][0]=znak;
                                                              wejscie[i][ii][1]=znak;
                                                       }

                                              }
               // cout << "tutaj ! " << endl;
              }

              int wyjsciex=-1;
              int wyjsciey=-1;
              int wyjsciez=0;

              while(kx.size()>0 && ky.size()>0 && kz.size()>0){
                      int x=kx.front();
                      kx.pop();
                      int y=ky.front();
                      ky.pop();
                      int z=kz.front();
                      kz.pop();

                //cout << kx.size() << endl;
                //cout << x << " " << y << " " << z << endl;
                      int szybka=odleglosc[x][y][z];

                              if(visited[x-1][y][z]==false && x-1>=0){
                            //cout << "push1" << endl;
                                      visited[x-1][y][z]=true;
                                      odleglosc[x-1][y][z]=szybka+1;
                                      if(wejscie[x-1][y][z]=='.' || wejscie[x-1][y][z]=='>' || wejscie[x-1][y][z]=='%'){
                                          //cout << "push1" << endl;
                            kx.push(x-1);
                            ky.push(y);
                            kz.push(z);
                                      }
                                        }
                                      if(visited[x+1][y][z]==false && x+1<V){
                                          //cout << "push2" << endl;
                                      visited[x+1][y][z]=true;
                                      odleglosc[x+1][y][z]=szybka+1;
                                      if(wejscie[x+1][y][z]=='.' || wejscie[x+1][y][z]=='>' || wejscie[x+1][y][z]=='%'){
                                //cout << "PUSHH " << endl;
                                          //cout << "push2" << endl;
                            kx.push(x+1);
                            ky.push(y);
                            kz.push(z);
                                      }
                                        }
                                      if(visited[x][y-1][z]==false && y-1>=0){
                                         // cout << "push3" << endl;
                                      visited[x][y-1][z]=true;
                                      odleglosc[x][y-1][z]=szybka+1;
                                      if(wejscie[x][y-1][z]=='.' || wejscie[x][y-1][z]=='>' || wejscie[x][y-1][z]=='%'){
                                          //cout << "push3" << endl;
                            kx.push(x);
                            ky.push(y-1);
                            kz.push(z);
                                      }
                                        }

                                      if(visited[x][y+1][z]==false && y+1<E){
                                          //cout << "push4 " << endl;
                                      visited[x][y+1][z]=true;
                                      odleglosc[x][y+1][z]=szybka+1;
                                      //cout << x << " " << y+1 << endl;
                                      //cout << wejscie[x][y+1] << endl;
                                      if(wejscie[x][y+1][z]=='.' || wejscie[x][y+1][z]=='>' || wejscie[x][y+1][z]=='%'){
                                          //cout << "push4" << endl;
                            kx.push(x);
                            ky.push(y+1);
                            kz.push(z);
                                      }
                                        }
                                       //==============================================//
                                      if(wejscie[x][y][z]=='%'){
                            //cout << "portalik " << endl;

                                              if(z==0) z=1;
                                              else z=0;

                                                              if(visited[x-1][y][z]==false && x-1>=0){
                            //cout << "push1" << endl;
                                      visited[x-1][y][z]=true;
                                      odleglosc[x-1][y][z]=szybka+1;
                                      if(wejscie[x-1][y][z]=='.' || wejscie[x-1][y][z]=='>' || wejscie[x-1][y][z]=='%'){
                                          //cout << "push1" << endl;
                            kx.push(x-1);
                            ky.push(y);
                            kz.push(z);
                                      }
                                        }
                                      if(visited[x+1][y][z]==false && x+1<V){
                                          //cout << "push2" << endl;
                                      visited[x+1][y][z]=true;
                                      odleglosc[x+1][y][z]=szybka+1;
                                      if(wejscie[x+1][y][z]=='.' || wejscie[x+1][y][z]=='>' || wejscie[x+1][y][z]=='%'){
                                //cout << "PUSHH " << endl;
                                          //cout << "push2" << endl;
                            kx.push(x+1);
                            ky.push(y);
                            kz.push(z);
                                      }
                                        }
                                      if(visited[x][y-1][z]==false && y-1>=0){
                                          //cout << "push3" << endl;
                                      visited[x][y-1][z]=true;
                                      odleglosc[x][y-1][z]=szybka+1;
                                      if(wejscie[x][y-1][z]=='.' || wejscie[x][y-1][z]=='>' || wejscie[x][y-1][z]=='%'){
                                          //cout << "push3" << endl;
                            kx.push(x);
                            ky.push(y-1);
                            kz.push(z);
                                      }
                                        }

                                      if(visited[x][y+1][z]==false && y+1<E){
                                          //cout << "push4 " << endl;
                                      visited[x][y+1][z]=true;
                                      odleglosc[x][y+1][z]=szybka+1;
                                      //cout << x << " " << y+1 << endl;
                                      //cout << wejscie[x][y+1] << endl;
                                      if(wejscie[x][y+1][z]=='.' || wejscie[x][y+1][z]=='>' || wejscie[x][y+1][z]=='%'){
                                          //cout << "push4" << endl;
                            kx.push(x);
                            ky.push(y+1);

                            kz.push(z);
                                      }
                                        }

                                              if(z==0) z=1;
                                              else z=0;

                              }
                              if(wejscie[x][y][z]=='>' && z==0){
                    wyjsciex=x;
                    wyjsciey=y;
                    wyjsciez=z;
                    if(z==0) goto koniec;
                              }

        }
              //cout << "ble" << endl;
                      koniec:
                      if(kx.empty() && kz.empty() && ky.empty() || (wyjsciex==-1 && wyjsciey==-1)){
                              if(wyjsciex==-1 && wyjsciey==-1){
                                      cout << "NIE" << endl;
                                      goto poza;
                              }
              }

                       if(visited[wyjsciex][wyjsciey][wyjsciez]==1) cout << odleglosc[wyjsciex][wyjsciey][wyjsciez] << endl;
                       else cout << "NIE" << endl;
                       poza:;
      }
}
