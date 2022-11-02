//Palindromes with Deque
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    deque<char> dq;
    for(ll i = 0; i < s.length(); i++)
    {
        dq.push_back(s[i]);
    }
    while(dq.size() > 1)
    {
        if(dq.front() != dq.back())
        {
            cout << "NO";
            return 0;
        }
        dq.pop_front();
        dq.pop_back();
    }
    cout << "YES";
    return 0;
}
