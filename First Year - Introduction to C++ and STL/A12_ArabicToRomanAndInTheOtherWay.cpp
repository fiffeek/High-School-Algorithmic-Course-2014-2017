#include <iostream>
#include <cstdlib>
using namespace std;

//FilipMikina
//FirstYear
//ArabicToRoman
//RomanToArabic

bool czy(string a){
    if(a[0]-'0'>=0 && a[0] - '0' <10) return true;
    else return false;
}

unsigned long long dziesietny(string a){
    string str = a;
int i = atoi(str.c_str());

    if(i>1999){
    cout << "MM";
    i-=2000;
    }

    if(i>999){
    cout << "M";
    i-=1000;
    }

    if(i>899){
    cout << "CM";
    i-=900;
    }

    if(i>499){
    cout << "D";
    i-=500;
    }

    if(i>399){
    cout << "CD";
    i-=400;
    }

    while(i>99){
    cout << "C";
    i-=100;
    }

    if(i>89){
    cout << "XC";
    i-=90;
    }

    if(i>49){
    cout << "L";
    i-=50;
    }

    if(i>39){
    cout << "XL";
    i-=40;
    }

    while(i>9){
    cout << "X";
    i-=10;
    }

    if(i>8){
    cout << "IX";
    i-=9;
    }

    if(i==4){
    cout << "IV";
    i-=4;
    }

    if(i>4){
    cout << "V";
    i-=5;
    }

    while(i>0){
    cout << "I";
    i-=1;
    }
    cout << endl;
}

void rzymski(string a){
int licznik=0;
int dlugosc=a.length();
int ii=0;
while(ii<dlugosc){
    if(a[ii] == 'M' && a[1] == 'M'){
    licznik+=2000;
      ii=ii+2;
    }

 else  if(a[ii]== 'M'){
    licznik+=1000;
      ii=ii+1;
    }


 if(a[ii] == 'C' && a[ii+1] == 'M'){
    licznik+=900;
      ii=ii+2;
    }
else if(a[ii] == 'D'){
    licznik+=500;
      ii=ii+1;
    }
else if(a[ii] == 'C' && a[ii+1] == 'D'){
    licznik+=400;
      ii=ii+2;
    }
else  if(a[ii] == 'C'){
    licznik+=100;
      ii=ii+1;
    }
else if(a[ii] == 'X' && a[ii+1] == 'C'){
    licznik+=90;
      ii=ii+2;
    }
else if(a[ii] == 'L'){
    licznik+=50;
      ii=ii+1;
    }
else if(a[ii] == 'X' && a[ii+1] == 'L'){
    licznik+=40;
      ii=ii+2;
    }
else if(a[ii] == 'I' && a[ii+1] == 'X'){
licznik+=9;
  ii=ii+2;
}
else if(a[ii] == 'X'){
    licznik+=10;
        ii++;
    }
else if(a[ii] == 'V'){
    licznik+=5;
        ii++;
    }
else if(a[ii] == 'I' && a[ii+1] == 'V'){
    licznik+=4;
        ii=ii+2;
    }
else if(a[ii] == 'I'){
    licznik+=1;
        ii++;
    }

}
  cout << licznik << endl;
}

int main()
{
int rr;
cin >> rr;
for(int i=0;i<rr;i++)
{
string a;
cin >> a;

if(czy(a)) dziesietny(a);
else rzymski(a);
}
}
