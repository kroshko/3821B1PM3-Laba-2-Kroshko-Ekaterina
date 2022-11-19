#include<iostream>
#include "vector.h"
#include "metrix.h"
int main() {
  int n = 3;
  TDynamicVector<int>a(n);
  for (int i = 0; i < n; i++)
    a[i] = i + 1;
  TDynamicVector<int>b = a;
  TDynamicVector<int>c;
  c = a + b;
  std::cout << c;
  /* for(auto i=c.begin(); i!=c.end(); ++i)
     std::cout << *i;
  TDynamicMatrix<int> a(5), b(5), c(5);
  int i, j;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++)
    {
      a[i][j] = i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
  TDynamicVector<int> v(5), f(5);
  for (int i = 0; i < 5; i++) {
    v[i] = i;
    f[i] = -i;
  }
  cout << v;
  cout << a * v;
  cout << a * b;
  cout << a * 100 - b;
*/
}
