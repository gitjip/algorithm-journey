#include <bits/stdc++.h>
using namespace std;
tuple<int, int, int, int> arr[100005];
int tr[200005];
int f[100005];
int cnt[100005];
bool cmpb(tuple<int, int, int, int> x, tuple<int, int, int, int> y)
{
    return get<1>(x) < get<1>(y);
}
bool eq(tuple<int, int, int, int> x, tuple<int, int, int, int> y)
{
    return get<0>(x) == get<0>(y) && get<1>(x) == get<1>(y) && get<2>(x) == get<2>(y);
}
void upd(int p, int x)
{
    for (int i = p; i <= 200000; i += i & -i) {
        tr[i] += x;
    }
}
int qry(int p)
{
    int res = 0;
    for (int i = p; i > 0; i -= i & -i) {
        res += tr[i];
    }
    return res;
}
void cdq(int l, int r)
{
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    int a = mid + 1, b = l;
    for (; a <= r; ++a) {
        while (b <= mid && get<1>(arr[b]) <= get<1>(arr[a])) {
            upd(get<2>(arr[b]), 1);
            ++b;
        }
        f[get<3>(arr[a])] += qry(get<2>(arr[a]));
    }
    for (int i = l; i < b; ++i) {
        upd(get<2>(arr[i]), -1);
    }
    sort(arr + l, arr + r + 1, cmpb);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> get<0>(arr[i]) >> get<1>(arr[i]) >> get<2>(arr[i]);
        get<3>(arr[i]) = i;
    }
    sort(arr + 1, arr + n + 1);
    for (int i = n, j; i >= 1;) {
        for (j = i - 1; j >= 1 && eq(arr[j], arr[i]); --j) {
            f[get<3>(arr[j])] = i - j;
        }
        i = j;
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << get<0>(arr[i]) << " " << get<1>(arr[i]) << " " << get<2>(arr[i]) << ":" << f[get<3>(arr[i])] << "\n";
    // }
    cdq(1, n);
    for (int i = 1; i <= n; ++i) {
        ++cnt[f[i]];
    }
    for (int i = 0; i < n; ++i) {
        cout << cnt[i] << "\n";
    }
    return 0;
}