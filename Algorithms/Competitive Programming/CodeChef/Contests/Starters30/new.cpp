#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int moneay = p;
        int lI = -1;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (moneay >= arr[i])
            {
                moneay -= arr[i];
                count += 1;
            }
            else
            {
                if (moneay >= ((arr[i] + 1) / 2))
                {
                    count += 1;
                    break;
                }
            }
        }

        cout << count << endl;
    }
}