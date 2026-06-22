class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26,0);

        int n = text.length();

        for(int i = 0; i<n; i++){
            freq[text[i]-'a']++;
        }

        int ans = INT_MAX;
       ans =  min(ans,freq[0]);
       ans =  min(ans,freq[1]);
        ans = min(ans,freq[11]/2);
        ans = min(ans,freq[13]);
       ans = min(ans,freq[14]/2);

       
       return ans;
        
    }
};