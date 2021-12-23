#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int> > v;
    v[0].push_back(1);
    cout << v[0][1] ;
    return 0;
}