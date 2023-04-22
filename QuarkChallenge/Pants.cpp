#include "Pants.h"

Pants::Pants(TypeOfPants type, float price, int stock, Quality quality)
{
	this->type = type;
	this->price = price; 
	this->stock = stock; 
	this->quality = quality;

	float customMultiplier = 1;
	string actualName;
	switch (type) {
	case COMUN:
		actualName = "Pantalon - Comun";
		break;
	case CHUPIN:
		actualName = "Pantalon - Chupin";
		customMultiplier *= 0.88;
		break;
	}

	string actualQuality;
	switch (quality) {
	case PREMIUM:
		actualQuality = "Premium";
		customMultiplier *= 1.3;
		break;
	case STANDARD:
		actualQuality = "Standard";
		break;
	}

	this->name = actualName + " - " + actualQuality;
	this->multiplier = customMultiplier;
}
