// Cho 2 số S và T. Mỗi thao tác ta được thực hiện 1 trong 2 việc sau:
// S = S - 1 hoặc S = S * 2
// Hãy tính số thao tác tối thiểu để biến S thành T.
#define ll long long
#define INF 1e18
#define fi first
#define se second
#define pb push_back
#include <bits/stdc++.h>
using namespace std;

int solve(int S, int T)
{
//    pair gồm 2 phần tử là:
//    +trạng thái của số hiện tại
//    +số bước để chuyển từ S thành số hiện tại
    queue< pair<int, int> > q;
    set<int> Set;
    q.push({S, 0});
    while(q.empty() == false)
    {
        pair<int, int> fro = q.front(); q.pop();
        if(fro.fi == T)return fro.se;
        if(Set.count(fro.fi) == 0)
        {
            if(fro.fi < T)q.push({fro.fi * 2, fro.se + 1});
            if(fro.fi > 1)q.push({fro.fi - 1, fro.se + 1});
        }
        Set.insert(fro.fi);
    }
}

int main()
{
    srand(time(NULL));

//  Đồng bộ iostream với stdio.h của C để nhập xuất nhanh hơn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int S, T;
    cin >> S >> T;
    cout << solve(S, T);
    return 0;
}
