#ifndef STUDENTS_H_INCLUDED
#define STUDENTS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"



typedef struct studNode{
   int id;
   char *name;
   char *surname;
}studNode;


typedef struct student{
   int stunum;
   int size;
   studNode *start;

}student;


extern struct student* create_student(int size);
extern void add_student(student* std, int temp_id, char name[], char surname[]);
extern void free_list(student* std);
extern void get_student_data(student *std) ;
extern int id_removing(void);
extern void remove_student(student * std, int id_to_remove );
extern void print_list(student *std);
extern void readFile(student * std);
extern void printMenu(student * std);

extern void insertionSort(student *std);
extern void studentQSort(student *std);
extern int compare(const void *a, const void *b);

#endif // STUDENTS_H_INCLUDED
