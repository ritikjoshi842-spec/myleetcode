class Solution
{
    public:
        int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
        {
            priority_queue<int> profit;
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> capi;
            int n = profits.size();
            for (int i = 0; i < n; i++)
            {
                if (capital[i] <= w)
                {
                    profit.push(profits[i]);
                }
                else
                {
                    capi.push({ capital[i],
                        profits[i] });
                }
            }
            while (k--)
            {
                if (profit.empty())
                {
                    return w;
                }
                else
                {
                    w = w + profit.top();
                    profit.pop();
                }
                while (!capi.empty() and w >= capi.top().first)
                {
                    profit.push(capi.top().second);
                    capi.pop();
                }
            }
            return w;
        }
};