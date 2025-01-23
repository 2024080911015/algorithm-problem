#include<iostream>
#include<cstring>
using namespace std;
int n, m;
int MOD = 998242353;
int f(int i, int pre, int ppre, int pppre, int ppppre);
int mem[5002][10][10][10][10];
int main() {
    memset(mem, -1, sizeof(mem));
    cin >> n >> m;
    int result = 0;
    int pre, ppre, pppre, ppppre;
    for (pre = 1; pre <= 9; pre += 2) {
        for (ppre = 0; ppre <= 8; ppre += 2) {
            for (pppre = 1; pppre <= 9; pppre += 2) {
                for (ppppre = 0; ppppre <= 8; ppppre += 2) {
                    result = (result + f(5, pre, ppre, pppre, ppppre)) % MOD;
                }
            }
        }
    }
    cout << result << endl;
    return 0;
}
int f(int i, int pre, int ppre, int pppre, int ppppre) {
    int res = 0;
    if (i > n) {
        return 1;
    }
    if (i<=5000&&mem[i][pre][ppre][pppre][ppppre] != -1) {
        return mem[i][pre][ppre][pppre][ppppre];
    }
    if (i % 2 == 0) {
        for (int j = 0; j <= 8; j += 2) {
            if (j + pre + ppre + pppre + ppppre <= m) {
                res = (res + f(i + 1, j, pre, ppre, pppre)) % MOD;
            }
        }
    }
    if (i % 2 == 1) {
        for (int j = 1; j <= 9; j += 2) {
            if (j + pre + ppre + pppre + ppppre <= m) {
                res = (res + f(i + 1, j, pre, ppre, pppre)) % MOD;
            }
        }
    }
    if (i <= 5000) {
        mem[i][pre][ppre][pppre][ppppre] = res;
    }
    return res;
}



