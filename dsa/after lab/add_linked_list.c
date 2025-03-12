#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* next;
}node;


void insert(node** prev,int data){
    node *temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    if(*prev==NULL){
        *prev=(temp);
       // prev=&(temp);
        return ;
    }
    (*prev)->next=temp;
    
}

void add(node* prev1,node* prev2){
    node* res=NULL;
    node** prev=&res;
    int carry=0;
    while(prev1!=NULL && prev2!=NULL){
         int sum=(prev1->data+prev2->data + carry)%10;
    carry=(prev1->data+prev2->data + carry)/10;
       
        insert(prev,sum);
        prev=&((*prev)->next);
        prev1=prev1->next;
        prev2=prev2->next;
    }
    while(prev1!=NULL){
        int sum=(prev1->data+carry)%10;
        carry=(prev1->data+carry)/10;
        insert(prev,sum);
        prev=&((*prev)->next);
        prev1=prev1->next;
    }
    while(prev2!=NULL){
        int sum=(prev2->data+carry)%10;
        carry=(prev2->data+carry)/10;
        insert(prev,sum);
        prev=&((*prev)->next);
        prev2=prev2->next;
    }
    if(carry>0){
        insert(prev,carry);
    }
    while(res!=NULL){
        printf("%d ",res->data);
        res=res->next;
    }
        printf("\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        node *num1=NULL;
        node** prev1=&num1;
        while(1){
            int t;
            scanf("%d",&t);
            if(t==-1){
                break;
            }
            insert(prev1,t);
            prev1=&((*prev1)->next);
        }
        node *num2=NULL;
        node** prev2=&num2;
        while(1){
            int t;
            scanf("%d",&t);
            if(t==-1){
                break;
            }
            insert(prev2,t);
            prev2=&((*prev2)->next);
        }
       
        add(num1,num2);
    }
return 0;
}