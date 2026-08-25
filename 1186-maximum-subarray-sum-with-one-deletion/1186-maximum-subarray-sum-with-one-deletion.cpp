class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete = arr[0];
        int onedelete = 0;
        int mxlen= INT_MIN;
        for(int i = 1; i< arr.size(); i++){
           int v1 = arr[i] + nodelete;
           int v2 = arr[i];
           int v3 = nodelete;
           int v4 = arr[i] + onedelete;
           mxlen = max(mxlen, max(max(v1, v2), max(v3, v4)));
           nodelete= max(v1, v2);
           onedelete= max(v3, v4);
        }
        if(mxlen== INT_MIN){
           return arr[0];   
        }
        return mxlen;
    }
};