#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no * next;
}No;

// Inserção normal
void insert(No **fila, int dado){
    No *aux, * new = malloc(sizeof(No));
    if(new){
        new->valor = dado;
        new->next = NULL;
    }

    if(*fila == NULL){
        *fila = new;
    }else{
        aux = *fila;
        while (aux->next)
            aux = aux->next;
        aux->next = new;
    }
}

// Inserção com prioridade
void insertWithPriority(No **fila, int dado){
    No *aux, * new = malloc(sizeof(No));
    if(new){
        new->valor = dado;
        new->next = NULL;
    }

    if(*fila == NULL){
        *fila = new;
    }else{
        if(dado > 59){
            if((*fila)->valor < 60){
                new->next = *fila;
                *fila = new;
            }else{
                aux = *fila;
                while (aux->next && aux->next->valor > 59){
                    aux = aux->next;
                }
                new->next = aux->next;
                aux->next = new;
            }

        }else{
            aux = *fila;
            while (aux->next){
                aux = aux->next;
            }
            aux->next = new;
        } 
    }
}

No* removeItem(No **fila){
    No * current = NULL;
    if(*fila){
        current = *fila;
        *fila = current->next;
    }

    return current;
}

void print(No *fila){
    printf(" start --> ");
    while (fila)
    {
        printf("%d ", fila->valor);
        fila = fila -> next;
    }
    printf(" <-- End\n");    
}

void finish(No * fila){
    No * temp = NULL;
    while (fila)
    {
        temp = removeItem(&fila);
        free(temp);
    }
}

void menu(){
    printf("[1] -> insert\n");
    printf("[2] -> insert with priority\n");
    printf("[3] -> remove\n");
    printf("[4] -> print\n");
    printf("[0] - Exit\n");
}

int main(){
    No * temp, * fila = NULL;
    int choce, dado;

    do
    {
        system("cls");
        menu();
        fflush(stdin);
        scanf("%d", &choce);
        switch (choce)
        {
        case 1:
            printf("Enter a value: ");
            scanf("%d", &dado);
            insert(&fila,dado);
            break;
        case 2:
            printf("Enter a value: ");
            scanf("%d", &dado);
            insertWithPriority(&fila,dado);
            break;
        case 3:
            temp = removeItem(&fila);
            if(temp){
                printf("Removed: %d\n", temp->valor);
                free(temp);
            }
            break;
        case 4:
            print(fila);
            getchar();getchar();
            break;
        default:
            if(choce != 0){
                printf("\n Invalid choce!\n");
            }else{
                finish(fila);
            }
        }
    } while (choce !=0 );
    return 0;
}