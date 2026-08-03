class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int len = 0;

        while (right < n) {
            long long maxi = nums[right];
            long long mini = nums[left];

            if(left < right && maxi > k * mini) {
                left++;
                mini = nums[left];
            }
            len = max(len, right - left + 1);
            right++;

        }

        return n - len;

        
    }
};