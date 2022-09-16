#define ll long long
#define INF 1e18
#define fi first
#define se second
#define pb push_back
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        stack<ll> st;
        ll m[1001] = {}, dig = 1;
        for(ll i = 0; i < s.length(); i++)
        {
            if(s[i] == '('){st.push(i); continue;}

            ll j = st.size(), pre = i;
            string num = "";

            while(isdigit(s[i+1]) != 0) //s[i+1] la so
            {
                num += s[i+1];
                i++;
            }

            dig = 1;
            if(num != "")dig = stoll(num);

            if(s[pre] == ')')
            {
                m[j] *= dig;
                m[j - 1] += m[j];
                m[j] = 0;
                st.pop();
            }

            if(s[pre] == 'C')m[j] += 12*dig;
            if(s[pre] == 'H')m[j] += dig;
            if(s[pre] == 'O')m[j] += 16*dig;
        }
        cout << m[0] << "\n";
    }
    return 0;
}
