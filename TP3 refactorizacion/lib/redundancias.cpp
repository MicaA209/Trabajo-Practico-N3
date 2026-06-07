#include "../include/redundancias.h"

double minMaxInput(int min, int max)
{

	double var;

	while (true)
	{
		var = entradaLimpia<double>(); //osea haces algo con esta funcion y rompes esto tmb
		//a quien se le ocurrio eso??? ah si, a mi XDDD

		if (var >= min && var <= max)
		{

			return var;

		}
		else
		{
			if(max != std::numeric_limits<int>::max())
			{ std::cout << "Ingrese un valor entre " << min << " y " << max << std::endl; }
			else
			{std::cout << "Ingrese un valor mayor a " << min << std::endl;}
		}
	}

}

//esto controla de que no se excedan ciertos limites, osea
//resume 2 ifs, XDDD
int minMaxControl(int value, int min, int max)
{
	if (value < min)
	{
		value = min;
		return value;
	}
	else if (value > max)
	{
		value = max;
		return value;
	}
	else
	{
		return value;
	}


}

void calcularPromedio(const std::vector<int>& valores)
{
	if (!valores.empty())
	{
		double promedio = 0;
		for (int i = 0; i < valores.size(); i++)
		{
			promedio += valores[i];
		}
		promedio /= valores.size();
		std::cout << "promedio: ([--" << promedio << "--])" << std::endl;
	}
	else
	{
		std::cout << "no se pudo calcular el promedio: el vector esta vacio! por la chucha!" << std::endl;
	}
}

void clrscr()
{
	system("cls"); //NADA DE IFDEFS, aca en mi casa usamos windows
}