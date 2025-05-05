#include <bits/stdc++.h>
#define MAX_N 500005

using namespace std;

int n;
int arr[MAX_N];

struct Node {
    // int upper;
    int lower;
    bool leave = false;
    Node* left = nullptr;
    Node* right = nullptr;
};
Node* root = nullptr;

void print(Node* x, int d = 0) {
    if(x->left)
        print(x->left, d+1);
    for(int i = 0; i < d; i++)
        cout << "    ";
    cout << x->lower << endl;
    if(x->right)
        print(x->right, d+1);
}

void set_val(Node** px) {
    Node* x = *px;
    if(!x->left && !x->right) {
        if(!x->leave) {
            // printf("set nullptr\n");
            *px = nullptr;
        }
    } else if(!x->left) {
        *px = x->right;
    } else if(!x->right) {
        *px = x->left;
    } else {
        // x->upper = x->left->upper;
        x->lower = x->right->lower;
    }
}

void init(Node* x, int a, int e) {
    if (e - a < 1) {
        // printf("wrong: %d %d\n", a, e);
        assert(false);
    }
    if (e - a == 1) {
        // x->upper = arr[a];
        x->lower = arr[a];
        x->leave = true;
        return;
    }

    int mid = (a + e) / 2;
    x->left = new Node();
    x->right = new Node();
    // printf("%d %d %d\n", a, mid, e);

    init(x->left, a, mid);
    init(x->right, mid, e);

    set_val(&x);
}

int query(Node** px, int q) {
    Node* x = *px;
    int ret;
    
    if (!(x->left && x->right)) {
        if (x->lower > q)
            ret = -1;
        else {
            ret = x->lower;
            x->leave = false;       // kann in set_val entfernt werden
        }
    } 
    else if(q >= x->left->lower)
        ret = query(&x->left, q);
    else
        ret = query(&x->right, q);
    
    set_val(px);
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", arr + i);

    sort(arr, arr + n, greater<int>());

    root = new Node();
    init(root, 0, n);
    //print(root);
    // printf("init done\n");

    int outp = n;
    for(int i = 0; i < n - 1; i++) {
        //printf("look for %d\n", arr[i]/2);
        int ret = query(&root, arr[i] / 2);
        
        //printf("(%d)\n", ret);
        //print(root);

        if(ret == -1)
            break;
        outp--;
    }

    printf("%d\n", outp);
    
    return 0;
}