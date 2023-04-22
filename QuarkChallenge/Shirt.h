#include <iostream>
#include "Clothes.h"

using namespace std;

enum TypeOfShirt { MANGA_CORTA = 1, MANGA_LARGA };
enum VariationShirt { CUELLO_MAO = 1, CUELLO_COMUN };

class Shirt : public Clothes{
private:
	TypeOfShirt type;
	VariationShirt variation;
public:
	Shirt(TypeOfShirt type, VariationShirt variation, float price, int stock, Quality quality);
};