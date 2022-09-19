//Cho 1 chuỗi biểu thức chỉ gồm các phép toán cộng, trừ và nhân.
//Tính giá trị của biểu thức đó.
//VD: 3*4+5 => 17

#define ll long long
#define INF 1e18
#define fi first
#define se second
#define pb push_back
#include <bits/stdc++.h>
using namespace std;

ll a[1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    a[(int)'+'] = 1;
    a[(int)'-'] = 1;
    a[(int)'*'] = 2;
    a[(int)'/'] = 2;
    a[(int)'^'] = 3;
    a[(int)'('] = -1;
    string s, ans = "";
    getline(cin, s);
    stack<char> st;
    st.push('.'); // Đệm 1 phần tử vào stack để tránh stack bị rỗng khó xử lí
    for(ll i = 0; i < s.size(); i++)
    {
        if(isdigit(s[i]))
        {
            ans += s[i];
            continue;
        }
        ll x = (int)s[i];
        if(a[x] > 0)
        {
            char c = st.top();
            while(a[(int)c] >= a[x])
            {
                ans += st.top();
                st.pop();
                c = st.top();
            }
            st.push(s[i]);
        }
        if(s[i] == '(')st.push(s[i]);
        if(s[i] == ')')
        {
            while(st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop(); //pop dau ngoac '('
        }
    }
    while(st.top() != '.')
    {
        ans += st.top();
        st.pop();
    }
    cout << ans << '\n';
    stack<ll> newst;
    for(ll i = 0; i < ans.size(); i++)
    {
        if(isdigit(ans[i])){ll x = (ll)ans[i] - 48; newst.push(x); continue;}
        if(a[(int)ans[i]] > 0)
        {
            ll s1 = newst.top(); newst.pop();
            ll s2 = newst.top(); newst.pop();
            ll s3;
            if(ans[i] == '+')s3 = s2 + s1;
            if(ans[i] == '-')s3 = s2 - s1;
            if(ans[i] == '*')s3 = s2 * s1;
            if(ans[i] == '/')s3 = s2 / s1;
            if(ans[i] == '^')s3 = pow(s2, s1);
            newst.push(s3);
        }
    }
    cout << newst.top();
    return 0;
}
