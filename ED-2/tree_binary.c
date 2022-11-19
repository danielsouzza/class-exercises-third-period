#include <stdio.h>
#include <stdlib.h>



struct No{
    int data;
    struct No *left;
    struct No *right;
};

typedef struct No* TreeBinary;

TreeBinary* root;

TreeBinary* creator_TreeBin(){
    TreeBinary * root = malloc(sizeof(TreeBinary));
    if(root != NULL) *root = NULL;
    return root;
}

void freeknot(struct No* knot){
    if(knot == NULL) return;
    freeknot(knot->left);
    freeknot(knot->right);
    free(knot);
    knot = NULL;
}

void freeTree(TreeBinary* root){
    if(root == NULL) return;
    freeknot(*root);
    free(root);
}

int insertKnot(TreeBinary* root, int value){
    if(root == NULL) return 0;
    struct No* new;
    new = malloc(sizeof(struct No));
    if(new == NULL) return 0;
    new->data = value;
    new->left = NULL;
    new->right = NULL;

    if(*root == NULL){
        *root = new;
    }else{
        struct No* current = *root;
        struct No* previous = NULL;
        while (current != NULL)
        {
            previous = current;
            if(value ==current->data ){
                free(new);
                return 0;
            }else if(value > current->data){
                current = current->right;
            }else{
                current = current->right;
            }
        }

        if(value > previous->data){
            previous->right = new;
        }else{
            previous->left = new;
        }
    }
    return 1;
}

struct No* remove_current(struct No* current) {
    struct No *no1, *no2;
    if(current->left == NULL){
        no2 = current->right;
        free(current);
        return no2;
    }
    no1 = current;
    no2 = current->left;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->right;
    }
    if(no1 != current){
        no1->right = no2->left;
        no2->right = current->left;
    }
    no2->right = current->right;
    free(current);
    return no2;
}

int removeTreeBi(TreeBinary * root, int value){
    if(root == NULL) return 0;
    struct No* previous = NULL;
    struct No* current = *root;
    while (current != NULL)
    {
        if(value == current->data){
            if(current == *root){
                *root = remove_current(current);
            }else if(previous->right == current){
                previous->right = remove_current(current);
            }else{
                previous->left = remove_current(current);
            }
        }
        return 1;
    }
    previous = current;
    if(value > current->data){
        current = current->right;
    }else current = current->left;
}

int consulta_TreeBin(TreeBinary *root, int valor){
    if(root == NULL)
        return 0;
    struct No* current = *root;
    while(current != NULL){
        if(valor == current->data){
            return 1;
        }
        if(valor > current->data)
            current = current->right;
        else
            current = current->left;
    }
    return 0;
}

void knotPrint(struct No * knot)
{
   if(knot != NULL ){
        printf("%d",knot->data);
        knotPrint(knot->left);
        knotPrint(knot->right);
    } 
}


int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    TreeBinary* root = creator_TreeBin();

    int i;
    for(i=0; i < N; i++){
        insertKnot(root,dados[i]);
    }
    treePrint(root);
    freeTree(root);

    return 0;
}