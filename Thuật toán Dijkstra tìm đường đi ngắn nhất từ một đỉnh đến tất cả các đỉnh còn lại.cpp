//Dijkstra: Shortest Reach 2 -> Hackerrank
#define INF 999999999
#include <bits/stdc++.h>
using namespace std;

int d[30001],n,x,m,t;
vector<pair<int,int>> a[30001];

void dijkstra(int x)
{
    //Khởi tạo hàng đợi ưu tiên, giá trị second bé nhất ưu tiên cho lên đầu
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    d[x]=0;
    pq.push( make_pair(0, x) );
    while( pq.size() )
    {
        //Lấy giá trị second của phần tử đỉnh của pq
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        //Điều kiện để bỏ qua pair mà giá trị d[u] được cập nhật từ lần lặp trước.
        if (du != d[u])
        {
            continue;
        }

        //Duyệt các đỉnh kề của đỉnh u
        for (int i = 0; i < (int)a[u].size(); i++)
        {
            int v = a[u][i].first;
            int uv = a[u][i].second;

         /* Nếu tổng của đỉnh đang xét + trọng số của cạnh nối 2 đỉnh u và v
            nhỏ hơn thì cập nhật d[v] mới */
            if (d[v] > du + uv)
            {
                d[v] = du + uv; // Lấy giá trị nhỏ hơn
                pq.push( make_pair(d[v], v) ); // Thêm pair vào pq
            }
        }
    }
}

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++)
    {
        cin >> n >> m;
        int x, y, s, r;
        for (int i=1; i<=n; i++)
        {
            d[i] = INF;
            a[i].clear();
        }
        for (int i=1; i<=m; i++)
        {
            cin >> x >> y >> s;
            a[x].push_back(make_pair(y, s));
            a[y].push_back(make_pair(x, s));
        }
        cin >> r;
        dijkstra(r);
        for(int i=1; i<=n; i++)
            if(d[i] == INF)cout << -1 << " ";
            else if(i == r)continue;
            else cout << d[i] << " ";
        cout << "\n";
    }
    return 0;
}
