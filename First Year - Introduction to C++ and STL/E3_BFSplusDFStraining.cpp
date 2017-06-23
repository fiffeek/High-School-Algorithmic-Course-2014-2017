#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

long long koszt[505];
vector <pair <long long, long long> > G[505];
bool visited[505];

void dfsczy(int a){
	visited[a] = 1;
	
	for(int j=0;j<G[a].size();j++){
		if(visited[G[a][j].first]==0) dfsczy(G[a][j].first);
	}
	
}

/*struct ps{
	int p , c;
	
};*/


int main(){
      ios_base::sync_with_stdio(0);
      long long z;
      cin >> z;
      while(z--){
              long long a,b;
              cin >> a >> b;


              for(int j=1;j<=a;j++){
                      koszt[j] = 1844674407370955161;
                      G[j].clear();
                      visited[j] = 0;
              }

              for(int j=0;j<b;j++){
                      long long temp,temp2,k;
                      cin >> temp >> temp2 >> k;
                      pair <long long , long long > P;
                      P.first = temp2;
                      P.second = k;
                      G[temp].push_back(P);
              }
              
              int p , k;
              cin >> p >> k;			
			  koszt[p] = 0;	

			  bool wyjsc=0;
			 
			  	
			  /*stack <ps, vector <ps > > Q;
			  ps para;
			  para.p = 0;
			  para.c = p;
			  Q.push(para);*/
			
              for(int i=0;i<=a;i++){
              	
              		wyjsc = true;
              		//int p = Q.top().c;
              		//Q.pop();
              		for(int x=1;x<=a;x++){
              			//int x= Q.top().c;
              			//Q.pop();
	                      for(int j=0;j<G[x].size();j++){
	                      //	cout << p << " " << koszt[p]  << " " << G[p][j].second << " hije"<< endl;
											//cout << koszt[G[][j].first] << " " << koszt[p] + G[p][j].second << endl;
	                                      if(koszt[G[x][j].first] > koszt[x] + G[x][j].second){
	                                      //	cout << koszt[G[p][j].first] << " " << koszt[p] + G[p][j]
	                                      	//cout << "prr" << endl;
	                                      		  wyjsc = false;
	                                              koszt[G[x][j].first] = koszt[x] + G[x][j].second;
	                                             /* ps para;
	                                              para.p = koszt[G[p][j].first];
	                                              para.c = G[p][j].first;
	                                              Q.push(para);*/
	                                      }
	
	                      }
					}
					
					if(wyjsc == true) goto k;
              }
			  k:
			  	//cout << wyjsc << endl;
			  for(int j=1;j<=a;j++){
			  		for(int p=0;p<G[j].size();p++){
			  			if(koszt[G[j][p].first] > koszt[j] + G[j][p].second){
			  				cout << "Luka w systemie bankowym!" << endl;
			  				goto koniec;
					  }
			 	 }
			  }	
			  
			  dfsczy(p);
			  if(visited[k]==0) cout << "Bank niedostepny!" << endl;
              else cout << "Minimalny koszt: " << koszt[k] << endl;	
              koniec:;
              	
		 	}

}                       
					         
						 	
						 
							
							
							
							
							
						
																	           														    
