#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Optimización de la entrada y salida estándar para programación competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Usamos 'long long' porque a y b pueden valer hasta 10^9, 
    // por lo que su suma superará el límite de un 'int' estándar de 32 bits.
    long long a, b;
    if (cin >> a >> b) {
        
        // El número mínimo de animales ocurre cuando maximizamos los gatos compartidos en el medio
        long long minimo = max(a, b) + 2;
        
        // El número máximo de animales ocurre cuando no hay ningún gato entre los dos perros (M = 0)
        long long maximo = a + b + 2;
        
        // Imprimimos los dos resultados separados por un espacio
        cout << minimo << " " << maximo << "\n";
    }
    
    return 0;
}
