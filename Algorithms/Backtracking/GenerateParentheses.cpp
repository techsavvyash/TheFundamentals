/**
 * @file GenerateParentheses.cpp
 *
 * @author Yash Mittal (mittal.yash12@hotmail.com)
 * @brief logic here
 * @version 0.1
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */

// code for the generate parenthesis problem here
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getParens(vector<string> &strs, string str, int open, int close, int n)
{
    // base case
    if (str.length() == 2 * n)
    {
        strs.push_back(str);
        str = "";
        return;
    }

    // rec case

    if (open < n)
    {
        str += '(';
        getParens(strs, str, open + 1, close, n);
        str.pop_back(); // backtracking step
    }

    if (close < open)
    {
        str = +')';
        getParens(strs, str, open, close + 1, n);
        str.pop_back();
    }
}

int main()
{
    int n;
    cin >> n; // number of pairs of brackets
    vector<string> strs;
    string str = "";

    getParens(strs, str, 0, 0, n);

    return 0;
}