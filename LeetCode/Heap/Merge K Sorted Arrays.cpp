// Approach 1 : Naive (sorting)
// TC is O(mlogm) where m is the total size of all the k arrays
// SC is O(m)

#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k)
{
    vector<int> res;
    
    for(int i = 0;i < k; i++)
    {
        for(int j = 0; j < kArrays[i].size(); j++)
        {
            res.push_back(kArrays[i][j]);
        }
    }
    
    sort(res.begin(), res.end());
    
    return res;
}

// Approach 2 : Using merge on two arrays at a time
// TC ?
// SC is O(m) where m is the total size of all the k arrays

#include <bits/stdc++.h>
vector<int> merge(vector<int> arr1, vector<int> arr2) {
    if (arr1.size() == 0) return arr2;
    if (arr2.size() == 0) return arr1;

    int p1 = 0, p2 = 0;
    vector<int> res;
    while (p1 != arr1.size() && p2 != arr2.size()) {
        if (arr1[p1] <= arr2[p2]) {
            res.push_back(arr1[p1]);
            p1++;
        } else {
            res.push_back(arr2[p2]);
            p2++;
        }
    }
    while (p1 != arr1.size()) {
        res.push_back(arr1[p1++]);
    }
    while (p2 != arr2.size()) {
        res.push_back(arr2[p2++]);
    }

    return res;
} 

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k)
{
    if (kArrays.size() == 1) return kArrays[0];

    vector<int> res = merge(kArrays[0], kArrays[1]);
    for (int i = 2; i < kArrays.size(); i++) {
        res = merge(kArrays[i], res);
    }

    return res;
}

// Approach 3 : Using divide and merge
// TC is O(mlogk)
// SC is O(mlogk)

#include <bits/stdc++.h>
vector<int> merge(vector<int> arr1, vector<int> arr2) {
    if (arr1.size() == 0) return arr2;
    if (arr2.size() == 0) return arr1;

    int p1 = 0, p2 = 0;
    vector<int> res;
    while (p1 != arr1.size() && p2 != arr2.size()) {
        if (arr1[p1] <= arr2[p2]) {
            res.push_back(arr1[p1]);
            p1++;
        } else {
            res.push_back(arr2[p2]);
            p2++;
        }
    }
    while (p1 != arr1.size()) {
        res.push_back(arr1[p1++]);
    }
    while (p2 != arr2.size()) {
        res.push_back(arr2[p2++]);
    }

    return res;
} 

vector<int> helper(int l, int r, vector<vector<int>>& kArrays) {
    if (l == r) return kArrays[l];
    if (l == r - 1) return merge(kArrays[l], kArrays[r]);

    int mid = l + (r - l) / 2;
    return merge(helper(l, mid, kArrays), helper(mid + 1, r, kArrays));
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    if (kArrays.size() == 1) return kArrays[0];

    return helper(0, k - 1, kArrays);
}


// Approach 4 : Using minheap
// TC is O(mlogk)
// SC is O(m)

#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k)
{
    vector<int> result; 
  
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > minHeap; 
  
    for (int i = 0; i < kArrays.size(); i++) {
        minHeap.push({ kArrays[i][0], { i, 0 } }); 
    }
  
    while (minHeap.empty() == false) { 
        pair<int, pair<int, int> > curr = minHeap.top(); 
        minHeap.pop(); 
  
        int i = curr.second.first; 
        int j = curr.second.second; 
    
        result.push_back(curr.first); 
  
        if (j + 1 < kArrays[i].size()) {
            minHeap.push({ kArrays[i][j + 1], { i, j + 1 } }); 
        }
    } 
  
    return result; 
}
