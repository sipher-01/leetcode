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
    int findGCD (int a,int b){
        if(a%b==0)return b;
        return findGCD(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        ListNode* nextNode = head->next;
        while(nextNode){
            int gcd ;
            if(curr->val>nextNode->val) gcd = findGCD(curr->val,nextNode->val);
            else gcd = findGCD(nextNode->val,curr->val);
            ListNode* newNode = new ListNode(gcd);
            curr->next = newNode;
            newNode->next = nextNode;
            curr = nextNode;
            nextNode = nextNode->next;
        }
        return head;

    }
};