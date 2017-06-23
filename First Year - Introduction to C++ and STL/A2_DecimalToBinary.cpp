#include <iostream>
using namespace std;

//FilipMikina
//FirstYear
//DecimalToBinary

int main(){
	
	unsigned long long int a;
	int i=0,r;
	cin >>r;
	string b;
	
	for(int o=0;o<r;o++){
	
		cin >> a;
		if(a==0) cout << 0;
		while(a!=0){
		
		      if(a%2==0) b='0'+b;
		      else b='1'+b;
		
		      a=(a/2);
		}
		
		cout << b << endl;
		b="";
	
	}

}
