class Solution {
public:
    
    void findSubsets(vector<int> nums,int i,int n,vector<vector<int>> &ans) {
        if(i==n) {
            return ;
        }
        int a=nums[i];
        vector<vector <int>> v=ans;
        for(auto x:v) {
            x.push_back(a);
            ans.push_back(x);
        }
        findSubsets(nums,i+1,n,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0,n=nums.size();
        if(n==0) {
            return {};
        }
        vector<vector <int>> ans;
        ans.push_back({});
        findSubsets(nums,i,n,ans);
        return ans;
    }
};
