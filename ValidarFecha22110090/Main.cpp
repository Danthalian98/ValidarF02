#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

class Fecha {
public:
    string a;
    Fecha();
    void validar();
    void menu();
    void sumar();
    string datos[3];
    int z;
    int s;
private:
    int dia;
    int mes;
    int year;
    int opc;
};

Fecha::Fecha() {
    dia = 0;
    mes = 0;
    year = 0;
    opc = 0;
    z = 0;
    s = 0;
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
                s = 1;
                sumar();
            }
            else if (mes == 4 || mes == 6 || mes == 9 || mes == 11 && dia <= 30) {
                cout << "La fecha es valida :D" << endl;
                s = 2;
                sumar();
            }
            else if (mes == 2 && dia <= 29) {
                s = 3;
                if (dia <= 28) {
                    cout << "La fecha es valida :D" << endl;
                    sumar();
                }
                else if (year % 4 == 0 && dia == 29) {
                    cout << "Es bisiesto " << endl;
                    cout << "La fecha es valida :D" << endl;
                    sumar();
                }
                if (year % 4 != 0 && dia == 29) {
                    cout << "No es bisiesto" << endl;
                    cout << "La fecha no es valida >:(" << endl;
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

void Fecha::sumar() {
    switch (s) {
    case 1:
        if (dia == 31) {
            dia = 1;
            if (mes == 12) {
                year++;
                mes = 1;
            }else {
                mes++;
            }
        }
        else {
            dia++;
        }
        break;
    case 2:
        if (dia == 30) {
            dia = 1;
            mes++;
        }else {
            dia++;
        }
        break;
    case 3:
        if (year % 4 == 0 && dia == 28) {
            dia++;
        }else if (year % 4 == 0 && dia == 29) {
            dia = 1;
            mes++;
        }else if (dia == 28) {
            dia = 1;
            mes++;
        }else if (dia < 28 ){
            dia++;
        }
        break;
    }
    if (mes < 10 && dia < 10) {
        cout << year << "/0" << mes << "/0" << dia << endl;
    }else if (mes < 10) {
        cout << year << "/0" << mes << "/" << dia << endl;
    }else if (dia < 10) {
        cout << year << "/" << mes << "/0" << dia << endl;
    }else {
        cout << year << "/" << mes << "/" << dia << endl;
    }
}

int main() {
    Fecha fecha;
    fecha.menu();
    return 0;
}
