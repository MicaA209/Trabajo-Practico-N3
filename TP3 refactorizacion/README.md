la estructura del proyecto es basicamente:

/src <-- contiene los archivos de origen cpp [las consignas]

/include <-- declaracion de clases en .h (headers)

/lib <-- implementacion de clases (cpp)

a cada consigna le cree su header, si no, se rehusaba a compilar, lol

----------PUNTOS----------
1. Una universidad registra a sus alumnos en una lista enlazada. De cada alumno se conoce
su nombre y un vector con sus 3 notas del cuatrimestre.
Se pide: Desarrollar el algoritmo para recorrer la lista y mostrar por pantalla el nombre de
cada alumno junto con su promedio de notas.


2. Un supermercado almacena las compras de los clientes en una lista. Cada nodo representa
un "Ticket" de compra que contiene: el nombre del cliente y un vector con los precios de
los 5 productos que compró.
Se pide: Cada vez que un cliente llega a la caja, su ticket se debe insertar al final de la lista
(para respetar el orden de llegada). Desarrollar la lógica de inserción de un nuevo ticket.


3. Un torneo de fútbol amateur registra los equipos en una lista enlazada. De cada equipo se
guarda el nombre y un vector con los goles convertidos en los últimos 4 partidos.
Hacer que se pueda insertar un nuevo equipo al inicio de la lista.
Recorrer la lista completa y mostrar únicamente los nombres de los equipos que hayan hecho
más de 10 goles en total sumando los 4 partidos.


4. Una empresa de turismo tiene una lista de clientes VIP en espera. De cada cliente se
conoce su nombre y un vector con los montos de sus últimas 3 compras.
Se requiere que el sistema reciba un nuevo cliente y la posición exacta (un número entero pos)
donde se lo quiere ubicar en la fila. Desarrollar el algoritmo para avanzar por la lista hasta el
nodo anterior a esa posición y realizar el enganche del nuevo cliente allí.


5. Un club de running almacena los datos de sus atletas en una lista enlazada. De cada
corredor se tiene su nombre y un vector con los tiempos (en minutos) que tardó en
completar sus últimas 4 carreras de 10K.
Se requiere armar una nueva lista llamada listaElite. Para esto, se debe recorrer la lista
original, calcular el tiempo total de cada corredor en las 4 carreras, y si ese tiempo total es
menor a 180 minutos (es decir, son rápidos), se debe insertar al inicio de la nueva listaElite. Al
finalizar, mostrar la nueva lista por pantalla.
