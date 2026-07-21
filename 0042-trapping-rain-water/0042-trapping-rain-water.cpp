class Solution {
public:
    int trap(vector<int>& height) {
     int left= 0;
     int leftmax= 0;
     int right = height.size()- 1;
     int rightmax= 0;
     int water= 0;
     while(left< right){
        if(height[left]> height[right]){
            if(height[right]< rightmax){
                water= water + min(rightmax, height[left])- height[right];
            }
            else{
                rightmax= height[right];
            }
            right--;
        }
        else{
            if(height[left]< leftmax){
                water= water + min(leftmax, height[right])- height[left];
            }
            else{
                leftmax= height[left];
            }
            left++;
        }
     } 
     return water;  
    }
};