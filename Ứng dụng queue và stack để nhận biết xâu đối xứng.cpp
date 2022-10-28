#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    queue<char> Qu;
    stack<char> St;
    for(int i = 0; i < s.length(); i++)
    {
        Qu.push(s[i]);
        St.push(s[i]);
    }
    while(!Qu.empty())
    {
        char FrontQu = Qu.front(); Qu.pop();
        char TopSt = St.top(); St.pop();
        if(FrontQu != TopSt)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
