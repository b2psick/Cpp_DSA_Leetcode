class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* ok=head;
        ListNode* ok1=head;
        while(ok1&&ok1->next){
            ok1=ok1->next->next;
            ok=ok->next;
        }
        if(head->next==nullptr) return nullptr;
        if(ok->next==nullptr) head->next=nullptr;
        else{
        ok->val=ok->next->val;
        ok->next=ok->next->next;
        }
        return head;
    }
};