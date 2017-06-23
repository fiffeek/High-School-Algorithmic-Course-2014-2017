#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
using namespace std;

//FilipMikina
//FirstYear
//BigNumbersMultiplication

int tablicaa[500005],tablicab[500005],tablicawynik[1000005];
int dlugoscprawidlowa,dlugoscprawidlowb,dlugosc,ii,tablicowy,stala,miejscewyniku,taka,liczba;

void zerowaniezmiennych(string a, string b){
      dlugoscprawidlowa=0;
      dlugoscprawidlowb=0;
      dlugosc=0;
      ii=0;
      liczba=0;
      tablicowy=0;
      stala=0;
      miejscewyniku=0;
      taka=0;

memset(tablicaa,0,(a.length())*sizeof(int));
memset(tablicab,0,(b.length())*sizeof(int));
memset(tablicawynik,0,(a.length()+b.length()+1)*sizeof(int));
}



void przepisywanie(string a, string b){
        dlugoscprawidlowa=0;
        dlugoscprawidlowb=0;

      dlugosc=(a.length()/2)+1;
        ii=a.length();
      tablicowy=0;

      for(int i=dlugosc;i>0;i--){
                      int element=0;
                      int element2=0;
              element=a[ii-1]-'0';
              if((ii-1)<0) goto takio;
              element2=a[ii-2]-'0';
              if((ii-2<0)) element2=0;

                        tablicaa[tablicowy]=element+(10*element2);

              tablicowy++;
              ii-=2;

              dlugoscprawidlowa++;
      }
      takio:
      dlugosc=(b.length()/2)+1;
      ii=b.length();
      tablicowy=0;

      for(int i=dlugosc;i>0;i--){
                      int element=0;
                      int element2=0;
              element=b[ii-1]-'0';
              if((ii-1)<0) goto broken1;
              element2=b[ii-2]-'0';
              if((ii-2)<0) element2=0;

              tablicab[tablicowy]=element+(10*element2);

              tablicowy++;
              ii-=2;
              dlugoscprawidlowb++;
      }
      broken1:;
}

void mnozenie(string a, string b){

    przepisywanie(a,b);


      stala=dlugoscprawidlowb;
      miejscewyniku=0;
      liczba=0;

      for(int i=0;i<dlugoscprawidlowa;i++){
              int mnoznik=tablicaa[i];
              miejscewyniku=i;

              while(dlugoscprawidlowb>0){
                      int mnoznik2=tablicab[liczba];
                      tablicawynik[miejscewyniku]+=(mnoznik2*mnoznik);
                      miejscewyniku++;
                      liczba++;
                      dlugoscprawidlowb--;

              }

              liczba=0;
              dlugoscprawidlowb=stala;
      }


      taka=miejscewyniku-1;
      if(tablicawynik[miejscewyniku]>0) taka++;
      for(int i=0;i<miejscewyniku;i++){
                 if(tablicawynik[i]>99){
                     if(i==miejscewyniku-1) taka++;
                      tablicawynik[i+1]+=tablicawynik[i]/100;
              }
              tablicawynik[i]%=100;
      }
      for(int i=taka;i>-1;i--){
              if(i!=taka)
                  if(tablicawynik[i]<10) cout << "0";
              cout << tablicawynik[i];
      }

}



main(){



      int rr;
      cin >> rr;
      for(int i=0;i<rr;i++){
   char str[50005],str1[50005];
    scanf("%50005s",str);
    scanf("%50005s",str1);
    string a=str,b=str1;
              zerowaniezmiennych(a,b);
    int licznika=0;




    if(a[0]=='-'){
            a.erase(0,1);
            licznika++;
    }
    if(b[0]=='-'){
                  b.erase(0,1);
                  licznika++;
    }

    if(a=="0" || b=="0"){
          cout << "0";
              goto end;
    }

      if(a[0]!='0' && b[0]!='0')
       if(licznika == 1) cout << "-";

         if(a=="1"){
          cout << b;
              goto end;
    }
     if(b=="1"){
          cout << a;
              goto end;
    }

      mnozenie(a,b);
      end:

              cout << endl;
                cout << endl;
                  cout << endl;
}
}

