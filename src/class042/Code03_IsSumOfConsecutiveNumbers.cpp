// 问题：
// 判断一个数字是否是若干数量(数量>1)的连续正整数的和

// 输入：
// 一行一个正整数n

// 输出：
// 若n是若干连续正整数的和，输出T，否则输出F

#include <bits/stdc++.h>
using namespace std;
bool chk(int n)
{
	for (int i = 1; i < n; ++i)
	{
		int sum = 0;
		for (int j = i; sum <= n; ++j)
		{
			if (sum == n)
			{
				return true;
			}
			sum += j;
		}
	}
	return false;
}
int bitn(int x)
{
	int cnt = 0;
	while (x)
	{
		cnt += x & 1;
		x >>= 1;
	}
	return cnt;
}
int main()
{
	// 打表
	// for (int i = 1; i <= 80; ++i)
	// {
	// 	cout << i << " " << (chk(i) ? "T" : "F") << "\n";
	// }

	// 答案
	int n;
	cin >> n;
	cout << (bitn(n) == 1 ? "F" : "T") << "\n";
}
