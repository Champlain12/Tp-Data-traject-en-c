#include <stdio.h>
#include <stdlib.h>
typedef struct Parcour{
	char date[50];
	char sexe[50];
	int age;
	char depart[50];
	char arriver[50];
	int cout;
	char etatroute[50];
}Parcour;

void save(Parcour P){
	int i;
	FILE *f;
	f=fopen("dataparcout.txt","a");
	if(f==NULL){
		printf("ouverture du fichier non effectuer");
		exit(1);
	}
	for(i=0;i<2;i++){
		printf("entrer le sexe\n");
		scanf("%s",&P.sexe);
		printf("entrer l'age\n");
		scanf("%d",&P.age);
		printf("entrer la date\n");
		scanf("%s",&P.date);
		printf("entrer le depart\n");
		scanf("%s",&P.depart);
		printf("entrer l'arriver\n");
		scanf("%s",&P.arriver);
		printf("entrer le cout\n");
		scanf("%d",&P.cout);
		printf("entrer l'etat de la route\n");
		scanf("%s",&P.etatroute);
		fprintf(f,"%s %d %s %s %s %d %s\n",P.sexe,P.age,P.date,P.depart,P.arriver,P.cout,P.etatroute);
	}
	fclose(f);
}
void save_read(Parcour P){
// ici les info sont stocquer dans un fichier
	Parcour T[50];
	int n,i=0;
	FILE *f;
	f=fopen("dataparcout.txt","r");
	if(f==NULL){
		printf("ouverture du fichier non effectuer");
		exit(1);
	}
	while(fscanf(f,"%s %d %s %s %s %d %s\n",P.sexe,&P.age,P.date,P.depart,P.arriver,&P.cout,P.etatroute)!=EOF){
		T[i]=P;
		i++;
	}
	n=i;
	for(i=0;i<n;i++){
		printf("%s %d %s %s %s %d %s\n",T[i].sexe,T[i].age,T[i].date,T[i].depart,T[i].arriver,T[i].cout,T[i].etatroute);
	}
	fclose(f);
}
void rechercher( char depart[],char arriver[]){
	Parcour P;
	Parcour T[50];
	int i=0,n;
	FILE *f;
	f=fopen("dataparcout.txt","r");
	if(f==NULL){
		printf("ouverture du fichier non effectuer");
		exit(1);
	}
	while(fscanf(f,"%s %d %s %s %s %d %s\n",P.sexe,&P.age,P.date,P.depart,P.arriver,&P.cout,P.etatroute)!=EOF){
		T[i]=P;
		i++;
	}
	n=i;
	for(i=0;i<n;i++){
		if((strcmp(T[i].depart,depart)==0)&&(strcmp(T[i].arriver,arriver)==0)){
			printf("le trajet existe dans notre tableau\n");
			printf("le sexe de l'individu est :%s\n",T[i].sexe);
			printf("l'age de l'individu est :%d\n",T[i].age);
			printf("la date de consomation est :%s\n",T[i].date);
			printf("le lieu de depart est:%s\n",T[i].depart);
			printf("le lieu d'arriver est:%s\n",T[i].arriver);
			printf("le cout du transport est:%d\n",T[i].cout);
			printf("l'etat de la route est:%s\n",T[i].etatroute);
		}
	}
}
void sort(Parcour P){
	Parcour T[100];
	int permut, passage;
	int tmp;
	FILE *f;
	int n,i;
	f=fopen("dataparcout.txt","r");
	if(f==NULL){
		printf("ouverture du fichier non effectuer");
		exit(1);
	}
	while(fscanf(f,"%s %d %s %s %s %d %s\n",P.sexe,&P.age,P.date,P.depart,P.arriver,&P.cout,P.etatroute)!=EOF){
		T[i]=P;
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
		printf("%s %d %s %s %s %d %s\n",T[i].sexe,T[i].age,T[i].date,T[i].depart,T[i].arriver,T[i].cout,T[i].etatroute);
	}
}
int main()
{
	Parcour P;
	char depart[]="mveng";
	char arriver[]="chateau";
	save(P);
	save_read(P);
	rechercher(depart,arriver);
	printf("les informations triees dans l'odre croissant sont les suivantes:\n");
	sort(P);
    return 0;
}
