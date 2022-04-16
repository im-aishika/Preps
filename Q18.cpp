// Given 2 strings, write a program to find the longest common subsequence in both the strings

#include<bits/stdc++.h>
using namespace std;

int func(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    //out of bound cases
    if(i == 0 || j == 0) return 0;
    
    if(s[i-1] == t[j-1]){
        return dp[i][j] = 1 + func(i-1, j-1, s, t, dp);
    }
    
    return dp[i][j] = max(func(i-1, j, s, t, dp), func(i, j-1, s, t, dp));
}


int longestCommonSubsequence(string &s, string &t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    
    return func(n, m, s, t, dp);
}

/*

int longestCommonSubsequence(string &s, string &t){
    int n = s.size();
    int m = t.size();
    
    int dp[n+1][m+1];
    
    for(int j = 0; j <= m; j++) dp[0][j] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

*/

int main(){
    string s, t;
    cin >> s;
    cin >> t;
    
    cout << longestCommonSubsequence(s, t) << endl;
    
    return 0;
}
