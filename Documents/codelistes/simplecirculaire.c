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
void insertete(noeud** tete, int val){
    noeud* n=creernoeud(val);
    if(*tete==NULL){
        *tete=n;
        n->suiv=*tete;
        return;
    }
    noeud* temp=*tete;
    while(temp->suiv !=*tete) temp=temp->suiv;
    temp->suiv=n;
    n->suiv=*tete;
    *tete=n;
}
void insertail(noeud** tete, int val){
    noeud* n=creernoeud(val);
    if(*tete==NULL){
        *tete=n;
        n->suiv=*tete;
        return;
    }
    noeud* temp=*tete;
    while(temp->suiv !=*tete)temp=temp->suiv;
    temp->suiv=n;
    n->suiv=*tete;
}
void afficher(noeud* tete){
    if(tete==NULL) return;
    noeud* temp=tete;
    do{
        printf("%d ->",temp->p);
    } while (temp !=tete);
    printf("retour a la tete \n");
}
int main(){
    noeud* tete=NULL;
    int n,i,val;
    printf("nombre de valeur a inserer: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("elememt %d: ",i+1);
        scanf("%d",&val);
        insertail(&tete, val);
    }
    printf("\n liste circulaire: ");
    afficher(tete);
    printf("entrez une valeur a inserer en tete: ");
    scanf("%d",&val);
    insertete(&tete, val);
    printf("\n apres insertion en tete: ");
    afficher(tete);
    printf("entrez un evaleur a inserer en queue: ");
    scanf("%d",&val);
    insertail(&tete,  val);
    printf("\n apres insertion en queue: ");
    afficher(tete);
    return 0;
}