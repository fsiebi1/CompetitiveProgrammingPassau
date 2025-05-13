#include <bits/stdc++.h>
#define MAX_N 100

using namespace std;

int c, m;
int dp[MAX_N][MAX_N];
int inp[MAX_N][MAX_N];

int main() {
	cin >> c >> m;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= c; j++)
            cin >> inp[i][j];

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= c; j++)
            for(int k = 0; k <= j; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + inp[i][k]);

    cout << dp[m][c] << endl;

    return 0;
}