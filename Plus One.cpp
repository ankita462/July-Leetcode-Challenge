class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
         int i = digits.size() - 1;
        while(i >=0 && digits[i] == 9){  
            digits[i] = 0;  
            i--; 
        }
        if(i == -1){   
            vector<int>ans(digits.size()+1);  
            ans[0] = 1; 
            return ans;
        }
        digits[i]++;
        return digits;
    }
};
