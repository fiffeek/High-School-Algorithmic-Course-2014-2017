#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//FilipMikina
//FirstYear
//EuclideanAlgorithm

int liczenie;
string dzielenie(string a)
{
      int licznik=a.length();
      for(int i=licznik;i>-1;i--)
      {
              if(a[i]%2==1)
              {
                      int gaude=a[i+1]-'0';
                      gaude=gaude+5;
                      a[i+1]=gaude+'0';
              }
                      int gaude=a[i]-'0';
                      gaude=gaude/2;
                      a[i]=gaude+'0';
      }

        if(a[0]=='0')
      a.erase(0,1);

 return a;
}

unsigned long long konwersja(string a)
{
      string str = a;
unsigned long long i = atoi(str.c_str());
return i;
}

unsigned long long euklides(unsigned long long a, unsigned long long b)
{
if(a == 0) return b;
if(b == 0) return a;
if(a == b) return a;
if(a>b) return euklides(a % b, b);
if(b>a) return euklides(a, b % a);
}

string odejmowanie(string a,string b)
{
      int licznik = 0;
      int dlugosc=a.length();
      int dlugosc2=b.length();
      int gaude = dlugosc - dlugosc2;
      int licznik3=0;
      for (int i=dlugosc-1;i>-1;i--)
        {
              int suma = licznik;
              licznik = 0;
              if (i>=gaude) suma -=b[i-gaude]-'0';
              suma += (a[i]-'0');

              if (suma < 0)
                        {
                      licznik = -1;
                      suma +=10;
              }
              a[i]=suma+'0';


               if (suma==0)
                        {
                        if (licznik3==0)
                        licznik3=i+1;
              }
                        else licznik3=0;

    }
      dlugosc=a.length();
        a.erase(0, licznik3);
      return a;
}

string dodawanie(string a)
{
      string c=a;
      int kam=0;
      int dlugosc=a.length()-1;
      for(int i=dlugosc;i>-1;i--)
      {
              kam=0;
              int gaude=a[i]-'0';
              int gaude1=c[i]-'0';
              if(gaude+gaude1<10)
              a[i]=gaude+gaude1+'0';
              else
              {
                      kam=kam+1;
                      if(i==0) kam=kam+1;
                      int licznik= gaude+gaude1-10;
                      a[i]=licznik+'0';
                      int licznik2=c[i-1]-47;
                      c[i-1]=licznik2+'0';
              }
      }
        if (kam>1)
        a = '1' + a;
return a;
}

bool sprawdzanie(string a, string b)
{
        int p1=a.length();
      int p2=b.length();
      if(p1>p2) return true;
      if(p2>p1) return false;
      for(int i=0;i<p2-1;i++)
      {
              int gaude=a[i];
              int gaude1=b[i];
        if(gaude>gaude1) return true;
        if(gaude1>gaude) return false;
      }
}

string nwd(string a, string b)
{
      int dlugosc = a.length();
    int dlugosc2 = b.length();

      while ((a[dlugosc-1]!='0' || dlugosc>1) && (b[dlugosc2-1]!='0' || dlugosc2>1))
      {

              if(a==b) return a;
          else if ((dlugosc == 1 && a[0] == '0') || dlugosc == 0) return b;
              else if ((dlugosc2 == 1 && b[0] == '0') || dlugosc2 == 0) return a;
              else if ((dlugosc == 1 && a[0] == '1') || (dlugosc2 == 1 && b[0] == '1')) return "1";
              else if(a[dlugosc-1]%2==0 && b[dlugosc2-1]%2 ==0)
              {
                      liczenie++;
                      a=dzielenie(a);
                      b=dzielenie(b);
              }
              else if(a[dlugosc-1]%2==0 && b[dlugosc2-1]%2 ==1) a=dzielenie(a);
              else if(a[dlugosc-1]%2==1 && b[dlugosc2-1]%2 ==0) b=dzielenie(b);
              else if(a[dlugosc-1]%2==1 && b[dlugosc2-1]%2 ==1)
              {
                      if(sprawdzanie(a,b)) a=odejmowanie(a,b);
                      else b=odejmowanie(b,a);

              }
               dlugosc = a.length();
           dlugosc2 = b.length();
      }
      if ((a.length() == 1) && (a[0] == '0')) return b;
    else return a;
}



int main()
{
      int rr;
      cin >> rr;
      for(int i=0;i<rr;i++)
      {
      string a,b;
      cin >> a >> b;
      liczenie=0;
      if(a.length()<10 && b.length()<10)
      {
      unsigned long long all = konwersja(a);
      unsigned long long bll = konwersja(b);
      cout << euklides(all,bll) << endl;

      }
      else
      {
       a=nwd(a,b);
      for (int i=0;i<liczenie;i++)
    a=dodawanie(a);
    cout << a << endl;

      }

}
}
