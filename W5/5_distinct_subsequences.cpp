#include <bits/stdc++.h>
#define ANZ 26
#define MOD 1000000007

using namespace std;

long long arr[ANZ];
long long ret;

int main() {
    int t;
    cin >> t;

    for(; t > 0; t--) {
        for(int i = 0; i < ANZ; i++)
            arr[i] = 0;

        ret = 1;
        string s;
        cin >> s;

        for(int i = 0; i < s.size(); i++) {
            long long tmp = ret;
            ret = (ret * 2) % MOD;
            ret = (ret + MOD - arr[s.at(i) - 'A']) % MOD;
            arr[s.at(i) - 'A'] = tmp;

            //printf("%lld %lld %lld\n", ret, tmp, arr[s.at(i) - 'A']);
        }

        cout << ret << endl;
    }

    return 0;
}