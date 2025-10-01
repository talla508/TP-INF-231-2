#include<stdio.h>
#include<stdlib.h>
typedef struct noeud{
    int p;
    struct noeud *prev,*suiv;
} noeud;
noeud* creernoeud(int val){
    noeud* n=(noeud*)malloc(sizeof(noeud));
     if (n == NULL){
        printf("erreur d'allocation");
        exit(1);
    }
    n->p=val;
    n->prev= n->suiv=NULL;
    return n;
}
void insersorti(noeud** tete, int val){
    noeud* n=creernoeud(val);
    if(*tete==NULL || (*tete)->p >=val){
        n->suiv=*tete;
        if(*tete!=NULL)(*tete)->prev=n;
        *tete=n;
        return;
    }
    noeud* temp=*tete;
    while(temp->suiv!=NULL && temp->suiv->p<val)
        temp=temp->suiv;
    n->suiv=temp->suiv;
    if(temp->suiv !=NULL)
    temp->suiv->prev=n;
    temp->suiv=n;
    n->prev=temp;
}
void afficher(noeud* tete){
    noeud* temp=tete;
    while(temp !=NULL){
        printf("%d <->",temp->p);
        temp=temp->suiv;
    }
    printf("NULL \n");
}
int main(){
    noeud* tete=NULL;
    int n,i,val;
    printf("taille de liste: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("element %d: ",i+1);
        scanf("%d",&val);
        insersorti(&tete,val);
    }
    printf("\n liste doublr triee: ");
    afficher(tete);
    return 0;
}