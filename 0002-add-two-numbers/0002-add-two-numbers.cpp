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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; // 18, 1
        int sum = 0;
        //int rest = 0; // 18, 8
        ListNode* current = new ListNode();
        ListNode* result = current;
        while(l1 || l2) {
            sum = carry;
            if (l1 && l2) sum += l1->val + l2->val;
            else if (l1) sum += l1->val;
            else sum += l2->val;

            current->next = new ListNode(sum % 10);
            current = current->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            carry = sum / 10;
        }
        if (carry != 0) {
            current->next = new ListNode(carry);
            current = current->next;
        }
        return result->next;
    }
};