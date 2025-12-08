#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
mt19937_64 rng(random_device{}());
ll qpow(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}
/**
 * @brief 暴力
 */
ll f1(ll n, ll k)
{
	if (n == 0)
		return 0;
	if (k == 1)
		return n;
	ll ans = 0;
	for (ll i = 1; i < n; i++)
		ans = max(ans, i * f1(n - i, k - 1));
	return ans;
}
/**
 * @brief 标准
 */
ll f2(ll n, ll k)
{
	return qpow(n / k, k - n % k) * qpow(n / k + 1, n % k);
}
int main()
{
	int N = 20;
	int T = 10000;
	for (int i = 0; i < T; i++)
	{
		ll n = rng() % N + 1;
		ll k = rng() % n + 1;
		ll ans1 = f1(n, k);
		ll ans2 = f2(n, k);
		if (ans1 != ans2)
		{
			cout << "WA:\n"
				 << "n: " << n << "\n"
				 << "k: " << k << "\n"
				 << "f1: " << ans1 << "\n"
				 << "f2: " << ans2 << "\n";
			return 0;
		}
	}
	cout << "AC\n";
	return 0;
}