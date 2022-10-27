#define ll long long
#define INF 1e18
#define fi first
#define se second
#define pb push_back
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    ll cnt = 0;
    queue<string> Q;
    Q.push("1");
    while(cnt < n)
    {
        string s = Q.front();
        cout << s << "\n";
        cnt++;
        Q.push(s + '0');
        Q.push(s + '1');
        Q.pop();
    }
    return 0;
}
