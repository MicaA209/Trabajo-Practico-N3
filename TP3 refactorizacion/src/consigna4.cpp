#include "consigna4.h"
/*
4. Una empresa de turismo tiene una lista de clientes VIP en espera. De cada cliente se
conoce su nombre y un vector con los montos de sus últimas 3 compras.
Se requiere que el sistema reciba un nuevo cliente y la posición exacta (un número entero pos)
donde se lo quiere ubicar en la fila. Desarrollar el algoritmo para avanzar por la lista hasta el
nodo anterior a esa posición y realizar el enganche del nuevo cliente allí.
*/

void ejecutarPunto4()
{
	
	const int maxCompras = 3;
	Lista* vip = new Lista();
	configuracion turismoConf;
	turismoConf.setNombre("Cliente: ");
	turismoConf.setVectorNombre("montos de las ultimas compras: ");
	std::string nombreTemp;
	std::vector<int> montosTemp(maxCompras, 0);
	vip->agregarFinal(nombreTemp = "Javier Nuñez", montosTemp = {55,300,60});
	vip->agregarFinal(nombreTemp = "Daniel Cardozo", montosTemp = {100,120,60});
	vip->agregarFinal(nombreTemp = "Ian Noblega", montosTemp = {10,300,80});
	montosTemp.assign(maxCompras, 0);
	//para poner el estandar utf-8, si no, no lee la Ñ
	system("chcp 65001");
	clrscr();

	vip->imprimirLista(&turismoConf);
	clrscr();

	std::cout << "Ingrese el nombre del cliente" << std::endl;
	getline(std::cin, nombreTemp);
	clrscr();
	std::cout << "Ingrese las ultimas compras del cliente" << std::endl;
	for (int i = 0; i < maxCompras; i++)
	{
		std::cout << "Compra " << i + 1 << "/" << maxCompras << std::endl;
		montosTemp[i] = entradaLimpia<int>();
	} clrscr();

	std::cout << "En que posicion desea ubicar al cliente?";
	int poso = entradaLimpia<int>();

	vip->agregarPosicion(nombreTemp, montosTemp, poso);

	vip->imprimirLista(&turismoConf);

	matarLista(vip);
}