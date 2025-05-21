#include <bits/stdc++.h>
#define MAX_N 100005

using namespace std;

int t, n;
long long dp[MAX_N][2];     // dont take, take

int main() {
	cin >> t;
    for(; t > 0; t--) {
        cin >> n;
        
        for(int i = 1; i <= n; i++) {
            int c;
            cin >> c;

            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] + c, dp[i-1][1]);
        }

        cout << max(dp[n][0], dp[n][1]) << endl;
    }

    return 0;
}