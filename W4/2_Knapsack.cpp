#include <bits/stdc++.h>
#define MAX_N 200005

using namespace std;

int n, m;
int anz[4];
int outp1, outp2;

int main() {
    cin >> m >> n;
    outp1 = n; outp2 = n;

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        anz[x]++;
    }

    int max3 = n / 3;
    if(anz[3] > max3)
        anz[3] = max3;

    outp1 -= anz[3] * 3;
    outp2 -= max(anz[3] - 1, 0) * 3;

    int max2_1 = outp1 / 2;
    int max2_2 = outp2 / 2;

    outp1 -= min(max2_1, anz[2]) * 2;
    outp2 -= min(max2_2, anz[2]) * 2;

    int max1_1 = outp1;
    int max1_2 = outp2;

    outp1 -= min(max1_1, anz[1]);
    outp2 -= min(max1_2, anz[1]);

    cout << n - min(outp1, outp2) << endl;

    return 0;
}