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
    ListNode* reverse(ListNode* head, int k){
        if(head== nullptr){
            return nullptr;
        }
        ListNode *mech = head;
        ListNode *help = nullptr;
        ListNode *temp;
        for(int i = 0; i< k; i++){
            temp= mech-> next;
            mech -> next = help;
            help = mech;
            mech = temp;
        }
        return help;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode *start = head;
      for(int i=0; i< k; i++){
        if(start== nullptr){
          return head;
        }
        else{
            start= start-> next;
        }
      } 
      ListNode *newhead= reverse(head, k);
      head-> next = reverseKGroup(start, k);
      return newhead;
    }
};