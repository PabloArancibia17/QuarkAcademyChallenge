#include "Seller.h"
#include "Cotization.h"

Seller::Seller(int id, string name, string lastName) {
	this->name = name;
	this->lastName = lastName;
	this->id = id;
}

Cotization* Seller::NewCotization(Clothes* clotheToCotiz, int cantUnits, float price)
{
	cotizationId++;
	cotizId = "000" + to_string(cotizationId);
	Cotization* cotization = new Cotization(cotizId, clotheToCotiz, cantUnits, price, __DATE__);
	cotizacionList.emplace_back(cotization);
	return cotization;
}
