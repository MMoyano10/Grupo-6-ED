#include <iostream>
using namespace std;


int gcd (int a, int b, int c) 
{
  int maxi = 0;
  
  maxi = max(a, max(b, c));
  
  for(int i = maxi; i>1; i--)
  {
      if(( a%i == 0 ) and ( b%i == 0 ) and ( c%i == 0 ))
      {
          return i;
          break;
      }
  }
  
  return 1;
}

int main(int argc, char** argv) {
  int a, b, c;
  cout<<"Ingrese los numeros :";
  cin >> a >> b >> c;
  cout << "GCD DE" << a << ", " << b << " and " << c << " is " << gcd (a, b, c);
  
  return 0;
}


