#include "Cotization.h"

Cotization::Cotization(string id, Clothes* clotheToCotiz, int unitQuantity, float price, string date)
{
	this->id = id;
	this->clotheToCotiz = clotheToCotiz;
	this->unitQuantity = unitQuantity;
	this->price = price;
	this->result = SetCotizationResult();
	this->date = date;
}

Cotization::~Cotization() {
	delete clotheToCotiz;
}

float Cotization::SetCotizationResult()
{
	float result = clotheToCotiz->GetPrice() * unitQuantity;
	return result;
}


