#pragma once
#include "nodos.h"
class Atleta
{
	public:
		std::string nombre;
		std::vector<double> tiempos;
		double tiempoTotal;
		Atleta* siguiente;
};

class Listatletas
{
	Atleta* cabeza;

	public:
		void agregar(std::string& nombre, std::vector<double>& tiempos);
		void imprimir(const configuracion& configImpresion);
		void eliminar();
};

double calcTmpoTotal(std::vector<double>& tiempos);

void ejecutarPunto5();