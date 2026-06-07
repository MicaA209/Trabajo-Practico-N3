#pragma once
#include "impresiones.h"
#include "redundancias.h"
#include <optional>

class configuracion
{
	//les asigne valores para tener algo por default
	//sino el visual studio anda re molesto con las advertencias 
	//pq no hay constructor debido a la cantidad de atributos que hay
	protected:
		bool calcPromedio = false;
		bool mostrarPosicion = true;
	public:
		std::string nombrePresentacion = "Nombre: ";
		std::string vectorPresentacion = "Vector: ";
		//saltosLinea indica la cantidad de valores a mostrar del vector antes de un salto de linea (duuhh)
		int saltosLinea = 5;
		//POR QUE ME TIRA ERROR SI NO PONGO LOS STRINGS COMO CONSTANTE??????
		//te odio visual studio community
		void setNombre(const std::string& nombre = "Nombre: ") { this->nombrePresentacion = nombre; }
		void setVectorNombre(const std::string& vecNombre = "Vector: ") { this->vectorPresentacion = vecNombre; }
		void setPromedio(bool calcular = false) { this->calcPromedio = calcular; }
		void setMostrarPos(bool mostrar = false) { this->mostrarPosicion = mostrar; }
		void setSaltosLinea(int saltos = 5) { this->saltosLinea = saltos; }
		//no le puse constructor pq soy un ciruja
		bool hacePromedio() const { return this->calcPromedio; }
		bool muestraPosicion() const { return this->mostrarPosicion; }
};

//lo hago clase en lugar de struct pq en el punto 5
//requiero hacer herencia
//NOTA FUTURA: no la hice xddd
class Nodo
{
public:
	std::string nombre;
	std::vector<int> valores;
	int posicion;
	Nodo* siguiente;
};


//originalmente iba a poner todo en la clase Nodo
//pero un re quilombo, mejor hago esto aparte
class Lista
{
	Nodo* cabeza;
	

	public:
		Lista(Nodo* cabeza = nullptr)
		{ this->cabeza = cabeza; }
		//ma' encima me obligaron a poner los atributos de Nodo en publico 
		//hijos de perra
		void agregarFinal(std::string& nombre, std::vector<int>& valores);
		void agregarPrincipio(std::string& nombre, std::vector<int>& valores);
		void agregarPosicion(std::string& nombre, std::vector<int>& valores, int pos);
		void imprimirLista(configuracion* Config = nullptr);
		Nodo retornarPosicion(int pos);
		void limpiarResto();
		
};

void matarLista(Lista*& listado);