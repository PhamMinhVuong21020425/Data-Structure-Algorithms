// Cho một dãy gồm N số nguyên: a1, a2, ..., an và dãy B rỗng. 
// Trên dãy B, bạn hãy thực hiện N phép biến đổi. Với phép biến đổi thứ i:
// + Thêm ai vào cuối dãy BB.
// + Đảo ngược thứ tự các phần tử của dãy B.
// Hãy tìm kết quả của dãy B sau khi thực hiện N phép biến đổi.
#define ll long long
#define fi first
#define se second
#define pb push_back
#include <bits/stdc++.h>
using namespace std;

ll a[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    deque<ll> dq;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i % 2 == 0)dq.push_front(a[i]);
        else dq.push_back(a[i]);
    }
    while(!dq.empty())
    {
        if(n%2 == 0)
        {
            cout << dq.front() << " ";
            dq.pop_front();
        }
        else
        {
            cout << dq.back() << " ";
            dq.pop_back();
        }
    }
    return 0;
}
