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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        vector<int>len(k,0);
        for(int i=0; i<n; i++){
            if(i>=k)len[i%k]++;
            else len[i]++;
        }
        vector<ListNode*>ans(k,NULL);
        temp = head;
        for(int i=0; i<k; i++){
            if(len[i]==0)break;
            ListNode* prev = nullptr;
            ans[i] = temp;
            while(len[i]>0){
                prev = temp;
                temp=temp->next;
                len[i]--;
            }
            prev->next = nullptr;
        }
        return ans;
    }
};