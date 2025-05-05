#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (; t > 0; t--) {
        string s;
        cin >> s;

        stack<int> st;
        int sum = 0;
        
        // for(char c : s) {
        for(int x = 0; x < s.length(); x++) {
            char c = s.at(x);

            if (c == '/') {
                if (!st.empty()) {
                    int now = st.top();
                    st.pop();
                    sum += x - now;
                }
            } else if(c == '\\') {
                st.push(x);
            }
        }
        printf("%d\n", sum);

    }

    return 0;
}