#include "pch.h"
#include "TD.h"
#include <iostream>

using namespace std;


TD::TD(string name)
{
	nombre = name;
}

TD::TD(void)
{
}

string TD::GetName(void)
{
	return nombre;
}

void TD::SetName(string name)
{
	nombre = name;
}

void TD::AgregarDependencias(string nueva)
{
	LDT.push_back(nueva);
}

string TD::ConsultarDependencia(int a)
{
	return LDT[a];
}

int TD::TamanoDeLista(void)
{
	return LDT.size();
}

void TD::MostrarTD(void)
{
	cout << " " << nombre << " --> ";
	if (LDT.size() > 0) {
		for (int x = 0; x < LDT.size(); x++) {
			cout << LDT[x];
		}
	}
	else
	{
		cout << " 0 " << endl;
	}
}

void TD::Limpiar(void)
{
	nombre = ' ';
	LDT.clear();
}

void TD::MostrarOriginal(void)
{
	if (LDT.size() > 0) {
		for (int x = 0; x < LDT.size(); x++) {
			cout << " " << nombre << " --> " << LDT[x];
			cout << endl;
		}
	}
	else
	{
		cout << " " << nombre << " --> " << " 0 " << endl;
	}
}

void TD::MostrarDependencias(void)
{
	for (int x = 0; x < LDT.size(); x++) {
		cout << LDT[x];
	}
}


TD::~TD()
{
}

//std::ostream & operator<<(std::ostream & os,  TD & datito)
//{
//	os << " " << datito.GetName() << " --> ";
//	/*for (int x = 0; x < datito.TamañoDeLista(); x++) {
//		os << datito.ConsultarDependencia(x);
//	}*/
//	return os;
//}


