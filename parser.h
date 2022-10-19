#ifndef PARSER_H_
#define PARSER_H_
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct
{
	char letra;
	double medida1;
	double medida2;
}medidas;
//Si la segunda medida es cero, significa que la figura geometrica solo tiene una medida.
//Caso contrario estariamos hablando del rectangulo.
class Parser
{
private:
	medidas registro_medidas;
	string linea;
	fstream archivo;
public:
	Parser();
	medidas obtenerMedida();
private:
	void leerLinea(bool &es_fin);
	void parseoCasoGeneral(string auxiliar,char cadena1[7]);
	void parseoCasoB(string auxiliar,char cadena1[7],char cadena2[7]);
};
#endif /* PARSER_H_ */
