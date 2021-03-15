#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "students.h"


int main()
{
   int size=8;
   student *s;
   s=create_student(size);
   printMenu(s);
   print_list(s);
   free_list(s);

    return 0;
}


