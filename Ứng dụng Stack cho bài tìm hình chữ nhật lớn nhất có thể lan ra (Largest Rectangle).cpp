// Largest Rectangle -> Hackerrank
#define ll long long
#define INF 1e18
#define fi first
#define se second
#define pb push_back
#include <bits/stdc++.h>
using namespace std;

ll a[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin >> n;
    for(ll i = 1; i <= n; i++)cin >> a[i];
    stack<ll> st;
    ll mx = 0;
    a[0] = 0;
    a[n + 1] = 0;
    st.push(0);
    for(ll i = 1; i <= n + 1; i++)
    {
        ll j = st.top();
        while(a[i] < a[j]) // => stack sẽ chứa chỉ số các phần tử tăng dần
        {
            st.pop();
            ll s = a[j]*(i - st.top() - 1);
            j = st.top();
            mx = max(mx, s);
        }
        st.push(i);
    }
    cout << mx;
    return 0;
}
