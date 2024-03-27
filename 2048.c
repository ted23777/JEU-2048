#include<stdio.h>
#include<time.h>
#include<stdlib.h>

///*FONCTIONS D'INITIALISATION *///

void initialisation(int plateau[5][5])
{
    int ligne,colonne,ligne1,colonne1,ligne2,colonne2;
    ligne1=rand()%5;
    colonne1=rand()%5;
    ligne2=rand()%5;
    colonne2=rand()%5;
    int z=0;
    for(ligne=0; ligne<5; ligne++)
    {
        for(colonne=0; colonne<5; colonne++)
        {
            if((ligne==ligne1&&colonne==colonne1)||(ligne==ligne2&&colonne==colonne2))
                plateau[ligne][colonne]=2;
            else
                plateau[ligne][colonne]=0;
        }
    }

}
//FONCTION QUI GENERE UN 2 DE MANIERE ALEATOIRE
void gen2(int plateau[5][5])
{
    int ligne,colonne;
    do
    {
        ligne=rand()%5;
        colonne=rand()%5;
    }
    while(plateau[ligne][colonne]!=0);
    plateau[ligne][colonne]=2;
}
///FIN INITIALISATION
//FONCTION QUI AFFICHE LE PLATEAU DE JEU
void affichage(int plateau[5][5])
{
    system("cls");
    int ligne,colonne;
    printf("\n");
    for(ligne=0; ligne<5; ligne++)
    {
        for(colonne=0; colonne<5; colonne++)
        {
            printf("\t %d \t",plateau[ligne][colonne]);
        }
        printf("\n");
    }
    // system("cls");
}

//DEPLACEMENT VERS LE HAUT
void moveup(int jeu[5][5])
{
    int ligne,colonne,valtempo;

    for(colonne=0; colonne<5; colonne++) //placons nous sur une colonne
    {
        int compt=0;//ligne ou on doit remplacer
        for(ligne=0; ligne<5; ligne++) //placons nous sur une ligne
        {
            if(jeu[ligne][colonne]!=0)//si l'emplacement est vide on permute
            {
                valtempo=jeu[ligne][colonne];//on stocke la valeur à permuter
                jeu[ligne][colonne]=0;
                jeu[compt][colonne]=valtempo;//on met cette valeur au bon endroit
                compt++;
            }
        }
    }
}
//somme des valeurs vers le haut
void sumup(int jeu[5][5],int *score)
{
    int ligne,colonne;
    for(colonne=0; colonne<5; colonne++) //placons nous sur une colonne
    {
        for(ligne=0; ligne<5; ligne++) //parcourons notre colonne suivant les differentes lignes
        {
            if(jeu[ligne][colonne]==jeu[ligne+1][colonne])//si on a 2 valeurs cote a cote egales alors on les somme
            {
                jeu[ligne+1][colonne]=0;
                jeu[ligne][colonne]=2*jeu[ligne][colonne];
                *score=*score+jeu[ligne][colonne];//et le score s'incremente
            }
        }
    }
}

