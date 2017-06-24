#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

pair <int, int> Pary[3000005];
list <int> Wierzcholki;
int spojne = 1;
vector <int> V;
queue <int> Q;


void bfs(int a, int p){
      while(Q.empty()==0) Q.pop();
      Q.push(a);
      
      while(Q.empty()==0){
      	int op = Q.front();
      	Q.pop();
      	
      	
      	for(list <int>::iterator  it = Wierzcholki.begin();it!=Wierzcholki.end();){
      		if(binary_search(Pary, Pary+p,make_pair(op, *it))==0 && op!=(*it)){
           
                      int pp = (*it);
                      list<int>::iterator tmp = it;
                      it++;
                      Wierzcholki.erase((tmp));
                      Q.push(pp);
                      spojne++;

              }
              else it++;
		}
      	
	  }    

}


int main(){
      int z;
      cin >> z;
      while(z--){
              int n,m;
              cin >> n >> m;

              int p = 0;
              for(int i=0;i<m;i++){
                      int a,b;
                      cin >> a >> b;

                      Pary[p].first=(a);
                      Pary[p].second=(b);
                      p++;


                      Pary[p].first=(b);
                      Pary[p].second=(a);
                      p++;

              }

              for(int i = 1;i<=n;i++) Wierzcholki.push_back(i);

              sort(Pary,Pary+p);
              //cout << "AAAA" << endl;
              //int pp=0;
              V.clear();
              while(Wierzcholki.empty()==0){
                      //cout << "A" << Wierzcholki.size()<< endl;
                      spojne = 1;
                      int it = *Wierzcholki.begin();
                      Wierzcholki.erase(Wierzcholki.begin());
                      bfs(it,p);
                      V.push_back(spojne);
                      //pp++;
              }
              //cout << "AAAAAAAAA" << endl;
              sort(V.begin(),V.end());

              for(int i=0;i<V.size();i++){
                      cout << V[i] << " ";
              }
              cout << endl;

      }
}

