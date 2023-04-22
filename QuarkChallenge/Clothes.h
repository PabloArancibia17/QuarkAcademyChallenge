#pragma once
#include <string>

using namespace std;

enum Quality { STANDARD = 1, PREMIUM };

class Clothes
{
#pragma region Protected Attributes
protected:
	string name;
	float price, multiplier;
	int stock;
	Quality quality;
#pragma endregion

#pragma region Public Functions
public:
	float GetPrice();
	float GetMultiplier();
	string GetName();
	int GetStock();
	void SetPrice(float price);
	void UpdateStock(int unitsSelled);
#pragma endregion

};

