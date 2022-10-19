#include <iostream>
#include "parser.h"
using namespace std;
Parser::Parser()
{
	this->linea = " ";
	this->registro_medidas.letra = '0';
	this->registro_medidas.medida1 = 0;
	this->registro_medidas.medida2 = 0;
	this->archivo.open("figuras.txt",ios::in);
}
//Si ambas medidas se devuelven con cero, significa que el parseo no fue exitoso.
medidas Parser::obtenerMedida()
{
	bool es_fin_de_archivo = true;
	char cad1[7],cad2[7];
	this->registro_medidas.medida1 = 0;
	this->registro_medidas.medida2 = 0;
	this->registro_medidas.letra = '0';
	leerLinea(es_fin_de_archivo);
	if (es_fin_de_archivo == false)			//Me aseguro de que no sea el fin del archivo
	{
		switch (this->linea[0])
		{
			case 'A':
				this->registro_medidas.letra = this->linea[0];
				parseoCasoGeneral(this->linea,cad1);
				registro_medidas.medida1 = atof(cad1);
				break;
			case 'B':
				this->registro_medidas.letra = this->linea[0];
				parseoCasoB(this->linea,cad1,cad2);
				registro_medidas.medida1 = atof(cad1);
				registro_medidas.medida2 = atof(cad2);
				break;
			case 'C':
				this->registro_medidas.letra = this->linea[0];
				parseoCasoGeneral(this->linea,cad1);
				registro_medidas.medida1 = atof(cad1);
				break;
		}
	}
	return(registro_medidas);
}
void Parser::leerLinea(bool &es_fin)
{
	if (this->archivo.is_open() == true)
	{
		es_fin = this->archivo.eof();
		if (this->archivo.eof() == false)
		{
			getline(this->archivo,this->linea);
			cout<<"Linea leida"<<endl;
		}
		else
		{
			cout<<"Fin del archivo!"<<endl;
			this->archivo.close();
		}
	}
	else
	{
		cout<<"No existe dicho archivo."<<endl;
		this->linea = " ";
	}
}
void Parser::parseoCasoGeneral(string auxiliar,char cadena1[7])
{
	 int i = 2;
	 int j = 0;
	 while(auxiliar[i] != '\0')
	 {
		 cadena1[j] = auxiliar[i];
		 i++;
		 j++;
	 }
}
void Parser::parseoCasoB(string auxiliar,char cadena1[7],char cadena2[7])
{

	 int i = 2;
	 int j = 0;
	 while(auxiliar[i] != ' ')
	 {
		 cadena1[j] = auxiliar[i];
	     i++;
	     j++;
	 }
	 j = 0;
	 i++;
	 while(auxiliar[i] != '\0')
	 {
		 cadena2[j] = auxiliar[i];
	     i++;
	     j++;
	 }
}
