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
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int s=0;
            if(l1!=NULL){
                s+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                s+=l2->val;
                l2=l2->next;
            }
            s+=carry;
            carry=s/10;
            ListNode* newNode=new ListNode(s%10);
            temp->next=newNode;
            temp=temp->next;
            
        }
        return dummy->next;
    }
  };
    // Create a main function
        int main(){
            Solution sol;
            // Create first linked list 2->4->3 (represents number 342)
            ListNode* l1=new ListNode(2);
            l1->next=new ListNode(4);
            l1->next->next=new ListNode(3);
            
            // Create second linked list 5->6->4 (represents number 465)
            ListNode* l2=new ListNode(5);
            l2->next=new ListNode(6);
            l2->next->next=new ListNode(4);
            
            ListNode* resultHead=sol.addTwoNumbers(l1,l2);
            
            // Print the resulting linked list (represents number 807)
            ListNode* temp=resultHead;
            cout<<"The sum of the two numbers is represented by the linked list: ";
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp=temp->next;
            }
            cout<<endl;
            return 0;
        }