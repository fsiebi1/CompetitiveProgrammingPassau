#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(; t > 0; t--) {
        map<int, int> m;
        map<int,int>::iterator it;

        int n;
        cin >> n;

        int longest = 0;
        int res = -1;       // eins nach letzten paar.first

        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;

            it = m.find(x);

            if (it != m.end()) {
                longest = i - max(it->second, res - 1);

                if(it->second >= res)
                    res = it->second + 1;

                it->second = i;
            }
            else 
                m[x] = i;
        }

        for (it = m.begin(); it != m.end(); it++) {
            longest = n - max(it->second, res);
        }
        printf("%d\n", longest);
    }

    return 0;
}