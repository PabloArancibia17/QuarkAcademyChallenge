#include <string>
#include <list>
#include "Clothes.h"

class Cotization;

using namespace std;

class Seller
{

#pragma region Public Attributes
public:
	string name, lastName, cotizId;
	int id, cotizationId;
	list<Cotization*> cotizacionList;
#pragma endregion

#pragma region Public Functions
public:
	Seller(int id, string name, string lastName);
	Cotization* NewCotization(Clothes* clotheToCotiz, int cantUnits, float price);
#pragma endregion

};

