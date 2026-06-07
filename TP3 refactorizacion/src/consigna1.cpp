#include "consigna1.h"

/*
1. Una universidad registra a sus alumnos en una lista enlazada. De cada alumno se conoce
su nombre y un vector con sus 3 notas del cuatrimestre.
Se pide: Desarrollar el algoritmo para recorrer la lista y mostrar por pantalla el nombre de
cada alumno junto con su promedio de notas.

*/

void ejecutarPunto1()
{
	const int notasMax = 3;
	//xddddd
	Lista* alumnos = new Lista();
	configuracion escuelaConfig;//("Alumno: ", "Notas: ", true, false, notasMax);
	escuelaConfig.setNombre("Alumno: ");
	escuelaConfig.setVectorNombre("Notas: ");
	escuelaConfig.setPromedio(true);
	escuelaConfig.setMostrarPos(false);
	escuelaConfig.setSaltosLinea(notasMax);

	std::vector<int> notasTemp(notasMax, 0);
	std::string nombreTemp;
	int alumnosCantidad;

	clrscr();

	std::cout << "Ingrese la cantidad de alumnos: " << std::endl;
	alumnosCantidad = entradaLimpia<int>();

	clrscr();

	for (int i = 0; i < alumnosCantidad; i++)
	{
		std::cout << i+1 << "/" << alumnosCantidad << std::endl;
		std::cout << "Ingrese el nombre del alumno: ";
		std::getline(std::cin, nombreTemp);
		
		clrscr();

		for (int j = 0; j < notasMax; j++)
		{
			std::cout << i + 1 << "/" << alumnosCantidad << std::endl;
			std::cout << "Alumno: " << nombreTemp << std::endl;
			std::cout << "Ingrese su nota " << j + 1 << "/" << notasMax << std::endl;
			notasTemp[j] = minMaxInput(1, 10);

			clrscr();
		}

		alumnos->agregarFinal(nombreTemp, notasTemp);

		notasTemp.assign(notasMax, 0);
	}
	alumnos->imprimirLista(&escuelaConfig);

	matarLista(alumnos);
}