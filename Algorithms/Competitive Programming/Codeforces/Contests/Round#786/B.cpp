#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        int startingIdx = (25 * (str[0] - 'a'));
        // cout << "startingIdx: " << startingIdx << endl;
        if (str[1] > str[0])
        {
            cout << startingIdx + ((str[1] - 'a')) << endl;
        }
        else
        {
            cout << startingIdx + ((str[1] - 'a') + 1) << endl;
        }
    }
    return 0;
}