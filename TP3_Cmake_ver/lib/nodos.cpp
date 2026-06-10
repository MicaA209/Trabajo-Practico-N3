#include "nodos.h"
/*
Nota: pasar una variable(que no sea primitiva, como un string) por referencia(&) hace que
el proceso sea mas rapido, aunque no se nota aca pq es una app de consola XDDDDDDDDDDDDDD
*/
bool Lista::agregarCuandoNulo(Nodo* nodo)
{
	if (this->cabeza == nullptr)
	{
		this->cabeza = nodo;
		return true;
	}
	return false;

}

void Lista::agregarFinal(std::string& nombre, std::vector<int>& valores)
{
	Nodo* nuevo = new Nodo();
	nuevo->nombre = nombre;
	nuevo->valores = valores;
	nuevo->siguiente = nullptr;

	if (agregarCuandoNulo(nuevo)) { return; }

	Nodo* temp = this->cabeza;

	while (temp->siguiente != nullptr)
	{
		temp = temp->siguiente;
		//DEBUG
		//-------------------------------//
		//std::cout << "Investigando...";
		//std::cin.get();
	}

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
	nuevo->valores = valores;
	nuevo->siguiente = nullptr;

	if (agregarCuandoNulo(nuevo)) { return; }

	nuevo->siguiente = this->cabeza;
	this->cabeza = nuevo;
}

bool Lista::agregarPosicion(std::string& nombre, std::vector<int>& valores, int pos)
{
	Nodo* nuevo = new Nodo();
	nuevo->nombre = nombre;
	nuevo->valores = valores;
	nuevo->siguiente = nullptr;

	if (agregarCuandoNulo(nuevo)) { return true; }
	
	if (pos <= 0) 
	{
		nuevo->siguiente = this->cabeza;
		this->cabeza = nuevo;
		return true;
	}
	
	int contador = 0;
	Nodo* temp = this->cabeza;

	while (contador < pos-1 && temp->siguiente != nullptr)
	{
		temp = temp->siguiente;
		contador ++;
	}
	
	if (temp->siguiente == nullptr && contador != pos - 1) 
	{
		std::cout << "Posicion " << pos <<" fuera de rango!" << std::endl; 
		delete nuevo;
		std::cin.ignore();
		clrscr();
		return false;
	}
	
	nuevo->siguiente = temp->siguiente;
	temp->siguiente = nuevo;
	return true;
}

int Lista::solicitarPosicion(Nodo* nodo)
{
	Nodo* temp = this->cabeza;
	int contador = 0;

	if (nodo == nullptr) { return -1; }

	while (temp != nullptr && temp != nodo)
	{
		contador ++;
		temp = temp->siguiente;
	}

	if (temp != nodo) { return -1; }

	return contador;
}

void Lista::imprimirLista(const configuracion& configImpresion)
{
	Nodo* temp = this->cabeza;

	while (temp != nullptr)
	{
		bool estaVacio = temp->valores.empty();
		
		std::cout << configImpresion.nombrePresentacion << temp->nombre << std::endl;
		
		if (configImpresion.muestraPosicion())
		{ std::cout << "Posicion en lista: " << solicitarPosicion(temp) << std::endl; }
		
		std::cout << configImpresion.vectorPresentacion << std::endl;

		if (estaVacio)
		{ std::cout << "No hay nada!" << std::endl; }
		else
		{
			const int* arrTemp = temp->valores.data();
			const int sizeArr = temp->valores.size();
			printArray(arrTemp, sizeArr, configImpresion.saltosLinea);
			
			if (configImpresion.permitePromedio())
			{ std::cout << "promedio: ([--" << calcularPromedio(temp->valores) << "--])" << std::endl; }
		}

		if(configImpresion.permitePausas())
		{
			std::cout << "...";
			std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
		}
		temp = temp->siguiente;
	}
}

void Lista::limpiarResto()
{

	while (this->cabeza != nullptr)
	{
		Nodo* siguiente = this->cabeza->siguiente;
		//manejo de memoria is my main enemy D:<
		delete this->cabeza;
		this->cabeza = siguiente;
	}
	std::cout << "Memoria limpiada! quiero keke" << std::endl;
}

//TODO: achicar un toque el codigo, parece 5 kilos de fideos
//9/6/2026: achicamos... un poquito