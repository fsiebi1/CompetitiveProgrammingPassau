#include <bits/stdc++.h>
#define MAX_N 5005

using namespace std;

int n, r, m, zeit;
double dp[MAX_N][MAX_N];

int pos[MAX_N];
int get_there[MAX_N];
double prob[MAX_N];
int fail_wait[MAX_N];

// wh wahrscheinlichkeit pro versuch, wh_hierher wahrscheinlichkeit zu dieser abfrage zu kommen, weg der wiederholt werden muss
double rek(double wh, double wh_hierher, double weg) {
    double now = wh_hierher * weg;          // wh es jetzt nicht zu schaffen
    if (now < 0.0000001)
        return now;
    return now + rek(wh, wh_hierher * (1 - wh), weg);
}

int main1() {
    cout << rek(0.3, 1, 5) << endl;
    return 0;
}

int main() {
	cin >> n >> r >> m;
    zeit = r - n;       // muss < zeit sein, nicht ident

    for(int i = 1; i <= m; i++) {
        int po, f;
        double pr;
        cin >> po >> pr >> f;

        pos[i] = po;
        get_there[i] = pos[i] - pos[i-1];
        prob[i] = pr;
        fail_wait[i] = f;
    }

    // problem mit der wahrscheinlichkeit, wenn er wiederholen muss
    
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < zeit; j++) {
            //dp[i][j] = (dp[i-1][j] + get_there[i]) / prob[i];       // restart
            dp[i][j] = rek(prob[i], 1, dp[i-1][j] + get_there[i]);
            if (j >= fail_wait[i])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - fail_wait[i]] + get_there[i] + (fail_wait[i] * (1 - prob[i])));      // wait
        }
    }

    for (int i = 0; i <= m; i++) {
        for(int j = 0; j < zeit; j++)
            cout << dp[i][j] << "\t";
        cout << endl;   
    }
    cout << endl;

    // cout << dp[m][zeit - 1] << endl;
    cout << fixed << setprecision(15) << dp[m][zeit - 1] + (n - pos[m]) << endl;

    return 0;
}