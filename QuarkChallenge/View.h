#include "IView.h"
#include <vector>
#include <string>
#include "Shirt.h"
#include "Pants.h"


class Presenter;
class Cotization;

using namespace std;

class View : public IView
{

#pragma region Private Attributes
private:
	Presenter* presenter;
	vector<Clothes*> clothesList;
	Cotization* cotization;
	bool exitCondition;
	TypeOfPants toPants;
	TypeOfShirt toShirt;
	VariationShirt varShirt;
#pragma endregion

#pragma region Public Functions
public:
	View();
	~View();

	//Main Flow
	void MainMenu();
	void RunOption(int option);
	void ShowRecord();
	void ShowCotizationMenu();
	void ShowClotheSelectionMenu(int inputPrenda);
	void ShowSelectionQualityMenu(bool shirt, bool pants);
	void ShowEndMenu(Clothes* prenda);

	//Reusable visuals
	void Header();
	void ShowCotizacion(Cotization* cotization);

	//Interface declarations
	void SetClothes(vector<Clothes*> clothes) override;
	void SetCotization(Cotization* cotizationData) override;
#pragma endregion


};

