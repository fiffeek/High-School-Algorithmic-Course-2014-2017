#include <iostream>
#include <vector>

using namespace std;

int preorder[100005];
int inorder[100005];
vector <int> postorder;

void f(int liczba, int start, int koniec, int g,int punktg){
	
	//cout << liczba << " " << start << " " << koniec << endl;
	
	if(start>koniec) return;
	if(start==koniec){
		postorder.push_back(inorder[start]);
		return;
	}
	
	//cout << "kupaa" << endl;
	
		int a=start;
		int b=koniec;
		
		//cout << start << " " << koniec << endl;
		
		int odpowiedz=0;
		
		while(a!=b){
			if(inorder[a]==liczba){
				odpowiedz=a;
				goto k;
			}
			
			if(inorder[b]==liczba){
				odpowiedz=b;
				goto k;
			}
			a++;
			b--;
		}
		//	cout << a << " " << b << endl;
		if(a==b) odpowiedz = a;
		k:
		postorder.push_back(inorder[odpowiedz]);
		//cout << inorder[odpowiedz]  << " " << liczba << "wtf" << endl;
		
		//cout << "to ODP " << odpowiedz << endl;
		//cout << odpowiedz + 1 << endl;
		//prawy
		f(preorder[punktg+odpowiedz - start +1],odpowiedz+1,koniec,g,punktg+odpowiedz-start+1);
		//lewy
		f(preorder[punktg+1],start,odpowiedz-1,g,punktg+1);

}

int main(){
	int z;
	cin >> z;
	while(z--){
		postorder.clear();
		int a;
		cin >> a;
		
		for(int i=0;i<a;i++){
			cin >> preorder[i];
		}
		
		for(int i=0;i<a;i++){
			cin >> inorder[i];
		}
		
		f(preorder[0],0,a-1,0,0);
		
		for(int j=postorder.size();j>0;j--){
			cout << postorder[j-1] << " ";
		}
		cout << endl;
		
	}
}
