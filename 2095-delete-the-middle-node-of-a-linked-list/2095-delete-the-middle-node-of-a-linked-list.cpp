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
        if(head == NULL) return head;
        if(head->next == NULL) return NULL;
        
        ListNode* temp = head;
        int cnt = 0;
        ListNode* prev = NULL;

        while(temp != NULL){
            cnt++;
            temp = temp -> next;
        }

        int middle = cnt / 2 + 1 ;
        temp = head;
        cnt = 0;

        while(temp != NULL){
            cnt++;
            if(middle == cnt){
                prev -> next = prev -> next -> next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp -> next;
        }

        return head;
    }
};