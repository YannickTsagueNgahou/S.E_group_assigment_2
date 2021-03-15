#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "sort.h"
#include "students.h"

void insertionSort(student *std)
{
    //student *std;
    int i,j;
    studNode * tempNode = (studNode *)malloc(sizeof (studNode *));
    if (tempNode==NULL) printf("Error in memory allocation of tempNode\n");

    for(j=1; j< std->stunum; j++)
    {
        tempNode->id = std->start[j].id;
        tempNode->name = strdup(std->start[j].name);
        tempNode->surname = strdup(std->start[j].surname);
        for(i=j-1; i>=0 && (std->start[i].id>tempNode->id); i--)
        {
            std->start[i+1].id = std->start[i].id;
            std->start[i+1].name = std->start[i].name;
            std->start[i+1].surname = std->start[i].surname;
        }
            std->start[i+1].id = tempNode->id;
            std->start[i+1].name = strdup(tempNode->name);
            std->start[i+1].surname = strdup(tempNode->surname);
    }
    free(tempNode);
}


int compare(const void *a, const void *b)
{
    return ((studNode*)a)->id - ((studNode *)b)->id;
}

void studentQSort(student * std)
{
    qsort(std->start, std->stunum, sizeof(studNode),compare);
}
