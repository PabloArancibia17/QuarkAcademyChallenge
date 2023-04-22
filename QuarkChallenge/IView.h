#pragma once
#include <vector>
#include "Clothes.h"
#include "Cotization.h"

using namespace std;

class IView {
public:
	virtual void SetClothes(vector<Clothes*> list) = 0;
	virtual void SetCotization(Cotization* cotizationData) = 0;
};
