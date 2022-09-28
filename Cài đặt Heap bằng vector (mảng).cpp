#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void heapify(vector<ll> &heap, ll pos)
{
    ll n = heap.size();
    ll parent = pos;
    ll left = 2 * pos + 1;
    ll right = 2 * pos + 2;
    if(left < n && heap[parent] > heap[left])parent = left;
    if(right < n && heap[parent] > heap[right])parent = right;
    if(parent != pos)
    {
        swap(heap[pos], heap[parent]);
        heapify(heap, parent); // gọi heapify đến các cây con bên dưới
    }
}

void makeHeap(vector<ll> &heap)
{
    ll n = heap.size() - 1;
    for(ll i = (n - 1) / 2; i >= 0; i--)
    {
        heapify(heap, i);
    }
}

void insertHeap(vector<ll> &heap, ll x)
{
    heap.push_back(x);
    if(heap.size() == 1)return;
    ll i = heap.size() - 1;
    while(heap[i] < heap[(i-1)/2])
    {
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void deleteHeap(vector<ll> &heap, ll era)
{
    ll n = heap.size(), posErase;
    for(ll i = 0; i < n; i++)
    {
        if(heap[i] == era)
        {
            posErase = i;
            break;
        }
    }
    swap(heap[posErase], heap[n-1]);
    heap.pop_back();
    heapify(heap, posErase);
}

void printHeap(vector<ll> heap)
{
    for(ll i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<ll> heap;
    ll Q; cin >> Q;
//    for(ll i = 0; i < Q; i++)
//    {
//        ll x; cin >> x;
//        heap.push_back(x);
//    }
//    makeHeap(heap);
    printHeap(heap);
    while(Q--)
    {
        ll type; cin >> type;
        if(type == 1)
        {
            ll x;
            cin >> x;
            insertHeap(heap, x);
        }
        else if(type == 2)
        {
            ll era;
            cin >> era;
            deleteHeap(heap, era);
        }
        else if(type == 3)
        {
            if(heap.empty() == false)cout << heap[0] << "\n";
        }
    }

    return 0;
}