//pour faire un deplacement vers le bas
void movedown(int jeu[5][5])
{
    int n=5;
    int ligne,colonne;
    for(colonne=0; colonne<5; colonne++) //placons nous sur une colonne
    {
        int compt=n-1;//ligne ou on doit remplacer
        int valtempo=0;
        for(ligne=n-1; ligne>=0; ligne--) //placons nous sur une ligne
        {
            if(jeu[ligne][colonne]!=0)//si l'emplacement est vide on permute
            {
                valtempo=jeu[ligne][colonne];//on stocke la valeur à permuter
                jeu[ligne][colonne]=0;
                jeu[compt][colonne]=valtempo;//on met cette valeur au bon endroit
                compt--;
            }
        }
    }
}
//pour une somme vers le bas
void sumdown(int jeu[5][5],int *score)
{
    int ligne,colonne,n=5;
    for(colonne=0; colonne<n; colonne++) //placons nous sur une colonne
    {
        for(ligne=n-1; ligne>=0; ligne--) //parcourons notre colonne suivant les differentes lignes
        {
            if(jeu[ligne][colonne]==jeu[ligne-1][colonne])//si on a 2 valeurs cote a cote egales alors on les somme
            {
                jeu[ligne][colonne]=2*jeu[ligne][colonne];
                jeu[ligne-1][colonne]=0;
                *score=*score+jeu[ligne][colonne];//et le score s'incremente
            }
        }
    }
}
//pour le deplacement à droite
void moveright(int jeu[5][5])
{
    int n=5;
    int ligne,colonne;
    for(ligne=0; ligne<n; ligne++) //placons nous sur une ligne
    {
        int compt=n-1;//ligne ou l'on doit remplacer
        int valtempo=0;
        for(colonne=n-1; colonne>=0; colonne--) //parcours de la ligne suivant ses differentes colonnes
        {
            if(jeu[ligne][colonne]!=0)//ou cette valeur est differente de 0 je realise une permutation
            {
                valtempo=jeu[ligne][colonne];;//valeur de stockage de la valeur a remplacer
                jeu[ligne][colonne]=0;
                jeu[ligne][compt]=valtempo;
                compt--;
            }
        }
    }
}
//somme pour un deplacement a gauche
void sumright(int jeu[5][5],int *score)
{
    int ligne,colonne,n=5;
    for(ligne=0; ligne<n; ligne++) //placons nous sur une ligne
    {
        for(colonne=n-1; colonne>=0; colonne--) //parcours de la ligne suivant ses differentes colonnes
        {
            if(jeu[ligne][colonne]==jeu[ligne][colonne-1])//où les 2 valeurs sont egales je les sommes selon le sens du mouvement
            {
                jeu[ligne][colonne]=2*jeu[ligne][colonne];
                jeu[ligne][colonne-1]=0;
                *score=*score+jeu[ligne][colonne];//le score s'incrémente suivant la valeur de la somme effectuée
            }
        }
    }
}
//pour le deplacement à gauche
void moveleft(int jeu[5][5])
{
    int valtempo,ligne,colonne,n=5;
    for(ligne=0; ligne<n; ligne++) //placons nous sur une ligne
    {
        int compt=0;//ligne ou l'on doit remplacer
        int valtempo;
        for(colonne=0; colonne<n; colonne++)
        {
            if(jeu[ligne][colonne]!=0)//ou cette valeur est differente de 0 je realise une permutation
            {
                valtempo=jeu[ligne][colonne];
                jeu[ligne][colonne]=0;
                jeu[ligne][compt]=valtempo;
                compt++;
            }
        }
    }
}
//somme pour un deplacement a gauche
void sumleft(int jeu[5][5],int *score)
{
    int ligne,colonne,n=5;
    for(ligne=0; ligne<n; ligne++) //placons nous sur une ligne
    {
        for(colonne=0; colonne<n; colonne++) //parcours de la ligne suivant ses differentes colonnes
        {
            if(jeu[ligne][colonne]==jeu[ligne][colonne+1])//ou les 2 valeurs sont egales je les sommes selon le sens du mouvement
            {
                jeu[ligne][colonne+1]=0;
                jeu[ligne][colonne]=2*jeu[ligne][colonne];
                *score=*score+jeu[ligne][colonne];//le score s'incrémente suivant la valeur de la somme effectuée
            }
        }
    }
}
//fonction pour verifier s'il a gagné
// il y a un seul cas de victoire possible
int victoire(int plateau[5][5])
{
    int ligne,colonne;
    for ( ligne = 0; ligne < 5; ligne++)
    {
        for (colonne= 0; colonne < 5; colonne++)
        {
            if (plateau[ligne][colonne] == 2048)// si dans une des cases il y a 2048 alors il a gagne
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }

}
// Fonction pour vérifier si le joueur a perdu
//il y a 3 configurations possibles pour que l'utilisateur puisse continuer on verifie chaque cas séparement
int defaite(int plateau[5][5])
{
    int ligne=0;
    int colonne=0;
    for ( ligne = 0; ligne < 5; ligne++)
    {
        for ( colonne = 0; colonne < 5; colonne++)
        {
            if (plateau[ligne][colonne] == 0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    ligne=1;
    colonne=0;
    for ( ligne = 1; ligne < 5; ligne++)
    {
        for ( colonne = 0; colonne < 5; colonne++)
        {
            if (ligne> 0 && plateau[ligne][colonne] == plateau[ligne - 1][colonne])
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    ligne=0;
    colonne=1;
    for ( ligne = 0; ligne < 5; ligne++)
    {
        for ( colonne= 1; colonne < 5; colonne++)
        {
            if (colonne > 0 && plateau[ligne][colonne] == plateau[ligne][colonne - 1])
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
}


// FONCTION QUI PERMET DE COPIER LA GRILLE DU JEU POUR POUVOIR LA COMPARER ENSUITE GRACE A LA FONCTION COMPARE
// la copie est intégrale pour chaque element du plateau de jeu
void copy(int plateau[5][5], int test[5][5])
{
    int ligne,colonne;
    for(ligne=0; ligne<5; ligne++)
    {
        for(colonne=0; colonne<5; colonne++)
        {
            test[ligne][colonne]=plateau[ligne][colonne];
        }
    }
}

//FONCTION QUI COMPARE LE TABLEAU AVANT ET APRES UN DEPLACEMENT AFIN DE DETERMINER SI OUI OU NON UN 2 ALEATOIRE DOIT ETRE GENERE
int compare(int plateau[5][5],int test[5][5])
{
    int ligne,colonne;
    for(ligne=0; ligne<5; ligne++)
    {
        for(colonne=0; colonne<5; colonne++)
        {
            if(plateau[ligne][colonne]!=test[ligne][colonne])
                return 0;// 0 s'il y a une case differente le 2 sera généré
        }
    }
    return 1;// si toutes les cases sont identiques alors le 2 ne sera pas généré
}

int main()
{
    int resultat;
    int grille[5][5]= {1024,1024};// test pour verifier l'arret du jeu
    int test[5][5];//grille copie permettant de tester les valeurs
    int verif1,verif2,def=0,vic=1;
    srand(time(NULL));
    //initialisation(grille);
    affichage(grille);
    int score=0;
    printf("\n \t \t \t score :%d \n",score);
    int action;

   do {
        do{
            printf("\n \t QUE VOULEZ-VOUS FAIRE? \n 8-deplacement vers le haut  \n 2-deplacement vers le bas  \n 4-deplacement vers la gauche \n 6-deplacement vers la droite \n 0-quitter \n ");
            scanf("%d",&action);
            copy(grille,test);
            switch(action)
            {
            case 8:
                moveup(grille);
                sumup(grille,&score);
                moveup(grille);
                if(compare(grille,test)==0)
                    gen2(grille);
                affichage(grille);
                printf("\n \t \t \t SCORE : %d\n",score);
                break;
            case 2:
                movedown(grille);
                sumdown(grille,&score);
                movedown(grille);
                if(compare(grille,test)==0)
                    gen2(grille);
                affichage(grille);
                printf("\n \t \t \t SCORE %d\n",score);
                break;
            case 4:
                moveleft(grille);
                sumleft(grille,&score);
                moveleft(grille);
                if(compare(grille,test)==0)
                    gen2(grille);
                affichage(grille);
                printf("\n \t \t \t SCORE %d\n",score);
                break;
            case 6:
                moveright(grille);
                sumright(grille,&score);
                moveright(grille);
                if(compare(grille,test)==0)
                    gen2(grille);
                affichage(grille);
                printf("\n \t \t \t SCORE %d\n",score);
                break;
                system("cls");
            default :
                printf("\n \t \t touche invalide \n");
            }
        vic=victoire(grille);
        def=defaite(grille);
         if(vic == 0) {
            printf("\n Vous avez gagné !");
        } else if(def == 1) {
            printf("\n Vous avez perdu !");
        }
        }while((vic!=0&&def!=1));
        printf("merci d'avoir joué");
        return 0;
    } while(action!=0);

}





