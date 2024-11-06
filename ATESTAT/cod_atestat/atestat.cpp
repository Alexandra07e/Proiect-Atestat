#include <iostream>
#include <cmath>

using namespace std;

void comenzi() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "1. Suma dintre oglinditul lui n si oglinditul lui m." << endl;
    cout << "2. Verificare daca numarul x este prim." << endl;
    cout << "3. Determinarea celui mai mare divizor comun (cmmdc) "
        "a doua numere n si m" << endl;
    cout << "4. Sa se afiseze toate numerele din intervalul [1000,99999] \n"
        "care au proprietatea ca atat ele cat si oglinditul lor sunt prime.\n";
    cout << "5. Sa se afiseze primii n termeni ai sirului lui Fibonacci.\n";
    cout << "6. Sa se afiseze primele n (n < 101) numere prime folosind Ciurul lui Eraostene\n";
    cout << "7. Ordonarea si interclasarea a doi vectori cu n, m elemente.\n"
        "(cei doi vectori de intrare sunt ordonati crescator)\n";
    cout << "8. Afiseaza il afiseaza pe Darth Vader din Star Wars.\n";
    cout << "0. Programul ia sfarsit.\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Numarul problemei dorite: ";
}

int oglindire(int n) {
    int oglindit = 0;
    while (n) {
        oglindit = oglindit * 10 + n % 10;
        n = n / 10;
    }
    return oglindit;
}

int prim(int x) {
    bool ok = true;
    for (int d = 2; d <= x / 2 && ok; d++)
        if (x % d == 0)
            ok = false;
    return ok;
}

int cmmdc(int a, int b) {
    while (a != b)
        if (a > b)
            a -= b;
        else
            b -= a;
    return a;
}

void fibonacci(unsigned long n) {
    unsigned long f1 = 1, f2 = 1, c;
    cout << f1 << " " << f2 << " ";
    for (unsigned long i = 3; i <= n; i++) {
        c = f1 + f2;
        cout << c << " ";
        f1 = f2;
        f2 = c;
    }
}
int v[100];
void Eratostene(int n) {
    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i <= sqrt(n); i++)
        if (v[i] == 0)
            for (int j = 2; j <= n / i; j++)
                v[i * j] = 1;
}

void cin_vector(int x[100], int n) {
    for (int i = 0; i < n; i++)
        cin >> x[i];
}

void ord_intr(int a[100], int b[100], int c[200], int n, int m) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    if (i <= n) {
        for (int p = i; p < n; p++)
            c[k++] = a[p];
    }
    if (j <= m)
        for (int p = j; p < m; p++)
            c[k++] = b[p];
    for (int p = 0; p < k; p++)
        cout << c[p] << " ";
}

void darthVader() {
    cout << ""
        "                      .-.\n"
        "                      |_:_|\n"
        "                     /(_Y_)\\\n"
        "|.\\                 ( \\/M\\/ )\n"
        "\\'.\\              _.'-/'-'\\-'._\n"
        "  \\':\\          _/.--'[[[[]'--.\\_\n"
        "    \\':\\       /_'  : |::\"| :  '.\\\n"
        "      \\':\\    //   ./ |ooo| \\.'  :\\\n"
        "        \\':\\ _:'..' \\_|___|_/ :   :|\n"
        "          \\':\\  .'  |_[___]_|  :.':\\\n"
        "            [::\\ |  :  | |  :   ; : \\\n"
        "             '-'   \\/'.| |.' \\  .;.' |\n"
        "             |\\_    \\  '-'   :       |\n"
        "             |  \\    \\ .:    :   |   |\n"
        "             |   \\    | '.   :    \\  |\n"
        "             /       \\   :. .;       |\n"
        "            /     |   |  :__/     :  \\\\\n"
        "           |  |   |    \\:   | \\   |   ||\n"
        "          /    \\  : :  |:   /  |__|   /|\n"
        "          |     : : :_/_|  /'._\\  '--|_\\\n"
        "          /___.-/_|-'   \\  \\\n"
        "                         '-'"
        "\n";
}

int main() {
    int tasta;
    int x, n, m, a[100], b[100], c[200];

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t Selectati numarul unei probleme pentru a o executa: \n";
    comenzi();

    do {
        cin >> tasta;
        switch (tasta) {
        case 0:
            cout << "Sfarsit program..." << endl;
            break;
        case 1:
            cout << "n="; cin >> n;
            cout << "m="; cin >> m;
            cout << oglindire(n) + oglindire(m) << endl;
            comenzi();
            break;
        case 2:
            cout << "x="; cin >> x;
            if (prim(x))
                cout << "Numarul " << x << " este numar prim. \n";
            else
                cout << "Numarul " << x << " NU este numar prim. \n";
            comenzi();
            break;
        case 3:
            cout << "n="; cin >> n;
            cout << "m="; cin >> m;
            cout << cmmdc(n, m) << endl;
            comenzi();
            break;
        case 4:
            for (x = 1000; x < 100000; x++) {
                if (prim(x) && prim(oglindire(x)))
                    cout << x << " ";
            }
            cout << endl;
            comenzi();
            break;
        case 5:
            cout << "n="; cin >> n;
            fibonacci(n);
            cout << endl;
            comenzi();
            break;
        case 6:
            cout << "n="; cin >> n;
            Eratostene(n);
            for (int i = 1; i <= n; i++)
                if (!v[i])
                    cout << i << " ";
            cout << endl;
            comenzi();
            break;
        case 7:
            cout << "Cate elemente are vectorul A? "; cin >> n;
            cout << "Elementele vectorului A: "; cin_vector(a, n);
            cout << "Cate elemente are vectorul B? "; cin >> m;
            cout << "Elementele vectorului B: "; cin_vector(b, m);
            ord_intr(a, b, c, n, m);
            cout << endl;
            comenzi();
            break;
        case 8:
            darthVader();
            comenzi();
            break;
        default:
            cout << "Numarul introdus este incorect, incercati din nou." << endl;
            comenzi();
            break;
        }
    } while (tasta != 0);
    return 0;
}
