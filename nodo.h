#ifndef NODO_H_
#define NODO_H_
template <typename Dato>
class Nodo
{
private:
	Nodo* psig; //Puntero a otro nodo
	Dato dato;	//Dato a almacenar
public:
	//Constructor con parametro
	//Pre: Ninguna
	//Post: Crea un nodo con el dato d
	//y el puntero a NULL.
	Nodo(Dato d);
	//Destructor
	//Pre: Nodo creado
	//Post: No hace nada.
	~Nodo();
	//Setea el dato (Lo cambia)
	//Pre: El Nodo tiene que estar creado.
	//d es un dato valido.
	//Post: El nodo queda con el dato d.
	void set_dato(Dato d);
	//Setear el puntero al siguiente nodo
	//Pre: Nodo creado y ps valido.
	//Post: El puntero al siguiente apuntará a ps.
	void set_siguiente (Nodo* ps);
	//Obtener el dato
	//Pre: Nodo creado.
	//Post:Devuelte el dato que contiene el nodo.
	Dato get_dato();
	//Obtener el puntero al siguiente nodo.
	//Pre: Nodo creado.
	//Post: Devuelve el puntero al siguiente nodo.
	//Si es el ultimo, devuelve NULL.
	Nodo* get_siguiente();
	//Hay un siguiente?
	//Pre: Nodo creado.
	//Post: V si tiene sig. F sino.
	bool tiene_sig();
};
//Constructor con parametro.
template < typename Dato >
Nodo<Dato>::Nodo(Dato d)
{
	dato = d;
	psig = 0;
}
//Destructor
template < typename Dato >
Nodo<Dato>::~Nodo()
{
	//No hace nada
}
//Setear el dato
template < typename Dato >
void Nodo<Dato>::set_dato(Dato d)
{
	dato = d;
}
//Setear el prt al siguiente
template < typename Dato >
void Nodo<Dato>::set_siguiente(Nodo<Dato>* ps)
{
	psig = ps;
}
//Devolver el dato
template < typename Dato >
Dato Nodo<Dato>::get_dato()
{
	return(dato);
}
//Devolver el siguiente
template < typename Dato >
Nodo<Dato>* Nodo<Dato>::get_siguiente()
{
	return(psig);
}
//Tiene siguiente?
template < typename Dato >
bool Nodo<Dato>::tiene_sig()
{
	return(psig != 0);
}
#endif /* NODO_H_ */
