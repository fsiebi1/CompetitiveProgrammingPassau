#include <bits/stdc++.h>
#define MAX_N 1005

using namespace std;

const int ALPHABET_SIZE = 2;
const int OFFSET = '0';

struct Node {
    int children[ALPHABET_SIZE];
    bool all;
    bool done;
};
vector<Node> v(1);

void insert(string s, int pos = 0, int i = 0) {
    while(true) {
        if (pos == s.size()) {
            v[i].done = true;
            return;
        }

        if(s.at(pos) == '*') {
            v[i].all = true;
            return;
        }

        if (v[i].children[s.at(pos) - OFFSET] == 0) {
            v[i].children[s.at(pos) - OFFSET] = v.size();
            v.push_back(Node());
        }

        i = v[i].children[s.at(pos) - OFFSET];
        pos++;
    }
    // insert(s, pos + 1, v[i].children[s.at(pos) - OFFSET]);
}

bool check(string s, int pos = 0, int i = 0) {
    while(true) {
        if(v[i].all)
            return true;

        if (pos == s.size())
            return v[i].done;

        if (v[i].children[s.at(pos) - OFFSET] == 0)
            return false;

        i = v[i].children[s.at(pos) - OFFSET];
        pos++;
    }
    // return check(s, pos + 1, v[i].children[s.at(pos) - OFFSET]);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(s);
    }

    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if(check(s))
            printf("Yes\n");
        else
            printf("No\n");

        //cout << check(s) ? "Yes\n" : "No\n";
    }

    return 0;
}