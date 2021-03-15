#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "students.h"
#define M 10


struct student* create_student(int size)
{
    struct student *std;
    std=(student*)malloc(sizeof(struct student));
    if (std==NULL) printf("Error in memory allocation of student.\n");
    std->stunum =0;
    std->size = size;
    std->start = (studNode *)malloc(size*sizeof(struct studNode));
    if (std->start==NULL) printf("Error in memory allocation of start.\n");



    for(int i=0; i<size; i++ )
    {
        std->start[i].id=0;
        std->start[i].name=NULL;
        std->start[i].surname=NULL;
    }
    return std;
}

void add_student(student* std, int temp_id, char temp_name[M], char temp_surname[M])
{
  if(std->stunum >= std->size) printf("The list is full !\n");
  else{

    std->start[std->stunum].id= temp_id;
    std->start[std->stunum].name= strdup(temp_name);
    std->start[std->stunum].surname= strdup(temp_surname);

  }
  std->stunum++;
}

void free_list(student* std)
{
    free(std->start);
    free(std);
}

void get_student_data(student *std)
{
    int temp_id=0;
    char name[M], surname[M];

    printf("Insert the id : ");
    scanf("%d", &temp_id);
    printf("Insert the name : ");
    scanf("%s",name);
    printf("Insert the surname : ");
    scanf("%s",surname);
    add_student(std, temp_id, name, surname);

}

int id_removing(void)
{
    int id_to_remove;
    printf("insert the id of the student you want to delete : ");
    scanf("%d",&id_to_remove);

    return id_to_remove ;
}

void remove_student(student * std, int id_to_remove )
{
    int i=0, index=0;


    for(i=0; i<std->stunum; i++)
    {
        if(std->start[i].id == id_to_remove)
        {index=i;
             break;
        }

    }
    for(i=index; i<std->stunum; i++)
    {
        std->start[i].id=std->start[i+1].id;
        std->start[i].name=strdup(std->start[i+1].name);
        std->start[i].surname=strdup(std->start[i+1].surname);
    }
    std->stunum--;
}

void print_list(student *std)
{
    int i;

    if (std->stunum==0) printf("The list is empty\n");

   studentQSort(std);

    for(i=0; i<std->stunum; i++)
    {
        printf("Student ID : %d\nStudent name : %s\nStudent surname : %s\n",
               std->start[i].id,std->start[i].name,std->start[i].surname);
               printf("\n");
    }
}

void readFile(student * std)
{
    FILE *f =fopen("file.txt", "r");

    if(f==NULL){
        printf("Error in the opening of file!\n");
        //return -1;
    }

    int temp_id=0;
    char name[M], surname[M];

    while(fscanf(f,"%d %s %s",&temp_id, name,surname)!=EOF)
    {
        std->start[std->stunum].id=temp_id;
        std->start[std->stunum].name= strdup(name);
        std->start[std->stunum].surname= strdup(surname);
        std->stunum++;
    }
    fclose(f);

}

void printMenu(student * std)
{
    int choice =0;
    do{
        printf("\n\t\t Main Menu\n\n");
        printf("1) Add a student\n");
        printf("2) Remove a student\n");
        printf("3) Print the student list\n");
        printf("4) Read student list from the text file\n");
        printf("5) Sort the students information \n");
        printf("6) Search student information \n");
        printf("7) Exit\n");
        printf("\nChoose and option : ");
        scanf("%d",&choice);
        printf("\n");

        switch (choice){
           case 1: get_student_data(std); break;
           case 2: remove_student(std, id_removing()); break;
           case 3: print_list(std); break;
           case 4: readFile(std); break;
           case 5: insertionSort(std);break;

        }


    }while(choice!=7);


}
