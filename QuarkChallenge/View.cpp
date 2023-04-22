#include "View.h"
#include <iostream>
#include <vector>
#include <ctime>
#include "Presenter.h"

using namespace std;

//Setting string constants
#pragma region Constants
const string INVALID_OPTION = "Ha seleccionado una opcion incorrecta. Por favor ingrese nuevamente una opcion valida.";
const string INVALID_OPTION_CLOTHES = "Ha seleccionado una opcion incorrecta. Por favor ingrese nuevamente una opcion valida. Iniciaremos el proceso nuevamente";
const string OUT_OF_STOCK = "El Stock no es suficiente para realizar el pedido. Por favor inicie el proceso nuevamente.";

#pragma endregion

View::View()
{
	presenter = new Presenter(this);
	MainMenu();
}

View::~View()
{
	delete presenter;
	delete cotization;
	for(auto item : clothesList) {
		delete item;
	}
}

#pragma region Main User Flow

//Main
void View::MainMenu()
{
	string input;
	bool exitCondition = false;

	do {
		system("cls");
		cout << "COTIZADOR EXPRESS - MENU PRINCIPAL" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << presenter->GetTiendaData()->name + " | " << presenter->GetTiendaData()->address << endl;
		cout << "-------------------------------------------------" << endl;
		cout << presenter->GetTiendaData()->seller->name + " " + presenter->GetTiendaData()->seller->lastName + " | " << presenter->GetTiendaData()->seller->id << endl;
		cout << "\n" << "SELECCIONE UNA OPCION DEL MENU:" << "\n";
		cout << "1) Historial de Cotizaciones" << endl;
		cout << "2) Realizar Cotizacion" << endl;
		cout << "3) Salir" << endl;
		cin >> input;

		try {
			int intInput = stoi(input);
			system("cls");
			RunOption(intInput);
		}
		catch (invalid_argument) {
			cout << INVALID_OPTION << "\n" << endl;
			cin.get();
		}

		cout << "";
		cin.get();
	} while (!exitCondition);

}
void View::RunOption(int option) {

	switch (option) {
	case 1:
		ShowRecord();
		cin.get();
		break;
	case 2:
		ShowCotizationMenu();
		cin.get();
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << INVALID_OPTION << endl;
		cin.get();
	}
}

//Cotization Record
void View::ShowRecord()
{
	Header();

	//Getting history of cotizations
	auto historyList = presenter->GetTiendaData()->seller->cotizacionList;
	if (historyList.size() == 0) {
		cout << "\n" << "Aun no hay cotizationes :(";
		cin.get();

	}
	else {
		for (auto cotization : historyList) {
			ShowCotizacion(cotization);
			cout << "\n";
		}
		cin.get();
	}
	cin.get();
	MainMenu();
}

//Paso 1
void View::ShowCotizationMenu()
{
	string inputPrenda;

	//Populating list of clothes
	presenter->GetClothesList();

	Header();
	cout << "PASO 1: Selecciona la prenda a cotizar:" << endl;
	cout << "1- Pantalon" << endl;
	cout << "2- Camisa" << endl;
	cin >> inputPrenda;

	try
	{
		int intInputPrenda = stoi(inputPrenda);
		switch (intInputPrenda)
		{
		case 1:
		case 2:
			ShowClotheSelectionMenu(intInputPrenda);
			break;
		case 0:
			MainMenu();
			break;
		default:
			cout << INVALID_OPTION_CLOTHES << "\n" << endl;
			cin.get();
			break;
		}
	}
	catch (invalid_argument) {
		cout << INVALID_OPTION_CLOTHES << "\n" << endl;
		cin.get();
	}
	cin.get();
	system("cls");

	ShowCotizationMenu();

}

