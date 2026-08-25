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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        if(head == NULL) return head;

        if(n == 1 && head->next == NULL){
            return NULL;
        }

        int cnt = 0;

        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        temp = head;
        int k = cnt-n+1;
        cnt = 0;

        if(k == 1){
            head = temp->next;
            delete temp;
            return head;
        }

        while(temp != NULL){
            cnt++;
            if(cnt == k){
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};