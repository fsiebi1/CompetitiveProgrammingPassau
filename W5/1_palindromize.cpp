#include <bits/stdc++.h>
#define MAX_N 1005

using namespace std;

int t;
int arr[MAX_N][MAX_N];      // count of operations to make s[first][last] letters to a palindrome

int main() {
    cin >> t;
    for(int z = 1; z <= t; z++) {
        string s;
        cin >> s;
        int n = s.size();

        for(int i = 0; i <= n+2; i++)
            for(int j = 0; j <= n+2; j++)
                arr[i][j] = 0;

        for(int i = 0; i <= n; i++) {
            arr[i][0] = i;
            arr[0][i] = i;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <=n; j++) {
                arr[i][j] = min(arr[i-1][j], arr[i][j-1]) + 1;
                arr[i][j] = min(arr[i][j], arr[i-1][j-1] + (s.at(i-1) == s.at(n-j) ? 0 : 1));
            }
        }

        int mini = MAX_N;
        int n2 = (n/2)*2;
        //printf("\t%d\n", n2);

        for(int i = 0; i <= n; i++)
            mini = min(arr[i][n - i], mini);
        // if(n != n2)
            for(int i = 1; i < n; i++)
                mini = min(arr[i][n - i + 1], mini);
/*
        printf("\t\t");
        for(int i = 1; i <= n; i++)
            printf("%c\t", s.at(n-i));
        printf("\n");

        for(int i = 0; i <= n; i++) {
            if(i!= 0)
                printf("%c\t", s.at(i-1));
            else
                printf("\t");
            for(int j = 0; j <=n; j++) {
                printf("%d\t", arr[i][j]);
            }
            printf("\n");
        }

*/
        // cout << arr[n][n]/2 << endl;
        cout << "Case " << z << ": " << mini << endl;
    }

    return 0;
}