// Approach 1 : Using extra space
// TC is O(m + n), SC is O(m + n)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        vector<int> res;
        while (p1 < m && p2 < n) {
            if (nums1[p1] >= nums2[p2]) {
                res.push_back(nums2[p2]);
                p2++;
            } else {
                res.push_back(nums1[p1]);
                p1++;
            }
        }
        while (p1 < m) {
            res.push_back(nums1[p1]);
            p1++;
        }
        while (p2 < n) {
            res.push_back(nums2[p2]);
            p2++;
        }
        nums1 = res;
    }
};

// Approach 2 : Using O(1) space
// TC is O(m + n), SC is O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, i = m + n - 1;

        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] >= nums2[p2]) {
                nums1[i] = nums1[p1];
                p1--;
            } else {
                nums1[i] = nums2[p2];
                p2--;
            }
            i--;
        }
        while (p1 >= 0) {
            nums1[i] = nums1[p1];
            p1--;
            i--;
        }
        while (p2 >= 0) {
            nums1[i] = nums2[p2];
            p2--;
            i--;
        }
    }
};