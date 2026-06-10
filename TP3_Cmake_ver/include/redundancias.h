#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include <vector>

/*
basicamente, si no ingresas el tipo de dato correcto,
te vas pal lobby a ingresar el dato de vuelta
no sirve con strings
*/
template <typename generico>
generico entradaLimpia()
{
	generico variableInput;

	while (true)
	{

		if (std::cin >> variableInput)
		{

			//(odio el manejo de memoria)
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return variableInput;

		}
		else
		{

			std::cout << "Ingrese un valor valido" << std::endl;
			std::cin.clear(); //desbloquea el cin
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpia buffer
		}
	}
}

double minMaxInput(int min, int max = std::numeric_limits<int>::max());

double calcularPromedio(const std::vector<int>& valores);

void clrscr();
