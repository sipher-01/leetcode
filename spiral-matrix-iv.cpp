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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));

        ListNode* temp = head;
        int toprow=0,bottomrow=m-1;
        int leftcol = 0, rightcol = n-1;
        while(temp!=nullptr){
            int i=leftcol,j=rightcol;
            while(i<=j && temp!=nullptr){
                ans[toprow][i] =temp->val;
                temp = temp->next;
                i++; 
            }
            toprow++;
            i = toprow,j=bottomrow;
            while(i<=j && temp!=nullptr){
                ans[i][rightcol] = temp->val;
                temp = temp->next;
                i++;
            }
            rightcol--;
            i=leftcol,j=rightcol;
            while(j>=i && temp!=nullptr){
                ans[bottomrow][j] = temp->val;
                temp = temp->next;
                j--;
            }
            bottomrow--;
            i=toprow,j=bottomrow;
            while(j>=i && temp!=nullptr){
                ans[j][leftcol]=temp->val;
                temp = temp->next;
                j--;
            }
            leftcol++;
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};