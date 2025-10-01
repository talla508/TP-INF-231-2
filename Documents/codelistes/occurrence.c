#include<stdio.h>
#include<stdlib.h>
typedef struct noeud{
    int p;
    struct noeud* suiv;
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
void inserfin(noeud** tete,int val){
    noeud* n=creernoeud(val);
    if(*tete==NULL){
        *tete=n;
        return;
    }
    noeud* temp=*tete;
    while(temp->suiv !=NULL) temp=temp->suiv;
    temp->suiv=n;
    free(temp);
}
void afficher(noeud* tete){
    while (tete !=NULL){
        printf("%d->",tete->p);
        tete=tete->suiv;
    }
    printf("NULL \n");
}
void supptout(noeud** tete, int cle){
    noeud* temp= *tete, *prev=NULL;
    while(temp !=NULL){
        if(temp->p==cle){
            if(prev==NULL){
                 temp=*tete;
                *tete=temp->suiv;
                free(temp);
            }else{
                prev->suiv=temp->suiv;
                free(temp);
                temp=prev->suiv;
            }
        }else{
            prev=temp;
            temp=temp->suiv;
        }
    }
}
int main(){
    noeud* tete=NULL;
    int n,i,val,cle;
    printf("taille de la liste: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("element %d: ",i+1);
        scanf("%d",&val);
        inserfin(&tete,val);
    }
    printf("\n liste initiale: ");
    afficher(tete);
    printf("element a supprimer: ");
    scanf("%d",&cle);
    supptout(&tete,cle);
    printf("\n liste apres suppression: ");
    afficher(tete);
    
    return 0;
}