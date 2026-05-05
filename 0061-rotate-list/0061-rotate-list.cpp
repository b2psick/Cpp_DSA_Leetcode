class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        int count=1;
        if(head==nullptr) return nullptr;
        while(temp->next){
            temp=temp->next;
            count++;
        }
        temp->next=head;
        k=k%count;
        int ok=count-k;
        for(int i=0;i<ok;i++){
            temp=temp->next;
        }
        ListNode* p=temp->next;
        temp->next=nullptr;
        return p;
    }
};