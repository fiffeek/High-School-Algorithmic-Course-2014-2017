#include <iostream>

using namespace std;

pair < int,int > maxz[10005],maxbz[10005];
string glob;
	
void rek(int i){
	
	int a = glob[i] - '0';
	
	//cout << i << " to i" << endl;
		
	if(a==0){
		maxz[i].first = 1;
		maxz[i].second = 1;		
		maxbz[i].first = 0;
		maxbz[i].second = 0;
		return;
	}
	if(a==1){
		rek(i+1);
		
		if(maxz[i+1].second!=1){
			maxz[i].first = maxz[i+1].first + 1;
			maxz[i].second = 1;
		}else{
			maxz[i].first = maxz[i+1].first;
			maxz[i].second = 0;
		}
		
		maxbz[i].first = maxbz[i+1].first + 0;
		maxbz[i].second = 0;
		
	}
	if(a==2){
		rek(i+1);
		
		int p=0;
		for(int j=i+1;j<glob.length();j++){
			if(maxz[j].first==-1){
				p=j;
				break;
			}
		}
				
		rek(p);
		//cout << i+1 << " " << p << endl;
		//cout << maxz[i].second << " " << maxbz[i].second << endl;
		//cout << maxz[p].second << " " << maxbz[p].second << endl;
		
		if(maxz[i+1].second == 0 && maxz[p].second == 0){
			maxz[i].first = maxz[i+1].first + 1 + maxz[p].first;
			maxz[i].second = 1;
		}else if(maxz[i+1].second == 1 && maxz[p].second == 1){
			maxz[i].first = maxz[i+1].first + maxz[p].first - 1;
			maxz[i].second = 0;
		} else{
			maxz[i].first = maxz[i+1].first + maxz[p].first;
			maxz[i].second = 0;
		}
		
		if(maxbz[i+1].second == 0 && maxbz[p].second == 0){
			maxbz[i].first = maxbz[i+1].first + 1 + maxbz[p].first;
			maxbz[i].second = 1;
		}else if(maxbz[i+1].second == 1 && maxbz[p].second == 1){
			maxbz[i].first = maxbz[i+1].first + maxbz[p].first;
			maxbz[i].second = 0;
		}else {
			maxbz[i].first = maxbz[i+1].first + maxbz[p].first;
			maxbz[i].second = 0;
		}
	}	
}


int main(){
	int z;
	cin >> z;
	
	while(z--){
	
		cin >> glob;
		
		for(int i=0;i<glob.length()+3;i++){
			maxz[i].first=-1;
			maxz[i].second=0;
			maxbz[i].first=-1;
			maxbz[i].second=0;
		}
		
		int i=0;
		rek(i);
		
		/*	for(int i=glob.length()-1;i>=0;i--){
			cout << maxz[i].first << " ";
		}
		cout << endl;
		
			for(int i=glob.length()-1;i>=0;i--){
			cout << maxbz[i].first << " ";
		}
		cout << endl;
		*/
		cout << max(maxz[0].first,maxbz[0].first) << " ";
		cout << min(maxz[0].first,maxbz[0].first) << endl;
		//cout << maxbz[3].second << " " << maxbz[6].second << " " << maxbz[2].second << endl;
	}
	
}
