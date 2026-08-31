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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL) return {-1, -1};
        if(head->next == NULL || head->next->next == NULL){
            return {-1, -1};
        }

        ListNode* temp = head;
        ListNode* prev = NULL;
        int cnt = 0;
        int firstCritical = -1;
        int prevCritical = 0;
        int minDist = INT_MAX;
        int maxDist = 0;

        while(temp->next != NULL && temp->next->next != NULL){
            cnt++;
            prev = temp;
            temp = temp->next;

            if((prev->val < temp->val && temp->val > temp->next->val) ||
                    (prev->val > temp->val && temp->val < temp->next->val)){
                if(firstCritical == -1){
                    firstCritical = cnt;
                }
                else{
                    minDist = min(minDist, cnt - prevCritical);
                }

                maxDist = max(maxDist, cnt - firstCritical);
                prevCritical = cnt;
            }
        }

        if (minDist == INT_MAX) {
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};