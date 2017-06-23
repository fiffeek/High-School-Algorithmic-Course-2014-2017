#include <iostream>

using namespace std;

pair <int, int> tab[800005];

struct drzewo{
      bool uu;
      bool dd;
      bool ud;
      bool du;
      int pierwsza;
      int ostatnia;
};

drzewo d[800005];

void zrobdrzewo(int a, int x){
    for(int i=x;i<=2*x;i++){
    	d[i].dd=1;
    	d[i].uu=1;
    	d[i].ud=1;
    	d[i].du=1;
    	d[i].pierwsza=i-x+1;
    	if(i>=(x+a)) d[i].pierwsza = 0;
    	d[i].ostatnia=i-x+1;
    	if(i>=(x+a)) d[i].ostatnia = 0;

	}

    for(int i=x-1;i>=1;i--){
        d[i].pierwsza=d[2*i].pierwsza;
        d[i].ostatnia=d[2*i + 1].ostatnia;
        d[i].dd=0;
        d[i].uu=0;
        d[i].du=0;
        d[i].ud=0;
        
        if(i>=x/2){
        		if((tab[d[2*i].ostatnia].first<=tab[d[(2*i)+1].pierwsza].first)) d[i].uu = 1;
    			if((tab[d[2*i].ostatnia].second<=tab[d[(2*i)+1].pierwsza].second)) d[i].dd = 1;
    			if((tab[d[2*i].ostatnia].first<=tab[d[(2*i)+1].pierwsza].second)) d[i].ud = 1;
    			if((tab[d[2*i].ostatnia].second<=tab[d[(2*i)+1].pierwsza].first)) d[i].du = 1;	
		}else{
			if(d[2*i].uu==1 && d[(2*i) + 1].uu==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].first)) d[i].uu = 1;
			if(d[2*i].uu==1 && d[(2*i) + 1].ud==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].first)) d[i].ud = 1;
			if(d[2*i].uu==1 && d[(2*i) + 1].du==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].second)) d[i].uu = 1;
			if(d[2*i].uu==1 && d[(2*i) + 1].dd==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].second)) d[i].ud = 1;
			
			if(d[2*i].dd==1 && d[(2*i) + 1].dd==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].second)) d[i].dd = 1;
			if(d[2*i].dd==1 && d[(2*i) + 1].du==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].second)) d[i].du = 1;
			if(d[2*i].dd==1 && d[(2*i) + 1].uu==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].first)) d[i].du = 1;
			if(d[2*i].dd==1 && d[(2*i) + 1].ud==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].first)) d[i].dd = 1;
			
			if(d[2*i].du==1 && d[(2*i) + 1].uu==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].first)) d[i].du = 1;
			if(d[2*i].du==1 && d[(2*i) + 1].ud==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].first)) d[i].dd = 1;
			if(d[2*i].du==1 && d[(2*i) + 1].dd==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].second)) d[i].dd = 1;
			if(d[2*i].du==1 && d[(2*i) + 1].du==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].second)) d[i].du = 1;
			
			if(d[2*i].ud==1 && d[(2*i) + 1].dd==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].second)) d[i].ud = 1;
			if(d[2*i].ud==1 && d[(2*i) + 1].du==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].second)) d[i].uu = 1;
			if(d[2*i].ud==1 && d[(2*i) + 1].uu==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].first)) d[i].uu = 1;
			if(d[2*i].ud==1 && d[(2*i) + 1].ud==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].first)) d[i].ud = 1;
		}
    }
}

