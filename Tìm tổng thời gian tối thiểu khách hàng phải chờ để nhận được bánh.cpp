//Các loại pizza khác nhau cần thời gian nấu khác nhau.
//Ngoài ra, một khi anh ta bắt đầu nấu một chiếc bánh pizza,
//anh ta không thể nấu một chiếc bánh pizza khác cho đến khi
//chiếc bánh pizza đầu tiên chín hoàn toàn. Giả sử chúng ta có
//ba khách hàng lần lượt đến vào thời điểm t = 0, t = 1, & t = 2 và
//thời gian cần thiết để nấu bánh pizza của họ lần lượt là 3, 9 và 6.
//Nếu Tiêu áp dụng quy tắc ai đến trước được phục vụ trước,
//thì thời gian chờ đợi của ba khách hàng lần lượt là 3, 11 và 16.
//Thời gian chờ trung bình trong trường hợp này là (3 + 11 + 16) / 3 = 10.
//Đây không phải là giải pháp tối ưu hóa. Sau khi phục vụ khách hàng đầu tiên tại thời điểm t = 3,
//Tiêu có thể chọn phục vụ khách hàng thứ ba. Trong trường hợp đó, thời gian chờ sẽ lần lượt là 3, 7 và 17.
//Do đó, thời gian chờ trung bình là (3 + 7 + 17) / 3 = 9.
//Tìm thời gian chờ trung bình tối thiểu của khách.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
//    0   10
//    6   12
//    1   11
//    10 + (10 + 12) - 6 + (10 + 12 + 11) - 1
//    10 + (10 + 11) - 1 + (10 + 11 + 12) - 6 nhỏ hơn
//    Lượng trừ đi là như nhau nên ưu tiên phần tử a[i].second nhỏ nhất
//    trong danh sách các vị khách đến trùng thời gian đang làm bánh
//    n: số khách hàng
//    a[i].first: thời điểm khách thứ i đến
//    a[i].second: thời gian làm bánh cho khách thứ i
    ll n; cin >> n;
    pair<ll, ll> a[n];
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);

    // Vì set sắp xếp các phần tử theo thứ tự tăng dần nên được dùng,
    // để thuận lợi lấy được phần tử a[i].second nhỏ nhất
    set<pair<ll, ll>>s;
    ll t = a[0].first, ans = 0;
    ll i = 0;
    while(i < n || s.empty() == false)
    {
        while(i < n && a[i].first <= t)
        {
            s.insert({a[i].second, i});
            i++;
        }
        if(s.empty() == false)
        {
            ll pos = s.begin()->second;
            s.erase(s.begin());
            t += a[pos].second;
            ans += t - a[pos].first;
        }
       //Lúc này không có ai phải đợi nên gắn t là thời điểm khách tiếp theo đến
        else t = a[i].first;
    }
    cout << ans / n << endl;
    return 0;
}
