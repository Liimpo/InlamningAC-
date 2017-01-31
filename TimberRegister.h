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
  //PissDestruktor
  ~TimberRegister();

  //Funktioner som hanterar timber objekt.
  bool addTimber(string dimension, int meters, float cost);
  bool removeTimber(string dimension); // int meters, float cost
  bool existsTimber(string dimension)const;
  int searchTimber(string dimension)const;
  //Funktioner som hanterar information om objekten.
  int getNrOfTimbers()const;
  void copyToArray(string arr[], int nrs)const;
  //Ändrar värden i timmerobjekten.
  //void cockwomble(string dimension, int meters, float cost);

  //Läsa & Skriva från/till fil
  void readFromFile();
  void saveToFile()const;

};

#endif
