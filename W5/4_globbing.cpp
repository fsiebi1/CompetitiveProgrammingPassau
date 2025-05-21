#include <bits/stdc++.h>
#define MAX_N 1005

using namespace std;

bool pi_func(string s, int l) {
    //cout << "\t" << s << "\n";

    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    for(int i = 0; i < pi.size(); i++)
        if(pi[i] == l)
            return true;

    return false;
}

bool check() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    // cout << "'" << s << "'\n";
    // cout << "'" << t << "'\n";

    int pos = 0, pos2 = 1;

    for(; pos < s.size() && pos < t.size(); pos++) 
        if(s.at(pos) != t.at(pos)) {
            if(s.at(pos) == '*' || s.at(pos) == '+')
                break;
            else
                return false;
        }

    if (pos == s.size())
        return pos == t.size();

    for(; pos2 <= s.size() && pos2 <= t.size(); pos2++)
        if(s.at(s.size() - pos2) != t.at(t.size() - pos2)) {
            if(s.at(s.size() - pos2) == '*' || s.at(s.size() - pos2) == '+')
                break;
            else
                return false;
        }
    
    // if (pos - 1 >= t.size() - pos2 + 1)
    //     return false;

    // only one
    if (pos == s.size() - pos2) {
        if(s.at(pos) == '*')
            return t.size() >= s.size() - 1;
        return t.size() >= s.size();
    }

    // both
    string within = s.substr(pos + 1, s.size() - pos - pos2 - 1);
    if(s.at(pos) == '+')
        pos++;
    else
        pos2++;

    if(t.size() - pos - pos2 + 1 < 0)
        return false;
    string longer = t.substr(pos, t.size() - pos - pos2 + 1);
    
    return pi_func(within + "*" + longer, within.size());
}

int main() {
    int t;
    string x;
    getline(cin, x);
    t = stoi(x);
    
    for(;t>0;t--) {
        if(check())
            printf("Yes\n");
        else
            printf("No\n");
    }
}