#include <iostream>
#include <stack>

using namespace std;
int wynik[1000][1000];

int main(){
	int l;
	cin >> l;
	while(l--){		
	stack <char> S;
	int a,b;
	cin >> a >> b;

	
	for(int i=0;i<b;i++){
		for(int j=0;j<a;j++){
			int liczba;
			cin >> liczba;
			
			int spr,spr2;
			
			if(i-1>=0) spr=wynik[i-1][j];
			else spr=0;
			
			if(j-1>=0) spr2=wynik[i][j-1];
			else spr2=0;
						
			wynik[i][j]= liczba + max(spr,spr2)	;
		}
		
	}
	
	int i=b-1;
	int j=a-1;
while(i!=0 && j!=0){
	if(wynik[i-1][j] > wynik[i][j-1] ){
		S.push('v');
		i--;
	} 
	else{
		S.push('>');
		j--;	
	} 
}
	if(i==0){
		while(j!=0){
			S.push('>');
			j--;
		}
	}
	
	if(j==0){
		while(i!=0){
			S.push('v');
			i--;		
		}
	}
	
	cout << wynik[b-1][a-1] << " ";
	while(!S.empty()){
		cout << S.top();
		S.pop();
	}
	cout << endl;
	
}
}
	

