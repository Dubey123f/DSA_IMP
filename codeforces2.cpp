// You have been given 'N' ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.

// The test-data is such that the result will fit into a 32-bit integer.
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pq.push(x);

    }
    int  cost=0;
    while(pq.size()>1){
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        cost+=first+second;
        pq.push(first+second);

    }
    cout<<cost<<endl;
}


// Problem statement
// You are given two Singly Linked Lists of integers, which may have an intersection point.

// Your task is to return the first intersection node. If there is no intersection, return NULL.



// Example:-
// The Linked Lists, where a1, a2, c1, c2, c3 is the first linked list and b1, b2, b3, c1, c2, c3 is the second linked list, merging at node c1.

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
#include<bits/stdc++.h>
using namespace std;
int main(){
    //Intersection of two linked list
    Node* a1=new Node(1);
    Node* a2=new Node(2);
    Node* c1=new Node(3);
    Node* c2=new Node(4);
    Node* c3=new Node(5);
    Node* b1=new Node(6);
    Node* b2=new Node(7);
    Node* b3=new Node(8);
    a1->next=a2;
    a2->next=c1;
    c1->next=c2;
    c2->next=c3;
    b1->next=b2;
    b2->next=b3;
    b3->next=c1;
    Node* head1=a1;
    Node* head2=b1;
    unordered_set<Node*>s;
    while(head1!=NULL){
        s.insert(head1);
        head1=head1->next;
    }
    Node* ans=NULL;
    while(head2!=NULL){
        if(s.find(head2)!=s.end()){
            ans=head2;
            break;
        }
        head2=head2->next;
    }
    if(ans!=NULL){
        cout<<"Intersection at node with value: "<<ans->data<<endl;
    }
    else{
        cout<<"No intersection"<<endl;
    }
    return 0;

}