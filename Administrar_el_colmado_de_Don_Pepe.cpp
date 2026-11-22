#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

	// DATOS DEL SISTEMA:

	const int DIAS = 7;
	string dias[DIAS] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo" };
	double ventas[DIAS];

	double total_semana = 0.0, promedio_diario = 0.0;
	double venta_mayor, venta_menor;
	string dia_mayor, dia_menor;

	string dias_sobre_promedio[DIAS];
	int cant_sobre_promedio = 0;

	cout << fixed << setprecision(2);

	cout << "\n\t==== SISTEMA DE ADMINISTRACION ====" << endl;
	cout << "\t=Administra las ventas de la semana=" << endl;

	// Recorrido de lectura y confirmación de datos:

	cout << "\nDigita los montos totales por dia:\n" << endl;

	for (int i = 0; i < DIAS; i++) {
		do {
			cout << "Ventas del " << dias[i] << ": RD$ ";
			cin >> ventas[i];

			if (ventas[i] < 0) {
				cout << "\nMonto incorrecto, vuelve a intentarlo.\n" << endl;
			}
		} while (ventas[i] < 0);
	}

	// Impresion y acumulacion de los montos totales:

	cout << "\n\t==== VENTAS DEL COLMADO DON PEPE ====\n" << endl;

	for (int i = 0; i < DIAS; i++) {
		cout << (i + 1) << "# " << dias[i] << ": RD$ " << ventas[i] << endl;
		total_semana += ventas[i];
	}

	promedio_diario = total_semana / DIAS;

	// Busqueda de mayor y menor venta:

	venta_mayor = ventas[0];
	venta_menor = ventas[0];
	dia_mayor = dias[0];
	dia_menor = dias[0];

	for (int i = 1; i < DIAS; i++) {
		if (ventas[i] > venta_mayor) {
			venta_mayor = ventas[i];
			dia_mayor = dias[i];
		}
		else if (ventas[i] < venta_menor) {
			venta_menor = ventas[i];
			dia_menor = dias[i];
		}
	}

	// Registro de dias que superaron el promedio:

	for (int i = 0; i < DIAS; i++) {
		if (ventas[i] > promedio_diario) {
			dias_sobre_promedio[cant_sobre_promedio] = dias[i];
			cant_sobre_promedio++;
		}
	}

	// Calculos estadisticos de la semana:

	cout << "\n" << endl;
	cout << "Total semanal: RD$ " << total_semana << endl;
	cout << "Promedio diario: RD$ " << promedio_diario << endl;
	cout << "Mayor venta: " << dia_mayor << " RD$ " << venta_mayor << endl;
	cout << "Menor venta: " << dia_menor << " RD$ " << venta_menor << endl;

	cout << "Dias sobre el promedio: " << cant_sobre_promedio;
	if (cant_sobre_promedio > 0) {
		cout << " -> ";
		for (int i = 0; i < cant_sobre_promedio; i++) {
			cout << dias_sobre_promedio[i];
			if (i < cant_sobre_promedio - 1) {
				cout << ", ";
			}
		}
	}

	return 0;
}