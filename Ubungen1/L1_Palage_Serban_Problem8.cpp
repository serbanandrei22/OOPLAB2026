
#include <iostream>
#include <vector>
using namespace std;
int prim(int n) {
    if (n<2) return 0;
    if (n==2) return 1;
    if (n%2==0) return 0;
    for ( int i=3 ; i*i<=n ; i+=2 ) {
        if ( n%i==0 ) return 0;
    }
return 1;
}

void problema_a() {
    int n;
    cout << "\n--- Problema A: Perechi de numere gemene ---\n";
    cout << "Introduceti n: ";
    if (!  (cin >> n)||n<=0)return;
    int x=0;
    int p=3;
    cout<<"Perechile de numere gemene sunt: ";
    while (x<n) {
        int primul=prim(p);
        int doi=prim(p+2);
        if (primul==1 && doi==1) {
            cout<<"Perechea"<<x<<":("<<p<<","<<p+2<<")"<<endl;
            x++;
        }
        p++;

    }
}
void problema_b() {
    int n;
    cout << "\n--- Problema B: Subsecventa descrescatoare ---\n";
    cout << "Introduceti numarul de elemente din vector: ";
    cin >> n;
    if (n<=0)
        return ;
    vector<int> v(n);
    cout<<"Introduceti elemente din vector: ";
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int max=1;
    int curent=1;
    int final=0;
    for (int i=1; i<n; i++) {
        if (v[i]<v[i-1]) {
            curent++;
            if (curent > max) {
                max=curent;
                final=i;
            }
        }
        else { curent=1; }
    }
    cout<<"Cea mai lunga secventa este: ";
    for (int i=final-max+1;i<=final;i++)
    { cout<<v[i]<<" "; }
    cout<<endl;
}
int main() {
    problema_a();
    problema_b();
    return 0;
}