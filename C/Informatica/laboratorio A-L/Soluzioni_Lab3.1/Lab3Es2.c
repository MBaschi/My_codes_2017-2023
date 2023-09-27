/*Partendo da una struttura dati che descrive un file (NomeFile, data di creazione - 31092017, ultima modifica, dimensione); scrivere un programma che permetta di gestire attraverso un array, tutti i file presenti su disco (Massimo 100 ma possono essere anche meno).Il programma presenta un menù che permette di:1. Visualizzare i file che siano stati modificati a partire dalla data inserita dall’utente;2. Visualizzare lo spazio occupato da tutti i file (attraverso una funzione).3. Aggiungere un file in coda*/#include <stdio.h>typedef struct fileSystem{  char nomeFile[20];  int dataCreazione;  int dataModifica;  int dimensione;} fileSystem;int aggiungiFile(fileSystem files[100], int cont);void stampaData(int data);void visualizzaFile(fileSystem files[100], int cont, int data);int spazioOccupato(fileSystem files[100], int cont);int main(){  fileSystem file[100];  int contaFile = 0;  int r;  int giorno, mese, anno;    do{    printf("\nMenu\n\n");    printf("1) Visualizza file\n2) Visualizza spazio\n3) Aggiungi file\n4) ESCI\n\n>> ");    scanf("%d",&r);        switch(r){      case 1:      printf("Inserisci data di modidifica da ricercare:\nGiorno: ");      scanf("%d",&giorno);      printf("Mese: ");      scanf("%d",&mese);      printf("Anno: ");      scanf("%d",&anno);      visualizzaFile(file, contaFile, giorno*1000000+mese*10000+anno);      break;      case 2:      printf("La dimensione occupata da tutti i file e': %d\n", spazioOccupato(file, contaFile));      break;      case 3:        contaFile = aggiungiFile(file,contaFile);      break;    }  }while(r!=4);  return 0;}int aggiungiFile(fileSystem files[100], int cont){  if (cont>=99){    printf("Hai raggiunto la dimensione massima dei file");     return 99;  }  printf("Inserisci nome file: ");  scanf("%s", files[cont].nomeFile);  printf("Inserisci data di modifica (es. 31092017): ");  scanf("%d",&files[cont].dataModifica);  printf("Inserisci data di creazione (es. 31092017): ");  scanf("%d",&files[cont].dataCreazione);  printf("Inserisci dimensione: ");  scanf("%d",&files[cont].dimensione);  cont++;    return cont;}void visualizzaFile(fileSystem files[100], int cont, int data){  printf("\nFile modificati dopo la data %d\n",data);  printf("Nome file\tData Crazione\tData Modifica\tDimensione\n");  for (int i=0; i<cont; i++){    if ( (files[i].dataModifica%10000>=data%10000) && ((files[i].dataModifica%1000000)/10000>=(data%1000000)/10000) && ((files[i].dataModifica/1000000>=data/1000000)) )    {      printf("%s\t", files[i].nomeFile);      stampaData(files[i].dataCreazione);      stampaData(files[i].dataModifica);      printf("%d\n", files[i].dimensione);    }      }}void stampaData(int data){    printf("%d-%d-%d\t",data/1000000,(data%1000000)/10000,data%10000);}int spazioOccupato(fileSystem files[100], int cont){  int len = 0;  for (int i=0; i<cont; i++)    len += files[i].dimensione;  return len;}