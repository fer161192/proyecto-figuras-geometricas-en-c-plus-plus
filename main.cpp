#include <string>
#include <fstream>
#include "FigurasHeredadas.h"
#include "parser.h"
#include "Lista.h"
using namespace std;

void mostrarMenu();
void cargarLista(Lista<Figuras*>* &ptrL);
void cargar_en_lista(medidas,Lista<Figuras*>* &ptrL);
void Loop(Lista<Figuras*>* &ptrL);
void operar(int, Lista<Figuras*>* &ptrL);
void consultarFiguraMaxSuperficie(Lista<Figuras*>* &ptrL);
void consultarFiguraMaxPerimetro(Lista<Figuras*>* &ptrL);
void consultarFiguraMinPerimetro(Lista<Figuras*>* &ptrL);
void consultarFiguraMinSuperficie(Lista<Figuras*>* &ptrL);
void eliminarEnLista(Lista<Figuras*>* &ptrL);
void listarTodosLosObjetos(Lista<Figuras*>* &ptrL);
void consultarPosicionEnLista(Lista<Figuras*>* &ptrL);
int main()
{
    cout << "Lista de Figuras" << endl;
    Lista<Figuras*>* ptrL = new Lista<Figuras*>; //puntero de la lista l, que guarda como dato a un puntero de tipo Figuras
    cargarLista(ptrL);
    Loop(ptrL);
    return 0;
}

void mostrarMenu()
{
    cout<<"Menu: " << endl;
    cout<<"1.- Consultar Figura con la mayor superficie" << endl;
    cout<<"2.- Consultar Figura con mayor perimetro" << endl;
    cout<<"3.- Consultar Figura con menor perimetro" << endl;
    cout<<"4.- Consultar Figura con menor superficie" << endl;
    cout<<"5.- Borrar un elemento"<<endl;
    cout<<"6.- Listar todos los objetos"<<endl;
    cout<<"7.- Consultar Figura en una posicion"<<endl;
}

void Loop(Lista<Figuras*>* &ptrL)
{
	string respuesta;
    int opcion;
    respuesta =  "si";
    while (respuesta == "si")
    {
    	mostrarMenu();
    	cin>>opcion;
        operar(opcion, ptrL);
        cout<<"Desea seguir realizando operaciones? (si/no): "<<endl;
        cin>>respuesta;
    }
    cout << "Saliendo" << endl;
    delete ptrL;
}

void cargarLista(Lista<Figuras*>* &ptrL)
{
	medidas registro_medidas;
	string respuesta;
	Parser objeto_parser;
    respuesta = "si";
	while(respuesta == "si")
	{
		registro_medidas = objeto_parser.obtenerMedida();
		cargar_en_lista(registro_medidas, ptrL);
		cout<<registro_medidas.letra<<" "<<registro_medidas.medida1<<" "<<registro_medidas.medida2<<endl;
		cout << "Desea seguir insertando elementos a la lista? (si/no): "<<endl;
		cin >> respuesta;
	}

}

void cargar_en_lista(medidas reg_medidas,Lista<Figuras*>* &ptrL)
{
	if (reg_medidas.letra != '0')
	{
		switch(reg_medidas.letra)
		{
			case 'A':
				Cuadrado* puntero_cuadrado;
				puntero_cuadrado = new Cuadrado(reg_medidas.letra,reg_medidas.medida1);
				ptrL->insert(puntero_cuadrado);
				break;
			case 'B':
				Rectangulo* puntero_rectangulo;
				puntero_rectangulo = new Rectangulo(reg_medidas.letra,reg_medidas.medida1,reg_medidas.medida2);
				ptrL->insert(puntero_rectangulo);
				break;
			case 'C':
				Circulo* puntero_circulo;
				puntero_circulo = new Circulo(reg_medidas.letra,reg_medidas.medida1);
				ptrL->insert(puntero_circulo);
				break;
		}
	}
	else
		cout<<"Fin de archivo! No hay mas registros!"<<endl;
}

