class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());
        double sum = 0;
        int k = prices.size() - 1;
        int j = discounts.size() - 1;
           while(j>= 0 and k>= 0){
           double price = (float)prices[k];
           double discount_to_get = (price * (100 - (double)discounts[j]))/100;
           sum = sum + discount_to_get;
           j--;
           k--;
        }
        while(k>= 0){
            sum = sum + prices[k];
            k--;
        }
        return sum;
    }
};