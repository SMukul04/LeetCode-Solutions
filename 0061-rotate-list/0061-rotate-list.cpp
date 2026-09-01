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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* temp = head;
        int cnt = 0;

        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        temp = head;
        int d = 0;

        if(k >= cnt){
            int x = k % cnt;
            d = cnt - x;
        }
        else{
            d = cnt - k;
        }

        if(d == cnt){
            return head;
        }

        cnt = 0;
        ListNode* newTail = NULL;
        ListNode* newHead = NULL;

        while(temp != NULL && temp->next != NULL){
            cnt++;
            if(cnt == d){
                newTail = temp;
                newHead = temp->next;
            }

            if(temp->next->next == NULL){
                temp->next->next = head;
                newTail->next = NULL;
                break;
            }
            else{
                temp = temp->next;
            }
        }

        return newHead;
    }
};