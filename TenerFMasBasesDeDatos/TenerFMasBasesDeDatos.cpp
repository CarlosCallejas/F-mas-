// TenerFMasBasesDeDatos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include "TD.h"
#include"ItsSomething.h";
#include <string>

using namespace std;
int main()
{
	ItsSomething Hola;
	vector<TD> atributos;
	string atri;
	int pos = -1, atriNum = 1;
	system("color 0c");
	vector<string> tablaOriginal;

	int menu = 0;
	while (menu != 3)
	{
		system("cls");
		cout << "hola Miss, es mi programita para sacar F+ disfrutalo" << endl;
		cout << "1) programa  " << endl;
		cout << "2) Meme" << endl;
		cout << "3) Salir" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			//se ingresan todos los atributos
			while (atriNum != 0)
			{
				cout << "ingresa un atributo: ";
				cin >> atri;
				tablaOriginal.push_back(atri);
				pos++;
				atributos.push_back(atri);
				int d = 1;
				//ingresa todas las dependencias del atributo agregado
				while (d != 0) {
					cout << "tiene mas dependencias? 1=si, 0=no " << endl;
					cin >> d;
					if (d != 0) {
						string dep = " ";
						cout << "escribe su dependencia" << endl;
						cin >> dep;
						tablaOriginal.push_back(dep);
						atributos[pos].AgregarDependencias(dep);
					}
				}
				cout << "hay mas atributos? 1=si, 0=no" << endl;
				cin >> atriNum;
			}

			system("cls");
			//tabla original
			for (int x = 0; x < tablaOriginal.size(); x++) {
				string temp = tablaOriginal[x];
				for (int y = x + 1; y < tablaOriginal.size(); y++) {
					string temp2 = tablaOriginal[y];
					if (temp == temp2)
						tablaOriginal[y] = " ";
				}
			}
			cout << endl << "	RESULTADOS	" << endl;
			cout << endl;
			cout << "	F = { ";
			for (int x = 0; x < tablaOriginal.size(); x++) {
				if (x != 0)
					cout << ",";
				if (tablaOriginal[x] == " ")
					x++;
				cout << tablaOriginal[x];
			}
			cout << " }" << endl;

			cout << endl;
			cout << "Dependencias originales" << endl;
			for (int x = 0; x < atributos.size(); x++) {
				atributos[x].MostrarOriginal();
			}
			cout << endl;

			//demostracion de union
			cout << endl << "-------------------" << endl;
			system("color 0a");
			cout << "despues de aplicar union" << endl;
			for (int x = 0; x <= pos; x++)
				atributos[x].MostrarTD();
			cout << endl << "-------------------" << endl;
			//system("pause");

			//ordenacion para transitividad 

			for (size_t x = 0; x < atributos.size(); x++) {													//se recorre toda la lista de atributos
				TD Temp = atributos[x];																		//se hace referencia al atributo en x
				for (size_t y = 0; y < Temp.TamanoDeLista(); y++) {											//se recorre toda la lista de dependencia del atributo en x
					string letra = Temp.ConsultarDependencia(y);												//se hace referencia a la letra de dependencia en y del atributo en x
					for (size_t z = x + 1; z < atributos.size(); z++) {										//se recorre por segunda vez la lista de atributos 
						if (letra == atributos[z].GetName()) {												//se revisa si la letra sacada de las dependencias es la misma que alguna de los demas atributos 
							size_t tamano = atributos[z].TamanoDeLista();
							for (size_t a = 0; a < tamano; a++) {											//se recorre toda la lista de dependencias de 
								atributos[x].AgregarDependencias(atributos[z].ConsultarDependencia(a));		//se agregan las dependencias del atributo en z al atributo en x
							}
							//atributos[z].Limpiar();
						}
					}
				}
			}

			//demostracion de transitividad
			cout << endl << "-------------------" << endl;
			system("color 0b");
			cout << "despues de aplicar transitividad" << endl;
			for (int x = 0; x < pos; x++)
				atributos[x].MostrarTD();
			cout << endl << "-------------------" << endl;

			//system("pause");

			cout << "	F+ = { ";
			for (int x = 0; x < pos; x++) {
				if (x != 0)
					cout << ",";
				atributos[x].MostrarTD();
			}
			cout << " }" << endl;
			system("pause");

			cout << endl << endl;
			cout << "sugerencia de tablas nuevas" << endl;
			for (int x = 0; x < pos; x++) {
				cout << "llave principal: " << atributos[x].GetName() << endl;
				cout << "tabla " << x << " " << atributos[x].GetName() << " = {";
				atributos[x].MostrarDependencias();
				cout << " }" << endl;
			}
			system("pause");

			break;
		case 2:
			Hola.Mundo();
			system("pause");
			break;
		default:
			break;
		}
	}
	
	system("pause");
}

///check
//mostrar en formato tabla tabla={a,b,c} para mostrar como estaba  
///check
//mostrar f (todas dependencias como tecleo el usuario)
///check
//despues morstrar f+(como esta actual)
///not
//mostrar la sugerencia de nuevas tablas y abajo la llave candidata (A->bcd)