#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned long long int a;
    cin >> a;
    long double l = sqrt(a /(2 * 1.0));
    long double b = 1.0/l ;
    cout << 2*(l+b) << endl;
    return 0;
}