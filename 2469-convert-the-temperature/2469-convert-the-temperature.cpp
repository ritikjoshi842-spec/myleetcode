class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> res;
        double f = celsius* 1.80 + 32.00;
        double k = celsius + 273.15;
        res.push_back(k);
        res.push_back(f);
        return res;
    }
};