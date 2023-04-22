#include "Presenter.h"


Presenter::Presenter(IView* iView) : view(iView), tienda(new Shop()) {

}

Presenter::~Presenter()
{
	delete view;
	delete tienda;
	delete clothe;
}

Shop* Presenter::GetTiendaData() {
	return tienda;
}

void Presenter::GetClothesList()
{
	auto listOfClothes = tienda->GetClothes();
	view->SetClothes(listOfClothes);
}

void Presenter::GetCotization(Clothes* clotheToCotiz, int cantUnits, float price)
{
	Cotization* newCotization = tienda->seller->NewCotization(clotheToCotiz, cantUnits, price);
	view->SetCotization(newCotization);
}

void Presenter::UpdateClotheData(Clothes* clotheSelected, float price, int units)
{
	clothe = clotheSelected;
	clothe->SetPrice(price);
	clothe->UpdateStock(units);
}
