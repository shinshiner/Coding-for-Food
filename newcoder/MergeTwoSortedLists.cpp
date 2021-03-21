/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param l1 ListNode类 
     * @param l2 ListNode类 
     * @return ListNode类
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) {return l2;}
        else{if(l2==NULL) {return l1;}}
        
        ListNode *cur_l1 = l1, *cur_l2 = l2, *ans, *temp;
        if(l1->val>l2->val){ans = l2; cur_l2 = l2->next;}
        else{ans = l1; cur_l1 = l1->next;}
        temp = ans;
        
        while(cur_l1!=NULL && cur_l2!=NULL) {
            if(cur_l1->val > cur_l2->val) {
                temp->next = cur_l2;
                cur_l2 = cur_l2->next;
                temp = temp->next;
            }
            else{
                temp->next = cur_l1;
                cur_l1 = cur_l1->next;
                temp = temp->next;
            }
        }
        
        if(cur_l1!=NULL) {temp->next = cur_l1;}
        else{temp->next = cur_l2;}
        
        return ans;
    }
};