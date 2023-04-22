#include "Shop.h"
#include "Pants.h"
#include "Shirt.h"


Shop::Shop() {
	this->name = "Super Tienda";
	this->address = "Avenida Mi Tienda 902. Guaymallen. Mendoza";
	this->clothes = clothes;
	this->seller = new Seller(10001, "Pablo", "Arancibia");
}

Shop::~Shop() {
	delete seller;
	for (auto item : clothes) {
		delete item;
	}
}

vector<Clothes*> Shop::GetClothes()
{
	//Creating pants
	Clothes* chupinesStandard = new Pants(CHUPIN, 0, 750, STANDARD);
	Clothes* comunesStandard = new Pants(COMUN, 0, 250, STANDARD);
	Clothes* chupinesPremium = new Pants(CHUPIN, 0, 750, PREMIUM);
	Clothes* comunesPremium = new Pants(COMUN, 0, 250, PREMIUM);

	//Creating shirts
	Clothes* camisaCortaMaoStandard = new Shirt(MANGA_CORTA, CUELLO_MAO, 0, 100, STANDARD);
	Clothes* camisaCortaMaoPremium = new Shirt(MANGA_CORTA, CUELLO_MAO, 0, 100, PREMIUM);
	Clothes* camisaCortaComunStandard = new Shirt(MANGA_CORTA, CUELLO_COMUN, 0, 150, STANDARD);
	Clothes* camisaCortaComunPremium = new Shirt(MANGA_CORTA, CUELLO_COMUN, 0, 150, PREMIUM);
	Clothes* camisaLargaMaoStandard = new Shirt(MANGA_LARGA, CUELLO_MAO, 0, 75, STANDARD);
	Clothes* camisaLargaMaoPremium = new Shirt(MANGA_LARGA, CUELLO_MAO, 0, 75, PREMIUM);
	Clothes* camisaLargaComunStandard = new Shirt(MANGA_LARGA, CUELLO_COMUN, 0, 175, STANDARD);
	Clothes* camisaLargaComunPremium = new Shirt(MANGA_LARGA, CUELLO_COMUN, 0, 175, PREMIUM);


	//Adding pants
	clothes.push_back(chupinesStandard); //OPTION 0
	clothes.push_back(comunesStandard); //OPTION 1
	clothes.push_back(chupinesPremium); //OPTION 2
	clothes.push_back(comunesPremium); //OPTION 3

	//Adding shirts
	clothes.push_back(camisaCortaMaoStandard); //OPTION 4
	clothes.push_back(camisaCortaMaoPremium); //OPTION 5
	clothes.push_back(camisaCortaComunStandard); //OPTION 6
	clothes.push_back(camisaCortaComunPremium); //OPTION 7

	clothes.push_back(camisaLargaMaoStandard); //OPTION 8
	clothes.push_back(camisaLargaMaoPremium); //OPTION 9
	clothes.push_back(camisaLargaComunStandard); //OPTION 10
	clothes.push_back(camisaLargaComunPremium); //OPTION 11

	return clothes;
}
