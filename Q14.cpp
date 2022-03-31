/* A frog can jump either 1, 2, or 3 steps to reach the top. Write a program to find out how many ways it can reach the top. */


#include<bits/stdc++.h>
using namespace std;

int func(int n, vector<int> &dp){
    if(n == 0 || n == 1) return 1;
    
    if(dp[n] != -1) return dp[n];
    
    //climb up by one steps
    int one = func(n-1, dp);
    //climb up by two steps
    int two = func(n-2, dp);
    //climb up by three steps
    int thr = 0;
    if(n > 2) thr = func(n-3, dp);
    
    return dp[n] = (one + two + thr);
}

int main(){
    int n = 4;
    vector<int> dp(n+1, -1);
    cout << func(n, dp);
    return 0;
}
