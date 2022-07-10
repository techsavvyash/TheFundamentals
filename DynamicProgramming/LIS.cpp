#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n; // num of elements

    vector<int> arr(n); // array of elements

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // getting the array as input
    }

    vector<int> dp(n); // creating the dp array

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxEl = dp[0];

    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
        maxEl = max(maxEl, dp[i]);
    }
    cout << endl;

    cout << "Length of the longest increasing subsequence is: " << maxEl << endl;

    return 0;
}