void rek(int i){
	if(i==0) return;
	        d[i].pierwsza=d[2*i].pierwsza;
	        d[i].ostatnia=d[2*i+1].ostatnia;
	        d[i].dd=0;
	        d[i].uu=0;
	        d[i].du=0;
	        d[i].ud=0;
	     //   cout << "frekurencyjna " << tab[d[2*i].ostatnia].first << " " << tab[d[(2*i) + 1].pierwsza].first << endl;
			if(d[2*i].uu==1 && d[(2*i) + 1].uu==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].first)) d[i].uu = 1;
			if(d[2*i].uu==1 && d[(2*i) + 1].ud==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].first)) d[i].ud = 1;
			if(d[2*i].uu==1 && d[(2*i) + 1].du==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].second)) d[i].uu = 1;
			if(d[2*i].uu==1 && d[(2*i) + 1].dd==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].second)) d[i].ud = 1;
			
			if(d[2*i].dd==1 && d[(2*i) + 1].dd==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].second)) d[i].dd = 1;
			if(d[2*i].dd==1 && d[(2*i) + 1].du==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].second)) d[i].du = 1;
			if(d[2*i].dd==1 && d[(2*i) + 1].uu==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].first)) d[i].du = 1;
			if(d[2*i].dd==1 && d[(2*i) + 1].ud==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].first)) d[i].dd = 1;
			
			if(d[2*i].du==1 && d[(2*i) + 1].uu==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].first)) d[i].du = 1;
			if(d[2*i].du==1 && d[(2*i) + 1].ud==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].first)) d[i].dd = 1;
			if(d[2*i].du==1 && d[(2*i) + 1].dd==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].second)) d[i].dd = 1;
			if(d[2*i].du==1 && d[(2*i) + 1].du==1 & (tab[d[2*i].ostatnia].first<=tab[d[(2*i) + 1].pierwsza].second)) d[i].du = 1;
			
			if(d[2*i].ud==1 && d[(2*i) + 1].dd==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].second)) d[i].ud = 1;
			if(d[2*i].ud==1 && d[(2*i) + 1].du==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].second)) d[i].uu = 1;
			if(d[2*i].ud==1 && d[(2*i) + 1].uu==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].first)) d[i].uu = 1;
			if(d[2*i].ud==1 && d[(2*i) + 1].ud==1 & (tab[d[2*i].ostatnia].second<=tab[d[(2*i) + 1].pierwsza].first)) d[i].ud = 1;
	
	rek(i/2);
}

void pary(int i){
	d[i].pierwsza=d[2*i].pierwsza;
	d[i].ostatnia=d[2*i+1].ostatnia;
	d[i].dd=0;
	d[i].uu=0;
	d[i].du=0;
	d[i].ud=0;
	if((tab[d[2*i].ostatnia].first<=tab[d[(2*i)+1].pierwsza].first)) d[i].uu = 1;
    if((tab[d[2*i].ostatnia].second<=tab[d[(2*i)+1].pierwsza].second)) d[i].dd = 1;
    if((tab[d[2*i].ostatnia].first<=tab[d[(2*i)+1].pierwsza].second)) d[i].ud = 1;
    if((tab[d[2*i].ostatnia].second<=tab[d[(2*i)+1].pierwsza].first)) d[i].du = 1;	
}

bool aktualizacja(int i,int x){
		i=i/2;
		pary(i);
		rek(i/2);	
}

bool czydziala(){
	if(d[1].uu==1 || d[1].dd==1 || d[1].du==1 || d[1].ud==1) return true;
	else return false; 
}

int main(){
	int z;
	cin >> z;
	while(z--){
		int a;
		cin >> a;
		
		tab[0].first=2000000000;
		tab[0].second=tab[0].first;
		for(int i=1;i<=a;i++){
			cin >> tab[i].first;
			cin >> tab[i].second;
		}
		
		int x=1;
        while(x<a)x*=2;
		
		zrobdrzewo(a,x);
		
		int m;
		cin >> m;
		while(m--){
			int c,e;
			cin >> c >> e;
		  int potrzebny = d[x+c-1].pierwsza;
                      int p2 = d[x+c-1].ostatnia;
                      d[x+c-1].pierwsza = d[x+e-1].pierwsza;
                      d[x+c-1].ostatnia = d[x+e-1].ostatnia;

                      d[x+e-1].pierwsza = potrzebny;
                      d[x+e-1].ostatnia = p2;
			
			aktualizacja(x+c-1,x);
			aktualizacja(x+e-1,x);
			
			if(czydziala()) cout << "TAK" << endl;
			else cout << "NIE" << endl;
		}
		
	}

}
