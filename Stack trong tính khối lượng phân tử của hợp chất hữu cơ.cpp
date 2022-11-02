//Hợp chất hữu cơ chỉ gồm các nguyên tố C, H, O có khối lượng nguyên tử lần lượt là 12, 1, 16.
// Cho công thức phân tử của một hợp chất hữu cơ, hãy tính khối lượng phân tử của nó.
#include<bits/stdc++.h>
#define int long long
using namespace std;

int f[300];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int Q; cin >> Q;
    f[(int) 'H'] = 1;
    f[(int) 'C'] = 12;
    f[(int) 'O'] = 16;
    f[(int) '('] = -1;
    while(Q--)
    {
        string s; cin >> s;
        stack<int> st;
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(s[i] != ')' && isdigit(s[i]) == false)
            {
                st.push( f[(int)s[i]] );
                continue;
            }
            if(isdigit(s[i]))
            {
                // Xử lý nếu chỉ số đằng sau nguyên tố
                // là số có 2 chữ số trở lên.
                string digit = "";
                digit = digit + s[i];
                while(isdigit(s[i+1]) == true)
                {
                    digit = digit + s[i+1];
                    i++;
                }
                int tmp = st.top(); st.pop();
                st.push(tmp * stoll(digit));
            }
            if(s[i] == ')')
            {
                int tmp = 0;
                while(st.top() != -1)
                {
                    tmp += st.top();
                    st.pop();
                }
                st.pop(); // pop nốt dấu '(' ra ngoài
                st.push(tmp);
            }
        }
        int ans = 0;
        while(st.size())
        {
            ans += st.top();
            st.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}
