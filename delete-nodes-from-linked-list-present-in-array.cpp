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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>s;
        for(auto it: nums){
            s.insert(it);
        }
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = head;
        ListNode* temp1 = newHead;
        while(temp!=nullptr){
            if(s.find(temp->val)==s.end()){
                temp1->next = temp;
                temp1 = temp;
            }
                temp = temp->next;
        }
        temp1->next = nullptr;
        return newHead->next;
    }
};