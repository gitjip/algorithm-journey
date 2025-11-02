// 问题：
// 有装下8个苹果的袋子、装下6个苹果的袋子，一定要保证买苹果时所有使用的袋子都装满
// 对于无法装满所有袋子的方案不予考虑，给定n个苹果，返回至少要多少个袋子
// 如果不存在每个袋子都装满的方案返回-1

// 输入：
// 一行一个正整数n

// 输出：
// 一个整数表示答案

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int ans = INF;
void dfs(int x, int n)
{
	if (x < 0)
		return;
	if (x == 0)
		ans = min(ans, n);
	dfs(x - 6, n + 1);
	dfs(x - 8, n + 1);
}
int main()
{
	// 打表找规律
	// for (int i = 1; i <= 50; ++i)
	// {
	// 	ans = INF;
	// 	dfs(i, 0);
	// 	cout << i << " " << (ans == INF ? -1 : ans) << "\n";
	// }

	// 验证规律
	for (int n = 1; n <= 50; ++n)
	{
		cout << n << " ";
		if (n == 6 || n == 8)
		{
			cout << "1\n";
		}
		else if (n % 2 || n <= 10)
		{
			cout << "-1\n";
		}
		else
		{
			cout << (n - 1) / 8 + 1 << "\n";
		}
	}

	// 答案
	// int n;
	// cin >> n;
	// if (n % 2 || n <= 10)
	// {
	// 	cout << "-1\n";
	// }
	// else if (n == 6 || n == 8)
	// {
	// 	cout << "1\n";
	// }
	// else
	// {
	// 	cout << (n - 1) / 8 + 1 << "\n";
	// }
	return 0;
}