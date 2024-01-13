#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <climits>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t;
    cin >> t;
    while(t--) {
        long long int n, freq1, freqOdd, maxArr = INT_MIN, maxFreq = INT_MIN;
        cin >> n;
        vector<long long int> arr;
        unordered_map<long long int, long long int> freq;
        bool flag = false;
        for(int i=0;i<n;i++) {
            long long int el;
            cin >> el;
            arr.push_back(el);
            freq[el] += 1;
            if(freq[el] > 2) {
                flag = true;
            }
        }
        
        if(flag) {
            cout << -1 << endl;
            continue ;
        }
        set<long long int,  greater<long long int>> unique;
        set<long long int> dups;
        for(auto entry: freq) {
            if(entry.second == 1) {
                freq1++ ;
                if(maxArr < entry.first) {
                    maxArr = entry.first ;
                }
                unique.insert(entry.first);
            } else if(entry.second > 1) {
                freqOdd++;
                if(maxFreq < entry.first) {
                    maxFreq = entry.first ;
                }
                unique.insert(entry.first);
                dups.insert(entry.first) ;
            }
        }

        if(maxArr > maxFreq) {
            if(dups.size() != 0) {
                set<long long int > :: iterator itrDup = dups.end() ;
                set<long long int, greater<long long int> > :: iterator itrUq = unique.end();
                itrUq-- ; itrDup-- ;
                while(itrUq != unique.begin()) {
                    cout << *itrUq << " ";
                    itrUq--;
                }
                cout << *itrUq << " ";
                while(itrDup != dups.begin()) {
                    cout << *itrDup << " ";
                    itrDup-- ;
                }
                cout << *itrDup << " " ;
                cout << endl ;
            } else {
                set<long long int > :: iterator itrDup = dups.begin() ;
                set<long long int, greater<long long int> > :: iterator itrUq = unique.begin();

                while(itrUq != unique.end()) {
                    cout << *itrUq << " ";
                    itrUq++;
                }
                while(itrDup != dups.end()) {
                    cout << *itrDup << " ";
                    itrDup++ ;
                }
                cout << endl ;
            } 
        } else {
                cout << -1 << endl;
            }
    }
    return 0;
}