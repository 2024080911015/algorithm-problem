#include<iostream>
#include<vector>
using namespace std;
int plus1(vector<int>p);
int main() {
	vector<int>num(10000);
	int n = 0, m = 0, i = 0, j = 0, k = 0;
	int max = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> num[i];
	}
	vector<int>left;
	vector<int>right;
	for (i = 0; i < n; i++) {
		left.push_back(num[i]);
		int leftvalue = plus1(left);
		for (j = i + 1; j < n; j++) {
			right.push_back(num[j]);
			int rightvalue = plus1(right);
			int chazhi = (rightvalue - leftvalue > 0 ? rightvalue - leftvalue : leftvalue - rightvalue);
			if (chazhi > max) {
				max = chazhi;
			}
		}
		right.clear();
	}
	int result = max;
	cout << result << endl;
	return 0;
}
int plus1(vector<int>p) {
	int m = 0;
	for (int num : p) {
	     m = m ^ num;
	}
	return m;
}