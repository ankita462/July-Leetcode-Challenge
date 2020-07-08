class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        int n = nums.size();
        if(n == 0) return output;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            if(i > 0 and nums[i-1] == nums[i]) continue;
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                if(sum < 0) left++;
                else if(sum > 0) right--;
                else{
                    output.push_back({nums[i], nums[left++], nums[right--]});
                    while(left < right and nums[left] == nums[left-1]) left++;
                    while(left < right and nums[right] == nums[right+1]) right--;
                }
            }
        }
        return output;
    }
};
