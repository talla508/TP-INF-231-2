#include<stdio.h>
#include<stdlib.h>
typedef struct noeud{
    int p;
    struct noeud *suiv;
} noeud;
noeud* creernoeud(int val){
    noeud* n=(noeud*)malloc(sizeof(noeud));
    if (n == NULL){
        printf("erreur d'allocation");
        exit(1);
    }
    n->p=val;
    n->suiv=NULL;
    return n;
}
void insersorti(noeud** tete, int val){
    noeud* n=creernoeud(val);
    if(*tete==NULL || (*tete)->p >= val){
        n->suiv=*tete;
        *tete=n;
        return;
    }
    noeud* temp=*tete;
    while(temp->suiv !=NULL && temp->suiv->p < val)
        temp=temp->suiv;
    n->suiv=temp->suiv;
    temp->suiv=n;
}
void afficher(noeud* tete){
    while(tete!=NULL){
        printf("%d ->",tete->p);
        tete=tete->suiv;
    }
    printf("NULL \n");
}
int main(){
    noeud* tete=NULL;
    int n,i,val;
    printf("taille de la liste: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("element %d: ",i+1);
        scanf("%d",&val);
        insersorti(&tete,val);
    }
    printf("\n liste triee: ");
    afficher(tete);
    return 0;
}