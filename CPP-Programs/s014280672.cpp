#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>
static double pi = M_PI;
static void k(int n, std::complex<double>& p1, std::complex<double>& p2) {
    if (n <= 0) {
        return;
    }
    std::complex<double> s = (p1 * 2. + p2) / 3.;
    std::complex<double> t = (p1 + p2 * 2.) / 3.;
    std::complex<double> u = s + (t - s) * std::polar(1., pi / 3.);
    k(n - 1, p1, s);
    std::cout << s.real() << ' ' << s.imag() << std::endl;
    k(n - 1, s, u);
    std::cout << u.real() << ' ' << u.imag() << std::endl;
    k(n - 1, u, t);
    std::cout << t.real() << ' ' << t.imag() << std::endl;
    k(n - 1, t, p2);
}
int main() {
    int n;
    std::cin >> n;
    std::complex<double> p1 { 0., 0. }, p2 { 100., 0. };
    std::cout << std::fixed << std::setprecision(6);
    std::cout << p1.real() << ' ' << p1.imag() << std::endl;
    k(n, p1, p2);
    std::cout << p2.real() << ' ' << p2.imag() << std::endl;
}

