#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N = 0;
	cin >> N;
	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	vector<int>num2(N);
	num2 = num;
	sort(num2.begin(), num2.end());
	int k = 0;
	for (int j = 0; j < N&&k<N; j++) {
		if (num[j] == num2[k]) {
			k++;
		}
	}
	int ans = N - k;
	cout << ans << endl;
}