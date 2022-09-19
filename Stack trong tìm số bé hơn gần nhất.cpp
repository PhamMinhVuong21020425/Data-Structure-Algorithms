//Cho 1 mảng a gồm n phần tử a[1], a[2],.., a[n].
//Với mỗi phần tử a[i] bạn hãy tìm chỉ số j gần bên trái a[i] nhất
//sao cho a[j] < a[i](nếu không có j nào như thế thì in ra 0).\
//VD:
//4
//3 2 4 5  =>  0 0 2 3
#define ll long long
#define fi first
#define se second
#define pb push_back
#include <bits/stdc++.h>
using namespace std;

ll a[200005], b[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    stack<ll> st;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    st.push(1);
    for(ll i = 2; i <= n; i++)
    {
        while(st.empty() == false && a[i] <= a[st.top()])
        {
            st.pop();
        }
        if(st.empty())b[i] = 0;
        else b[i] = st.top();
        st.push(i);
    }
    for(ll i = 1; i <= n; i++)
        cout << b[i] << " ";
    return 0;
}
