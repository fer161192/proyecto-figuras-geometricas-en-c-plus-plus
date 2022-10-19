#include <iostream>
#include "FigurasHeredadas.h"
using namespace std;

Cuadrado::Cuadrado(char nombre, double lado):Figuras(nombre)
{
    this->lado = lado;
    this->tipo_de_letra = nombre;
}

Cuadrado::~Cuadrado()
{}

void Cuadrado::mostrar()
{
    cout<<"Lado: "<<this->lado<<" m"<<endl;
}

void Cuadrado::mostrarSuperficie()
{
    cout<<getSuperficie()<<" m^2"<<endl;
}

void Cuadrado::mostrarPerimetro()
{
    cout<<getPerimetro()<<" m"<<endl;
}

double Cuadrado::getPerimetro()
{
    return ((this->lado)*4);
}

double Cuadrado::getSuperficie()
{
	cout<<lado*lado<<endl;
    return ((this->lado)*(this->lado));
}
char Cuadrado::getCaracter()
{
	return(this->tipo_de_letra);
}
