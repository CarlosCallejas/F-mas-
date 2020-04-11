#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class TD
{
	string nombre;
	vector<string> LDT;
public:
	TD(string nombre);
	TD(void);
	//regresa el nombre del atributo
	string GetName(void);
	//configura el nombre del atributo
	void SetName(string name);
	//agrega dependencias del atributo
	void AgregarDependencias(string nueva);
	//regresa una dependencia (char)
	string ConsultarDependencia(int a);
	//regresa el tamaño de la lista 
	int TamanoDeLista(void);
	//muestra el atributo con sus dependencias
	void MostrarTD(void);
	//limpia los datos
	void Limpiar(void);
	//muestra el dato de la forma original
	void MostrarOriginal(void);
	//manda todas las dependencias con ,
	void MostrarDependencias(void);



	//friend std::ostream& operator<< (std::ostream& stream, const TD& datito);
	~TD();
};

