#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
   Node* next;
    Node* back;
    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }

};
Node* converArrtoDLL(vector<int>&arr){
    
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=prev->next;
    }
    return head;
}
void print(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
      head=head->next;
    }
    cout<<endl;
}
Node* deleteHead(Node* head){
    if(head==NULL|| head->next==NULL){
        return NULL;
    }
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
}
Node* deleteTail(Node* head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* prev=temp->back;
    prev->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;


}
Node*deleteKth(Node* head,int k){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    int c=0;
    Node* temp=head;
    while(temp){
        c++;
        if(c==k){
            break;
        }
        temp=temp->next;
    }
   Node*prev=temp->back;
   Node* front=temp->next;
   if(prev==NULL && front==NULL){
    delete temp;
    return NULL;
   }
  else if(prev==NULL){
    return deleteHead(head);
    // return head;
   } 
  else if(front==NULL){
    deleteTail(head);
    return head;
   }

    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;


}
void deleteNode(Node* temp){
    if(temp==NULL){
        return;
    }
    Node* prev=temp->back;
    Node* front=temp->next;
    if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        delete temp;
    }
    prev->next=front;
    temp->next=temp->back=nullptr;
    delete temp;

}
Node* insertBeforeHead(Node* head,int val){
    Node* temp=new Node(val,head,nullptr);
    head->back=temp;
    return temp;
}
Node* InsertAfterTail(Node* head,int val){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        // Node* prev=temp->back;
        // Node* n= new Node(val,nullptr,temp);
        // temp->next=n;
        // n->back=temp;
}
      Node* n= new Node(val,nullptr,temp);
        temp->next=n;
        n->back=temp;
return head;
}
Node* InsertBeforeTail(Node* head,int val){
    if(head->next==NULL){
        return insertBeforeHead(head,val);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* n=new Node(val,temp,prev);
    temp->back=n;
    prev->next=n;
    return head;
}
Node* InsertBeforeKthPosistionvValue(Node* head,int val,int k){
    if(k==1){
        return insertBeforeHead(head,val);
    }
    Node* temp=head;
    int c=0;
    while(temp!=NULL){
        c++;
        if(c==k){
            break;
        }
        temp=temp->next;

    }
    Node* prev=temp->back;
    Node* n=new Node(val,temp,prev);
    prev->next=n;
    temp->back=n;
    return head;

}
void InsertBeforeNode(Node* temp,int val){
    if(temp==NULL){
        return;
    }
    Node* prev= temp->back;
    Node* n=new Node(val,temp,prev);
    prev->next=n;
    temp->back=n;
}
Node* reverseDLL(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* curr=head;
    Node* last=nullptr;
    while(curr!=NULL){
        last=curr->back;
        curr->back=curr->next;
        curr->next=last;
        curr=curr->back;
    }
    return last->back;
}
Node* reverseDLL2(Node* head){
    if(head==NULL || head->next==NULL)
{
    return head;
}
Node* temp=head;
stack<int>st;
while(temp){
st.push(temp->data);
temp=temp->next;
}
temp=head;
while(temp){        
temp->data=st.top();
st.pop();
temp=temp->next;



}
return head;
}

int main(){
vector<int> arr={2,4,1,5,7,9,8};
Node* head=converArrtoDLL(arr);
// cout<<"The Doubly Linked List is:"<<endl;
// print(head);
// head=deleteHead(head);
// cout<<"After Deleting the Head The Doubly Linked List becomes:"<<endl;
// print(head);
// head=deleteTail(head);
// cout<<"After Deleting the Tail The Doubly Linked List becomes:"<<endl;
// print(head);
// cout<<"After Deleting the 3rd Node The Doubly Linked List becomes:"<<endl; 
// head=deleteKth(head,1);
// cout<<"After Deleting the 1st Node The Doubly Linked List becomes:"<<endl;
// deleteNode(head->next->next);
// cout<<"After Inserting before head the linked list becomes:"<<endl;
// head=insertBeforeHead(head,100);
// cout<<"After Inserting after Tail the linked list becomes:"<<endl;
// head=InsertAfterTail(head,100);
// cout<<"After Inserting before Tail the linked list becomes:"<<endl;
// head=InsertBeforeTail(head,100);
// cout<<"After Inserting before Kth position the linked list becomes:"<<endl;
// head=InsertBeforeKthPosistionvValue(head,100,7);
// cout<<"After Inserting before the Node the linked list becomes:"<<endl;
// InsertBeforeNode(head->next,100);
// cout<<"After Reversing the linked list becomes:"<<endl;
// head=reverseDLL2(head);

cout<<"After Reversing the linked list becomes:"<<endl;
head=divide(head);
print(head);

}