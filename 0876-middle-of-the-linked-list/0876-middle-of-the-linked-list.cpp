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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL) return head;

        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp -> next;
        }

        temp = head;

        if(cnt == 1){
            return head;
        }

        if(cnt >= 2){
            int middle = (cnt / 2) + 1;
            for(int i = 0; i < middle - 1; i++){
                temp = temp -> next;
                head = temp;
            }
        }

        return head;
    }
};