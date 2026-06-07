#include "../include/nodos.h"
/*
Nota: pasar una variable(que no sea primitiva, como un string) por referencia(&) hace que
el proceso sea mas rapido, aunque no se nota aca pq es una app de consola XDDDDDDDDDDDDDD
*/
void Lista::agregarFinal(std::string& nombre, std::vector<int>& valores)
{
	Nodo* nuevo = new Nodo();
	nuevo->nombre = nombre;
	nuevo->valores.resize(valores.size());
	nuevo->valores = valores;
	nuevo->siguiente = nullptr;
	int contador = 1;

	if (this->cabeza == nullptr)
	{
		this->cabeza = nuevo;
		this->cabeza->posicion = 0;
		
		//DEBUG
		//-------------------------------//
		//std::cout << "se creo un coso!";
		//std::cin.get();
		return;
	}

	Nodo* temp = this->cabeza;

	while (temp->siguiente != nullptr)
	{
		temp = temp->siguiente;
		contador ++;
		//DEBUG
		//-------------------------------//
		//std::cout << "Investigando...";
		//std::cin.get();
	}

	nuevo->posicion = contador;
	temp->siguiente = nuevo;

	//DEBUG
	//-------------------------------//
	//std::cout << "se agrego un coso!";
	//std::cin.get();
}

void Lista::agregarPrincipio(std::string& nombre, std::vector<int>& valores)
{
	Nodo* nuevo = new Nodo();
	nuevo->nombre = nombre;
	nuevo->valores.resize(valores.size());
	nuevo->valores = valores;
	nuevo->posicion = 0;
	nuevo->siguiente = nullptr;

	if (this->cabeza == nullptr)
	{
		this->cabeza = nuevo;
		this->cabeza->posicion = 0;

		//DEBUG
		//-------------------------------//
		//std::cout << "se creo un coso!";
		//std::cin.get();
		return;
	}

	Nodo* temp = this->cabeza;
	this->cabeza = nuevo;
	temp->posicion += 1;
	this->cabeza->siguiente = temp;

	while (temp->siguiente != nullptr)
	{
		temp = temp->siguiente;
		temp->posicion += 1;
	}
}

void Lista::agregarPosicion(std::string& nombre, std::vector<int>& valores, int pos)
{
	Nodo* nuevo = new Nodo();
	nuevo->nombre = nombre;
	nuevo->valores.resize(valores.size());
	nuevo->valores = valores;
	nuevo->posicion = pos;

	if (this->cabeza == nullptr)
	{
		this->cabeza = nuevo;
		this->cabeza->posicion = 0;
		return;
	}

	Nodo* temp = this->cabeza;

	while (temp->siguiente != nullptr && temp->siguiente->posicion != pos)
	{
		temp = temp->siguiente;
	}
	if (temp->siguiente == nullptr)
	{
		agregarFinal(nombre, valores);
		return;
	}
	
	Nodo* sigTemp = temp->siguiente;
	temp->siguiente = nuevo;
	nuevo->siguiente = sigTemp;

	while (nuevo->siguiente != nullptr)
	{
		nuevo->siguiente->posicion += 1;
		nuevo = nuevo->siguiente;
	}

}

void Lista::imprimirLista(configuracion* Config)
{
	bool esNulo = false;
	if(Config == nullptr)
	{ 
		Config = new configuracion();
		esNulo = true;
	}

	Nodo* temp = this->cabeza;
	bool estaVacio;
	int* arrTemp;
	int sizeArr;

	while (temp != nullptr)
	{
		estaVacio = temp->valores.empty();
		
		std::cout << Config->nombrePresentacion << temp->nombre << std::endl;
		
		if (Config->muestraPosicion())
		{ std::cout << "Posicion en lista: " << temp->posicion << std::endl; }
		
		std::cout << Config->vectorPresentacion << std::endl;

		if (estaVacio)
		{ std::cout << "No hay nada!" << std::endl; }
		else
		{
			arrTemp = temp->valores.data();
			sizeArr = temp->valores.size();
			printArray(arrTemp, sizeArr, Config->saltosLinea);
			
			if (Config->hacePromedio())
			{ calcularPromedio(temp->valores); }
		}

		std::cout << "...";
		std::cin.get();
		temp = temp->siguiente;
	}
	
	if(esNulo)
	{delete Config;}

}

Nodo Lista::retornarPosicion(int pos)
{
	

	Nodo* temp = this->cabeza;
	
	while (temp->siguiente != nullptr && temp->posicion != pos)
	{ temp = temp->siguiente; }

	if (temp->siguiente == nullptr && temp->posicion < pos)
	{
		std::cout << "Error: solicitud de indice fuera de limites" << std::endl;
		std::cout << "Activando protocolo de auto-destruccion" << std::endl;
	}
	
	return *temp;
	
}

void Lista::limpiarResto()
{
	Nodo* temp = this->cabeza;
	Nodo* siguiente = new Nodo();

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

//TODO: achicar un toque el codigo, parece 5 kilos de fideos

void matarLista(Lista*& listado)
{
	listado->limpiarResto();
	delete listado;
	std::cout << "memoria liberada correctamente, a tomar mate lavado" << std::endl;
}