class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        int left = 0, right = 0;
        int len = 1e9;
        long long sum = 0;

        while (right < n) {
            sum += nums[right];

            while (sum >= target){
                if(len > (right - left + 1)) len = right - left + 1;
                sum -= nums[left];
                left++;
            }

            right ++;


        }

        return (len == 1e9)? 0 : len;
        
    }
};