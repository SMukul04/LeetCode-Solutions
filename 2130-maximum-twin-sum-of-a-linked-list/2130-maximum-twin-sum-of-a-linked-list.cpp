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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* newHead = reverse(head->next);

        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

    int pairSum(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next->next == NULL){
            return (head->val + head->next->val);
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = slow->next;
        newHead = reverse(newHead);

        ListNode* first = head;
        ListNode* second = newHead;
        int sum = 0;
        int maxi = 0;

        while(second != NULL){
            sum = first->val + second->val;
            maxi = max(maxi, sum);

            first = first->next;
            second = second->next;
        }

        return maxi;
    }
};