#include <iostream>
using namespace std;

float Addition(float a, float b) { return a + b; }

float Subtraction(float a, float b) { return a - b; }

float Multiplication(float a, float b) { return a * b; }

float Division(float a, float b) {
    if (b != 0) {
        return a / b;
    }else {
        cerr << "Error: No se puede dividir entre 0" << endl;
        return 0;
    }
}

typedef float (*lpfnOperation)(float, float);
lpfnOperation vpf[4] = { &Addition, &Subtraction, &Multiplication, &Division };

int main() {
    float a, b, c; int opt;

    cout << "Ingresar a:"; cin >> a; cout << endl << "Ingresar b:";cin >> b;
    cout << endl<< "Ingresar una operacion (0-Addition, 1-Subtraction, 2-Multiplication, 3-Division): ";cin >> opt;

    if (opt >= 0 && opt < 4) {
        c = (*vpf[opt])(a, b);
        cout << endl<<"Resultado: " << c << endl;
    } else {
        cerr << "Error: Operacion Invalida" << endl;
    }

    return 0;
}
