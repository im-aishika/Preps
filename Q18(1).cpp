// Given 2 strings, write a program to find the longest common subsequence in both the strings

#include<bits/stdc++.h>
using namespace std;


string longestCommonSubsequence(string &s, string &t){
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
    
    //now at thsi point I know the length of the longest common subsequence of both  the strings
    //which I can get from dp[n][m]
    
    string str = "";
    int  i = n, j = m;
    
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]) {
            str += s[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(str.begin(), str.end());
    return str;
}


int main(){
    string s, t;
    cin >> s;
    cin >> t;
    
    cout << longestCommonSubsequence(s, t) << endl;
    
    return 0;
}
