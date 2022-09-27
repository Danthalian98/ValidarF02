#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

class Fecha {
public:
	Fecha();
	void validar();
	void menu();
	string datos[3];
	int z;
private:
	int dia;
	int mes;
	int year;
	int opc;
	string a;
};

Fecha::Fecha() {
	dia = 0;
	mes = 0;
	year = 0;
	opc = 0;
	z = 0;
}

void Fecha::menu() {
	do {
		system("cls");
		cout << "........Validacion de fechas by Zavala........" << endl;
		cout << "................Instrucciones................." << endl;
		cout << "1.-Introduzca la fecha en formato: yyyy/mm/dd" << endl;
		cout << "2.-Respete el uso de / para separar los datos" << endl;
		cout << "3.- Tenga sentido comun, no se vende por separado" << endl;
		cin >> a;
		system("cls");

		validar();

		cout << endl;
		cout << "Desea introducir una nueva fecha?" << endl;
		cout << "1.-Claro que yes" << endl;
		cout << "2.-No D:" << endl;
		cin >> opc;
	} while (opc == 1);

	cout << endl;
	cout << "Nos vemos" << endl;
	cout << endl;
	system("pause");
}

void Fecha::validar() {

	string lectura;
	stringstream inputFecha(a);
	while (getline(inputFecha, lectura, '/')) {
		datos[z] = lectura;
		z++;
	}
	z = 0;
	year = stoi(datos[0]);
	mes = stoi(datos[1]);
	dia = stoi(datos[2]);

	if (year > 0) {
		if (dia > 0 && dia <= 31) {
			if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12 && dia <= 31) {
				cout << "La fecha es valida :D" << endl;
			}
			else if (mes == 4 || mes == 6 || mes == 9 || mes == 11 && dia <= 30) {
				cout << "La fecha es valida :D" << endl;
			}
			else if (mes == 2 && dia <= 29) {
				if (dia <= 28) {
					cout << "La fecha es valida :D" << endl;
				}
				else if (year % 4 == 0 && dia == 29) {
					cout << "Es bisiesto " << endl;
					cout << "La fecha es valida :D" << endl;
				}
			}
			else {
				cout << "El mes no es valido >:(" << endl;
			}
		}
		else {
			cout << "El dia no es valido >:(" << endl;
		}
	}
	else {
		cout << "El year no es valido >:(" << endl;
	}
}

int main() {
	Fecha fecha;
	fecha.menu();
	return 0;
}




