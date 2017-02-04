#include "TimberRegister.h"
#include <iostream>
#include <fstream>

TimberRegister::TimberRegister(string title)
{
  this->title = title;
  this->nrOfLogs = 0;
  this->arrCap = 2;
  this->timbers = new Timber*[this->arrCap];
  this->initiate(0);
}

TimberRegister::TimberRegister(const TimberRegister &origObj)
{
	this->title = origObj.title;
	this->nrOfLogs = origObj.nrOfLogs;
	this->arrCap = origObj.arrCap;
	this->timbers = new Timber*[origObj.arrCap];
	for (int i = 0; i < origObj.nrOfLogs; i++)
	{
		this->timbers[i] = new Timber(*origObj.timbers[i]);
	}
	this->initiate(origObj.nrOfLogs);
}

TimberRegister TimberRegister::operator=(const TimberRegister &origObj)
{
	for (int i = 0; i < this->nrOfLogs; i++)
	{
		delete this->timbers[i];
	}
	delete[] this->timbers;

	this->title = origObj.title;
	this->nrOfLogs = origObj.nrOfLogs;
	this->arrCap = origObj.arrCap;
	this->timbers = new Timber*[origObj.arrCap];
	for (int i = 0; i < origObj.nrOfLogs; i++)
	{
		this->timbers[i] = new Timber(*origObj.timbers[i]);
	}

	return *this;
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
	this->arrCap *= 2;
	Timber* *temp = new Timber*[this->arrCap];

  for (int i = 0; i < this->nrOfLogs; i++)
  {
    temp[i] = this->timbers[i];
  }
  cout << "Yes!";
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
  cout << endl << "Yes!";
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

bool TimberRegister::addTimber(string dimension, int meters, double cost)
{
  bool isTimber = false;
  if (this->existsTimber(dimension) == false)
  {
    if (this->nrOfLogs >= this->arrCap)
    {
      this->expand();
      this->timbers[this->nrOfLogs++] = new Timber(dimension, meters, cost);
	  cout << endl << this->nrOfLogs;
      isTimber = true;
    }
    else
    {
      this->timbers[this->nrOfLogs++] = new Timber(dimension, meters, cost);
	  cout << endl << this->nrOfLogs;
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

void TimberRegister::copyToArray(string arr[])const
{
  for (int i = 0; i < this->nrOfLogs; i++)
  {
    arr[i] = this->timbers[i]->toString();
  }
}
double TimberRegister::displayTotalPrice()const
{
	double tempTot = 0;
	for (int i = 0; i < this->nrOfLogs; i++)
	{
		tempTot += this->timbers[i]->getPrice();
	}
	return tempTot;
}
bool TimberRegister::setTimberInfo(string dimension, int meters, double price)
{
	bool found = false;
	int posOfTimber = this->searchTimber(dimension);
	if (posOfTimber > -1)
	{
		this->timbers[posOfTimber]->setMeters(meters);
		this->timbers[posOfTimber]->setPrice(price);
		found = true;
	}
	return found;
}
void TimberRegister::saveToFile(string fileName)const
{
	ofstream outputFile(fileName);
	outputFile << this->getNrOfTimbers() << endl;
	for (int i = 0; i < this->nrOfLogs; i++)
	{
		outputFile << this->timbers[i]->getDimension() << endl;
		outputFile << this->timbers[i]->getMeters() << endl;
		outputFile << this->timbers[i]->getPrice() << endl;
	}
	outputFile.close();
}

void TimberRegister::readFromFile(string fileName)
{
	ifstream inputFile(fileName);
	//temp variabler för att läsa in.
	string tempDim = "";
	string strTmp= "";
	int tempMeters = 0;
	double tempPrice = 0;
	int tempSize = 0;

	//Läser in första raden för att sätta en arrCap.
	getline(inputFile, tempDim);
	tempSize = stoi(tempDim, nullptr, 0);
	for (int i = 0; i < tempSize; i++)
	{
		getline(inputFile, tempDim);
		getline(inputFile, strTmp);
		tempMeters = stoi(strTmp, nullptr, 0);
		getline(inputFile, strTmp);
		tempPrice = stoi(strTmp, nullptr, 0);

		//Lägger till i arrayen.
		this->addTimber(tempDim, tempMeters, tempPrice);
		cout << endl << this->nrOfLogs << endl;
		cout << this->arrCap << endl;
		cin.get();
	}
	inputFile.close();
}
