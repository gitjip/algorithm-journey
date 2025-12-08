#include <bits/stdc++.h>
using namespace std;
mt19937 rng(random_device{}());
int f1(vector<int> &arr)
{
	unordered_map<int, int> mp;
	unordered_set<int> se;
	for (auto x : arr)
		mp[x]++;
	do
	{
		for (auto x : se)
			if (!mp.count(x))
				mp[x]++;
		se.clear();
		for (auto [x, xc] : mp)
			for (auto [y, yc] : mp)
				if (!mp.count(abs(x - y)))
					se.insert(abs(x - y));
	} while (se.size());
	int ans = 0;
	for (auto [x, c] : mp)
		ans += c;
	return ans;
}
int f2(vector<int> &arr)
{
	int n = arr.size();
	unordered_map<int, int> mp;
	int gc = 0;
	for (int i = 0; i < n; i++)
		if (arr[i])
			gc = arr[i];
	if (!gc)
		return n;
	for (int i = 0; i < n; i++)
	{
		if (arr[i])
			gc = gcd(gc, arr[i]);
		mp[arr[i]]++;
	}
	int mx = *max_element(arr.begin(), arr.end());
	int ans = mx / gc;
	for (auto [x, c] : mp)
		if (x)
			ans += c - 1;
	if (mp.count(0))
		ans += mp[0];
	else
		ans++;
	return ans;
}
int main()
{
	int N = 50;
	int V = 100;
	int T = 1000;
	for (int i = 0; i < T; i++)
	{
		int n = rng() % N + 1;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			arr[i] = rng() % V + 1;
		int ans1 = f1(arr);
		int ans2 = f2(arr);
		if (ans1 != ans2)
		{
			cout << "WA:\n"
				 << "n: " << n << "\n";
			for (auto x : arr)
				cout << x << " ";
			cout << "\n";
			cout << "f1: " << ans1 << "\n"
				 << "f2: " << ans2 << "\n";
			return 0;
		}
	}
	cout << "AC\n";
	return 0;
}