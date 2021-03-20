/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 正解 快慢指针
        ListNode *p_slow=head, *p_fast=head->next;
        while(p_slow!=NULL && p_fast!=NULL && p_fast->next!=NULL){
            if(p_slow == p_fast){return true;}
            else{p_slow = p_slow->next; p_fast = p_fast->next->next;}
        }
        return false;
        
        // 无赖解法
//         int signal=-10000;
//         while(head!=NULL){
//             if(head->val==signal){return true;}
//             else{head->val = signal; head = head->next;}
//         }
//         return false;
    }
};