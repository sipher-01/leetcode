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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* s = head;
        ListNode* f = head;
        if(head==nullptr || head->next==nullptr)return nullptr;
        while(f!=nullptr &&f->next!=nullptr){
            prev = s;
            s = s->next;
            f = f->next->next;
        }

        prev->next = s->next;
        return head;
    }
};