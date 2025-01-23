#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[9][2];
int dfs(vector<int>m, int pos, bool is_tight);
int count_numbers_without3(int N);
int main()
{
	memset(dp, -1, sizeof(dp));
	int N = 0, s = 0;
	cin >> N;
	s = count_numbers_without3(N);
	cout << s-1;
	return 0;
}
int dfs(vector<int>m, int pos, bool is_tight) {
	if (pos == m.size()) {
		return 1;
	}
	if (dp[pos][is_tight] != -1) {
		return dp[pos][is_tight];
	}
	int result = 0;
	int limit = is_tight ? m[pos] : 9;
	for (int i = 0; i <= limit; i++) {
		if (i == 9)continue;
		result += (dfs(m, pos + 1, is_tight && (i == limit)));
	}
	dp[pos][is_tight] = result;
	return result;
}
int count_numbers_without3(int N) {
	vector<int> num;
	while (N > 0) {
		num.push_back(N % 10);
		N /= 10;
	}
	reverse(num.begin(), num.end());
	return dfs(num, 0, true);
}

