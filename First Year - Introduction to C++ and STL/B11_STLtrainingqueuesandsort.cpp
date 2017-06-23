#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Punkt{
      int x,y,z,numer,wyjscie,wlasciwet;
};

struct h{
      bool operator()(Punkt a, Punkt b){
              return a.z<b.z;
      }
};

struct w{
      bool operator()(Punkt a, Punkt b){
              return a.numer>b.numer;
      }
};

struct czas{
      bool operator()(Punkt a, Punkt b){
              return a.x>b.x;
      }
};

bool my (Punkt a,Punkt b) { return (a.x<b.x); }

Punkt tablica[100005];
bool tabb[100005];
priority_queue<Punkt,vector<Punkt>,w> wyj;
priority_queue<Punkt,vector<Punkt>,h> kolejka;
priority_queue<Punkt,vector<Punkt>,czas> kolejka1;
priority_queue<Punkt,vector<Punkt>,czas> kolejkat;

bool czybyl(Punkt przejsciowy){
      if(tabb[przejsciowy.wlasciwet]) return true;
      else return false;
}

int jaromir(int czasj, int n, int wskaznik, Punkt osoba, int czasurzedu){

      return czasj;
}

int main(){
      unsigned long long n;
      cin >> n;
      unsigned long long  i=0;

      while(i<n){
              Punkt a;
              cin >> a.x >> a.y >> a.z;
              a.numer=(i+1);
              a.wyjscie=0;
              tablica[i]=a;
              i++;
      }

      unsigned long long  czasurzedu;
      cin >> czasurzedu;

      unsigned long long  czasj=0,czast=20,obecny=0;

      sort(tablica,tablica+n,my);

      for(int i=0;i<n;i++){
              tablica[i].wlasciwet=i;
              tabb[i]=0;
              kolejka1.push(tablica[i]);
      }

      int iloscosob=n;
      while((czasj<czasurzedu || czast<czasurzedu) && (iloscosob!=0)){
              //cout << kolejka1.size() << " " << kolejka.size() << " " << kolejkat.size() << endl;
              //cout << "obrot" << endl;

              if(kolejka1.empty()==false){
                              while(kolejka1.top().x<=obecny && kolejka1.empty()==false){
                              	//cout << kolejka1.top().x<< " " << kolejka1.top().y<< " " << kolejka1.top().z<< " " << " to glowna kolejka " << endl;
                                      kolejkat.push(kolejka1.top());
                                      kolejka.push(kolejka1.top());
                                      kolejka1.pop();
                              }
               }

              //cout << "sprzwdzenie" << endl;
              if(((kolejkat.empty() || kolejka.empty())) && kolejka1.empty()==false){
                      //nie maja kogo zabrac => biora nastepnego => jezeli ktos pracuje to nie bierze ++ omijamy obrot.
                      if(czasj<kolejka1.top().x) czasj=kolejka1.top().x;
                      if(czast<kolejka1.top().x) czast=kolejka1.top().x;
                      goto koniec;
               }

              if(czasj<=czast){
                    //cout << "jaromir" << endl;
                    Punkt pomocniczy=kolejka.top();
                    //cout << pomocniczy.x << " " << pomocniczy.y << " " <<pomocniczy.z << " to jarek robi" << endl;
                    if(czybyl(pomocniczy)==false){
                        if(czasj<pomocniczy.x) czasj=pomocniczy.x;
                        czasj+=pomocniczy.y;
                        tabb[pomocniczy.wlasciwet]=true;
                        pomocniczy.wyjscie=czasj;
                        if(czasj>czasurzedu) pomocniczy.wyjscie=czasurzedu;
                        wyj.push(pomocniczy);
                        iloscosob--;
                        kolejka.pop();
                    }else kolejka.pop();
              }else{
                    //cout << "teodzia" << endl;
                    Punkt pomocniczy=kolejkat.top();
                    if(czybyl(pomocniczy)==false){
                          if(czast<pomocniczy.x) czast=pomocniczy.x;
                          czast+=2*pomocniczy.y;
                          tabb[pomocniczy.wlasciwet]=true;
                          pomocniczy.wyjscie=czast;
                          if(czast>czasurzedu) pomocniczy.wyjscie=czasurzedu;
                          czast+=20;
                          wyj.push(pomocniczy);
                          iloscosob--;
                          kolejkat.pop();
                    }else kolejkat.pop();
            }

            koniec:
            if(czasj<czast) obecny = czasj;
            else obecny = czast;

            //cout << czast << " " << czasj << " " << obecny << endl;
      }

      if(czasurzedu<=obecny){
                      if(kolejkat.empty()==false){
                              while(kolejkat.size()>0){
                              Punkt przejsciowy=kolejkat.top();
                              przejsciowy.wyjscie=czasurzedu;            
                              kolejkat.pop();
                              if(czybyl(przejsciowy)==false) wyj.push(przejsciowy);
                              tabb[przejsciowy.wlasciwet]=true;
                      }
                        }

                      if(kolejka.empty()==false){
                              while(kolejka.size()>0){
                              Punkt przejsciowy=kolejka.top();
                              przejsciowy.wyjscie=czasurzedu;
                              kolejka.pop();
                              if(czybyl(przejsciowy)==false) wyj.push(przejsciowy);
                               tabb[przejsciowy.wlasciwet]=true;
                      }
                        }

                      if(kolejka1.empty()==false){
                              while(kolejka1.size()>0){
                              Punkt przejsciowy=kolejka1.top();
                              przejsciowy.wyjscie=czasurzedu;
                              kolejka1.pop();
                              if(czybyl(przejsciowy)==false) wyj.push(przejsciowy);
                             tabb[przejsciowy.wlasciwet]=true;
                      }
                        }
        }

        //cout << "zmierzamy ku koncowi" << endl;

        while(wyj.empty()==false){
              cout << wyj.top().wyjscie << endl;
              wyj.pop();
        }

        return 0;
}
