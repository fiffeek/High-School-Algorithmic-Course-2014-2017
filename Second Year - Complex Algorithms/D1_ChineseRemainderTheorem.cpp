#include <iostream>
#include <cmath>

using namespace std;

struct moja{
      long long lewa,prawa,modulo;
};

moja tab[4];
long long x=1,y=0,nwd=0;

void gcd(int a, int b){
      if(b==0){
              nwd=a;
              return;
      }
      else{
      gcd(b, a%b);
      }

      int zmienna = y;
      y = x  - floor(a/b)*y;
    x = zmienna;
}

bool czypopr(int i){
      //cout << "ta" << endl;
      x=1,y=0,nwd=1;
      gcd(tab[i].lewa,tab[i].modulo);
      int k=nwd;
      if(k>1){
              if((tab[i].prawa%k)!=0) return false;
              else{
                      tab[i].lewa/=k;
                      tab[i].prawa/=k;
                      tab[i].modulo/=k;
              }
      }

      tab[i].lewa=1;
      tab[i].prawa=((tab[i].prawa * x))%tab[i].modulo;
      if(tab[i].prawa<0) tab[i].prawa+=tab[i].modulo;

      // << "OTO NOWA KONGRUENCJA" << endl;
      //cout << tab[i].lewa << " * x = " << tab[i].prawa << " mod " << tab[i].modulo << endl;
      return true;
}

bool skladaniekongruencji(int i, int j){
      tab[j].lewa=tab[i].modulo;
      tab[j].prawa=(tab[j].prawa - tab[i].prawa);

      //cout << "NOWA KONGRUENCJA DO ROZW" << endl;
      //cout << tab[j].lewa << " " << tab[j].prawa << " " << tab[j].modulo << endl;
      if(czypopr(j)==0) return false;
      else return true;
}

bool sprpo(int i){
      x=1,y=0,nwd=1;
      gcd(tab[i].lewa,tab[i].modulo);
      int k=nwd;
      if(k>1) if((tab[i].prawa%k)!=0) return false;
      return true;
}

bool sk(int i,int j){
              if(skladaniekongruencji(i,j)==0){
                              cout << "NIE"<<endl;
                              return false;
                      }

              tab[i].prawa += tab[i].modulo*tab[j].prawa;
              tab[i].modulo*=tab[j].modulo;

              if(sprpo(i)==0) return false;

              return true;
}


int main(){
      int z;
      cin >> z;
      while(z--){
              int a;
              cin >> a;

              for(int i=0;i<a;i++){
                      int przyx,rownosc,modul;
                      char gwiazda,iks,rowna,jeden,dwa,trzy;

                      cin >> przyx >> gwiazda >> iks >> rowna >> rownosc >> jeden >> dwa >> trzy >> modul;
                      tab[i].lewa = przyx;
                      tab[i].prawa = rownosc;
                      tab[i].modulo=modul;
                      //cout << tab[a].lewa << "rrw"<< endl;
              }

              for(int i=0;i<a;i++){
                      if(czypopr(i)==0){
                               cout << "NIE" << endl;
                               goto koniec;
                      }
              }

              if(a==1){
                      /*cout << "ROZWIAZANIE" << endl;
                      cout << "x = " << tab[0].modulo << "*k +/- " << tab[0].prawa << endl;*/
                      tab[0].prawa%=tab[0].modulo;
                      while(tab[0].prawa<0) tab[0].prawa += tab[0].modulo; 
                      cout << tab[0].prawa << endl;
              }else if(a==2){
                      if(sk(0,1)==0){
                              cout << "NIE" << endl;
                              goto koniec;
                      }


                      /*cout << "ROZWIAZANIE KONGRUENCJI PLS" << endl;
                      cout << "x = " << tab[0].modulo << "*k +/- " << tab[0].prawa << endl;*/
                      tab[0].prawa%=tab[0].modulo;
                      while(tab[0].prawa<0) tab[0].prawa += tab[0].modulo; 
                      cout << tab[0].prawa << endl;
              }else if(a==3){
                      if(sk(0,1)==0){
                              cout << "NIE" << endl;
                              goto koniec;
                      }
                      if(sk(0,2)==0){
                              cout << "NIE" << endl;
                              goto koniec;
                      }

                      /*cout << "ROZWIAZANIE KONGRUENCJI PLS" << endl;
                      cout << "x = " << tab[0].modulo << "*k +/- " << tab[0].prawa << endl;*/
                      tab[0].prawa%=tab[0].modulo;
                      while(tab[0].prawa<0) tab[0].prawa += tab[0].modulo; 
                      cout << tab[0].prawa << endl;

              }else if(a==4){
                      if(sk(0,1)==0){
                              cout << "NIE" << endl;
                              goto koniec;
                      }
                      if(sk(2,3)==0){
                              cout << "NIE" << endl;
                              goto koniec;
                      }
                      if(sk(0,2)==0){
                              cout << "NIE" << endl;
                              goto koniec;
                      }

                      /* << "ROZWIAZANIE KONGRUENCJI PLS" << endl;
                      cout << "x = " << tab[0].modulo << "*k +/- " << tab[0].prawa << endl;*/
                      tab[0].prawa%=tab[0].modulo;
                      while(tab[0].prawa<0) tab[0].prawa += tab[0].modulo; 
                      cout << tab[0].prawa << endl;
              }


              koniec:;
      }
}

