#include <iostream>
#include <vector>
#include <string>
#include <cmath>

// Funkcja obliczająca największy wspólny dzielnik
long long maxdivisor(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Rozszerzony algorytm Euklidesa
long long EkulidesInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Algorytm szybkiego potęgowania
long long fastexpon(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Funkcja szyfrowania
std::vector<long long> encryption(const std::string& message, long long e, long long n) {
    std::vector<long long> encryptedMessage;
    for (char c : message) {
        long long m = static_cast<long long>(c);
        encryptedMessage.push_back(fastexpon(m, e, n));
    }
    return encryptedMessage;
}

// Funkcja deszyfrowania
std::string decryption(const std::vector<long long>& encryptedMessage, long long d, long long n) {
    std::string decryptedMessage;
    for (long long c : encryptedMessage) {
        long long m = fastexpon(c, d, n) % 256;
        decryptedMessage.push_back(static_cast<char>(m));
    }
    return decryptedMessage;
}

// Funkcja ataku brute force
void bruteForceAttack(const std::vector<long long>& encryptedMessage, long long n, long long e) {
    long long phi = (13 - 1) * (17 - 1); // symulacja udanego ataku gdzie klucze sa znane a wartosci male
    for (long long possibleD = 1; possibleD < n; ++possibleD) {
        if ((e * possibleD) % phi != 1)
            continue;

        std::string decryptedMessage = decryption(encryptedMessage, possibleD, n);
        std::cout << "Znaleziony klucz prywatny: " << possibleD << "\n";
        std::cout << "Odszyfrowana wiadomosc: " << decryptedMessage << "\n";
        return;
    }
    std::cout << "Atak brute force nie powiodl się.\n";
}

//funkcja pokazująca udany atak
void demonstrateSuccessfulAttack() {
    long long p = 13, q = 17;
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);
    long long e = 5;
    long long d = EkulidesInverse(e, phi);

    std::cout << "Publiczny klucz: (n = " << n << ", e = " << e << ")\n";
    std::cout << "Prywatny klucz: (n = " << n << ", d = " << d << ")\n";
    std::string message = "Test";
    std::vector<long long> encryptedMessage = encryption(message, e, n);
    std::cout << "Oryginalna wiadomosc: " << message << "\n";
    std::cout << "Zaszyfrowany tekst: ";
    for (long long c : encryptedMessage) std::cout << c << " ";
    std::cout << "\n";

    bruteForceAttack(encryptedMessage, n, e);
}

//funkcja pokazująca nieudany atak z zabezpieczeniami 
void demonstrateSecuredSystem() {
    long long p = 101, q = 103;
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);
    long long e = 7;
    long long d = EkulidesInverse(e, phi);

    std::cout << "Publiczny klucz: (n = " << n << ", e = " << e << ")\n";
    std::cout << "Prywatny klucz: (n = " << n << ", d = " << d << ")\n";
    std::string message = "Test";
    std::vector<long long> encryptedMessage = encryption(message, e, n);
    std::cout << "Oryginalna wiadomosc: " << message << "\n";
    std::cout << "Zaszyfrowany tekst: ";
    for (long long c : encryptedMessage) std::cout << c << " ";
    std::cout << "\n";

    int maxAttempts = 10;
    int attempts = 0;
    for (long long possibleD = 1; possibleD < n; ++possibleD) {
        if (++attempts > maxAttempts) {
            std::cout << "Zbyt wiele prob. System zablokowany.\n";
            return;
        }
        if ((e * possibleD) % phi == 1) {
            std::cout << "Potencjalny klucz: " << possibleD << ", ale system uniemożliwił atak.\n";
            return;
        }
    }
    std::cout << "System bezpieczny przed atakiem brute force.\n";
}

int main() {
    std::cout << "Udany atak:\n";
    demonstrateSuccessfulAttack();

    std::cout << "\nOgraniczona liczba prob atak nieudany:\n";
    demonstrateSecuredSystem();

    return 0;
}
