#include <iostream>
using namespace std;

//FilipMikina
//FirstYear
//Fibonacci

int main()
{
	int a,b,c,n,r;
	cin>>r;
	
	
	for(int e=0;e<r;e++){
		a=0;
		b=1;
		cin >> n;
		
		for(int i=2;i<=n;i++){
			c=(a+b)%n;
			a=b;
			b=c;
		}
		
		if(n==1)c=0;
		if(n==0)c=0;
		
		cout << c << endl;
	
	}
}
