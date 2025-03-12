#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

// IMPORTANT
// its not like root->right then go to root->left
// since its possible that parent might not be  the required card(int the case when card doesn't exist)
// in that case we need to go to left to only that position which satisifes it
typedef struct node{
    int attack;
    int defense;
    int cnt;
    int ncnt;
    struct node* right;
    struct node* left; 
}node;

typedef struct Stack {
    struct node* root;
    struct Stack* next;
} Stack;
void update(node* root){
    if(root==NULL){
        return ;
    }
    update(root->right);
    update(root->left);
    root->ncnt=0;
    if(root->right!=NULL){
        root->ncnt+=(root->right->ncnt);
    }
    if(root->left!=NULL){
        root->ncnt+=(root->left->ncnt);
    }
    root->ncnt+=root->cnt;
}
int cmp(int a1,int d1,int a2,int d2){
    int sum1=a1+d1;
    int sum2=a2+d2;
    if(sum1>sum2){
        return 1;
    }else if(sum1<sum2){
        return -1;
    }else{
        if(a1>a2){
            return 1;
        }else if(a1<a2){
            return -1;
        }
    }
    return 0;
}

node* insert(node* root,int attack,int defense){
    node* temp=(node*)malloc(sizeof(node));
    temp->attack=attack;
    temp->defense=defense;
    temp->cnt=1;
    temp->right=NULL;
    temp->left=NULL;
    if(root==NULL){
        return temp;
    }
    node* store=root;
node* prev=NULL;
    while(root!=NULL){
        prev=root;
        int com=cmp(root->attack,root->defense,attack,defense);
        if(com<0){
            root=root->left;
            
        }else if(com>0){
            root=root->right;
        }else{
            root->cnt++;
            return store;
        }
    }
    if(cmp(prev->attack,prev->defense,attack,defense)<0){
        prev->left=temp;
    }else{
        prev->right=temp;
    }
    return store;
}
//0 for absence
//1 for presence
node* ispresent(int attack,int defense,node* root){
    if(root==NULL){
        return NULL;
    }
    while(root!=NULL){
       int com= cmp(root->attack,root->defense,attack,defense);
        if(com<0){
            root=root->left;
        }else if(com>0){
            root=root->right;
        }else{
            return root;
        }
    }
    if(root==NULL){
        return NULL;
    }
}

node* trade(node* root,int oa,int od,int ra,int rd){
    if(ra==-1 && rd==-1){
        printf("1\n");
       root= insert(root,oa,od);
      // update_new(root,);
        return root;
    }
    node* temp=ispresent(ra,rd,root);
    if(temp==NULL){
        printf("0\n");
        return root;
    }
    if(temp->cnt<=1){
        printf("0\n");
        return root;
    }

    node* another=ispresent(oa,od,root);
    if(another==NULL){
        printf("1\n");
        root=insert(root,oa,od);
        temp->cnt--;
        return root;
    }else{
        int com=cmp(oa,od,ra,rd);
        if(com>0){
            printf("1\n");
           root= insert(root,oa,od);
            temp->cnt--;
            return root;
        }else if(com<0){
            printf("0\n");
            return root;
        }else{
            printf("1\n");
            return root;
        }
    }

    return root;

}

node* findlargestinsmallest(node* root,int attack,int defense){
    node* temp=NULL;
    while(root!=NULL){
        if(cmp(root->attack,root->defense,attack,defense)<0){
            temp=root;
            root=root->left;
            
        }else{
            root=root->right;
        }
    }
    return temp;
}

node* findsmallestinlargest(node* root,int attack,int defense){
    node* temp=NULL;
    while(root!=NULL){
        if(cmp(root->attack,root->defense,attack,defense)>0){
            temp=root;
            root=root->right;
        }else{
            root=root->left;
        }
    }
    return temp;
}

void compare(node* root,int attack,int defense){
    node* temp=ispresent(attack,defense,root);
    if(temp==NULL){
        printf("0\n");
    }else{
        printf("%d\n",temp->cnt);
    }

    temp=findlargestinsmallest(root,attack,defense);
    if(temp==NULL){
        printf("-1\n");

    }else{
        printf("%d %d %d\n",temp->attack,temp->defense,temp->cnt);
    }

    temp=findsmallestinlargest(root,attack,defense);
    if(temp==NULL){
        printf("-1\n");

    }else{
        printf("%d %d %d\n",temp->attack,temp->defense,temp->cnt);
    }
}

node* kthstrongest(int k, node* root) {
    while (root) {
        if (root->ncnt < k) {
            return NULL;  // If tree has fewer than k nodes, return NULL
        }

        int left_count = (root->left ? root->left->ncnt : 0); // Handle NULL left subtree safely

        

        if (left_count >= k) {
            root = root->left; // Search in the left subtree
        } else if (left_count + root->cnt >= k) {
            return root; // Found the k-th strongest
        }else {
            k -= (left_count + root->cnt); // Reduce k and search in the right subtree
            root = root->right;
        }
    }
    return NULL;
}


