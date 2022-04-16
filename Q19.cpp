//Write a program to compute the square root of a given number

#include<bits/stdc++.h>
using namespace std;

int computeSQRT(int x) {
    long low = 0;
    long high = x;
    int ans = 0;
    
    while(low <= high){
        
        long mid = (low + high) >> 1;
        
        if(mid * mid == x) return mid;
        
        if(mid * mid < x){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    cout << computeSQRT (n) << endl;
    
    return 0;
}
