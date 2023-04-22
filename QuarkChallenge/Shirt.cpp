#include "Shirt.h"

Shirt::Shirt(TypeOfShirt type, VariationShirt variation, float price, int stock, Quality quality)
{
	this->type = type;
	this->variation = variation;
	this->price = price;
	this->stock = stock;
	this->quality = quality;

	float customMultiplier = 1;
	string actualName;
	switch (type) {
	case MANGA_CORTA:
		actualName = "Camisa - Manga Corta";
		customMultiplier *= 0.9;
		break;
	case MANGA_LARGA:
		actualName = "Camisa - Manga Larga";
	default:
		break;
	}

	string variationName;
	switch (variation)
	{
	case CUELLO_MAO:
		variationName = "Cuello Mao";
		customMultiplier *= 1.03;
		break;
	case CUELLO_COMUN:
		variationName = "Cuello Comun";
		break;
	default:
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
	default:
		break;
	}

	this->name = actualName + " - " + variationName + " - " + actualQuality;
	this->multiplier = customMultiplier;
}
