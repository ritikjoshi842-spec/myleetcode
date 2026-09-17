class Solution {
public:
    int maxArea(vector<int>& height) {
        int volume= 0;
        int maxvolume= 0;
        int left= 0;
        int right= height.size()- 1;
        while(left< right){
            int len= right- left;
            volume= min(height[left], height[right]) * len;
            maxvolume= max(volume, maxvolume);
            if(height[left]< height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxvolume;
    }
};