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
    ListNode* reverse(ListNode *head, int k){
        ListNode* curr= head;
        ListNode* prev= NULL;
        for(int i=0; i< k; i++){
            ListNode* temp = curr-> next;
            curr-> next= prev;
            prev= curr;
            curr= temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head== nullptr){
            return head;
        }
        int pos= k;
        ListNode* start= head;
        while(pos> 0){
            if(start== nullptr){
                return head;
            }
            start= start-> next;
            pos--;
        }
        ListNode* newhead= reverse(head, k);
        head-> next= reverseKGroup(start, k);
        return newhead;
    }
};