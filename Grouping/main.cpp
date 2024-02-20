#include <bits/stdc++.h>

using namespace std;
string Grouping (string s)
{
    string temp;
    temp = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i-1])
            temp += s[i];
        else
        {
            temp += "   ";
            temp += s[i];
        }
    }
    return temp;
}

int main()
{
    cout << Grouping ("younnessss");
    return 0;
}