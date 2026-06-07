#include "src/masi.h"

int main()
{
    int opt = 67;
    system("chcp 65001");
    clrscr();
    while (opt != 0)
    {
        std::cout << "  ╔══════════════════════════════════╗" << std::endl;
        std::cout << "  ║                                  ║" << std::endl;
        std::cout << "  ║    Trabajo  Practico  N* 3       ║" << std::endl;
        std::cout << "  ║                                  ║" << std::endl;
        std::cout << "  ╚══════════════════════════════════╝\n" << std::endl;
        std::cout << "Elija la consigna a ejecutar" << std::endl;
        std::cout << "desde la consigna 1 hasta la 5 (0: salir)" << std::endl;
        
        opt = entradaLimpia<int>();
        switch (opt)
        {
        case 1:
            clrscr();
            ejecutarPunto1();
            std::cin.get();
            clrscr();
            break;
        case 2:
            clrscr();
            ejecutarPunto2();
            std::cin.get();
            clrscr();
            break;
        case 3:
            clrscr();
            ejecutarPunto3();
            std::cin.get();
            clrscr();
            break;
        case 4:
            clrscr();
            ejecutarPunto4();
            std::cin.get();
            clrscr();
            break;
        case 5:
            clrscr();
            ejecutarPunto5();
            std::cin.get();
            clrscr();
            break;
        case 0:
            std::cout << "Hasta luego!!";
            break;
        default:
            std::cout << "No se encontro la consigna!";
            break;
        }

    }
}
