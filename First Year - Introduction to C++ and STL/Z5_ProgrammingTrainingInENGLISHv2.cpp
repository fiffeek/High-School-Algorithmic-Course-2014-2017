#include <iostream>

using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int a;
        cin >> a;

        int odp = 1;

        for(int i=1;i<a;i++) odp=2*odp+1;

        cout << odp << endl;
    }
}
