#include <string>
#include "Clothes.h"
#include <ctime>

class Seller;

using namespace std;


class Cotization {

#pragma region Public Attributes
public:
	Clothes* clotheToCotiz;
	int unitQuantity;
	float result, price;
	string id, date;
	
#pragma endregion

#pragma region Public Functions
	Cotization(string id, Clothes* clotheToCotiz, int unitQuantity, float price, string date);
	~Cotization();
	float SetCotizationResult();
#pragma endregion

};