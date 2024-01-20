#include <stdio.h>
#include <stdlib.h>
typedef struct FOOD{
	char sexe[50];
	int age;
	char date[50];
	char heure[50];
	char repas[50];
	char ustensile[50];
	char lieux[50];
	int nombre;
}FOOD;

/*
	QUESTION 4
	dans ce module nous implementons les operations en utilisant un tableau
*/
//Ici la fonction save et la fonction read seront jumilées
void save(FOOD F){
	int i;
	FILE *f;
	f=fopen("datafood.txt","a");
	if(f==NULL){
		printf("ouverture du fichier non effectuer");
		exit(1);
	}
	for(i=0;i<5;i++){
		printf("entrer le sexe\n");
		scanf("%s",&F.sexe);
		printf("entrer l'age\n");
		scanf("%d",&F.age);
		printf("entrer la date\n");
		scanf("%s",&F.date);
		printf("entrer l'heure\n");
		scanf("%s",&F.heure);
		printf("entrer le repas\n");
		scanf("%s",&F.repas);
		printf("entrer le ustensile\n");
		scanf("%s",&F.ustensile);
		printf("entrer le lieux\n");
		scanf("%s",&F.lieux);
		printf("entrer le nombre\n");
		scanf("%d",&F.nombre);
		fprintf(f,"%s %d %s %s %s %s %s %d\n",F.sexe,F.age,F.date,F.heure,F.repas,F.ustensile,F.lieux,F.nombre);
	}
	fclose(f);
}
void save_read(FOOD F){
// ici les info sont stocquer dans un fichier
	FOOD T[50];
	int n,i=0;
	FILE *f;
	f=fopen("datafood.txt","r");
	if(f==NULL){
		printf("ouverture du fichier non effectuer");
		exit(1);
	}
	while(fscanf(f,"%s %d %s %s %s %s %s %d\n",F.sexe,&F.age,F.date,F.heure,F.repas,F.ustensile,F.lieux,&F.nombre)!=EOF){
		T[i]=F;
		i++;
	}
	n=i;
	for(i=0;i<n;i++){
		printf("%s %d %s %s %s %s %s %d\n",T[i].sexe,T[i].age,T[i].date,T[i].heure,T[i].repas,T[i].ustensile,T[i].lieux,T[i].nombre);
	}
	fclose(f);
}
void recherche(char repas[]){
	printf("nous sommes dans rechercher\n");
	FOOD F;
	FOOD T[50];
	int n,i=0;
	FILE *f;
	f=fopen("datafood.txt","r");
	if(f==NULL){
		printf("ouverture du fichier non effectuer");
		exit(1);
	}
	while(fscanf(f,"%s %d %s %s %s %s %s %d\n",F.sexe,&F.age,F.date,F.heure,F.repas,F.ustensile,F.lieux,&F.nombre)!=EOF){
		T[i]=F;
		i++;
	}
	n=i;
	for(i=0;i<n;i++){
		if(strcmp(T[i].repas,repas)==0){
			printf("le repas existe dans la pile,:\n");
			printf("le sexe de l'individu est :%s\n",T[i].sexe);
			printf("l'age de l'individu est :%d\n",T[i].age);
			printf("la date de consomation est :%s\n",T[i].date);
			printf("l'heure de prise est:%s\n",T[i].heure);
			printf("le repas pris est:%s\n",T[i].repas);
			printf("l'ustensile de prise est:%s\n",T[i].ustensile);
			printf("le lieu de prise est:%s\n",T[i].lieux);
			printf("le nombre de personne est:%d\n",T[i].nombre);
		}
	}
}
void sort(FOOD F){
	FOOD T[100];
	int permut, passage;
	int tmp;
	FILE *f;
	int n,i;
	f=fopen("datafood.txt","r");
	if(f==NULL){
		printf("ouverture du fichier non effectuer");
		exit(1);
	}
	while(fscanf(f,"%s %d %s %s %s %s %s %d\n",F.sexe,&F.age,F.date,F.heure,F.repas,F.ustensile,F.lieux,&F.nombre)!=EOF){
		T[i]=F;
		i++;
	}
	n=i;
	passage=0;
	do{
		permut=0;
		for(i=0;i<n-1-passage;i++){
			if(T[i].age>T[i+1].age){
				tmp=T[i].age;
				T[i].age=T[i+1].age;
				T[i+1].age=tmp;
				permut=1;
			}
		}
		passage++;
	}while(permut==1);

	for(i=0;i<n;i++){
		printf("%s %d %s %s %s %s %s %d\n",T[i].sexe,T[i].age,T[i].date,T[i].heure,T[i].repas,T[i].ustensile,T[i].lieux,T[i].nombre);
	}
}
int main()
{
	FOOD F;
	char repas[]="koki";
	//ici on utilise les tableaux
	//save(F);
	save_read(F);
	recherche(repas);
	sort(F);
    return 0;
}
