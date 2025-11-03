// 问题：
// 草一共有n的重量，两只牛轮流吃草，A牛先吃，B牛后吃
// 每只牛在自己的回合，吃草的重量必须是4的幂，1、4、16、64....
// 谁在自己的回合正好把草吃完谁赢，根据输入的n，返回谁赢

// 输入：
// 一行一个整数表示草的重量

// 输出：
// 一行一个字符串表示赢的牛的名字

#include <bits/stdc++.h>
using namespace std;
string dfs(string cur, string ene, int rest)
{
	if (rest == 0)
		return ene;
	int w = 1;
	while (w <= rest)
	{
		if (dfs(ene, cur, rest - w) == cur)
		{
			return cur;
		}
		w *= 4;
	}
	return ene;
}
int main()
{
	// 打表找规律
	// for (int i = 1; i <= 50; ++i)
	// {
	// 	cout << i << " " << dfs("A", "B", i) << "\n";
	// }

	// 验证规律
	// for (int n = 1; n <= 50; ++n)
	// {
	// 	cout << n << " ";
	// 	if (n % 5 == 2 || n % 5 == 0)
	// 	{
	// 		cout << "B\n";
	// 	}
	// 	else
	// 	{
	// 		cout << "A\n";
	// 	}
	// }

	// 答案
	int n;
	cin >> n;
	if (n % 5 == 2 || n % 5 == 0)
	{
		cout << "B\n";
	}
	else
	{
		cout << "A\n";
	}
	return 0;
}