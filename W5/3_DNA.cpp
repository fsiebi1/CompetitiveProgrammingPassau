#include <bits/stdc++.h>
#define MAX_N 305

using namespace std;

string s, t;
int len = 0;
vector<string> v;

void pi_func(string s, int m) {
    //for(int pos = 0; pos < m; pos++) {

        int n = (int)s.length();
        vector<int> pi(n);

        for (int i = 1; i < n; i++) {
        // for (int i = pos + 1; i < n; i++) {
            int j = pi[i-1];
            // while (j > pos && s[i] != s[j])
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }

        // vector<int> z(n);
        // for (int i = pos + 1, l = pos, r = pos; i < n; ++i) {
        //     if (i <= r) z[i] = min (r - i + 1, z[i - l]);
        //     while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        //     if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        // }

        // cout << s << " " << "pos" << endl;
        // for(int i = 0; i < n; i++)
        //     cout << pi[i] << " ";
        // cout << endl;

        for(int i = 0; i < pi.size(); i++) {
            if(pi[i] > len) {
                len = pi[i];
                v.clear();
            }
            if(pi[i] == len && len != 0)
                v.push_back(s.substr(i - len + 1, len));
        }
    //}
}

int main() {
    while(!s.size()) {
        v.clear();
        len = 0;

        getline(cin, s);
        getline(cin, t);
        if(!s.size())
            break;

        for(int i = 0; i < s.size(); i++)
            pi_func(s.substr(i, s.size() - i) + "#" + t, s.size());
        
        if(len) {
            sort(v.begin(), v.end());
            for(string x : v)
                cout << x << "\n";
        } else {
            cout << "No common sequence.";
        }

        cout << "\n";
        getline(cin, s);
    }
}