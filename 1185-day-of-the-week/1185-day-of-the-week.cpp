class Solution {
public:
bool check(int year){
    if(year==2100){
        return false;
    }
    if(year%4 == 0){
        return true;
    }
    return false;
}
int leap(int year){
    int x = year/4 - year/100 + year/400;
    int y = 1971/4 - 1971/100 + 1971/400;
    int z = x - y;
    if(check(year)){
        z = z - 1;
    }
    return z;
}
    string dayOfTheWeek(int day, int month, int year) {
        int y = year - 1971;
        int d = y* 365;
        int l = leap(year);
        d = d + l;
        int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int m = month - 1;
        for(int i = 0; i< m; i++){
            d = d + arr[i];
        }
        if(check(year) and month> 2){
            d = d + 1;
        }
        d = d + day;
        int x = d%7;
        if(x==0){
            return "Thursday";
        }
        if(x==1){
            return "Friday";
        }
        if(x==2){
            return "Saturday";
        }
        if(x==3){
            return "Sunday";
        }
        if(x==4){
            return "Monday";
        }
        if(x==5){
            return "Tuesday";
        }
        if(x==6){
            return "Wednesday";
        }
        return "";
    }
};