#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isBalance(string s)
{
    stack<char> st;
    st.push('x');
    bool kt = true;
    for(ll i = 0; i < static_cast<ll>(s.length()); i++)
    {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')st.push(s[i]);
        if(s[i] == '}')
        {
            if(st.top() != '{')kt = false;
            else st.pop();
        }
        if(s[i] == ']')
        {
            if(st.top() != '[')kt = false;
            else st.pop();
        }
        if(s[i] == ')')
        {
            if(st.top() != '(')kt = false;
            else st.pop();
        }
    }
    if(st.size() != 1)kt = false;
    return kt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    while(n--)
    {
      string s; cin >> s;
      (isBalance(s) == 1) ? cout << "YES\n" : cout << "NO\n";   
    }
    return 0;
}
