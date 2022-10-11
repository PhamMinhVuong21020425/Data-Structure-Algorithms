Breadth First Search: Shortest Reach -> Hackerrank

Cho đồ thị vô hướng; các đỉnh đánh số từ 1 tới n; 
hai cạnh nếu nối với nhau thì có trọng số luôn là 6. 
Cho vào đỉnh xuất phát, hãy tìm và in đường đi ngắn nhất 
từ đỉnh này tới (n-1) đỉnh còn lại. Nếu không có đường đi thì in ra -1.
Chú ý là dữ liệu vào có q câu hỏi, mỗi câu hỏi cho một đồ thị với một đỉnh xuất phát.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int q;
    cin >> q;
    while(q--)
    {
        int n, m, u, v, s;
        cin >> n >> m;
        vector<int> a[10005];
        for(int i = 1; i <= m; i++)
        {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        cin >> s;
        queue<int> que; que.push(s);
        int cnt[1005] = {};
        int visited[1005];
        memset(visited, 0, sizeof(visited));
        visited[s] = 1;
        cnt[s] = 0;
        while(!que.empty())
        {
            int x = que.front(); que.pop();
            for(int k = 0; k < a[x].size(); k++)
            {
                int node = a[x].at(k);
                if(visited[node] == 0)
                {
                    cnt[node] = cnt[x] + 1;
                    que.push(node);
                    visited[node] = 1;
                }
            }
        }
        for(int j = 1; j <= n; j++)
        {
            if(visited[j] == 0)cout << -1 << " ";
            else if(j != s)cout << cnt[j] * 6 << " ";
        }
        cout << "\n";
    }
    return 0;
}
