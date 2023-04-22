#include "Clothes.h"

float Clothes::GetPrice()
{
	return price;
}
string Clothes::GetName() {
	return name;
}

int Clothes::GetStock()
{
	return stock;
}

float Clothes::GetMultiplier() {
	return multiplier;
}

void Clothes::SetPrice(float newPrice)
{
	price = newPrice * GetMultiplier();
}

void Clothes::UpdateStock(int unitsSelled)
{
	stock -= unitsSelled;
}
