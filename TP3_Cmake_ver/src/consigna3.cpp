#include "../include/consigna3.h"
/*
3. Un torneo de fútbol amateur registra los equipos en una lista enlazada. De cada equipo se
guarda el nombre y un vector con los goles convertidos en los últimos 4 partidos.
Hacer que se pueda insertar un nuevo equipo al inicio de la lista.
Recorrer la lista completa y mostrar únicamente los nombres de los equipos que hayan hecho
más de 10 goles en total sumando los 4 partidos.
*/

void ejecutarPunto3()
{
	const int ultimosPartidos = 4;
	const int minimoGoles = 10;
	Lista equipos;
	configuracion torneo;
	torneo.setNombre("Equipo: ");
	torneo.setVectorNombre("Ultimos goles: ");
	torneo.setMostrarPos(false);
	torneo.setPromedio(false);
	torneo.setSaltosLinea(ultimosPartidos);
	int cantidadEquipos = 1;

	std::vector<int> golesTemp(ultimosPartidos, 0);
	int golesTotal = 0;
	std::string nombreTemp;

	std::cout << "los equipos unicamente ingresaran al torneo si" << std::endl;
	std::cout << "realizaron mas de " << minimoGoles << " goles en sus ultimos " << ultimosPartidos << " partidos" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Ingrese la cantidad de equipos a procesar" << std::endl;
	cantidadEquipos = minMaxInput(1);
	clrscr();

	for (int i = 0; i < cantidadEquipos; i++)
	{
		std::cout << i + 1 << "/" << cantidadEquipos << std::endl;
		std::cout << "Ingrese el nombre del equipo" << std::endl;
		getline(std::cin, nombreTemp);

		clrscr();
		for (int j = 0; j < ultimosPartidos; j++)
		{
			std::cout << i + 1 << "/" << cantidadEquipos << std::endl;
			std::cout << "Equipo: " << nombreTemp << std::endl;
			std::cout << "goles del partido " << j + 1 << "/" << ultimosPartidos << std::endl;
			golesTemp[j] = entradaLimpia<int>();
			golesTotal += golesTemp[j];
			clrscr();
		}
		if (golesTotal >= minimoGoles)
		{ equipos.agregarPrincipio(nombreTemp, golesTemp); }
		
		golesTemp.assign(ultimosPartidos, 0);
		golesTotal = 0;
	}
	equipos.imprimirLista(torneo);

	equipos.limpiarResto();
}