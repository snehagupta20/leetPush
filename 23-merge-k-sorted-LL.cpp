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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // vector<int> nums;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(ListNode* head : lists){
            ListNode* temp = head;
            while(temp){
                // nums.push_back(temp->val);
                pq.push(temp->val);
                temp=temp->next;
                // else break;
            }
        }

        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        while(!pq.empty()){
            ListNode* helper = new ListNode(pq.top());
            temp->next = helper;
            temp = temp->next;
            pq.pop();
        }

        return head->next;
    }
};