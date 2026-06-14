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
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        stack<int> st;
        temp = head;

        for (int i = 0; i < n / 2; i++) {
            st.push(temp->val);
            temp = temp->next;
        }

        int maxi = INT_MIN;

        while (temp != nullptr) {
            maxi = max(maxi, st.top() + temp->val);
            st.pop();
            temp = temp->next;
        }

        return maxi;
    }
};