//Paso 2
void View::ShowClotheSelectionMenu(int inputPrenda)
{
	string inputSubprenda, inputVariation;
	bool shirtCotization = false, pantsCotization = false;

	switch (inputPrenda) {
	case 1:
		system("cls");
		Header();
		cout << "PASO 2: El pantalon a cotizar, ¿Es Chupin?" << endl;
		cout << "1- Si" << endl;
		cout << "2- No" << endl;
		cin >> inputSubprenda;

		try {
			int intInputPrenda = stoi(inputSubprenda);
			switch (intInputPrenda) {
			case 1:
				toPants = CHUPIN;
				break;
			case 2:
				toPants = COMUN;
				break;
			case 0:
				exit(0);
				break;
			default:
				cout << INVALID_OPTION_CLOTHES << "\n" << endl;
				cin.get();
				cin.get();
				system("cls");
				ShowCotizationMenu();
				break;
			}
		}
		catch (invalid_argument) {
			cout << INVALID_OPTION_CLOTHES << "\n" << endl;
			cin.get();
			cin.get();
			system("cls");
			ShowCotizationMenu();
		}

		cin.get();
		system("cls");
		pantsCotization = true;
		break;
	case 2:
		system("cls");
		Header();
		cout << "PASO 2.a: La Camisa a cotizar, ¿Es Manga corta?" << endl;
		cout << "1- Si" << endl;
		cout << "2- No" << endl;
		cin >> inputSubprenda;
		try {
			int intInputPrenda = stoi(inputSubprenda);
			switch (intInputPrenda) {
			case 1:
				toShirt = MANGA_CORTA;
				break;
			case 2:
				toShirt = MANGA_LARGA;
				break;
			case 0:
				exit(0);
				break;
			default:
				cout << INVALID_OPTION_CLOTHES << "\n" << endl;
				cin.get();
				cin.get();
				system("cls");
				ShowCotizationMenu();
				break;
			}
		}
		catch (invalid_argument) {
			cout << INVALID_OPTION_CLOTHES << "\n" << endl;
			cin.get();
			cin.get();
			system("cls");
			ShowCotizationMenu();
		}


		system("cls");
		Header();
		cout << "PASO 2.b: La Camisa a cotizar, ¿Es Cuello Mao?" << endl;
		cout << "1- Si" << endl;
		cout << "2- No" << endl;
		cin >> inputVariation;
		try {
			int intInputVariation = stoi(inputVariation);
			switch (intInputVariation) {
			case 1:
				varShirt = CUELLO_MAO;
				break;
			case 2:
				varShirt = CUELLO_COMUN;
				break;
			case 0:
				exit(0);
				break;
			default:
				cout << INVALID_OPTION_CLOTHES << "\n" << endl;
				cin.get();
				cin.get();
				system("cls");
				ShowCotizationMenu();
				break;
			}
		}
		catch (invalid_argument) {
			cout << INVALID_OPTION_CLOTHES << "\n" << endl;
			cin.get();
			cin.get();
			system("cls");
			ShowCotizationMenu();
		}

		cin.get();
		system("cls");
		shirtCotization = true;
		break;
	case 0:
		MainMenu();
		cin.get();
		break;
	default:
		cout << INVALID_OPTION_CLOTHES << "\n" << endl;
		cin.get();
		cin.get();
		system("cls");
		ShowCotizationMenu();
	}

	ShowSelectionQualityMenu(shirtCotization, pantsCotization);
}

//Paso 3
void View::ShowSelectionQualityMenu(bool shirt, bool pants)
{
	string inputQuality;
	Quality quality;
	Clothes* prenda = nullptr;

	Header();
	cout << "PASO 3: Seleccione la calidad de la prenda" << endl;
	cout << "1- Standard" << endl;
	cout << "2- Premium" << endl;
	cin >> inputQuality;

	try {
		int intInputQuality = stoi(inputQuality);
		if (intInputQuality == 1) {
			quality = STANDARD;
		}
		else if (intInputQuality == 2) {
			quality = PREMIUM;
		}
		else if (intInputQuality == 0) {
			exit(0);
		}
		else {
			cout << INVALID_OPTION_CLOTHES << "\n" << endl;
			cin.get();
			cin.get();
			system("cls");
			ShowCotizationMenu();
		}
	}
	catch (invalid_argument) {
		cout << INVALID_OPTION_CLOTHES << "\n" << endl;
		cin.get();
		cin.get();
		system("cls");
		ShowCotizationMenu();
	}


	switch (quality) {
	case STANDARD:
		if (pants) {
			if (toPants == CHUPIN) {
				prenda = clothesList.at(0);
			}
			else if (toPants == COMUN) {
				prenda = clothesList.at(1);
			}
		}

		if (shirt) {
			if (toShirt == MANGA_CORTA) {
				if (varShirt == CUELLO_MAO) {
					prenda = clothesList.at(4);
				}
				else {
					prenda = clothesList.at(6);
				}
			}
			else if (toShirt == MANGA_LARGA) {
				if (varShirt == CUELLO_MAO) {
					prenda = clothesList.at(8);
				}
				else {
					prenda = clothesList.at(10);
				}
			}
		}

		break;
	case PREMIUM:
		if (pants) {
			if (toPants == CHUPIN) {
				prenda = clothesList.at(2);
			}
			else if (toPants == COMUN) {
				prenda = clothesList.at(3);
			}
		}

		if (shirt) {
			if (toShirt == MANGA_CORTA) {
				if (varShirt == CUELLO_MAO) {
					prenda = clothesList.at(5);
				}
				else {
					prenda = clothesList.at(7);
				}
			}
			else if (toShirt == MANGA_LARGA) {
				if (varShirt == CUELLO_MAO) {
					prenda = clothesList.at(9);
				}
				else {
					prenda = clothesList.at(11);
				}
			}
		}
		break;
	}
	cin.get();
	system("cls");

	ShowEndMenu(prenda);
}

