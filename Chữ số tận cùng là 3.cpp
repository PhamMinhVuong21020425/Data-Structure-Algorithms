//Cho dãy số gồm n (1 <= n <= 2*10^5) phần tử a[1], a[2],...,a[n]. Nhiệm vụ của bạn là xác định xem
//có tồn tại hay không 3 phần tử trong mảng sao cho tổng của 3 phần tử đó có chữ số tận cùng là 3.
#include<bits/stdc++.h>
using namespace std;

int a[200005]; // khai báo ở data segment giảm bộ nhớ cho main làm việc khác
int cnt[10]; // biến khai báo ngoài main là biến toàn cục
				// nó sẽ được auto có giá trị là 0

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<int> b;
	for(int i = 1; i <= n; i++){
		a[i] %= 10;
		cnt[a[i]]++;
		if(cnt[a[i]] > 3)continue;
		b.push_back(a[i]);
	}
	for(int i = 0; i < b.size(); i++){
		for(int j = i + 1; j < b.size(); j++){
			for(int k = j + 1; k < b.size(); k++){
				if((b[i] + b[j] + b[k]) % 10 == 3){
					cout << 1;
					return 0;
				}
			}
		}
	}
	cout << 0;
}
