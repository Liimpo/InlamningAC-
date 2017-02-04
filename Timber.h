#ifndef TIMBER_H
#define TIMBER_H
#include <string>

using namespace std;

class Timber
{
private:
  // Dimensionsmått
  string dimension;
  int meters; //Antal meter @ lager
  double price; //Kostnad per löpmeter
public:
  //Konstruktor
  Timber(string title ="-", int meters=0, double price = 0);
  //Dekonstruktor
  ~Timber();

  //Set-funktioner
  void setDimension(string dimension);
  void setMeters(int meters);
  void setPrice(double price);

  //Get-funktioner
  string getDimension()const;
  int getMeters()const;
  double getPrice()const;

  string toString()const;

  //Operatorer
  bool operator==(Timber compTimb)const;
};

#endif
