//Cho một dãy gồm N số nguyên dương a[1], a[2],..., a[n] và số nguyên dương S.
//Cần tìm độ dài đoạn con liên tiếp dài nhất có tổng bằng S.
//Trường hợp không tìm được dãy con nào thoả mãn, in ra -1
#define ll long long
#define INF 1e18
#define fi first
#define se second
#define pb push_back
#include <bits/stdc++.h>
using namespace std;

ll a[100005], pre[100005];

int main()
{
    srand(time(NULL));

//  Đồng bộ iostream với stdio.h của C để nhập xuất nhanh hơn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    map<ll, ll> m;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
        m[pre[i]] = i;
    }
    ll s, ans = -1; cin >> s;
    for(ll i = 1; i <= n; i++)
    {
        ll left = m[pre[i] - s];
        if(left > 0)ans = max(ans, i - left);
    }
    cout << ans;
    return 0;
}
