
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
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* front=temp->next;
            prev=temp->next;
          
            prev=temp;
            temp=front;
            
        }
        return prev;
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
        
        ListNode* reversedHead=sol.reverseList(head);
        
        // Print the reversed linked list
        ListNode* temp=reversedHead;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        return 0;
    }