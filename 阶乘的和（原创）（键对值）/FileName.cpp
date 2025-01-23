#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main()
{
	int n = 0,i=0;
	cin >> n;
	vector<int>num(n);
	unordered_map<int, int>time;
	for (i = 0; i < n; i++) {
		cin >> num[i];
		time[num[i]]++;
	}
	bool changed = true;
	sort(num.begin(), num.end());
	while (changed) {
		changed = false;
		vector<int>new_num;
		for (auto& m : time) {
			int value = m.first;
			int count = m.second;
			if (count > value) {
				changed = true;
				int suplus = count - value-1;
				for (i = 0; i <suplus; i++) {
					new_num.push_back(value);
				}
				new_num.push_back(value + 1);
			}
			else {
				for (i = 0; i < count; i++) {
					new_num.push_back(value);
				}
			}
		}
		num = new_num;
		time.clear();
		for (int p : num) {
			time[p]++;
		}
		sort(num.begin(), num.end());
	}
	int result = num[0];
	cout << result << endl;
	return 0;
}