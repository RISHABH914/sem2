#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

// take care since n,m are <=100000 thus number will be very very large thus need to do by string
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
node* rev(node* root){
    node* prev=NULL;
    node* curr=root;
    while(curr!=NULL){
        node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
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

    res=rev(res);
    while(res!=NULL){
        printf("%d",res->data);
        res=res->next;
    }
    printf("\n");
}
int main(){
    int num,mum;
    scanf("%d %d",&num,&mum);
    char n[num+1],m[mum+1];
    scanf("%s %s",n,m);
        node *num1=NULL;
        node** prev1=&num1;
        for(int i=num-1;i>=0;i--){
                int sum=n[i]-'0';
            insert(prev1,sum);
            prev1=&((*prev1)->next);
           // n/=10;
            }
        
        node *num2=NULL;
        node** prev2=&num2;
        for(int i=mum-1;i>=0;i--){
            int sum=m[i]-'0';
            insert(prev2,sum);
            prev2=&((*prev2)->next);
           // m/=10;
            }
       
        add(num1,num2);
    
return 0;
}