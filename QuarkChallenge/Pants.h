#include <iostream>
#include "Clothes.h"

using namespace std;

enum TypeOfPants{CHUPIN = 1, COMUN};

class Pants : public Clothes {
private:
	TypeOfPants type;
public:
	Pants(TypeOfPants type, float price, int stock, Quality quality);
};