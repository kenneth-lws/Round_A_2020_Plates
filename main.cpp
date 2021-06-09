#include <iostream>
#include <string>
#include <stdlib.h>
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double


int t, n, k, p, a;
int dp[51][1501];
int answer;

int solve() {
    cin >> n >> k >> p;
    memset(dp, 0, sizeof(dp));
    dp[0][0]=0;
    for(int i=0; i<n; ++i) {
        memcpy(dp[i+1], dp[i], sizeof(dp[0]));
        for(int j=0, s=0; j<k; ++j) {
            cin >> a;
            s += a;
            for(int l=0; l+j+1<=p; ++l){
                dp[i+1][l+j+1]=max(dp[i][l]+s, dp[i+1][l+j+1]);
            }
        }
    }

    return dp[n][p];
}


int main(){
    cin >> t;
    for (int i = 0; i < t; i++){
        answer = solve();
        cout << "Case #" << i+1 <<": " << answer << endl;
    }
    return 0;
}
