
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



class Node {
public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {

    int capacity;
    unordered_map<int, Node*> mpp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newNode) {
        newNode->next = head->next;
        head->next->prev = newNode;
        newNode->prev = head;
        head->next = newNode;
    }
    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }

    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];
            int res = temp->val;
            mpp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mpp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* existingnode = mpp[key];
            mpp.erase(key);
            deleteNode(existingnode);
        }
        if (mpp.size() == capacity) {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


 class LFUCache {
    class Node {
    public:
        int key;
        int val;
        int cnt;
        Node* prev;
        Node* next;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->cnt = 1; 
            this->prev = NULL;
            this->next = NULL;
        }
    };

    class List {
    public:
        int size;
        Node* head;
        Node* tail;
        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addFront(Node* node) {
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;
            size++;
        }

        void deleteNode(Node* node) {
            Node* prevNode = node->prev;
            Node* nextNode = node->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            size--;
        }
    };

    unordered_map<int, List*> freqListMap;
    unordered_map<int, Node*> keyNode;
    int capacity;
    int minfreq;
    int curSize;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minfreq = 0;
        this->curSize = 0;
    }

    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);

        if (node->cnt == minfreq && freqListMap[node->cnt]->size == 0) {
            minfreq++;
        }

        List* nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }

        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            int val = node->val;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
            return;
        }

        if (curSize == capacity) {
            List* list = freqListMap[minfreq];
            keyNode.erase(list->tail->prev->key);
            list->deleteNode(list->tail->prev);
            curSize--;
        }

        curSize++;
        minfreq = 1;
        List* listfreq = new List();
        if (freqListMap.find(minfreq) != freqListMap.end()) {
            listfreq = freqListMap[minfreq];
        }

        Node* node = new Node(key, value);
        listfreq->addFront(node);
        keyNode[key] = node;
        freqListMap[minfreq] = listfreq;
    }
};





