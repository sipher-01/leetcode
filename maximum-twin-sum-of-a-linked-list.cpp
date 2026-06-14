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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        while(temp!=nullptr){
            temp = temp->next;
            n++;
        }
        int mid = n/2 - 1;

        ListNode* newHead = head;
        int l = 0;
        while(l!=mid){
            newHead = newHead->next;
            l++;
        }
        ListNode* t = newHead;
        newHead = newHead->next;
        t->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* cur = newHead;
        while(cur!=nullptr){
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        ListNode* head2 = prev;

        ListNode* t1 = head,*t2 = head2;
        int ans = 0;
        while(t1!=nullptr && t2!=nullptr){
            ans = max(ans,(t1->val + t2->val));
            t1 = t1->next;
            t2 = t2->next;
        }
        return ans;
    }
};