class Solution {
public:
    int maxArea(vector<int>& height) 
    {

        int n = height.size();
        int left = 0;
        int right = n-1;
        int total_water = 0;
        while(left < right)
        {
            int mini = min(height[left], height[right]);
            int width = right - left ;
            int current_water = mini * width;
            total_water = max(total_water,current_water);
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }

        }
        return total_water;
    }
};