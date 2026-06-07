#include "consigna2.h"

/*
2. Un supermercado almacena las compras de los clientes en una lista. Cada nodo representa
un "Ticket" de compra que contiene: el nombre del cliente y un vector con los precios de
los 5 productos que compró.
Se pide: Cada vez que un cliente llega a la caja, su ticket se debe insertar al final de la lista
(para respetar el orden de llegada). Desarrollar la lógica de inserción de un nuevo ticket.
*/

void ejecutarPunto2()
{
	int cantidadClientes = 1;
	int cantidadProductos = 1;
	std::string nombreTemp;
	std::vector<int> preciosTemp;

	Lista* tickets = new Lista();
	configuracion tienda; //("Cliente: ", "Precios de compras: ", false, false, 5);
	tienda.setNombre("Cliente: ");
	tienda.setVectorNombre("Precios de compras: ");
	tienda.setMostrarPos(false);

	clrscr();
	std::cout << "Ingrese la cantidad de clientes a procesar" << std::endl;
	cantidadClientes = minMaxControl(entradaLimpia<int>(), 1);
	clrscr();

	for (int i = 0; i < cantidadClientes; i++)
	{
		std::cout << i + 1 << "/" << cantidadClientes << std::endl;
		std::cout << "Ingrese el nombre del cliente" << std::endl;
		std::getline(std::cin, nombreTemp);
		std::cout << "Ingrese la cantidad de productos comprados" << std::endl;
		cantidadProductos = entradaLimpia<int>();
		preciosTemp.assign(cantidadProductos, 0);

		clrscr();

		for (int j = 0; j < cantidadProductos; j++)
		{
			std::cout << i + 1 << "/" << cantidadClientes << std::endl;
			std::cout << "Cliente: " << nombreTemp << std::endl;
			std::cout << "Ingrese el precio del producto " << j + 1 << "/" << cantidadProductos << std::endl;
			preciosTemp[j] = minMaxControl(entradaLimpia<int>(), 1);

			clrscr();
		}
		tickets->agregarFinal(nombreTemp, preciosTemp);
		
	}
	tickets->imprimirLista(&tienda);
	matarLista(tickets);
}