//Connected Cells in a Grid : Hackerrank
//
//Cho mảng hai chiều với các phần tử (ô) có giá trị là 0 hoặc 1.
//Hai phần từ được gọi là kết nối (connected) với nhau nếu chúng
//cùng có giá trị là 1 và ở sát nhau theo chiều ngang, chiều dọc và chéo cạnh.
//Như thế mỗi ô có thể có nhiều nhất 8 ô ở kề có thể nối với nó.
//Các ô kết nối với nhau tạo thành vùng. Hãy tìm và in ra số phần tử của vùng lớn nhất.

#include <bits/stdc++.h>
using namespace std;

int a[100][100];
int n, m, mx = 0, cnt = 0;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int i, int j)
{
    cout << i << " " << j << "\n";
    a[i][j] = 0; // đánh dấu đỉnh a[i][j] đã được thăm
    cnt++;
    for(int u = 0; u < 8; u++)
    {
        int ib = i + dx[u];
        int jb = j + dy[u];
        if(ib >= 1 && ib <= n && jb >=1 && jb <= m && a[ib][jb] == 1)
            dfs(ib, jb);
    }
}

void output()
{
    int dem = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] == 1) // nếu a[i][j] chưa được thăm
            {
                dem++;
                cout << "Thanh phan lien thong thu " << dem << " la:\n";
                dfs(i, j);
                if(mx < cnt)mx = cnt;
            }
        }
    }
    cout << "Thanh phan lien thong co so dinh lon nhat la: " << mx << "\n";
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    output();
    return 0;
}
