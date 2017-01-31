#include "Timber.h"

Timber::Timber(string title, int meters, float price)
{
  this->dimension = title;
  this->meters = meters;
  this->price = price;
}

Timber::~Timber()
{

}

void Timber::setDimension(string dimension)
{
  this->dimension = dimension;
}

void Timber::setMeters(int meters)
{
  this->meters = meters;
}

void Timber::setPrice(float price)
{
  this->price = price;
}

string Timber::getDimension()const
{
  return this->dimension;
}

int Timber::getMeters()const
{
  return this->meters;
}

float Timber::getPrice()const
{
  return this->price;
}

string Timber::toString()const
{
  string text="";
  text += "Dimension: ";
  text += this->dimension;
  text += ". Meters available: ";
  text += to_string(this->meters);
  text += ". Price per meter: ";
  text += to_string(this->price);
  text += "\n";

  return text;
}

bool Timber::operator==(Timber compTimb)const
{
  bool equals = false;

  if (this->dimension == compTimb.dimension)
  {
    equals = true;
  }
  return equals;
}
