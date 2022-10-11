// Thực thi bảng băm (hash table) dạng 'separate chaining'
// Missing Numbers: Hackerrank
// Cho 2 mảng A và B. (Chênh lệch giữa số lớn nhất và nhỏ nhất của B là không quá 100)
// Tìm và in ra các số có trong B nhưng không có trong A theo trật tự tăng dần.


#include <bits/stdc++.h>
using namespace std;

const int hashKey = 103;
vector<int> h[hashKey];

int getHash(int key)
{
    return key % hashKey;
}

void insertHash(int key)
{
    int hkey = getHash(key);

    //Nếu có đoạn mã này thì giống set còn không thì giống multiset
//    for(auto it = h[hkey].begin(); it != h[hkey].end(); it++)
//    {
//        if(*it == key) // nếu key đã tồn tại thì không chèn thêm
//            return;
//    }
    h[hkey].push_back(key);
}

int findHash(int key)
{
    int hkey = getHash(key);
    for(auto it = h[hkey].begin(); it != h[hkey].end(); it++)
    {
        if(*it == key)
        {
            h[hkey].erase(it);
            return 1;
        }
    }
    return -1;
}

int main()
{

    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        insertHash(a[i]);
    }
    set<int> ans;
    int m; cin >> m;
    int b[m];
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
        if(findHash(b[i]) == -1)ans.insert(b[i]);
    }
    for(auto u : ans)cout << u << " ";
    return 0;
}
