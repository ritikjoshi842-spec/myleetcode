class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int before_mid1, before_mid2, after_mid1, after_mid2;
        int low1 = 0;
        int high1 = nums1.size();
        int low2 = 0;
        int high2 = nums2.size();
        int n1 = nums1.size();
        int n2 = nums2.size();
        while (low1 <= high1) {
            int mid1 = low1 + (high1 - low1) / 2;
            int mid2 = (n1 + n2 + 1) / 2 - mid1;
            if (mid1 == 0) {
                before_mid1 = INT_MIN;
            } else {
                before_mid1 = nums1[mid1 - 1];
            }
            if (mid2 == 0) {
                before_mid2 = INT_MIN;
            } else {
                before_mid2 = nums2[mid2 - 1];
            }
            if (mid2 == n2) {
                after_mid2 = INT_MAX;
            } else {
                after_mid2 = nums2[mid2];
            }
            if (mid1 == n1) {
                after_mid1 = INT_MAX;
            } else {
                after_mid1 = nums1[mid1];
            }
            if (before_mid1 <= after_mid2 and before_mid2 <= after_mid1) {
                if ((n1 + n2) % 2 == 0) {
                    return (max(before_mid1, before_mid2) +
                           min(after_mid1, after_mid2)) / 2.0;
                } else {
                    return max(before_mid1, before_mid2);
                }
            }
            else if(before_mid1>= after_mid2){
                high1 = mid1 - 1;
            }
            else{
                low1 = mid1 + 1;
            }
        }
        return -1;
    }
};