void operar(int opcion, Lista<Figuras*>* &ptrL)
{
    switch (opcion)
    {
    case 1:
        consultarFiguraMaxSuperficie(ptrL);
        break;
    case 2:
        consultarFiguraMaxPerimetro(ptrL);
        break;
    case 3:
        consultarFiguraMinPerimetro(ptrL);
        break;
    case 4:
        consultarFiguraMinSuperficie(ptrL);
        break;
    case 5:
    	eliminarEnLista(ptrL);
    	break;
    case 6:
    	listarTodosLosObjetos(ptrL);
    	break;
    case 7:
    	consultarPosicionEnLista(ptrL);
    	break;
    default:
    	cout<<"Opcion incorrecta!"<<endl;
    }
}
void consultarFiguraMaxSuperficie(Lista<Figuras*>* &ptrL)
{
    unsigned pos = 1;
    double maximo_superficie;
    if (! ptrL->lista_vacia())
    {
    	maximo_superficie = 0;
        for (unsigned i = 1; i <= (ptrL->get_tam()); i++)
        {
            if (ptrL->get_dato(i)->getSuperficie() > maximo_superficie)
            {
                pos = i;
                maximo_superficie = ptrL->get_dato(pos)->getSuperficie();
            }
        }
        switch(ptrL->get_dato(pos)->getCaracter())
        {
        	case 'A':
        		cout<<"La figura con mayor superficie es el cuadrado en la posicion " <<pos<< " de la lista." << endl;
        		cout<<"Su superficie es: "<<ptrL->get_dato(pos)->getSuperficie()<<endl;
        		break;
        	case 'B':
        		cout<<"La figura con mayor superficie es el rectangulo en la posicion "<<pos<<" de la lista."<<endl;
        		cout<<"Su superficie es: "<<ptrL->get_dato(pos)->getSuperficie()<<endl;
        		break;
        	case 'C':
        		cout<<"La figura con mayor superficie es el circulo en la posicion "<<pos<<" de la lista."<<endl;
        		cout<<"Su superficie es: "<<ptrL->get_dato(pos)->getSuperficie()<<endl;
        		break;
        }
    }
}

void consultarFiguraMinSuperficie(Lista<Figuras*>* &ptrL)
{
    unsigned pos = 1;
    double superficie_minima;
    if (! ptrL->lista_vacia())
    {
    	superficie_minima = 500; //Coloco un valor inicial aleatorio
        for (unsigned i = 1; i <= (ptrL->get_tam()); i++)
        {
            if (ptrL->get_dato(i)->getSuperficie() < superficie_minima)
            {
                pos = i;
                superficie_minima = ptrL->get_dato(pos)->getSuperficie();
            }
        }
        switch(ptrL->get_dato(pos)->getCaracter())
        {
        	case 'A':
        		cout<<"La figura con menor superficie es el cuadrado en la posicion " <<pos<< " de la lista." << endl;
        		cout<<"Su superficie es: "<<ptrL->get_dato(pos)->getSuperficie()<<endl;
               	break;
            case 'B':
            	cout<<"La figura con menor superficie es el rectangulo en la posicion "<<pos<<" de la lista."<<endl;
            	cout<<"Su superficie es: "<<ptrL->get_dato(pos)->getSuperficie()<<endl;
            	break;
            case 'C':
            	cout<<"La figura con menor superficie es el circulo en la posicion "<<pos<<" de la lista."<<endl;
            	cout<<"Su superficie es: "<<ptrL->get_dato(pos)->getSuperficie()<<endl;
            	break;
        }

    }
}

