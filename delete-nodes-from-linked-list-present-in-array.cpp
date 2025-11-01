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
        multiset<int>st;
        for(int i=0; i<nums.size(); i++)st.insert(nums[i]);
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = head;
        ListNode* prev = dummy;
        while(temp!=NULL){
            if(st.find(temp->val)!=st.end()){
                prev->next = temp->next;
            }
            else{
                prev = temp;
            }
            temp = temp->next;
        }

        return dummy->next;

    }
};