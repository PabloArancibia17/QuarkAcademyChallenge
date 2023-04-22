#include <iostream>
#include "Shop.h"
#include "IView.h"

class Cotization;

class Presenter{

#pragma region Private Attributes
private:
	IView* view = nullptr;
	Shop* tienda = nullptr;
	Clothes* clothe = nullptr;
#pragma endregion

#pragma region Public Functions
public:
	explicit Presenter(IView* iView);
	~Presenter();
	Shop* GetTiendaData();
	void GetClothesList();
	void GetCotization(Clothes* clotheToCotiz, int cantUnits, float price);
	void UpdateClotheData(Clothes* clotheSelected, float price, int units);
#pragma endregion

};