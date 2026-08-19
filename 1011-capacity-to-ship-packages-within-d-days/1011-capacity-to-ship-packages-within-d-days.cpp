class Solution {
public:
    bool fx(vector<int>& weights, int days, int guess){
        int weight = 0;
        int count = 1;
        for(int i = 0; i< weights.size(); i++){
           if(weight + weights[i]<= guess){
             weight = weight + weights[i];
           }
           else{
            weight = weights[i];
            count++;
           }
        }
        if(count> days){
          return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for(int i =0; i< weights.size(); i++){
            high = high + weights[i];
        }
        int res = -1;
        while(low<= high){
            int mid = low + (high - low)/2;
            if(fx(weights, days, mid)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }
};