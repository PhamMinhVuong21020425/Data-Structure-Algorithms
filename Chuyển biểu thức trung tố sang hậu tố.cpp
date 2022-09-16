//Bạn được cho một danh sách các biểu thức toán học đúng ở dạng trung tố chỉ chứa:
//
//- Biến: là các chữ cái latinh in thường a-z, (mỗi biến là một chữ cái)
//
//- Các toán tử hai ngôi: +,-,*,/,^(lũy thừa) với thứ tự ưu tiên như sau:
//+, - cùng độ ưu tiên thấp nhất,
//* , / cùng độ ưu tiên thứ hai,
//^ có độ ưu tiên cao nhất
//
//- Các cặp dấu ngoặc
//
//Hãy chuyển đổi biểu thức đó sang dạng hậu tố và giữ nguyên thứ tự các số hạng (RPN - ký pháp nghịch đảo Ba Lan)
//VD: (a+(b*c)) => abc*+

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
    cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    a[(int)'+'] = 1; a[(int)'-'] = 1;
    a[(int)'*'] = 2; a[(int)'/'] = 2;
    a[(int)'^'] = 3;
    a[(int)'('] = -1;
    while(n--)
    {
        string s, ans = ""; cin >> s;
        stack<char> st;
        st.push('.'); // Đệm 1 phần tử vào stack để tránh stack bị rỗng khó xử lí
        for(ll i = 0; i < s.size(); i++)
        {
            if(islower(s[i])){ans += s[i]; continue;}
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
    }
    return 0;
}
