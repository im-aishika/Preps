/* For a given array of n integers, find the length of the longest increasing subsequence (LIS) from the array  */

void func(vector<int> &nums){
    
    vector<int> ans;
    int n = nums.size();
    
    for(int i = 0; i < n; i++){
        if(nums[i] > ans.back() || ans.size() == 0){
            ans.push_back(nums[i]);
        }
        else{
            int lb = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[lb] = nums[i];
        }
    }
    
    //displaying the longest increasing subsequence
    for(auto n: ans){
        cout << n <<" ";
    }
    
    cout <<endl;
    
    //to print the length of the longest increasing subsequence
    cout << ans.size();
}
