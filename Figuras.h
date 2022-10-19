#ifndef FIGURAS_H_
#define FIGURAS_H_
#include <string>
using namespace std;
class Figuras
{
protected:
    char letra;
public:
    Figuras(char nombre);
	virtual ~Figuras();
    virtual void mostrarPerimetro()=0;
    virtual void mostrarSuperficie()=0;
    virtual void mostrar()=0;
    virtual double getSuperficie()=0;
    virtual double getPerimetro()=0;
    virtual char getCaracter()=0;
};
#endif /* FIGURAS_H_ */
