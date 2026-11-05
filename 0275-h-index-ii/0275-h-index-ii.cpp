class Solution {
public:
bool check(int mid, vector<int>& citations){
    
    int count_citations = 0;
    for(int i = 0; i< citations.size(); i++){
       if(citations[i]>= mid){
        count_citations++;
       } 
    }
    if(count_citations>= mid){
        return true;
    }
    return false;
}
    int hIndex(vector<int>& citations) {
        int low = 0;
        int high = citations.size();
        int res = -1;
        while(low<= high){
            int mid = low + (high - low)/2;
            if(check(mid, citations)){
                res = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return res;
    }
};