class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10;
        int sum = 0;
        int y = 0;
        while(sum< n){
            sum = sum + x;
            if(sum> n){
                break;
            }
            x--;
            y++;
        }
        if(y%2==0){
            return false;
        }
        return true;
    }
};