void consultarFiguraMaxPerimetro(Lista<Figuras*>* &ptrL)
{
    unsigned pos = 1;
    double perimetro_maximo;
    if (! ptrL->lista_vacia())
    {
    	perimetro_maximo = 0;
        for (unsigned i = 1; i <= (ptrL->get_tam()); i++)
        {
            if (ptrL->get_dato(i)->getPerimetro() > perimetro_maximo)
            {
                pos = i;
                perimetro_maximo = ptrL->get_dato(pos)->getPerimetro();
            }
        }
        switch(ptrL->get_dato(pos)->getCaracter())
        {
        	case 'A':
        		cout<<"La figura con mayor perimetro es el cuadrado en la posicion " <<pos<< " de la lista." << endl;
        		cout<<"Su perimetro es: "<<ptrL->get_dato(pos)->getPerimetro()<<endl;
                break;
           case 'B':
               cout<<"La figura con mayor perimetro es el rectangulo en la posicion "<<pos<<" de la lista."<<endl;
               cout<<"Su perimetro es: "<<ptrL->get_dato(pos)->getPerimetro()<<endl;
               break;
           case 'C':
              cout<<"La figura con mayor perimetro es el circulo en la posicion "<<pos<<" de la lista."<<endl;
              cout<<"Su perimetro es: "<<ptrL->get_dato(pos)->getPerimetro()<<endl;
              break;
         }
    }
}
void consultarFiguraMinPerimetro(Lista<Figuras*>* &ptrL)
{
    unsigned pos = 1;
    double perimetro_minimo;
    if (! ptrL->lista_vacia())
    {
    	perimetro_minimo = 500;
        for (unsigned i = 1; i <= (ptrL->get_tam()); i++)
        {
            if ((ptrL->get_dato(i)->getPerimetro()) < perimetro_minimo)
            {
                pos = i;
                perimetro_minimo = ptrL->get_dato(pos)->getPerimetro();
            }
        }
        switch(ptrL->get_dato(pos)->getCaracter())
        {
        	case 'A':
        		cout<<"La figura con menor perimetro es el cuadrado en la posicion " <<pos<< " de la lista." << endl;
                break;
            case 'B':
            	cout<<"La figura con menor perimetro es el rectangulo en la posicion "<<pos<<" de la lista."<<endl;
                break;
            case 'C':
            	cout<<"La figura con menor perimetro es el circulo en la posicion "<<pos<<" de la lista."<<endl;
            	break;
         }
    }
}
void listarTodosLosObjetos(Lista<Figuras*>* &ptrL)
{
	int contadorCuadrados = 0, contadorCirculos = 0, contadorRectangulos = 0;
	if (! ptrL->lista_vacia())
	{
		cout << "Hay " << ptrL->get_tam() << " figuras geometricas en la lista" << endl;
	    for (unsigned i = 1; i <= ptrL->get_tam(); i++)
	    {
	    	if ((ptrL->get_dato(i)->getCaracter())=='C')
	    		contadorCirculos++;
	    	if ((ptrL->get_dato(i)->getCaracter())=='A')
	    		contadorCuadrados++;
	    	if ((ptrL->get_dato(i)->getCaracter())=='B')
	    		contadorRectangulos++;
	    }
	}
	cout << contadorCirculos << " Circulos" << endl;
	cout << contadorCuadrados << " Cuadrados" << endl;
	cout << contadorRectangulos << " Rectangulos" << endl;
}
void consultarPosicionEnLista(Lista<Figuras*>* &ptrL)
{
    unsigned pos;
    cout << "Ingrese la posicion a consultar: "<< endl;
    cin >> pos;
    if (pos > 0 && pos <= ptrL->get_tam())
        ptrL->get_dato(pos)->mostrar();
    else
    	cout<<"Posicion no encontrada!"<<endl;
}
void eliminarEnLista(Lista<Figuras*>* &ptrL)
{
    unsigned pos;
    cout << "Ingrese la posicion a eliminar en la lista: "<< endl;
    cin >> pos;
    if (pos > 0 && pos <= ptrL->get_tam())
    {
        ptrL->del_dato(pos);
        cout<<"El elemento, ha sido eliminado con exito!"<<endl;
    }
    else
    	cout<<"El elemento en esa posicion no existe!"<<endl;
}
