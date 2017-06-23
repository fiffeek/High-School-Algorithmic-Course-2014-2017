#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <iomanip>
#include <string>

using namespace std;

unsigned long long koszt[205];
vector <pair <int, int> > G[205];
map<string, int> miasto;
map<int , string> miasto2;

struct ps{
      int p,c;
};

struct cs{
      bool operator()(ps a,ps b){
              return a.p>b.p;
      }
};

int dij(int pocz,int kon){
	//cout << "dijjj" << endl;
			  for(int j=0;j<=kon;j++){
                      koszt[j] = 1844674407370955161;
                      //G[j].clear();
              }

              koszt[pocz] = 0;

              ps para;
              para.p = koszt[pocz];
              para.c = pocz;

              priority_queue <ps, vector<ps>, cs > Q;

              Q.push(para);

              while(Q.empty()==false){
                      int w = Q.top().c;
                      Q.pop();
						//cout << "to na kolejce " << w << endl;
						//cout << "SIZE " << G[w].size() << endl;
                      for(int j=0;j<G[w].size();j++){
										//cout << koszt[G[w][j].first] << endl;
                                      if(koszt[G[w][j].first]> koszt[w] + G[w][j].second){
                                              koszt[G[w][j].first] = koszt[w] + G[w][j].second;

                                              ps para;
                                              para.p = koszt[G[w][j].first];
                                              para.c = G[w][j].first;
                                              Q.push(para);

                                      }

                      }

              }
              //cout << kon << endl;
              cout << setw(12) << right << miasto2[pocz];
              for(int j=0;j<kon;j++) cout << setw(12) << right << koszt[j];
              
              cout << endl;

              
}

int main(){
      ios_base::sync_with_stdio(0);
      int z;
      cin >> z;
      while(z--){
              int a,b;
              cin >> a;
              
           miasto.clear();
           miasto2.clear();
             
             for(int j=0;j<=a;j++){
                      //koszt[j] = 1844674407370955161;
                      G[j].clear();
              }
             
             for(int i=0;i<a;i++){
             	 string y;
             	 cin >> y;
				 miasto[y] = i;
				 miasto2[i] = y;
				 //cout << y << " " << i << endl;
			 }
			 
			 cin >> b;

             

              for(int j=0;j<b;j++){
                      string temp,temp2;
					  int k;
                      cin >> temp >> temp2 >> k;
                      
                      
                      pair <int , int > P;
                      P.first = miasto[temp2];
                      //cout << miasto[temp] << endl;
                      P.second = k;
                      G[miasto[temp]].push_back(P);
                      P.first = miasto[temp];
                      G[miasto[temp2]].push_back(P);
              }
              
              cout << "            ";
              for(int i=0;i<a;i++) cout << setw(12) << right << miasto2[i];
              cout << endl;
              for(int i=0;i<a;i++) dij(i,a);
              

      }

}
