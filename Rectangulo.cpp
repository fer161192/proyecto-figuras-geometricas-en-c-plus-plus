#include <iostream>
#include "FigurasHeredadas.h"
using namespace std;

Rectangulo::Rectangulo(char nombre, double base, double altura):Figuras(nombre)
{
	this->tipo_de_letra = nombre;
    this->base = base;
    this->altura = altura;
}

Rectangulo::~Rectangulo()
{}

void Rectangulo::mostrar()
{
    cout<<"Base: "<<this->base<<" m"<<endl;
    cout<<"Altura: "<<this->altura<<" m"<<endl;
}

void Rectangulo::mostrarSuperficie()
{
    cout<<getSuperficie()<<" m^2"<<endl;
}

void Rectangulo::mostrarPerimetro()
{
    cout<<getPerimetro()<<" m"<<endl;
}

double Rectangulo::getPerimetro()
{
    return ((this->altura*2)+(this->base*2));
}

double Rectangulo::getSuperficie()
{
	cout<<altura*base<<endl;
    return ((this->altura)*(this->base));
}
char Rectangulo::getCaracter()
{
	return(this->tipo_de_letra);
}
