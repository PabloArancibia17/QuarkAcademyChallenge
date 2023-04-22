#include<iostream>
#include<vector>
#include "Seller.h"
#include "Clothes.h"

using namespace std;

class Shop {

#pragma region Public Attributes
public:
	Seller* seller;
	string name, address;
	vector<Clothes*> clothes;
#pragma endregion

#pragma region Public Functions
public:
	Shop();
	~Shop();
	vector<Clothes*> GetClothes();
#pragma endregion

};