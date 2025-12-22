
#include<bits/stdc++.h>

class Solution {
public:
    string minWindow(string s, string t) {
        int left=0;
        int right=0;
        int minlen=INT_MAX;
        int cnt=0;
        int sin=-1;
        unordered_map<char,int> mpp;
        for(int i=0;i<t.length();i++){
            mpp[t[i]]++;
        }
        while(right<s.length()){
            if(mpp[s[right]]>0) cnt++;
            mpp[s[right]]--;
            while(cnt==t.length()){
                if(right-left+1 < minlen){
                    minlen=right-left+1;
                    sin=left;
                }
                mpp[s[left]]++;
                if(mpp[s[left]]>0)cnt--;
                left++;

            }
            right++;
        }
        return (sin==-1)?"":s.substr(sin,minlen);
        
        }
    
};