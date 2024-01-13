#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


void computeLPSArray(char* pat, int M, int* lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, string txt, vector<ll> &v)
{
	int M = strlen(pat);
	int N = txt.length();

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int lps[M];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			//printf("Found pattern at index %d ", i - j);
			v.push_back(i - j) ;
            j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

// Fills lps[] for given patttern pat[0..M-1]



int main() {
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        ll n; string str ;
        vector<ll> v1;
        vector<ll> v2 ;
        cin >> n ;
        cin >> str ;
	    char pat1[] = "10" ;
        char pat2[] = "01" ;
	    KMPSearch(pat1, str, v1);
        KMPSearch(pat2, str, v2) ;
        if(v1.size() == 0 &&  v2.size() == 0) {
                cout << ((n/2)%2 ? "JJ" : "UTTU") << endl ;
                continue ;
            }

        if(v1.size() == n/2 || v2.size() == n/2) {
            cout << "UTTU" << endl ;
            continue ;
        }
        vector<ll> idxs1 ;
        vector<ll> idxs0 ;
        if(v1.size() > v2.size()) {
            //case when predominant pattern is 10
            for(int i = 0;i<n;i++) {
                if(i%2 == 0 && str[i] != 1) {
                    idxs1.push_back(i) ;
                } else if(i%2 == 1 && str[i] != 0) {
                    idxs1.push_back(i) ;
                }
            }
            int count = 0;
            for(ll i = 0;i<idxs1.size() - 1;i++) {
                if(idxs1[i + 1] == idxs1[i] + 1) {
                    continue ;
                } else {
                    count++ ;
                }
            }

            if(count%2 == 0) {
                cout << "UTTU" << endl;
            } else {
                cout << "JJ" << endl;
            }


        } else {
            for(int i = 0;i<n;i++) {
                if(i%2 == 0 && str[i] != 0) {
                    idxs1.push_back(i) ;
                } else if(i%2 == 1 && str[i] != 1) {
                    idxs1.push_back(i) ;
                }
            }
            int count = 0;
            for(ll i = 0;i<idxs1.size() - 1;i++) {
                if(idxs1[i + 1] == idxs1[i] + 1) {
                    continue ;
                } else {
                    count++ ;
                }
            }
            if(count%2 == 0) {
                cout << "JJ" << endl;
            } else {
                cout << "UTTU" << endl;
            }
        }

    }
 return 0;
}