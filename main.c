//librariele pentru proiect
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "stdbool.h"
void append();
void display();
void sortshell();
void sortbubble();
void sortInsert();
void sortQuick();

typedef struct ECarti{
  char nume_autor[30];
  char titlul_cartii[30];
  char editura[30];
  int anul_editari;
  char disponib[30];

}t1, t2;

int main(){
  int ch = 0;
  while(1)
  {

      printf("\n _____________Sistemul de Management Fiseirului de Date_______________\n");
      printf(" | 1. Adaugarea datelor.                                           |\n");
      printf(" | 2. Afisarea datelor.                                           |\n");
      printf(" | 3. Sortarea alfabetica shell.                                           |\n");
      printf(" | 4. Sortarea numerica bubble.                                           |\n");
      printf(" | 5. Sortarea numerica insert.                                           |\n");
      printf(" | 6. Sortarea numerica quick.                                           |\n");
      printf(" | 0. Iesire.                                                      |\n");
      printf(" ___________________________________________________________________\n");
      printf("\n Introduceti optiunea:");
      scanf("%d",&ch);

  switch(ch)
  {
    case 1: { system("cls"); append(); break;}
    case 2: { system("cls"); display(); break;}
    case 3: { system("cls"); sortshell(); break;}
    case 4: { system("cls"); sortbubble(); break;}
    case 5: { system("cls"); sortInsert (); break;}
    case 6: { system("cls"); sortQuick(); break;}

    case 0: { system("cls"); exit(0);}
    default:printf("\nError 0..2!");
  }
  }
  return 0;
}

void append(){
  int i = 0, n = 0;
  FILE *fp;
  struct ECarti t1;

  fp = fopen("experiment.txt","ab");
  printf("\n Introduce numarul necesar de articole:");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
    printf("\n %d. Introdoceti numele: ", i+1);
    scanf("%s", &t1.nume_autor);

    printf("\n Introduceti titlul cartii: ");
    scanf("%s", &t1.titlul_cartii);

    printf("\n Introduceti editura: ");
    scanf("%s", &t1.editura);

    printf("\n Introduceti anul editarii: ");
    scanf("%d", &t1.anul_editari );

    printf("\n Cartea este disponibila? (da/nu): ");
    scanf("%s", &t1.disponib);


    fwrite(&t1, sizeof(t1), 1, fp);
  }
  fclose(fp);
  printf(" \nDatele au fost introduse cu success!\n");
}

//afisarea datelor introduse
void display(){

  fflush(stdin);
  FILE *fp;
  struct ECarti t2;
  int found = 0;
  fp = fopen("experiment.txt","rb");
  while(1)
  {
    fread(&t2, sizeof(t2), 1, fp);
    if(feof(fp)){
      break;
    }
    printf("\n___________________________________________________________________________________________________________\n\n");
    printf("___________________________________________________________________________________________________________\n\n");
    printf(" Autorul\tTitlul\tEditura\t\tAnul\tDisponibilitatea\n\n");
    printf(" %s  \t", t2.nume_autor);
    printf("%s\t\t", t2.titlul_cartii);
    printf("%s\t\t", t2.editura);
    printf("%d\t", t2.anul_editari);
    printf("%s\n", t2.disponib);
    printf("___________________________________________________________________________________________________________\n\n");
  }
  if(found == 0){
    printf("\n Scuzati nu a fost introdusa nici o inregistrare.");
  }

  fclose(fp);
  printf("\n\n Apasa Enter pentru a continua");

}
//sortarea shell pentru partea alfabetica
void sortshell(){
  FILE *fp1;
  FILE *fp2;
      struct ECarti t1;
        fp1=fopen("experiment.txt", "rb");
        fp2=fopen("shelsort.txt", "wb");
        fread(&t1, sizeof(t1), 1, fp1);
        int y = 0, top = 0, i = 0;
        char temp[20];
        char str[20][20];
        char denumire[30];
        while(!feof(fp1))
        {
            if(strcmp(t1.nume_autor, denumire)!=0)
            {
                 strcpy(str[y], t1.nume_autor);
               y++;
            }
             fread(&t1, sizeof(t1),1,fp1);
        }
        top = y;
        for (int y = 0; y < top; ++y) {
            for (int j = y + 1; j < top; ++j) {
                if (strcmp(str[y], str[j]) > 0) {
                    strcpy(temp, str[y]);
                    strcpy(str[y], str[j]);
                    strcpy(str[j], temp);
                }
            }
        }

             fseek(fp1, 0, SEEK_SET);
             printf(" Autorul\tTitlul\tEditura\t\tAnul\tDisponibilitatea\n\n");
              i = 1;
              for(y=0; y<top; y++)
              {
             fseek(fp1, 0, SEEK_SET);
                  fread(&t1, sizeof(t1),1,fp1);
             while(!feof(fp1))
             {
                  if(strcmp(t1.nume_autor, str[y])==0)
                 {
                   printf(" %s\t\t", t1.nume_autor);
                   printf("%s\t", t1.titlul_cartii);
                   printf("%s\t", t1.editura);
                   printf("%d\t", t1.anul_editari);
                   printf("%s\t", t1.disponib);
                 }
                  fread(&t1, sizeof(t1),1,fp1);
             }
           }
           fwrite(&t1, sizeof(t1),1, fp2);
        fclose(fp1);
        fclose(fp2);
}
//sortarea buble, anului editari
void sortbubble(){
  FILE *tr1;
  FILE *tr2;
struct ECarti t2;
    int index=0;
    int a[100];
    int k = 0;
    float num;
    int n = 0, i = 0;

    tr1 = fopen("experiment.txt","rb");
    tr2 = fopen("bublesort.txt","wb");

    fread(&t2,sizeof(t2),1,tr1);

    while(!feof(tr1))
    {
        if(t2.anul_editari > index)
        {
            a[k] = t2.anul_editari;
            k=k+1;
        }
         fread(&t2, sizeof(t2), 1, tr1);
    }
    n=k;
//Bublle sort
            int f;
            int aux;
             do
             {
                 f=1;
                 for(k=0; k<n-1; k++)
                 {
                 if(a[k]>a[k+1])
                 {
                     aux = a[k];
                     a[k] = a[k+1];
                     a[k+1] = aux;
                     f=0;
                 }
                 }
             }while(!f);
       fseek(tr1, 0, SEEK_SET);
       printf(" Autorul\tTitlul\tEditura\t\tAnul\tDisponibilitatea\n\n");
       i = 1;

        for(k=0; k<n; k++)
        {
       fseek(tr1, 0, SEEK_SET);
            num = a[k];
       while(1)
       {
         fread(&t2, sizeof(t2), 1, tr1);
         if(feof(tr1))
         {
           break;
         }
           if(t2.anul_editari == num)
           {

             printf("\t%s\t%s\t%s\t%d\t%s\n\n",t2.nume_autor, t2.titlul_cartii, t2.editura, t2.anul_editari, t2.disponib);
           }
       }
         }
       fwrite(&t2, sizeof(t2),1, tr2);

   fclose(tr1);
   fclose(tr2);
 }

