#include <bits/stdc++.h>
#define MAX_N 100005
#define MAX_ALL 1'000'000'000'001
//#define MAX_ALL 20

using namespace std;

struct Node {
    int c = -1;
    Node* left = nullptr;
    Node* right = nullptr;
};

int n, m;
long long outp[MAX_N];
Node* root = new Node();

void print(Node* x = root, int d = 0, long long a = 1, long long e = MAX_ALL) {
    long long mid = (a+e)/2;
    if(x->left)
        print(x->left, d+1, a, mid);
    for(int i = 0; i < d; i++)
        cout << "    ";
    cout << x->c << " (" << a << ", " << e << ")\n";
    if(x->right)
        print(x->right, d+1, mid, e);
}

void update(Node* x, long long a, long long e, long long p, long long q, int c, int c2) {
    if(e <= a)
        return;
    if(x->c == -1)
        x->c = c2;

    if(p <= a && e <= q) {
        x->c = c;
        return;
    }
    if(q <= a || e <= p)
        return;
    
    if(!x->left) {
        x->left = new Node();
        x->right = new Node();
    }

    long long mid = (a+e)/2;
    update(x->left, a, mid, p, q, c, x->c);
    update(x->right, mid, e, p, q, c, x->c);
    x->c = -1;
}

void query(Node* x, long long a, long long e) {
    if(x->c != -1) {
        outp[x->c] += e-a;
    }
    else if(x->left) {
        long long mid = (a+e)/2;
        query(x->left, a, mid);
        query(x->right, mid, e);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        long long l, r;
        int c;
        scanf("%lld %lld %d", &l, &r, &c);
        if(l != r)
            update(root, 1, MAX_ALL, l, r, c, -1);
        //print();
    }

    query(root, 1, MAX_ALL);
    for(int i = 0; i < n; i++)
        printf("%lld ", outp[i]);
    printf("\n");

    return 0;
}