#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nA, nB;
    if (!(cin >> nA >> nB)) return 0;

    int k, m;
    cin >> k >> m;

    vector<long long> a(nA);
    for (int i = 0; i < nA; ++i) {
        cin >> a[i];
    }

    vector<long long> b(nB);
    for (int i = 0; i < nB; ++i) {
        cin >> b[i];
    }


    if (a[k - 1] < b[nB - m]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}