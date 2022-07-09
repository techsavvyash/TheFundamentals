#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string remDups(string str, int idx, string res)
{
    if (idx >= (str.length() - 1))
    {
        if ((idx == str.length() - 1) && str[idx] != str[idx - 1])
        {
            res += str[idx];
        }

        return res;
    }

    if ((idx == 0 && str[idx] != str[idx + 1]) || (idx > 0 && str[idx] != str[idx + 1] && str[idx] != str[idx - 1]))
    {
        res += str[idx];
    }

    return remDups(str, idx + 1, res);
}
int main()
{
    string str;
    cin >> str;
    string res = "";
    res = remDups(str, 0, res);
    bool loop = true;
    // while (loop)
    // {
    //     if (res.length() == 0 || str.length() == 0)
    //     {
    //         break;
    //     }
    //     bool callRecur = false;
    //     for (int i = 0; i < res.length() - 1; i++)
    //     {
    //         if (res[i] == res[i + 1])
    //         {
    //             str = res;
    //             callRecur = true;
    //             break;
    //         }
    //     }

    //     if (callRecur)
    //     {
    //         res = "";
    //         res = remDups(str, 0, res);
    //     }
    //     else
    //     {
    //         loop = false;
    //     }
    // }

    while (loop)
    {
        if (str.length() == 0 || res.length() == 0)
        {
            break;
        }
        str = res;
        res = "";
        res = remDups(str, 0, res);
        if (res == str)
        {
            break;
        }
    }

    //  cout << "res: " << res << endl;
    cout << "===================================OUTPUT=============================" << endl;
    cout << res << endl;
    return 0;
}