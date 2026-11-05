#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        long long count = 0;

        // Billetes de 100
        count += n / 100;
        n %= 100;

        // Billetes de 20
        count += n / 20;
        n %= 20;

        // Billetes de 10
        count += n / 10;
        n %= 10;

        // Billetes de 5
        count += n / 5;
        n %= 5;

        // Billetes de 1
        count += n;

        cout << count << "\n";
    }

    return 0;
}