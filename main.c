#include <stdio.h>
#include <stdlib.h>

typedef struct node node ;
typedef struct procesus{
    char signe ;
    int x ;
    char k;
    char o;
    char f;

}p;
struct node
{
     p data ;
     node *next ;
};

typedef struct DataListe{
    char Etat;
    int DebBloc;
    int TailleBloc;
}DataL;
typedef struct Node Node;
struct Node{
    DataL data2;
    Node *suivant;
};
Node * CreateNode(){
    Node *n=(Node*)malloc(sizeof(Node));

    return n;
}

void FirstFit(Node **Head, node **head,int taille){
 Node *n=CreateNode();
 Node *Temp =*Head,*n2;
 node *temp =*head;
 n->data2.Etat = 'L';
 n->data2.DebBloc = temp->data.x;
 n->data2.TailleBloc = taille-temp->data.x;
 *Head = n;
    while(temp!=NULL){
        n2 =CreateNode();
            if(temp->data.signe=='+'){
                while(Temp->suivant!=NULL){
                    Temp = Temp->suivant;}
                     n2->data2.Etat = 'O';
                    n2->data2.DebBloc = Temp->data2.DebBloc + temp->data.x;
                    n2->data2.TailleBloc-=temp->data.x;
                    n2->suivant = NULL;
                    Temp->suivant = n2;

            }
            else if(temp->data.signe=='-'){
                while(Temp->suivant!=NULL){
                    Temp = Temp->suivant;}
                     n2->data2.Etat = 'L';
                    n2->data2.DebBloc = Temp->data2.DebBloc - temp->data.x;
                    n2->data2.TailleBloc+=temp->data.x;
                    n2->suivant = NULL;
                    Temp->suivant = n2;

            }


    }
 }
 void ChargerFille(FILE *pf){
     char chemin[500];
   printf("donnez le chemin \n");
	gets(chemin);

    pf = fopen(chemin,"r") ;
      if( pf ==NULL){
            printf("le fichier est vide ") ;
         exit(-1);}

 }


void ajouterfin(p e,node **head )
{
   node *n = (node *)malloc(sizeof(node));
	node *temp = *head;
	n->data = e;
	n->next = NULL;
	if (*head == NULL){
		*head = n;
		return;
	}

	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = n;
}
void charger(FILE *pf, node **head){

	p e;
	while((fscanf(pf,"%c%d%c%c%c",&e.signe,&e.x,e.k,&e.o,&e.f))!= EOF){
		ajouterfin(e,head);
	}
}
void afficher(node *head )
{
    node *temp=head ;
    while(temp!=NULL)
    {
        printf("%c%d\n",temp->data.signe,temp->data.x);
        temp=temp->next;
    }
}
int main()
{
    FILE *pf;
    node *head=NULL ;
    int n=0 ;
    int NAlgo;

   while(n!=0){
    printf("\t---------------------------------------\n");
    printf("\t|                                      |\n ") ;
    printf("\t|                                      |\n ") ;
    printf("\t|             Menu                     |\n" );
    printf("\t|                                      |\n ") ;
    printf("\t|                                      |\n ") ;
    printf("\t|--------------------------------------|\n");
    printf("\t|  1) lecture des donnees:             |\n ") ;
    printf("\t|  2) choix d'algorithme:              |\n ");
    printf("\t|  3) l'affichage:                     |\n ");
    printf("\t|  4) Quiter:                          |\n ");
    printf("\t|                                      |\n ") ;
    printf("\t|                       votre choix:   |\n ") ;
    printf("\t|                                      |\n ") ;
    printf("\t|--------------------------------------|\n");

  scanf("%d",&n);

    switch(n){
   case 1:
       ChargerFille(pf);
       charger(pf,&head);
       afficher(head);

    break;

    case 2:system("cls");printf("\t  \tEnter le choix de algoritheme:\n "); puts("");
    printf("\t|----------------------------|\n");
    printf("\t|  1) First Fit:             |\n ") ;
    printf("\t|  2) Worst Fit:             |\n ");
    printf("\t|  3) Best Fit:              |\n ");
    printf("\t|  3) Next Fit:              |\n ");
    printf("\t|  4) Quiter:                |\n ");
    printf("\t|                            |\n ") ;
    printf("\t|            votre choix:    |\n ") ;
    printf("\t|                            |\n ") ;
    printf("\t|----------------------------|\n");
     scanf("%d           ",&NAlgo);
    break;

    case 3: printf("l'aaff");
    break;
    case 4:
        exit(-1);

    default :
        printf("erreur");
        break;

    }
   }

  fclose(pf);
    return 0;
}
