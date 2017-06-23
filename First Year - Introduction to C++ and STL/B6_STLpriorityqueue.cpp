#include <iostream>
#include <queue>
using namespace std;

int main(){

int licznik;
cin >> licznik;

while(licznik--){
int liczba;
cin >> liczba;

priority_queue<int> kolejka;

for(int i=0;i<liczba;i++){
	int taka;
	cin >> taka;
	kolejka.push(-taka);
}

int sumawszystkich=0;

while(kolejka.size()!=1){
	int pierwsza = (-1)*(kolejka.top());
	kolejka.pop();
	int druga = (-1)*(kolejka.top());
	kolejka.pop();

	kolejka.push(-(pierwsza+druga));
	
	sumawszystkich+=pierwsza+druga;
}

cout << sumawszystkich << endl;
}
}
