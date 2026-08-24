class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL) return head;

        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* beforeLeft = NULL;
        ListNode* leftNode = NULL;

        int cnt = 0;

        while(temp != NULL){
            cnt++;

            if(cnt < left){
                beforeLeft = temp;
            }

            if(cnt == left){
                leftNode = temp;
            }

            if(cnt >= left && cnt <= right){

                ListNode* nextNode = temp->next;

                temp->next = prev;
                prev = temp;
                temp = nextNode;

                if(cnt == right){
                    if(beforeLeft != NULL){
                        beforeLeft->next = prev;
                    }
                    else{
                        head = prev;
                    }

                    leftNode->next = temp;
                    break;
                }
            }
            else{
                temp = temp->next;
            }
        }

        return head;
    }
};