//sortarea numerica insert
void sortInsert(){
  int  key = 0, x = 0;
  FILE *ts1;
  FILE *ts2;
struct ECarti t2;
    int index=0;
    int a[100];
    int k = 0;
    float num;
    int n = 0, i = 0;
    int j = 0;

    ts1 = fopen("experiment.txt","rb");
    ts2 = fopen("insertsort.txt","wb");

  fread(&t2,sizeof(t2),1,ts1);

  while(!feof(ts1))
    {
        if(t2.anul_editari > index)
        {
            a[k] = t2.anul_editari;
            k=k+1;
        }
         fread(&t2, sizeof(t2),1,ts1);
    }

  for (i = 1; i <= n; i++)
  {
    key = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > key){
      a[j + 1] = a[j];
      j = j - 1;
      }
      fseek(ts1, 0, SEEK_SET);
      fread(&t2, sizeof(t2), 1, ts1);
    a[j + 1] = key;
     printf("\t%s\t%s\t%s\t%d\t%s\n\n",t2.nume_autor, t2.titlul_cartii, t2.editura, t2.anul_editari, t2.disponib);
  }
  fwrite(&t2, sizeof(t2),1, ts2);

  fclose(ts1);
  fclose(ts2);
}


void sortQuick(){
  int  key = 0, x = 0;
  FILE *td1;
  FILE *td2;
  int   pivot = 0, temp = 0;
  int index = 0, k = 0, j = 0;
  int first = 0, last = 0, i = 0;
  char a[30];

  struct ECarti t2;

    td1 = fopen("experiment.txt","rb");
    td2 = fopen("quicksort.txt","wb");

  fread(&t2,sizeof(t2),1,td1);

  while(!feof(td1))
    {
        if(t2.anul_editari > index)
        {
            a[k] = t2.anul_editari;
            k=k+1;
        }
        if (k == 1){
          first = t2.anul_editari;
        }

         fread(&t2, sizeof(t2),1, td1);
    }
    last = t2.anul_editari;
    fseek(td1, 0, SEEK_SET);

  if(first < last)
  {
     pivot = first;
     i=first;
     j=last;
     while(i<j)
     {

        while(a[i]<=a[pivot]&&i<last)
           i++;
        while(a[j]>a[pivot])
           j--;
        if(i<j)
        {
           temp=a[i];
           a[i]=a[j];
           a[j]=temp;
        }
        fread(&t2, sizeof(t2), 1, td1);
        printf("\t%s\t%s\t%s\t%d\t%s\n\n",t2.nume_autor, t2.titlul_cartii, t2.editura, t2.anul_editari, t2.disponib);
     }
     temp=a[pivot];
     a[pivot]=a[j];
     a[j]=temp;
     sortQuick(a,first,j-1);
     sortQuick(a,j+1,last);
  }
  fwrite(&t2, sizeof(t2),1, td2);

  fclose(td1);
  fclose(td2);

}
