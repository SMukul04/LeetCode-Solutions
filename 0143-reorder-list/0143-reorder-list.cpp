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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHead = slow->next;
        slow->next = NULL;
        ListNode* curr = secondHead;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode* t1 = head;
        ListNode* t2 = prev;
        ListNode* temp = head;

        while(t2 != NULL && temp->next != NULL){
            temp = temp->next;
            prev = prev->next;
            t1->next = t2;
            t2->next = temp;

            t1 = temp;
            t2 = prev;
        }
    }
};