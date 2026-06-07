#include "consigna5.h"
/*
5. Un club de running almacena los datos de sus atletas en una lista enlazada. De cada
corredor se tiene su nombre y un vector con los tiempos (en minutos) que tardó en
completar sus últimas 4 carreras de 10K.
Se requiere armar una nueva lista llamada listaElite. Para esto, se debe recorrer la lista
original, calcular el tiempo total de cada corredor en las 4 carreras, y si ese tiempo total es
menor a 180 minutos (es decir, son rápidos), se debe insertar al inicio de la nueva listaElite. Al
finalizar, mostrar la nueva lista por pantalla.
*/

//Por que hice esto?????????????
double calcTmpoTotal(std::vector<double>& tiempos)
{
	if (tiempos.empty()) { return 0; }
	double tmpTotal = 0;

	for (int i = 0; i < tiempos.size(); i++)
	{ tmpTotal += tiempos[i]; }
	
	return tmpTotal;
}

void Listatletas::agregar(std::string& nombre, std::vector<double>& tiempos)
{
	Atleta* nuevo = new Atleta();
	nuevo->nombre = nombre;
	nuevo->tiempos.resize(tiempos.size());
	nuevo->tiempos = tiempos;
	nuevo->tiempoTotal = calcTmpoTotal(tiempos);
	nuevo->siguiente = nullptr;

	if (this->cabeza == nullptr)
	{
		this->cabeza = nuevo;
		return;
	}

	Atleta* temp = this->cabeza;
	this->cabeza = nuevo;
	this->cabeza->siguiente = temp;
}

void Listatletas::imprimir(configuracion* conf)
{
	bool esNulo = false;
	if (conf == nullptr)
	{
		conf = new configuracion();
		esNulo = true;
	}
	Atleta* temp = this->cabeza;

	double* arrtemp;

	while (temp->siguiente != nullptr)
	{
		std::cout << conf->nombrePresentacion << temp->nombre << std::endl;
		
		if(temp->tiempos.empty()) 
		{std::cout << "no hay tiempos!" << std::endl;}
		else
		{
		arrtemp = temp->tiempos.data();
		std::cout << conf->vectorPresentacion << std::endl;
		printArray<double>(arrtemp, temp->tiempos.size(), conf->saltosLinea);
		std::cout << "total: " << temp->tiempoTotal << std::endl;
		}

		std::cout << "...";
		std::cin.get();

		temp = temp->siguiente;
	}

	if (esNulo)
	{delete conf;}

}

void Listatletas::eliminar()
{
	Atleta* temp = this->cabeza;
	Atleta* siguiente = new Atleta();

	while (temp != nullptr)
	{
		siguiente = temp->siguiente;
		//el delete es una cagada!!
		//*libera memoria*
		//el delete es clave
		delete temp;
		temp = siguiente;
	}

	delete siguiente;
	this->cabeza = nullptr;
}

void ejecutarPunto5()
{
	const int maxCarreras = 4;
	Listatletas* ListaElite = new Listatletas();
	configuracion club;
	club.setNombre("Atleta: ");
	club.setVectorNombre("Tiempos: ");
	std::vector<double> tiemposTemp(maxCarreras, 0);
	double totalTemp = 0;
	std::string nombreTemp;
	int atletasIngreso = 0;


	clrscr();
	std::cout << "Ingrese la cantidad de atletas a procesar" << std::endl;
	atletasIngreso = entradaLimpia<int>();
	clrscr();

	for (int i = 0; i < atletasIngreso; i++)
	{
		std::cout << i+1 << "/" << atletasIngreso << std::endl;
		std::cout << "Ingrese el nombre del atleta" << std::endl;
		std::getline(std::cin, nombreTemp);
		clrscr();

		for (int j = 0; j < maxCarreras; j++)
		{
			std::cout << i + 1 << "/" << atletasIngreso << std::endl;
			std::cout << "Atleta: " << nombreTemp << std::endl;
			std::cout << "Ingrese el tiempo(en minutos) de la carrera " << j + 1 << "/" << maxCarreras << std::endl;
			tiemposTemp[j] = entradaLimpia<double>();

			clrscr();
		}
		totalTemp = calcTmpoTotal(tiemposTemp);

		if (totalTemp < 180)
		{ ListaElite->agregar(nombreTemp, tiemposTemp); }
		
		totalTemp = 0;
		tiemposTemp.assign(maxCarreras, 0);
	}

	ListaElite->imprimir();

	ListaElite->eliminar();
	delete ListaElite;
}