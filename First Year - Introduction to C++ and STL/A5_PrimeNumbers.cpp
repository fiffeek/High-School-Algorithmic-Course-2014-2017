#include <iostream>
#include <cmath>
using namespace std;

//FilipMikina
//FirstYear
//PrimeNumbers


bool czy(int a, int g){
	g=0;
	
	for(int i=2;i*i<=a+1;i++){
		if(a%i==0) g++;
	}
	
	if(a==0) return true;
	else{
		if(g>0) return false;
		else return true;
	}
}

int main(){
	int a;
	cin >> a;
	int g=0;
	int c=a;
	
	
	
	for(int b=0;b<a;b++){
		if(c==1){
			cout << "1 green bottle standing on the wall." << endl;
			cout << "1 green bottle standing on the wall." << endl;
		}
		 else{
			 if(czy(c,g)) cout << "BUZZ";
			 else cout << c;
			 cout << " green bottles standing on the wall." << endl;
			 if(czy(c,g)) cout << "BUZZ";
			 else cout << c;
			 cout << " green bottles standing on the wall." << endl;
		}
			
			
			 cout << "and if one green bottle should accidentally fall," << endl;
			
			 c=c-1;
			 
			 cout << "there'd be ";
			 
			 if(c==0) cout << "no";
			 else{
				 if(c==1)
				 cout << 1;
				 else{
					 if(czy(c,g)) cout << "BUZZ";
					 else cout << c;
			 	}
			 }
			 if(c==1){
			 cout << " green bottle standing on the wall." << endl;
			 cout << endl;
			}
			else{
			 cout << " green bottles standing on the wall." << endl;
			 cout << endl;
		
			}
	}
}

