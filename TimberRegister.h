#ifndef TIMBER_REGISTER_H
#define TIMBER_REGISTER_H
#include "Timber.h"

class TimberRegister
{
private:
  string title;
  int nrOfLogs;
  int arrCap;
  Timber* *timbers;

  //Hjälpfunktioner
  void expand();
  void initiate(int from = 0);

public:
  //Pisskonstruktor
  TimberRegister(string title = "-");
  //PissCopyKonstruktor
  TimberRegister(const TimberRegister &origObj);
  //PissDestruktor
  ~TimberRegister();

  //Funktioner som hanterar timber objekt.
  bool addTimber(string dimension, int meters, double cost);
  bool removeTimber(string dimension); // int meters, float cost
  bool existsTimber(string dimension)const;
  int searchTimber(string dimension)const;
  TimberRegister operator=(const TimberRegister &origObj);
  //Funktioner som hanterar information om objekten.
  int getNrOfTimbers()const;
  void copyToArray(string arr[])const;
  double displayTotalPrice()const;
  bool setTimberInfo(string dimension, int meters, double price);
  //void cockwomble(string dimension, int meters, float cost);

  //Läsa & Skriva från/till fil
  void readFromFile(string fileName);
  void saveToFile(string fileName)const;

};

#endif
