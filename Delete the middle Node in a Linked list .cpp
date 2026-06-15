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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* dummy = new ListNode( -1);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        while(fast->next != nullptr && fast->next->next != nullptr){
              slow = slow->next;
              fast = fast->next->next;
        }

        ListNode* newHead = dummy->next;

        ListNode* mid = slow->next;
        slow->next = mid->next;
        delete(mid);
        delete(dummy);
        return newHead;
    }
};
