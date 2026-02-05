//You are given two non-empty linked lists representing two non-negative integers.
//The digits are stored in reverse order, and each of their nodes contains a single digit. 
//Add the two numbers and return the sum as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry=0;
    struct ListNode* head=NULL;
    struct ListNode* tail=NULL;
    while(l1!=NULL||l2!=NULL){
        int a=0;
        int b=0;
        if(l1!=NULL){
            a=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            b=l2->val;
            l2=l2->next;
        }
        int sum=a+b+carry;
        carry=sum/10;
        int digit=sum%10;

        struct ListNode* newnode=malloc(sizeof(struct ListNode));
        newnode->val=digit;
        newnode->next=NULL;

        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }

    }
    if(carry>0){
        struct ListNode* newnode=malloc(sizeof(struct ListNode));
        newnode->val=carry;
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;

    }
    return head;
}