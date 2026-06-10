#include <string>
#include <iostream>

template <typename generico> //a mi me tiene que meter en cana pq alta funcion sirrosa
void printArray(const generico Arr[], int size, int maxPrintWidth = 5) //por cierto 5 es el valor default de cada vez que se hace un salto de linea
{

	int printWidth = 0;

	for (int i = 0; i < size; i++)
	{
		std::cout << "[" << Arr[i] << "] ";
		//hola si, fabrica de tonotos, se les escapo uno		

		printWidth++;
		if (printWidth == maxPrintWidth)
		{
			printWidth = 0;

			std::cout << "\n\n";
			//mAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMATENMEEEEEEEEEEEEEEEEEEE
		}

	} std::cout << std::endl;

}




//basicamente lo pongo en el template pq si lo pongo en la peticion de funcion, me tira un error

template <typename generico, int row, int column>//showCurrentRow == mostrar el nombre de fila y el numero
void printMatrix(const generico matriz[row][column], std::string rowName, bool showCurrentRow = true)
{

	for (int i = 0; i < row; i++)
	{

		if (showCurrentRow) {
			std::cout << rowName << " " << i + 1 << ": " << std::endl;
		}
		for (int j = 0; j < column; j++)
		{

			std::cout << "[" << matriz[i][j] << "] ";
			//deberia haberme ido a Quimica bld
		}
		std::cout << "\n\n"; //deja un salto de linea adicional, YA SE AMIGO, QSY LPEKAPOFKOGHR
	}
}
