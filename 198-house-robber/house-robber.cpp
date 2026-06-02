class Solution {
public:
    int f(int index, vector<int>& nums, vector<int>& dp) {
        if(index >= nums.size()) return 0;
        if(dp[index]!= -1) return dp[index];
        int take = nums[index] + f(index+2,nums,dp);
        int nottake = 0 + f(index+1,nums,dp);

        return dp[index] = max(take, nottake);
    }
    int rob(vector<int>& nums){
        int n = nums.size();
        vector<int>dp(n,-1);
        return f(0, nums,dp);
    }
};