#include "TimberRegister.h"

TimberRegister::TimberRegister(string title)
{
  this->title = title;
  this->nrOfLogs = 0;
  this->arrCap = 3;
  this->timbers = new Timber*[this->arrCap];
  this->initiate(0);
}

TimberRegister::~TimberRegister()
{
  for (int i = 0; i < this->nrOfLogs; i++)
  {
    delete this->timbers[i];
  }
  delete [] this->timbers;
}

void TimberRegister::initiate(int from)
{
  for (int i = from; i < this->arrCap; i++)
  {
    this->timbers[i] = nullptr;
  }
}

void TimberRegister::expand()
{
  Timber* *temp = new Timber*[this->arrCap];

  for (int i = 0; i < this->nrOfLogs; i++)
  {
    temp[i] = this->timbers[i];
  }
  delete [] this->timbers;
  // Riktar om pekaren.
  this->timbers = temp;
  //Initierar resterande platser i arrayen med nullpekare.
  this->initiate(this->nrOfLogs);
}

int TimberRegister::getNrOfTimbers()const
{
  return this->nrOfLogs;
}

int TimberRegister::searchTimber(string dimension)const
{
  int index = -1;
  bool found = false;
  Timber temp(dimension);
  for (int i = 0; i < this->nrOfLogs && !found; i++)
  {
    if (*this->timbers[i] == temp)
    {
      index = i;
      found = true;
    }
  }
  return index;
}

bool TimberRegister::existsTimber(string dimension)const
{
  bool found = false;
  if (this->searchTimber(dimension) > -1)
  {
      found = true;
  }
  return found;
}

bool TimberRegister::addTimber(string dimension, int meters, float cost)
{
  bool isTimber = false;
  if (this->existsTimber(dimension) == false)
  {
    if (this->nrOfLogs >= this->arrCap)
    {
      this->expand();
      this->timbers[this->nrOfLogs++] = new Timber(dimension, meters, cost);
      isTimber = true;
    }
    else
    {
      this->timbers[this->nrOfLogs++] = new Timber(dimension, meters, cost);
      isTimber = true;
    }
  }
  return isTimber;
}

bool TimberRegister::removeTimber(string dimension)
{
  bool removed = false;
  int yolo = this->searchTimber(dimension);
  if (yolo > - 1)
  {
    delete this->timbers[yolo];
    this->timbers[yolo] = this->timbers[--this->nrOfLogs];
    removed = true;
  }
  return removed;
}

void TimberRegister::copyToArray(string arr[], int nrs)const
{
  for (int i = 0; i < nrs; i++)
  {
    arr[i] = this->timbers[i]->toString();
  }
}
/*void TimberRegister::cockwomble(string dimension, int meters, float cost)
{

}
*/
