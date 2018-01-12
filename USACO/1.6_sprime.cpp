/*
ID: wanying1
PROG: sprime
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
using namespace std;

bool isPrime(int n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void printSuperPrimes(int prev, int n, int digits, ofstream &fout) {
    if (digits == n) {
        if (isPrime(prev + 1)) fout << prev + 1 << endl;
        if (isPrime(prev + 3)) fout << prev + 3 << endl;
        if (isPrime(prev + 7)) fout << prev + 7 << endl;
        if (isPrime(prev + 9)) fout << prev + 9 << endl;
    }
    else {
        if (isPrime(prev + 1)) printSuperPrimes(10*(prev + 1), n, digits+1, fout);
        if (isPrime(prev + 3)) printSuperPrimes(10*(prev + 3), n, digits+1, fout);
        if (isPrime(prev + 7)) printSuperPrimes(10*(prev + 7), n, digits+1, fout);
        if (isPrime(prev + 9)) printSuperPrimes(10*(prev + 9), n, digits+1, fout);
    }
}

int main() {
    ofstream fout("sprime.out");
    ifstream fin("sprime.in");
    int n;
    fin >> n;
    if (n == 1) fout << "2\n3\n5\n7\n";
    else {
        printSuperPrimes(20, n, 2, fout);
        printSuperPrimes(30, n, 2, fout);
        printSuperPrimes(50, n, 2, fout);
        printSuperPrimes(70, n, 2, fout);
    }
    return 0;
}
