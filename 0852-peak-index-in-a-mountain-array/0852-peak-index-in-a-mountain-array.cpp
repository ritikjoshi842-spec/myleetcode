class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low= 0;
        int high= arr.size()- 1;
        int res= -1;
        while(low<= high){
            int mid= low+ (high- low)/ 2;
            if(mid==0 and arr[mid]> arr[mid + 1]){
              return 0;
            }
            else if((mid == arr.size()- 1) and arr[mid- 1]< arr[mid]){
                return arr.size()- 1;
            }
            if(arr[mid]< arr[mid+ 1]){
                low= mid+ 1;
            }
            else{
                res= mid;
                high= mid- 1;
            }
        }
        return res;
    }
};