int sum(node* root){
    if(root==NULL){
        return 0;
    }
    int temp1=sum(root->left);
    int temp2=sum(root->right);
    return 1+temp1+temp2;
}
void print(node* root){
    if(root==NULL){
        return ;
    }
    print(root->left);
    printf("%d %d %d \n",root->attack,root->defense,root->cnt);
    print(root->right);

}

void shuffle(int arr[][2], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp0 = arr[i][0], temp1 = arr[i][1];
        arr[i][0] = arr[j][0];
        arr[i][1] = arr[j][1];
        arr[j][0] = temp0;
        arr[j][1] = temp1;
    }
}


// Create a new BST node
node* newNode(int attack,int defense) {
    node* temp = (node*)malloc(sizeof(node));
    temp->attack=attack;
    temp->defense=defense;
    temp->cnt=1;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

// Push to stack
void push(Stack** top, node* node) {
    Stack* new_top = (Stack*)malloc(sizeof(Stack));
    new_top->root = node;
    new_top->next = *top;
    *top = new_top;
}

// Pop from stack
node* pop(Stack** top) {
    if (*top == NULL) return NULL;
    Stack* temp = *top;
    node* node = temp->root;
    *top = (*top)->next;
    free(temp);
    return node;
}

node* constructBST(int arr[][2], int n) {
    if (n == 0) return NULL;

    node* root = newNode(arr[0][0], arr[0][1]); // First element as root
    Stack* stack = NULL;
    push(&stack, root);

    for (int i = 1; i < n; i++) {
        node* new_node = newNode(arr[i][0], arr[i][1]);

        node* temp = NULL;

        // **Step 1: Check if this node already exists**
        node* current = root;
        while (current) {
            int comparison = cmp(current->attack, current->defense, arr[i][0], arr[i][1]);

            if (comparison == 0) {  // Exact match found
                current->cnt++;  // Increase count
                free(new_node);   // Free the unnecessary node
                new_node = NULL;  // Mark as handled
                break;
            } else if (comparison > 0) {  // Current node is stronger, go left
                if (!current->left) break;
                current = current->left;
            } else {  // Current node is weaker, go right
                if (!current->right) break;
                current = current->right;
            }
        }

        // If we found a duplicate, skip adding a new node
        if (!new_node) continue;

        // **Step 2: Find correct position in the BST**
        while (stack != NULL && cmp(stack->root->attack, stack->root->defense, arr[i][0], arr[i][1]) > 0) {
            temp = pop(&stack);
        }

        // **Step 3: Insert the new node**
        if (temp) {
            temp->left = new_node; // Stronger cards go left
        } else if (stack != NULL) {
            stack->root->right = new_node; // Weaker cards go right
        }

        push(&stack, new_node);
    }

    return root;
}



node* new_shuffle(node* root,int left,int right,int arr[][2]){
    int mid=(left+right)/2;
    root=insert(root,arr[mid][0],arr[mid][1]);
    root->right=new_shuffle(root->right,mid+1,right,arr);
    root->left=new_shuffle(root->left,left,mid,arr);
    return root;

}

int main(){
    srand(time(NULL));
    int n;
    scanf("%d",&n);
   // node* root=NULL;
    int arr[n][2];
    node* root=NULL;
    int random=rand();
    for(int i=0;i<n;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
        
    }
    shuffle(arr,n);
    for(int i=0;i<n;i++){
        root=insert(root,arr[i][0],arr[i][1]);
        
    }
   // root=constructBST(arr,n);
   // printf("hello\n");
   // print(root);
    int q;
    scanf("%d",&q);
   // printf("q is %d\n",q);
    while(q--){
        char op[15];
        scanf("%s",op);
        
        if(strcmp(op,"TRADE")==0){
            int oa,od,ra,rd;
        scanf("%d %d %d %d",&oa,&od,&ra,&rd);
            root=trade(root,oa,od,ra,rd);
            update(root);
        }else if(strcmp(op,"COMPARE")==0){
            int attack,defense;
            scanf("%d %d",&attack,&defense);
            compare(root,attack,defense);
        }else if(strcmp(op,"KTH_STRONGEST")==0){
            int k;
            scanf("%d",&k);
            update(root);
            node* temp=kthstrongest(k,root);
            if(temp==NULL){
                printf("-1\n");
            }else{
                printf("%d %d %d\n",temp->attack,temp->defense,temp->cnt);
            }
        }
    }
    printf("%d\n",sum(root));
    print(root);
return 0;
}