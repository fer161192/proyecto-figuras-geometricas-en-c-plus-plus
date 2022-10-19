#include <iostream>
#include "FigurasHeredadas.h"
using namespace std;

const double PI = 3.14;

Circulo::Circulo(char nombre, double radio):Figuras(nombre)
{
	this->tipo_de_letra = nombre;
    this->radio = radio;
}

Circulo::~Circulo()
{}

void Circulo::mostrar()
{
    cout<<"Radio: "<<this->radio<<" m"<<endl;
}

void Circulo::mostrarSuperficie()
{
    cout<<getSuperficie()<<" m^2"<<endl;
}

void Circulo::mostrarPerimetro()
{
    cout<<getPerimetro()<<" m"<<endl;
}

double Circulo::getPerimetro()
{
    return ((this->radio)*2*PI);
}

double Circulo::getSuperficie()
{
	cout<<this->radio*(this->radio)*(PI)<<endl;
    return ((this->radio)*(this->radio)*(PI));
}
char Circulo::getCaracter()
{
	return(this->tipo_de_letra);
}
