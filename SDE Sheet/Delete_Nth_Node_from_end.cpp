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
    ListNode* deleteNthFromend(ListNode* head,int n){
        //Brute force Approach
    //     ListNode* temp=head;
    //     int c=0;
    //     while(temp!=NULL){
    //         c++;
    //         temp=temp->next;
    //     }
    //     if(n==c){
    //         return head->next;

    //     }
    //     int del=c-n;
    //     ListNode* curr=head;
    // for(int i=1;i<del;i++){
    //     curr=curr->next;

    // }
    // curr->next=curr->next->next;
    // return head;
    // }
    //optimal Approach
    ListNode* dummy=new ListNode(-1);
    dummy->next=head;
    ListNode* slow=dummy;
    ListNode* fast=dummy;
    for(int i=0;i<=n;i++){
        fast=fast->next;
    }
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
    return dummy->next;
}
  };
    // Create a main function
        int main(){
            Solution sol;
            // Create a linked list 1->2->3->4->5
            ListNode* head=new ListNode(1);
            head->next=new ListNode(2);
            head->next->next=new ListNode(3);
            head->next->next->next=new ListNode(4);
            head->next->next->next->next=new ListNode(5);
            
            int n=2; // Node to be deleted from end
            ListNode* modifiedHead=sol.deleteNthFromend(head,n);
            
            // Print the modified linked list
            ListNode* temp=modifiedHead;
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp=temp->next;
            }
            return 0;
        }