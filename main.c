#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Person
{
    char name[50];
    int  DOB;
    long long int mobile_numbrt;
    int is_free;
}details;

int list(){

FILE  *fp;
fp = fopen("fileName.txt", "r");
    char line[1000];
    int c=0;
    while (fgets(line, sizeof(line), fp)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
                   c++;
        printf("%d: %s", c,line);

    }

    fclose(fp);
    return c;
}

void modify(int cc, int is_del){
    char str[256];
    FILE *filePointer, *fp;
    filePointer = fopen("fileName.txt", "r");
    if (!filePointer)
        {
                printf("Unable to open the file!!\n");
                return 0;
        }
    fp = fopen("temp.txt", "w");
    if (!fp)
        {
                printf("Unable to open the temp file!!\n");
                return 0;
        }


        int c=0;
        char line[1000];
    while (fgets(line, sizeof(line), filePointer)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */

        if(c==cc){
                if(is_del==0){
char temp[3];

            printf("Please enter new deatils:\n");

                printf("Please enter your name: ");
                 scanf("%c", &temp); //flushing the buffer
    scanf("%[^\n]",details.name);//todo
    printf("Please enter your year of birth: \n");
    scanf("%d",&details.DOB);
    printf("Please enter your Mobile Number: \n");
    scanf("%lli",&details.mobile_numbrt);
    char yes_no[20];
    printf("Do you wanna get free vacnnination (pelase enter only yes or no): ");
    scanf("%s", yes_no);
    details.is_free = (strcmp(yes_no,"yes")==0 || strcmp(yes_no,"Yes")==0 ||strcmp(yes_no,"YES")==0) ? 1:0;
     fprintf(fp, "%s %d %lli %s\n", details.name , details.DOB , details.mobile_numbrt, (details.is_free == 1)?"yes":"no");

        }}else{
        fprintf(fp,"%s",line);}
c++;

    }

     fclose(fp);
    fclose(filePointer);

 FILE *fptr1, *fptr2;
 char dcc;

    // Open one file for reading
    fptr1 = fopen("temp.txt", "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }


    // Open another file for writing
    fptr2 = fopen("fileName.txt", "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
dcc = fgetc(fptr1);
    while (dcc != EOF)
    {
        fputc(dcc, fptr2);
        dcc = fgetc(fptr1);
    }

    fclose(fptr1);
    fclose(fptr2);
  remove("temp.txt");


}





void write(){
    FILE *filePointer;
filePointer = fopen("fileName.txt", "a");
    if (!filePointer)
        {
                printf("Unable to open the file!!\n");
                return 0;
        }
//struct Person details;
    printf("Please enter your name: ");

  //fgets(details.name, 50, stdin);
scanf("%[^\n]",details.name);

    printf("Please enter your Date of year: \n");

    scanf("%d",&details.DOB);
    printf("Please enter your Mobile Number: \n");
    scanf("%lli",&details.mobile_numbrt);
    char yes_no[20];
    printf("Do you wanna get free vacnnination (pelase enter only yes or no): ");
    scanf("%s", yes_no);
    details.is_free = (strcmp(yes_no,"yes")==0 || strcmp(yes_no,"Yes")==0 ||strcmp(yes_no,"YES")==0) ? 1:0;

    fprintf(filePointer, "%s %d %lli %s\n", details.name , details.DOB , details.mobile_numbrt, (details.is_free == 1)?"yes":"no");
    fclose(filePointer);
    printf("DONE!!!!");
}
int main()
{int choice;
    do{
    char temp[3];
    printf("\t\t\t\t\Hello! Welcome to the Vaccination Center\n");

    printf("please choose from following:\n1:Add Data\n2:Modify Data\n3:Delete Data\n4:Create List\nPress 0 to exit");
    scanf("%d", &choice);
    scanf("%c", &temp); //flushing the buffer

    if(choice ==1)
        write();
    else if(choice ==4)
        list();
    else if(choice==2){
       int s =  list();
       printf("please select from above (enter between 1 and %d)",s);
       int c;
       scanf("%d",&c);
       modify(c-1,0);

    }
    else if(choice==3){
       int s =  list();
       printf("please select from above (enter between 1 and %d)",s);
       int c;
       scanf("%d",&c);
       modify(c-1,1);

    }
    else if (choice ==0){
        exit(0);
    }

    }while(choice <=4 || choice >=1);

    return 0;
}
