#include <bits/stdc++.h>

using namespace std;

class LinkedList{
    public:
    int val;
    LinkedList* next;
    LinkedList(int val){
        this-> val=val;
        this->next=NULL;
    }
};
void it_printlist(LinkedList* head){
    LinkedList* current =  head;
    while(current!= NULL){
        cout<<current->val<<endl;
        current = current->next;
    }
}
void it_sumlist(LinkedList* head){
    int sum=0;
    LinkedList* current =  head;
    while(current!= NULL){
        sum+=current->val;
        current = current->next;
    }
    cout<<sum<<endl;
}

bool it_findlist(LinkedList* head, int target){
    LinkedList* current =  head;

    while(current!= NULL){
        int val=current->val;
        if(val==target)return true;
        current = current->next;
    }
    return false;
}
LinkedList *revList(LinkedList* head){
    LinkedList *prev=NULL;
    LinkedList *current=head;
    while(current!=NULL){
        LinkedList* next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}

//recursive solution to print list
printlist(LinkedList* head){
    if(head== NULL)
        return 0;
    cout<<head->val<<endl;
    printlist(head->next);
}
int sumList(LinkedList* head){
    if(head==NULL)return 0;
    return  head->val+sumList(head->next);

}
bool rec_findlist(LinkedList* head, int target){
    int val=head->val;
    if(head==NULL)return false;
    if(target==val)return true;
    return rec_findlist(head->next, target);
}

LinkedList* rec_revList(LinkedList* head, LinkedList *prev){
    if(head==NULL)return head;
    LinkedList *next=head->next;
    head->next=prev;
    return rec_revList(next, head);
}
int main()
{
    LinkedList* a = new LinkedList(10);
    LinkedList* b = new LinkedList(20);
    LinkedList* c = new LinkedList(30);
    LinkedList* d = new LinkedList(5);
    LinkedList* e = new LinkedList(15);

    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;

    //it_findlist(a,5)?cout<<"true\n":cout<<"false"<<endl;
    //rec_findlist(a,5)?cout<<"true\n":cout<<"false"<<endl;
    cout<<rec_revList(a, NULL)<<endl; it_printlist(e);
}
