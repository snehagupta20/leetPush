class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;

        while(fastPointer != nullptr && fastPointer->next != nullptr){
            fastPointer=fastPointer->next->next;
            slowPointer=slowPointer->next;
        }

        return slowPointer;
    }
};


new sol :

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
        ListNode* tortoise = head;
        ListNode* hare = head;

        while(hare && hare->next){
            tortoise = tortoise->next;
            hare = hare->next->next;
        }

        return tortoise;
    }
};