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
        if(lists.empty())return NULL;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]==nullptr)continue;
            ListNode* temp = lists[i];
            while(temp!=NULL){
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        if(pq.empty())return NULL;
        ListNode* root = new ListNode(pq.top());
        pq.pop();
        ListNode* curr = root;
        while(!pq.empty()){
            ListNode* temp = new ListNode(pq.top());
            pq.pop();
            curr->next = temp;
            curr = curr->next;
        }
        return root;
    }
};