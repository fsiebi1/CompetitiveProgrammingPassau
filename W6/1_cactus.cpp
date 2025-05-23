//#include <bits/stdc++.h>
#include <vector>
#include <stdio>
#include <iostream>

#define MAX_N 10005

using namespace std;

int n, m, t;
long long outp;
int arr[MAX_N];
vector<int> v[MAX_N];

void dfs(int pos, int depth) {
    if(arr[pos]) {
        outp += (depth - arr[pos]) * (depth - arr[pos]);
        return;
    }

    arr[pos] = depth;
    for(int i = 0; i < v[pos].size(); i++)
        dfs(v[pos][i], depth + 1);
}

int main() {
    cin >> t;

    for(;t>0;t--) {
        outp = 0;
        for(int i = 0; i < MAX_N; i++) {
            v[i].erase();
            arr[i] = 0;
        }

        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        dfs(0, 1);
        cout << outp << endl;
    }

    return 0;
}