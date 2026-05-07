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
    int len(ListNode* head){
        ListNode* temp = head;
        int l = 0;
        while(temp!=NULL){
            temp = temp->next;
            l++;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int l = len(head);
        if(k==0 || l==0)return head;
        int n = l - k%l;

        ListNode* temp = head;
        int i = 1;
        while(i!=n && temp!=NULL){
            temp = temp->next;
            i++;
        }
        ListNode* newHead = NULL;
        if(temp->next)
        {
            newHead = temp->next;
            temp->next = NULL;
            ListNode* temp1 = newHead;
            while(temp1->next!=NULL){
                temp1 = temp1->next;
            }
            temp1->next = head;
        }
        return newHead?newHead:head;
    }
};