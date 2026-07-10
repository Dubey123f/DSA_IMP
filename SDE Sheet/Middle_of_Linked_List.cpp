// Generate general template to find middle of linked list
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
    ListNode* middleNode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
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
        
        ListNode* middle=sol.middleNode(head);
        
        // Print the middle node
        cout<<"The middle node value is: "<<middle->val<<endl;
        return 0;
    }
