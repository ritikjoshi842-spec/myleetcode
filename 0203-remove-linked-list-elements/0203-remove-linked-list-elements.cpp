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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!= nullptr){
            if(curr-> val== val){
                if(curr== head){
                    head= curr-> next;
                    curr= head;
                }
                else{
                ListNode* temp = curr-> next;
                prev-> next= curr-> next;
                curr= temp; 
                }
            }
            else{
                if(curr== head){
                    prev= head;
                    curr= curr-> next;
                }
                else{
                    prev= prev-> next;
                    curr= curr-> next;
                }           
            }
        }
        return head;
    }
};