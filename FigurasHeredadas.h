#ifndef FIGURAS_HEREDADAS_H_
#define FIGURAS_HEREDADAS_H_
#include "Figuras.h"
//'A' es cuadrado
//'B' es rectangulo
//'C' es circulo
class Cuadrado:public Figuras
{
private:
    double lado;
    char tipo_de_letra;
public:
    Cuadrado(char, double);
    ~Cuadrado();
    void mostrar();
    void mostrarSuperficie();
    void mostrarPerimetro();
    double getSuperficie();
    double getPerimetro();
    char getCaracter();
};

class Rectangulo:public Figuras
{
private:
	char tipo_de_letra;
    double base, altura;
public:
    Rectangulo(char, double, double);
    ~Rectangulo();
    void mostrar();
    void mostrarSuperficie();
    void mostrarPerimetro();
    double getSuperficie();
    double getPerimetro();
    char getCaracter();
};

class Circulo:public Figuras
{
private:
	char tipo_de_letra;
    double radio;
public:
    Circulo(char, double);
    ~Circulo();
    void mostrar();
    void mostrarSuperficie();
    void mostrarPerimetro();
    double getSuperficie();
    double getPerimetro();
    char getCaracter();
};
#endif /* FIGURAS_HEREDADAS_H_ */
