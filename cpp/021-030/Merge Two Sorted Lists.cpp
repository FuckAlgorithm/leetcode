class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *fake_head = head;
        
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                head->next = l2;
                break;
            } else if(l2 == nullptr) {
                head->next = l1;
                break;
            }
            
            if (l1->val <= l2->val) {
                head->next = l1;
                head = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                head = l2;
                l2 = l2->next;
            }
        }
        return fake_head->next;
    }
};
