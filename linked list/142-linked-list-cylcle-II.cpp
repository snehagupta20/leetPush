/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* tortoise = head;
        ListNode* hare = head;

        while(hare && hare->next && hare->next->next){
            hare = hare->next->next;
            tortoise = tortoise->next;
            if(hare==tortoise) break;
        }

        if(!hare || !hare->next || !hare->next->next) return NULL;

        while(head!=tortoise){

            head=head->next;
            tortoise=tortoise->next;

            if(head==tortoise) return head;
        }

        return head;
    }
};
