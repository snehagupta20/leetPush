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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* temp = list1;
            vector<int> elements;
            while(temp!=nullptr){
                elements.push_back(temp->val);
                temp=temp->next;
            }
    
            temp = list2;
            while(temp!=nullptr){
                elements.push_back(temp->val);
                temp=temp->next;
            }
            
            if(elements.size()==0) return list1;
    
            sort(elements.begin(), elements.end());
            ListNode* ans = new ListNode(elements[0]);
            temp = ans;
            for(int i=1;i<elements.size();i++){
                ListNode* newnode = new ListNode(elements[i]);
                temp->next = newnode;
                temp=temp->next;
            }
    
            return ans;
        }
    };