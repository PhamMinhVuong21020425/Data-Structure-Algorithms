//Cho một xâu chỉ gồm các kí tự '(' và ')'. Một dãy ngoặc đúng được định nghĩa như sau:
//- Xâu rỗng là 1 dãy ngoặc đúng.
//- Nếu A là 1 dãy ngoặc đúng thì (A) là 1 dãy ngoặc đúng.
//- Nếu A và B là 2 dãy ngoặc đúng thì AB là 1 dãy ngoặc đúng.
//
//Cho một xâu S. Hãy tìm dãy ngoặc đúng dài nhất là xâu con gồm các phần tử liên tiếp trong xâu đã cho.

#define ll long long
#define INF 1e18
#define fi first
#define se second
#define pb push_back
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Đồng bộ iostream với stdio.h của C để nhập xuất nhanh hơn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n; cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        s = " " + s;
        stack<ll> st; st.push(0);
        ll ans = 0;
        for(ll i = 1; i < (ll)s.length(); i++)
        {
            if(s[i] == '(')st.push(i);
            else
            {
                st.pop();

//              Nếu là dấu đóng ngoặc mà stack rỗng tức là chuỗi ngoặc đúng đã bị kết thúc
//              nên cần đánh dấu điểm bắt đầu của chuỗi ngoặc đúng mới.
                if(st.empty())st.push(i);

                ans = max(ans, i - st.top());
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
