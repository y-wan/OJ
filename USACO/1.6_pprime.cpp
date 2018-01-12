/*
ID: wanying1
PROG: pprime
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
using namespace std;

bool isPrime(int n) {  // n >= 5
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void printPrimePalindromes(int a, int b, ofstream &fout) {
    // 1-digit numbers
    if (a <= 5 && b >= 5) fout << 5 << endl;
    if (a <= 7 && b >= 7) fout << 7 << endl;

    // 2-digit numbers
    if (a <= 11 && b >= 11) fout << 11 << endl;

    // 3-digit numbers
    for (int i = 1; i <= 9; i += 2) {
        for (int j = 0; j <= 9; ++j) {
            int n = i*101 + j*10;
            if (n >= a && n <= b && isPrime(n)) fout << n << endl;
        }
    }

    // 4-digit numbers
    for (int i = 1; i <= 9; i += 2) {
        for (int j = 0; j <= 9; ++j) {
            int n = i*1001 + j*110;
            if (n >= a && n <= b && isPrime(n)) fout << n << endl;
        }
    }

    // 5-digit numbers
    for (int i = 1; i <= 9; i += 2) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                int n = i*10001 + j*1010 + k*100;
                if (n >= a && n <= b && isPrime(n)) fout << n << endl;
            }
        }
    }

    // 6-digit numbers
    for (int i = 1; i <= 9; i += 2) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                int n = i*100001 + j*10010 + k*1100;
                if (n >= a && n <= b && isPrime(n)) fout << n << endl;
            }
        }
    }

    // 7-digit numbers
    for (int i = 1; i <= 9; i += 2) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                for (int l = 0; l <= 9; ++l) {
                    int n = i*1000001 + j*100010 + k*10100 + l*1000;
                    if (n >= a && n <= b && isPrime(n)) fout << n << endl;
                }
            }
        }
    }

    // 8-digit numbers
    for (int i = 1; i <= 9; i += 2) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                for (int l = 0; l <= 9; ++l) {
                    int n = i*10000001 + j*1000010 + k*100100 + l*11000;
                    if (n >= a && n <= b && isPrime(n)) fout << n << endl;
                }
            }
        }
    }
}

int main() {
    ofstream fout("pprime.out");
    ifstream fin("pprime.in");
    int a, b;
    fin >> a >> b;
    printPrimePalindromes(a, b, fout);
    return 0;
}
