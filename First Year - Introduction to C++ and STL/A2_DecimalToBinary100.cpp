#include <iostream>
using namespace std;

//FilipMikina
//FirstYear
//DecimalToBinary

int main(){
	
	int r;
	cin >> r;
	
	for(int y=0;y<r;y++){
	
		string a,c,d;
		cin >> a;
		d=a;
		
		if(a.length()==1){
			if(a[0]=='1'){
			cout << "1" << endl;
			}
		}
		
		if(a[0]=='0') cout << "0" << endl;
		
		int v=(a.length()-1);
		int g=0,t=0;
		
		if(a[v]%2==0) c='0' + c;
		else c='1' + c;
		
		do{
			g=0;
			for(int t=0;t<v;t++) if(d[t]=='0') g++;
			
			for(int i=v;i>-1;i--){
			    int b=static_cast<int>(d[i]);
			    b=b-48;
			    if(b%2==1) d[i+1] = d[i+1] + 5;
			    b=b/2;
			
				if(b==0) d[i]='0';
				if(b==1) d[i]='1';
				if(b==2) d[i]='2';
				if(b==3) d[i]='3';
				if(b==4) d[i]='4';
				if(b==5) d[i]='5';
				if(b==6) d[i]='6';
				if(b==7) d[i]='7';
				if(b==8) d[i]='8';
				if(b==9) d[i]='9';

			}
			
			if(d[v]%2==0) c='0' + c;
			else c='1' + c;
		
		}while(g<v);
		
		if(d[v]== '2' || d[v]== '3') cout << "1" << c << endl;
		if( d[v]== '4') cout << "10" << c << endl;
		if(d[v]=='1' ) cout << c << endl;		
	}

}
