#include <iostream>

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w;
    cin >> w;

    // Check if the weight is even and strictly greater than 2
    if (w % 2 == 0 && w > 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
