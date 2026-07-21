class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete= arr[0];
        int onedelete= 0;
        int res= arr[0];
        for(int i= 1; i< arr.size(); i++){
            int v1= nodelete+ arr[i];
            int v2= nodelete;
            int v3= onedelete+ arr[i];
            int v4= arr[i];
            nodelete= max(v1, v4);
            onedelete= max(v2, v3);
            res= max(res, max(nodelete, onedelete));
        }
        return res;
    }
};