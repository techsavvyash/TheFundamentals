//problem code: DISTELE
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;
const long long int mod = 1e9 + 7 ;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t, n;
    cin >> t;
    vector<int> v;
    while(t--) {
        cin >> n;
        unordered_map<int, int> arr;
        bool flag = true ;
        for(int i=0;i<n;i++) {
            int e;
            cin >> e;
            arr[e]++;
            if(arr[e] > 1) flag = false;
            else v.push_back(e);
        }
        if(flag) {
            cout << pow(2, n) - 1 << endl;
            continue ;
        }
        long long int ways = 1;
        for(auto entry: arr) {
            ways = (ways*(entry.second + 1))%mod; //+1 for the no included choice
        }

        cout << (ways - 1) << endl;
    }
}