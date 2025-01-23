#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return 0;
        }
        int k = 0;
        vector<int> p(1000000000);
        while (x > 0) {
            p[k++] = x % 10;
            x = x / 10;
        }
        int is = 1;
        for (int i = 0; i < k; i++) {
            if (p[i] != p[k - i - 1]) {
                is = 0;
                return 0;
            }
        }
        return 1;
        
    }
};
int main()
{
    Solution so;
    int m = 0;
    cin >> m;
    int x = so.isPalindrome(m);
    cout << x << endl;
    return 0;
}

