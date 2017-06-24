#include <iostream>
#include <set>

using namespace std;

set <long long> S;
long long prep[2005];


int main(){
	//prep
	prep[0] = 0;
	prep[1] = 0;
	prep[2] = 2;
//	cout << prep[0] << " " << prep[1] << " " << prep[2] <<" ";
	for(long long i=3;i<=2005;i++){
			S.clear();
			
			for(long long j = 0;j<=i-2;j++){
				if(j==i-2){
					S.insert(prep[j]);
					//cout << "DODAWANE4 " << prep[j] << endl; 
				}else{
					if(i-j-2 >= 0 && j!=0) S.insert(prep[j]^prep[i-j-2]);
					//if(i-j-2 >= 0 && j!=0) cout << "DODAWANE " << (prep[j]^prep[i-j-2]) << endl;
				}
			}
			
			for(long long j=0;j<i;j++){
				if(j==0){
					S.insert(1^prep[i-1]);
					//cout << "DODAWANE3 " << (1^prep[i-1]) << endl;
				}else{
					 if(i-j-1>=0) S.insert(1^prep[j]^prep[i-j-1]);
					 //if(i-j-1>=0) cout << "DODAWANE2 " << (1^prep[j]^prep[i-j-1]) << endl;
				}
				
			}
			
			for(long long k=0;k<=2005;k++){
				if(S.count(k)==0){
					prep[i] = k;
					break;
				} 
			}
			
		//	cout << prep[i] << " ";
		}
	//	cout << endl;
	
	long long z;
	cin >> z;
	while(z--){
		//long long a,b;
		long long n,m;
		cin >> n >> m;
		
		long long xort = 0;
		
		for(long long i=0;i<n;i+=2){
			string a,b;
			cin >> a >> b;
			
			long long odl = 0;
			for(long long j=0;j<m;j++){
				if(a[j]!='1' && b[j]!='1') odl++;
				else if(a[j]=='1' && b[j]=='1'){
					 xort = xort ^ prep[odl];
					 odl = 0;
				}
				else{
					xort = xort ^ prep[odl];
					xort = xort ^ 1;
					odl = 0;
				}			
			}
			xort = xort ^ prep[odl];
		}
		
		if(xort == 0) cout << "TAK" << endl;
		else cout << "NIE" << endl;
		
	}
}
