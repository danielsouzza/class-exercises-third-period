#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node * initialize(){
    return NULL;
}

Node * insert(Node * root, int dado){
    if(root == NULL){
        Node * aux = (Node*)malloc(sizeof(Node));
        aux->data = dado;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    }else{
        if(dado > root->data){
            root->right = insert(root->right,dado);
        }else if(dado < root->data){
            root->left = insert(root->left,dado);
        }
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

void treePrint(Node * root){
    if(root != NULL){
        printf("%d ", root->data);
        treePrint(root->left);
        treePrint(root->right);
    }
}

int main(){
    Node * root = initialize();
    int values[] = {77,72,68,74,82,69,84};

    for(int i = 0; i < 7; i++){
        root = insert(root, values[i]);
    }

    treePrint(root);
    treeFree(root);
    return 0;
}