class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
		
    }
};


sol : 23/11/2024

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
    bool hasCycle(ListNode *head) {
        ListNode* tortoise = head;
        ListNode* hare = head;

        while(hare && hare->next && hare->next->next){
            hare = hare->next->next;
            tortoise = tortoise->next;

            if(hare==tortoise) return true;
        }            

        return false;
    }
};

// if tortoise and hare ever meet, that means there is a cycle