#ifndef LISTA_H_
#define LISTA_H_
#include <iostream>
#include "nodo.h"
using namespace std;
template < typename Dato >
class Lista
{
private:
	//Primer elemento de la lista
	Nodo<Dato>* primero;
	//Tamaño de la lista
	unsigned tam;
public:
	/*Constructor
	*Pre: Ninguna.
	*Post: Construye una lista vacia
	* - primero apunta a NULL
	* - tam = 0
	*/
	Lista();
	/*Destructor
	 *Pre: Lista creada.
	 *Post: Libera todos los recursos de la lista.
	 */
	~Lista();
	/*Agregar un elemento de la lista.
	 *Pre: Lista creada y d valido.
	 *Post: Agrega un dato dentro de un nodo al principio
	 * - modifica el primero
	 * - tam se incrementa en 1
	 */
	void insert(Dato d);
	/*Obtener el tamaño de la lista.
	 *Pre: Lista creada.
	 *Post: Devuelve el tamaño de la lista (Cantidad de nodos).
	 */
	unsigned get_tam();
	/*Obtener el dato que esta en la posicion pos.
	 * Pre: - lista creada y no vacia
	 * 		- 0< pos <= tam
	 * Post: Devuelve el dato que esta en la posicion pos.
	 * 	Se toma 1 como el primero.
	 */
	Dato get_dato(unsigned pos);
	/*Lista vacia?
	 * Pre: Lista creada.
	 * Post: T si es vacia, F sino
	 */
	bool lista_vacia();
	/*Borrado del nodo que esta en la posicion pos.
	 * Pre: - lista creada y no vacia
	 * 		- < pos <= tam
	 * Post: Libera el nodo que esta en la posicion pos.
	 * Se toma como 1 el primero.
	 */
	void del_dato(unsigned pos);
};
//Constructor
template <typename Dato >
Lista<Dato>::Lista()
{
	primero = 0;
	tam = 0;
}
//Destructor
template < typename Dato >
Lista<Dato>::~Lista()
{
	while (this->lista_vacia() == false)
	{
		this->del_dato(1);
	}
}
//Devuelve T si la lista esta vacia, F sino
template < typename Dato >
bool Lista<Dato>::lista_vacia()
{
	return(tam == 0);
}
//Colocar, al principio, un nuevo nodo con el dato d
template < typename Dato >
void Lista<Dato>::insert(Dato d)
{
	Nodo<Dato>* nuevo = new Nodo<Dato>(d);
	if (this->lista_vacia() == false)
	{
		nuevo->set_siguiente(primero);
	}
	primero = nuevo;
	tam++;
}
//Devuelve el dato que esta en la posicion pos
template < typename Dato >
Dato Lista<Dato>::get_dato(unsigned pos)
{
	Nodo<Dato>* aux = primero;
	if (this->lista_vacia() == false)
	{
		for (unsigned cont = 1;(cont<pos && aux); cont++)
			aux = aux->get_siguiente();
		return(aux->get_dato());
	}
	return(0);
}
//Devuelve la cantidad de nodos que tiene la lista
template < typename Dato >
unsigned Lista<Dato>::get_tam()
{
	return(tam);
}
//Elimina el dato que esta en la posicion pos
template < typename Dato >
void Lista<Dato>::del_dato(unsigned pos)
{
	Nodo<Dato>* aux = primero;
	if (this->lista_vacia() == false)
	{
		if (pos == 1)
		{
			primero = primero->get_siguiente();
		}
		else
		{
			for (unsigned cont = 0; (cont<pos-1 && aux->get_siguiente()); cont++)
				aux = aux->get_siguiente();
			aux->set_siguiente(aux->get_siguiente());
		}
		Nodo<Dato>* borrar = aux;
		cout<<"Se elimina el nodo con el dato "<<borrar->get_dato()<<endl;
		delete borrar;
		tam--;
	}
}
#endif /* LISTA_H_ */
