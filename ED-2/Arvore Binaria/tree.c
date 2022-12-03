#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct person
{
    int cpf;
    char name[30];
    char job[50];
}Person;


typedef struct node{
    Person * person;
    struct node *left;
    struct node *right;
}Node;

Node * initialize(){
    return NULL;
}

Person * buildPerson(){
    Person * person = malloc(sizeof(Person));
    printf("CPF: ");
    scanf("%d",&(*person).cpf);
    getchar();
    printf("Nome: ");
    fgets((*person).name,30,stdin);
    printf("JOB: ");
    fgets((*person).job,50,stdin);

    return person;
}

void treePrint(Node * root){
    if(root != NULL){
        printf("CPF: %d\n", root->person->cpf);
        //printf("NOME: %s",root->person->name);
        //printf("JOB: %s",root->person->job);
        treePrint(root->left);
        treePrint(root->right);
    }
}

void treeFree(Node * root){
    if(root != NULL){
        treeFree(root->left);
        treeFree(root->right);
        free(root);
    }
}

Node * insert_by_cpf(Node * root, Person * person){
    if(root == NULL){
        Node * aux = malloc(sizeof(Node));
        aux->person = person;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    }else{
        if(person->cpf > root->person->cpf){
            root->right = insert_by_cpf(root->right,person);
        }else if(person->cpf < root->person->cpf){
            root->left = insert_by_cpf(root->left,person);
        }
    }
    return root;
}

Node * insert_by_name(Node * root, Person * person){
    if(root == NULL){
        Node * aux = malloc(sizeof(Node));
        aux->person = person;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    }else{
        if(person->cpf > root->person->cpf){
            root->right = insert_by_name(root->right,person);
        }else if(person->cpf < root->person->cpf){
            root->left = insert_by_name(root->left,person);
        }
    }
    return root;
}

Node * search_by_cpf(Node * root, int cpf){
    if(root){
        if(cpf == root->person->cpf){
            return root;
        }else if(cpf > root->person->cpf){
            root->right = search_by_cpf(root, cpf);
        }else if(cpf < root->person->cpf){
            root->left = search_by_cpf(root, cpf);
        }
    }

    return NULL;
}

Node * search_by_nome(Node * root, char * name){
    if(root){
        if(strcmp(name,root->person->name) > 0){
            return root;
        }else if(name[0] > root->person->name[0]){
            root->right = search_by_nome(root, name);
        }else if(name[0] < root->person->name[0]){
            root->left = search_by_nome(root, name);
        }
    }
    return NULL;
}

Node * remove_cpf(Node * root, int cpf){

    if(root){
        if(cpf == root->person->cpf){
            if(root->left == NULL && root->right == NULL){
                free(root);
                return NULL;
            }else if (root->left != NULL && root->right != NULL){
                treePrint(root);
                Node * aux = root->left;
                while (aux->right != NULL)
                {
                    aux = aux->right;
                }
                aux->left = root->left;
                aux->right = root->right;
                free(root);
                return aux;   

            }else{
                Node * aux;
                if(root->left != NULL){
                    aux = root->left;
                }else{
                    aux = root->right;
                }
                free(root);
                return aux;
            }
        }else if(cpf > root->person->cpf){
            root->right = remove_cpf(root, cpf);
        }else if(cpf < root->person->cpf){
            root->left = remove_cpf(root, cpf);
        }
    }

    return root;
}



void menu(){
    printf("[1] - Inserir com cpf\n");
    printf("[2] - Inserir com nome\n");
    printf("[3] - Remover com cpf\n");
    printf("[4] - Remover com nome\n");
    printf("[5] - Buscar com cpf\n");
    printf("[6] - Buscar com nome\n");
    printf("[7] - Imprimir Arvore ordenado por cpf\n");
    printf("[8] - Imprimir Arvore ordenado por nome\n");
    printf("[0] - Exit\n");
}


int main(){
    Node * root_cpf = initialize();
    Node * root_name = initialize();

    int choose;
    char name[40];
    int cpf;

    do{

        menu();
        printf("Digite uma opção: ");
        scanf("%d", &choose);

        switch (choose){
        case 1:
            root_cpf = insert_by_cpf(root_cpf, buildPerson());
            break;
        case 2:
            root_name = insert_by_name(root_name, buildPerson());
            break;
        case 3:
            printf("Digite o cpf: ");
            scanf("%d", &cpf);
            //root_cpf = remove_cpf(root_cpf,cpf);
            getchar();getchar();
            break;
        case 4:
            printf("Digete o nome\n");
            fgets(name,30,stdin);
            //
            break;
        case 5:
            printf("Digite o cpf: ");
            scanf("%d", &cpf);
            treePrint(search_by_cpf(root_cpf,cpf));
            getchar();getchar();
            break;
        case 6:
            printf("Digite o name: ");
            fgets(name,30,stdin);
            treePrint(search_by_nome(root_name,name));
            getchar();getchar();
            break;
        case 7:
            treePrint(root_cpf);
            getchar();getchar();
            break;
        }


        system("clear");

    }while(choose != 0);

    treeFree(root_cpf);
    treeFree(root_name);
    return 0;
}