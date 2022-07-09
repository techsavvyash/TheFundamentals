/**
 * @file getPermutations.cpp
 *
 * @author @techsavvyash
 * @brief
 * @version 0.1
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */
/*
1 2 3 4 5 6


*/
// code for getPermutations problem here
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void getPermutations(vector<vector<int>> &permutations, vector<int> arr, int idx)
{
    // base case
    if (idx == arr.size())
    {
        permutations.push_back(arr);
        return;
    }

    // rec case

    for (int i = idx; i < arr.size(); i++)
    {
        swap(arr[i], arr[idx]);
        getPermutations(permutations, arr, idx + 1);
        swap(arr[i], arr[idx]); // backtracking step
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        // getting the array as input
        cin >> arr[i];
    }

    vector<vector<int>> permutations;

    getPermutations(permutations, arr, 0);

    // printing all the permutations
    for (int i = 0; i < permutations.size(); i++)
    {

        for (int j = 0; j < permutations[i].size(); j++)
        {
            cout << permutations[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}