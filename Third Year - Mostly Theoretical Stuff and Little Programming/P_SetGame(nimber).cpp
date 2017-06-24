#include <iostream>
#include <set>

using namespace std;

int l[1005];
int prep[1005];
set <int> S;

int main(){
	
		prep[0] = 0;
		prep[1] = 1;
		prep[2] = 2;
		//cout << prep[0] << " " << prep[1] << " " << prep[2] << " ";
		for(int i=3;i<=1000;i++){
			S.clear();
			for(int j = 0;j<i;j++){
				//suuwamy1,2,3
				
				//1
				if(i-j-1 > 0) S.insert(prep[j]^prep[(i-j-1)]);
				if(i -j - 2 > 0) S.insert(prep[j]^prep[(i-j-2)]);
				if(i-j-3 > 0) S.insert(prep[j]^prep[(i-j-3)]);
			}
			
			for(int k=0;k<=1000;k++){
				if(S.count(k)==0){
					prep[i] = k;
					break;
				} 
			}
			
			//cout << prep[i] << " ";
		}
	
	
	
	int z;
	cin >> z;
	while(z--){
		int n; cin >> n;
		for(int i=0;i<n;i++){
			cin >> l[i];
		}

		int xorl = prep[l[0]];
		for(int i=1;i<n;i++){
			 xorl = xorl ^ prep[l[i]];
		}
		
		if(xorl == 0) cout << "B" << endl;
		else cout << "A" << endl;
	}
}
