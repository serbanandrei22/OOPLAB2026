#include <iostream>
#include <vector>
using namespace std;
int prim(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int cmmdc(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void problema_a() {
    int n;
    cout << "\n--- Problema A: Primele n numere prime ---\n";
    cout << "Introduceti n: ";
    cin >> n;

    int gasite = 0;
    int numar = 2;

    cout << "Rezultat A: ";
    while (gasite < n) {
        if (prim(numar) == 1) {
            cout << numar << " ";
            gasite++;
        }
        numar++;
    }
    cout << endl;
}
void problema_b() {
    int n;
    cout << "\n--- Problema B: Subsecventa relativ prima ---\n";
    cout << "Introduceti numarul de elemente: ";
    cin >> n;

    if (n <= 0) return;
    if (n == 1) {
        int x; cin >> x;
        cout << "Rezultat B: " << x << endl;
        return;
    }

    vector<int> v(n);
    cout << "Introduceti elementele: ";
    for (int i = 0; i < n; i++) cin >> v[i];

    int max = 1;
    int curent = 1;
    int final = 0;

    for (int i = 1; i < n; i++) {

        if (cmmdc(v[i], v[i - 1]) == 1) {
            curent++;
            if (curent > max) {
                max = curent;
                final = i;
            }
        } else {
            curent = 1;
        }
    }
    cout << "Rezultat B (cea mai lunga secventa): ";
    for (int i = final - max + 1; i <= final; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main(){
    problema_a();
    problema_b();
    return 0;
}