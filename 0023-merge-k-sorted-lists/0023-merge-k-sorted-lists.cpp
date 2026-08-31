/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
       for(int i = 0; i< lists.size(); i++){
        if(lists[i]!= nullptr){
            pq.push({lists[i]-> val, lists[i]});
        }
       }
       ListNode* dummy = new ListNode(-1);
       ListNode* tail= dummy;
       while(!pq.empty()){
        auto temp = pq.top();
        ListNode* i= temp.second;
        tail-> next= i;
        tail= i;
        pq.pop();
        if(i-> next!= nullptr){
            pq.push({i-> next-> val, i-> next});
        }
       }
       return dummy-> next;
    }
};