#include<stdio.h>
#include<stdlib.h>

typedef struct noeud {
    int p;
    struct  noeud *prev, *suiv;
} noeud;
noeud* creernoeud(int val){
    noeud* n=(noeud*)malloc(sizeof(noeud));
     if (n == NULL){
        printf("erreur d'allocation");
        exit(1);
    }
    n->p=val;
    n->prev=n->suiv=NULL;
    return n;
}
void insertete(noeud** tete,int val){
    noeud* n=creernoeud(val);
    if(*tete==NULL){
        *tete=n;
        n->suiv=n->prev=n;
        return;
    }
    noeud* tail=(*tete)->prev;
    n->suiv=*tete;
    n->prev=tail;
    tail->suiv=n;
    (*tete)->prev=n;
    *tete=n;
}
void insertail(noeud** tete, int val){
    noeud* n=creernoeud(val);
    if(*tete==NULL){
        *tete=n;
        n->suiv=n->prev=n;
        return;
    }
    noeud* tail=(*tete)->prev;
    n->suiv=*tete;
    n->prev=tail;
    tail->suiv=n;
    (*tete)->prev=n;
    *tete=n;
}
void afficher(noeud* tete){
    if(tete==NULL) return;
    noeud* temp=tete;
    do{
        printf("%d <->",temp->p);
        temp=temp->suiv;
    } while(temp != tete);
    printf("retour de la liste \n");
}
int main(){
    noeud* tete=NULL;
    int n,i,val;
    printf("nombre de valeurs initiale: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("element %d",i+1);
        scanf("%d",&val);
        insertail(&tete, val);
    }
    printf("\n liste double circulaire au debut: ");
    afficher(tete);
    printf("entrez une valeur a insereren tete: ");
    scanf("%d",&val);
    insertete(&tete, val);
    printf("\n apres insertion en tete: ");
    afficher(tete);

    printf("entre une valeur a inserer en fin: ");
    scanf("%d",&val);
    insertail(&tete, val);
    printf("\n apres insertion en fin: ");
    afficher(tete);
    return 0;
}