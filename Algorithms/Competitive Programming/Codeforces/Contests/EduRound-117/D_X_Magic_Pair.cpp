#include <bits/stdc++.h>
using namespace std;

void func(long long int a, long long int b, long long int x) {
    if( a == x || b == x) {
        cout << "YES" << endl;
        return;
    }

    if(a < x && b < x) {
        cout << "NO" << endl;
        return;
    }

    if(a > b) {
        a = abs(a - b);
    } else {
        b = abs(a - b);
    }

    func(a, b, x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t;
    cin >> t;
    while(t--) {
        long long int x, a, b;
        cin >> a >> b >> x;
        //func(a, b, x);
        if(a == x || b == x) {
            cout << "YES" << endl;
            continue;
        } 

        if(a < x && b < x) {
            cout << "NO" << endl;
            continue ;
        }

        

        while(/*abs(a-b) > x*/ (a > x || b > x) && a != 0 && b != 0) {
            if(a > b) {
                a = abs(a - b);
            } else {
                b = abs(a - b);
            }
        }
        
        if(x == abs(a - b) || x == a || x == b) {
            cout << "YES" << endl;
            continue ;
        } else if(abs(min(a, b) - abs(a-b)) == x) {
            cout << "YES" << endl;
            continue;
        } else {
            //cout << "a: " << a << " b: " << b << endl;
            cout << "NO" << endl;
        }


    }
    return 0;
}