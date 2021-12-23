#include <iostream>
#include <unordered_map>
#include <string>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long int x, n;
        cin >> x >> n;
        
        if(x%2) {
            switch(n%4) {
                case 0:
                cout << x << endl;
                break;
                case 1:
                cout << x + n << endl;
                break; 
                case 2:
                cout << x - 1 << endl;
                break ;
                case 3:
                cout << x - n - 1 << endl;
                break ; 
            }
        } else {
            switch(n%4) {
                case 0:
                cout << x << endl;
                break;
                case 1:
                cout << x - n << endl;
                break; 
                case 2:
                cout << x + 1 << endl;
                break ;
                case 3:
                cout << x + n + 1 << endl;
                break ; 
            }
        }
    }

    return 0;
}