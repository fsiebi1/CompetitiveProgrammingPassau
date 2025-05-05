#include <bits/stdc++.h>

using namespace std;

int inp[] = {5, 1, 1, 3};

int main() {
    for(int i : inp) 
        cout << "? insert " << i << endl;

    int x;
    cout << "? remove" << endl;
    cin >> x;
    assert (x != -1);

    if (x == 3) {
        cout << "! stack" << endl;
        return 0;
    }
    if (x == 5) {
        cout << "! queue" << endl;
        return 0;
    }

    assert(x == 1);

    cout << "? remove" << endl;
    cin >> x;
    assert (x != -1);
    
    if (x == 1) {
        cout << "! pq" << endl;
        return 0;
    }
    if (x == 3) {
        cout << "! set" << endl;
        return 0;
    }

    return -1;
}