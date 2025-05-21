#include <bits/stdc++.h>
#define MAX_N 1005

using namespace std;

const int ALPHABET_SIZE = 26;

struct Node {
    int children[ALPHABET_SIZE];
    bool is_word;
};
vector<Node> v(1);

void insert(string s, int pos = 0, int i = 0) {     // cast to lower...
    if (pos == s.size()) {
        v[i].is_word = true;
        return;
    }

    if (v[i].children[s.at(pos) - 'a'] == 0) {
        v[i].children[s.at(pos) - 'a'] = v.size();
        v.push_back(Node());
    }

    insert(s, pos + 1, v[i].children[s.at(pos) - 'a']);
}

bool check(string s, int pos = 0, int i = 0) {
    if (pos == s.size())
        return v[i].is_word;

    if (v[i].children[s.at(pos) - 'a'] == 0)
        return false;

    return check(s, pos + 1, v[i].children[s.at(pos) - 'a']);
}

int main() {
    v[0] = Node();
    insert("asdf");
    insert("jklo");

    if(check("asdf"))
        printf("first\n");
    if(check("florian"))
        printf("second\n");
    if(check("a"))
        printf("third\n");

    printf("done\n");

    return 0;
}