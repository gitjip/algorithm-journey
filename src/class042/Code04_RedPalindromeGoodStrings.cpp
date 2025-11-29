// 问题：
// 可以用r、e、d三种字符拼接字符串，如果拼出来的字符串中
// 有且仅有1个长度>=2的回文子串，那么这个字符串定义为"好串"
// 返回长度为n的所有可能的字符串中，好串有多少个
// 结果对 1000000007 取模， 1 <= n <= 10^9

// 输入：
// 一行一个正整数n表示字符串长度

// 输出：
// 一个正整数表示好串的个数

// 示例：
// n = 1, 输出0
// n = 2, 输出3
// n = 3, 输出18

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string path;
ll ans = 0;
bool chk(int l, int r)
{
	for (int i = l; i <= r; ++i)
	{
		if (path[i] != path[r - i + l])
		{
			return false;
		}
	}
	return true;
}
void dfs(int x, int n)
{
	if (x == n)
	{
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (sum > 1)
					return;
				sum += chk(i, j);
			}
		}
		ans += (sum == 1);
		return;
	}
	path[x] = 'r';
	dfs(x + 1, n);
	path[x] = 'e';
	dfs(x + 1, n);
	path[x] = 'd';
	dfs(x + 1, n);
}
int main()
{
	// 打表
	// for (int i = 1; i <= 12; ++i)
	// {
	// 	path.resize(i);
	// 	ans = 0;
	// 	dfs(0, i);
	// 	cout << i << " " << ans << "\n";
	// }

	// 验证
	// for (int n = 1; n <= 12; ++n)
	// {
	// 	cout << n << " ";
	// 	if (n == 1)
	// 	{
	// 		cout << "0\n";
	// 	}
	// 	else if (n == 2)
	// 	{
	// 		cout << "1\n";
	// 	}
	// 	else if (n == 3)
	// 	{
	// 		cout << "2\n";
	// 	}
	// 	else
	// 	{
	// 		cout << (n + 1) * 6 << "\n";
	// 	}
	// }

	// 答案
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "0\n";
	}
	else if (n == 2)
	{
		cout << "1\n";
	}
	else if (n == 3)
	{
		cout << "2\n";
	}
	else
	{
		cout << (n + 1) * 6 << "\n";
	}
	return 0;
}