#include <iostream>
#include <vector>

using namespace std;

bool is_prime(long long num) {
    if (num < 2) return false;
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    if (!(cin >> n >> m)) return 0;

    // Find the smallest prime P >= n - 1
    long long P = n - 1;
    while (!is_prime(P)) {
        P++;
    }

    // Both shortest path (1 to n) and MST weight equal P
    cout << P << " " << P << "\n";

    // Build the path 1 -> 2 -> ... -> n
    // First n - 2 edges have weight 1
    for (long long i = 1; i <= n - 2; i++) {
        cout << i << " " << i + 1 << " 1\n";
    }

    // Last edge on the path makes the total weight equal to P
    long long last_edge_weight = P - (n - 2);
    cout << n - 1 << " " << n << " " << last_edge_weight << "\n";

    // Add remaining m - (n - 1) edges with maximum weight 10^9
    long long edges_needed = m - (n - 1);
    const long long MAX_W = 1000000000;

    for (long long u = 1; u <= n && edges_needed > 0; u++) {
        // Start v at u + 2 because (u, u + 1) is already used in the path
        for (long long v = u + 2; v <= n && edges_needed > 0; v++) {
            cout << u << " " << v << " " << MAX_W << "\n";
            edges_needed--;
        }
    }

    return 0;
}
