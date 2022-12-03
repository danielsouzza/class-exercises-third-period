#include <stdio.h>
#include "stack.h"


typedef struct node
{
    char item;
    struct node * right, *left;
    
}Node;

Node * new(char item){
    Node * node = malloc(sizeof(Node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findId(char str[], int start, int end){
    if(start > end) return -1;

    Stack * stack = NULL;

    for(int i = start ; i <= end; i++){
        if(str[i] == '('){
            stack = push(stack,str[i]);
        }else if(str[i] == ')'){
            stack = pop(stack);
            if(stack == NULL) return i;
        }
    }

    return -1; 
}

Node * buildTree(char str[], int start, int end){
    if(start > end) return NULL;

    Node * root = new(str[start]);
    int id = -1;

    if(start + 1 <= end && str[start + 1] == '('){
        id = findId(str,start + 1, end);
    }

    if(id != -1){
        root->left =  buildTree(str, start + 2, id -1);
        root->right = buildTree(str, id + 2, end - 1);
    }

    return root;
}

void treeFree(Node * root){
    if(root != NULL){
        treeFree(root->left);
        treeFree(root->right);
        free(root);
    }
}

void preOrder(Node* node){
    if (node == NULL) return;

    printf("%c ", node->item);
    preOrder(node->left);
    preOrder(node->right);
}

void centOrder(Node * node){
    if(node == NULL) return;

    centOrder(node->left);
    printf("%c ", node->item);
    centOrder(node->right);
}


void posOrder(Node * node){
    if(node == NULL) return;

    posOrder(node->left);
    posOrder(node->right);
    printf("%c ", node->item);
}


int main(){
    // char str[] = "A(B(D)(E(H)))(C(F(I)(J))(G(K))";
    char str[] = "A(B(D()())(E(H)()))(C(F(I)(J))(G()(K))";

    int size = (sizeof(str) / sizeof(str[0])) -1;
    Node * root = buildTree(str, 0, size);

    printf("Caminhamento Pré-Fixado: ");
    preOrder(root);
    printf("\n");

    printf("Caminhamento Central: ");
    centOrder(root);
    printf("\n");

    printf("Caminhamento Pós-Fixado: ");
    posOrder(root);
    printf("\n");

    treeFree(root);
    return 0;
}