//Paso 4 y 5.
void View::ShowEndMenu(Clothes* prenda)
{
	Header();

	string price;
	cout << "PASO 4: Ingrese el precio unitario de la prenda a cotizar" << endl;
	cin >> price;
	try {
		int intPrice = stoi(price);
	}
	catch (invalid_argument) {
		cout << INVALID_OPTION_CLOTHES << "\n" << endl;
		cin.get();
		cin.get();
		system("cls");
		ShowCotizationMenu();
	}

	int checkedPrice = stoi(price);
	system("cls");

	Header();

	//Using presenter data to validate clothe picked by user
	Clothes* clotheReference = nullptr;
	for (Clothes* clothe : clothesList) {
		if (clothe = prenda) {
			clotheReference = clothe;
		}
	}

	string unidades;
	cout << "INFORMACION:" << endl;
	cout << "EXISTEN " << clotheReference->GetStock() << " CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA" << "\n" << endl;
	cout << "PASO 5: Ingrese la cantidad de unidades a cotizar" << endl;

	if (clotheReference->GetStock() == 0) {
		cout << "No hay mas prendas disponibles. Te invitamos a elegir otra prenda. Muchas gracias!" << endl;
		cin.get();
		cin.get();
		system("cls");
		ShowCotizationMenu();
	}
	else 
	{	
		try {
			cin >> unidades;
			int intUnits = stoi(unidades);
			if (intUnits > clotheReference->GetStock()) {
				cout << OUT_OF_STOCK << endl;
				cin.get();
				cin.get();
				system("cls");
				ShowCotizationMenu();
			}
				
		}
		catch (invalid_argument) {
			cout << INVALID_OPTION_CLOTHES << "\n" << endl;
			cin.get();
			cin.get();
			system("cls");
			ShowCotizationMenu();
		}
		catch (out_of_range) {
			cout << INVALID_OPTION_CLOTHES << "\n" << endl;
			cin.get();
			cin.get();
			system("cls");
			ShowCotizationMenu();
		}
		int intUnits = stoi(unidades);

		cin.get();
		system("cls");

		//Sending values to presenter in order to update data
		presenter->UpdateClotheData(prenda, checkedPrice, intUnits);
		presenter->GetCotization(prenda, intUnits, checkedPrice);

	}

	//Showing actual cotization
	Header();
	ShowCotizacion(cotization);
	cin.get();
	system("cls");

	//Going back to main
	MainMenu();
}

#pragma endregion

#pragma region Reusable string outputs

void View::ShowCotizacion(Cotization* newCotization)
{
	cout << "Numero de id: " << newCotization->id << endl;
	cout << "Fecha y hora de la cotizacion: " << newCotization->date << endl;
	cout << "Codigo del vendedor: " << presenter->GetTiendaData()->seller->id << endl;
	cout << "Prenda cotizada: " << newCotization->clotheToCotiz->GetName() << endl;
	cout << "Precio unitario: $" << newCotization->price << endl;
	cout << "Cantidad de unidades cotizadas: " << newCotization->unitQuantity << endl;
	cout << "Precio Final: $" << newCotization->result << endl;
}
void View::Header() {
	cout << "COTIZADOR EXPRESS - MENU PRINCIPAL" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "Presiona 0 para volver al menu principal" << endl;
	cout << "-------------------------------------------------" << endl;
}

#pragma endregion

//Comunication with Presenter
void View::SetClothes(vector<Clothes*> clothes)
{
	clothesList = clothes;
}
void View::SetCotization(Cotization* cotizationData)
{
	cotization = cotizationData;
}

