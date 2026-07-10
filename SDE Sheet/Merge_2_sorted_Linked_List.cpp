struct ListNode {
      int val;
      ListNode *next;
 ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  #include<bits/stdc++.h>
  using namespace std;
  class Solution{
    public:
    ListNode* mergeTwoLists(ListNode* L1,ListNode* L2){
        if(L1==NULL){
            return L2;
        }
        if(L2==NULL){
            return L1;
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(L1!=NULL && L2!=NULL){
            if(L1->val<L2->val){
                temp->next=L1;
                L1=L1->next;
                temp=temp->next;
            }
            else{
                temp->next=L2;
                L2=L2->next;
                temp=temp->next;
            }

        }
        if(L1!=NULL){
            temp->next=L1;
        }
        if(L2!=NULL){
            temp->next=L2;
        }
        return dummy->next;
    }

  };
  int main(){
        Solution sol;
        // Create first sorted linked list 1->3->5
        ListNode* L1=new ListNode(1);
        L1->next=new ListNode(3);
        L1->next->next=new ListNode(5);
        
        // Create second sorted linked list 2->4->6
        ListNode* L2=new ListNode(2);
        L2->next=new ListNode(4);
        L2->next->next=new ListNode(6);
        
        ListNode* mergedHead=sol.mergeTwoLists(L1,L2);
        
        // Print the merged linked list
        ListNode* temp=mergedHead;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        return 0;
  }