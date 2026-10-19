#include <iostream>
#include <map>

using namespace std;

int main() {
    // Optimización de la entrada y salida estándar de C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    map<int, int> frecuencias;
    int mayores_a_cero = 0;

    for (int i = 0; i < n; ++i) {
        int ingrediente;
        cin >> ingrediente;
        frecuencias[ingrediente]++;
        if (ingrediente > 0) {
            mayores_a_cero++;
        }
    }

    // El MEX actual que deseamos agregar a la secuencia B
    int mex_buscado = 0;

    while (true) {
        if (mex_buscado == 0) {
            // Para obtener un 0 en B, necesitamos cualquier elemento mayor a 0 al inicio
            if (mayores_a_cero > 0) {
                mayores_a_cero--; // Gastamos un elemento mayor a 0
                mex_buscado++;
            } else {
                // Si no hay elementos mayores a 0, el 0 nunca aparecerá en B
                break;
            }
        } else {
            // Para obtener el valor 'mex_buscado' en B, necesitamos el ingrediente 'mex_buscado - 1'
            int ingrediente_necesario = mex_buscado - 1;

            if (frecuencias[ingrediente_necesario] > 0) {
                frecuencias[ingrediente_necesario]--;
                
                // Si el ingrediente que gastamos era mayor a cero, 
                // debemos actualizar también nuestro contador global de "mayores a cero"
                if (ingrediente_necesario > 0) {
                    mayores_a_cero--;
                }
                mex_buscado++;
            } else {
                // Si no tenemos el ingrediente necesario para avanzar, nos estancamos aquí
                break;
            }
        }
    }

    // El valor en el que se detuvo 'mex_buscado' es el primer número que falta en B
    cout << mex_buscado << "\n";

    return 0;
}
