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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* temp = head;
        ListNode* lessHead = new ListNode(0); 
        ListNode* greatHead = new ListNode(0);
        ListNode* less = lessHead;
        ListNode* great = greatHead;

        while(temp != 0){
            if(temp->val < x){
                less->next = temp;
                less = less->next;
            }
            else{
                great->next = temp;
                great = great->next;
            }
            temp = temp->next;
        }
        less->next = greatHead->next;
        great->next = NULL;

        return lessHead->next;
    }
};