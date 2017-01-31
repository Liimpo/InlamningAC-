#include "TimberRegister.h"
#include <iostream>
#include <iomanip>
int main()
{
  TimberRegister t1("Lager");
  t1.addTimber("24x200", 240, 10.5);
  t1.addTimber("33x100", 100, 25.3);
  t1.addTimber("33x150", 30, 25.3);
  t1.addTimber("33x100", 100, 25.3);
  t1.addTimber("33x100", 100, 25.3);
  int nrOf = t1.getNrOfTimbers();
  string *test = new string[nrOf];
  t1.copyToArray(test, nrOf);
  for (int i = 0; i < nrOf; i++)
  {
    cout << test[i] << endl;
  }

  delete [] test;
  return 0;
}
