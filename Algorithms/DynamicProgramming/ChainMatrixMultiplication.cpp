#include <iostream>
#include <climits>
using namespace std;


int chainMatrixMultiplication(int *dimensions, int n) {
    int m[256][256] = {0} ;
    int s[256][256] = {0} ;

    int j, min, q ;
    for(int d=1;d<n;d++) {
        for(int i=1; i <n + 1 -d;i++) {
            j = i + d ;
            min = INT_MAX;
            for(int k = 1;k<= j - i;k++) {
                q = m[i][k] + m[k+1][j] + dimensions[i-1]*dimensions[k]*dimensions[j] ;
                if(q < min) {
                    min = q ;
                    s[i][j] =  k;
                }

                m[i][j] = min ;
            }
        }
    }

    return m[1][n];
}


int main() {
    int n;
    cout << "Enter the number of matrices: " << endl;
    cin >> n;

    int *dimensions = new int[n + 1];

    for(int i = 0;i<n+1;i++ ) {
        cin >> dimensions[i] ;
    }

    cout << chainMatrixMultiplication(dimensions, n) << endl;
 
}