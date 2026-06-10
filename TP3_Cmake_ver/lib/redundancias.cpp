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

double calcularPromedio(const std::vector<int>& valores)
{
	if (!valores.empty())
	{
		double promedio = 0;
		for (int i = 0; i < valores.size(); i++)
		{
			promedio += valores[i];
		}
		promedio /= valores.size();
		return promedio;
	}
	else
	{
		std::cout << "NULL VECTOR" << std::endl;
		return 0;
	}
}

void clrscr()
{
	#ifdef _WIN32:
		system("cls");
	#else:
		system("clear");
	#endif
}