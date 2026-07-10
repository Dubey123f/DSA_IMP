#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;

    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;

    }
};
Node* convertArrtoLL(vector<int> &arr){
Node* head=new Node(arr[0]);
Node* mover=head;
for(int i=1;i<arr.size();i++){
    Node* temp=new Node(arr[i]);
    mover->next=temp;
    mover=temp;
}
return head;
}
int LengthofLL(Node* head){
    int c=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        c++;

    }
    return c;
}
int searchInLL(Node* head,int val){
    Node*temp=head;
    while(temp){
        temp=temp->next;
        if(temp->data==val){
            return 1;
        }
         return 0;
    }
   
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node* Remove(Node* head){
    if(head==NULL){
        return head;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
Node* deleteTail(Node* head)
{
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}
Node* removeK(Node* head,int k){
    if(head==NULL){
        return head;
    }
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node*temp=head;
    Node* prev=NULL;
    int c=0;
    while(temp){
        c++;
        if(c==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* deleteVal(Node* head,int element){
    if(head==NULL){
        return head;
    }
    if(head->data==element){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp){
if(temp->data==element){
    prev->next=prev->next->next;
    free(temp);
    break;
}
prev=temp;
temp=temp->next;
    }
    return head;
}
Node* InsertHead(Node* head,int val){
    Node* temp=new Node(val,head);
    return temp;
}
Node* insertTail(Node* head,int v){
    if(head==NULL){
        return new Node(v);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* new_Node=new Node(v);
    temp->next=new_Node;
    return head;
}
Node* insertatK(Node* head,int k,int val){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
    }
    if(k==1){
        return new Node(val,head);
    }
    Node* temp=head;
    int c=0;
    while(temp){
        c++;
        if(c==k-1){
            Node* new_node=new Node(val);
            new_node->next=temp->next;
            temp->next=new_node;
            break;
        }
        temp=temp->next;
    }
    return head;
}
Node* InsertbeforeVal(Node* head,int el,int val){
if(head==NULL){
    return NULL;
}
if(head->data==val){
    return new Node(el,head);
}
Node* temp=head;
while(temp->next!=NULL){
    if(temp->next->data==val){
        Node* x=new Node(el);
        x->next=temp->next;
        temp->next=x;
        break;
    }
    temp=temp->next;
}
return head;
}
Node* reverseBetween(Node* head,int m,int n){

    if(head==NULL || m==n){
        return head;

    }
    Node* d= new Node(0);
    d->next=head;
    Node* p=d;
    for(int i=0;i<m-1;i++){
        p=p->next;
    }
    Node* start=p->next;
    Node* t=start->next;
 for(int i=0;i<n-m;i++){
    start->next=t->next;
    t->next=p->next;
    p->next=t;
    t=start->next;
 }
return head;
}
 Node* divide(Node* head) {
        // code here
        if(head==NULL || head->next==NULL){
            return head;
        }
        vector<int>arr;
        Node* t=head;
        while(t){
                if(t->data%2==0){
            arr.push_back(t->data);
        }
            t=t->next;
          
        }
        Node* newHead=convertArrtoLL(arr);
        Node* temp=head;
        return newHead;
      
        
    }
 

int main(){
    vector<int> arr={17,15,8,9,2,4,6};
    Node* head=convertArrtoLL(arr);
//     cout<<"Linked List created from array: ";
//     cout<<head->data<<" ";
//     cout<<endl;
//     // Traverse the linked list to print all elements

//     Node* temp=head;
//     while(temp){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     cout<<endl;
//     cout<<"Length of Linked List: "<<LengthofLL(head)<<endl;
  
//     int x;
//     cout<<"Enter the value to search: ";
//     cin>>x;
//     cout<<searchInLL(head,x)<<endl;
//     cout<<"Removing the first element from the linked list."<<endl;
//     cout<<"New Linked List: ";
// head=Remove(head);
// print(head);
// cout<<"Deleting the tail of the linked List:"<<endl;
// head=deleteTail(head);
// cout<<"Delete the Kth element from the linked list:"<<endl;
// head=removeK(head,7);
// print(head);
//     cout<<"Delete the element from the linked list:"<<endl;
//     head=deleteVal(head,8);
//     print(head);
    //     head=InsertHead(head,100);
    // cout<<"Insert the element at the head of the linked list:"<<endl;
    // cout<<"After Inserting at Tail The Linked List becomes:"<<endl;
    //  head=insertTail(head,100);
    // print(head);
    //    cout<<"After Inserting at Kth Position The Linked List becomes:"<<endl;
    //  head=insertatK(head,1,100);
    // print(head);
    // cout<<"After Inserting before the val The Linked List becomes:"<<endl;
    //  head=InsertbeforeVal(head,100,7);
    // cout<<"After Reversing the Linked List between m and n:"<<endl;
    // head=reverseBetween(head,1,2);

head=convertArrtoLL(head);
    print(head);
    return 0;
}
// auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; }); for leetcode timecomplexity zero