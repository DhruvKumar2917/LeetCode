
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


class Solution {
    int numberOfArray(vector<int> &nums,int mid){
        int arr=1;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if((sum+nums[i])<=mid){
                sum+= nums[i];

            }
            else{
                sum =nums[i];
                arr++;
            }
        }
        return arr;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
         int low =*max_element(nums.begin(),nums.end());
        int high =accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(numberOfArray(nums,mid)>k) low=mid+1;
            else{
                high=mid-1;
            }
        }
        return low;
        
    }
};


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;;
        int high=arr.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k)low= mid+1;
            else high=mid-1;
        }
        return high+1+k;
    }
};


class Solution {
    void merge(vector<pair<int,int>> &newArr, int low, int mid, int high, vector<int> &ans) {
        vector<pair<int,int>> temp;
        int i = low;
        int j = mid + 1;

        while (i <= mid && j <= high) {
            if (newArr[i].first < newArr[j].first) {
                // right element is greater
                ans[newArr[i].second] += (high - j + 1);
                temp.push_back(newArr[i++]);
            } else {
                temp.push_back(newArr[j++]);
            }
        }

        while (i <= mid) temp.push_back(newArr[i++]);
        while (j <= high) temp.push_back(newArr[j++]);

        for (int k = low; k <= high; k++) {
            newArr[k] = temp[k - low];
        }
    }

    void MergeSort(vector<pair<int,int>> &newArr, int low, int high, vector<int> &ans) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            MergeSort(newArr, low, mid, ans);
            MergeSort(newArr, mid + 1, high, ans);
            merge(newArr, low, mid, high, ans);
        }
    }

  public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        vector<int> ans(n, 0);
        vector<int> result;
        vector<pair<int,int>> newArr;

        for (int i = 0; i < n; i++) {
            newArr.push_back({arr[i], i});
        }

        MergeSort(newArr, 0, n - 1, ans);

        for (auto it : indices) {
            result.push_back(ans[it]);
        }

        return result;
    }
};
