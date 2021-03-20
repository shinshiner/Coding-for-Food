/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        /* 能过但不是题目的意思，题目意思是结点的内存地址一样，这里只是认为值一样然后用暴力求解
        ListNode* p2;
        while(pHead1 != NULL){
            p2 = pHead2;
            while(p2 != NULL){
                if(pHead1->val==p2->val){return p2;}
                else{p2 = p2->next;}
            }
            pHead1 = pHead1->next;
        }
        return NULL;
        */
        ListNode *p1=pHead1, *p2=pHead2;
        if(p1 == NULL || p2 == NULL) {return NULL;}
        while(p1 != p2){
            if(p1 != NULL) {p1 = p1->next;}
            else{p1 = pHead2;}
            if(p2 != NULL) {p2 = p2->next;}
            else{p2 = pHead1;}
        }
        return p1;
    }
};