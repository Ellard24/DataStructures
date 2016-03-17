#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */

	  //If statements to take care each option

	  if (cmd == 'l')
	  {
		  char filename[60];
		  FILE *fileController;
		  int length = 0;
		  
		  printf("Type the name of the file you want to open.\n");
		  printf("The format is filename.txt. Dont forget the .txt part!\n");
		  fgets(filename, sizeof(filename), stdin);
		  
		  length = strlen(filename);
		  if (filename[length - 1] == '\n')
			  filename[length - 1] = 0;

		  

		  fileController = fopen(filename, "r");

		  loadList(mainList, fileController);

		  fclose(fileController);

		  printf("To-Do List has been loaded");


	  }

	  if (cmd == 's')
	  {
		  char filename[60];
		  FILE *fileController;
		  int length = 0;


		  if (sizeDynArr(mainList) != 0)
		  {
			  printf("Type the name of the file you want to save to. Format is \n");
			  printf("The format is filename.txt. Dont forget the .txt part!\n");
			  fgets(filename, sizeof(filename), stdin);
			  
			  length = strlen(filename);
			  if (filename[length - 1] == '\n')
				  filename[length - 1] = 0;
			  
			  
			  // "W+" is used for creating an empty file for writing
			  fileController = fopen(filename, "w+");
			  saveList(mainList, fileController);
			  fclose(fileController);
			  printf("To-Do List has been saved\n");

		  }
		  else
			  printf("There is no data to save\n");
		  

	  }


	  if (cmd == 'a')
	  {
		  struct Task *newTask;
		  char description[TASK_DESC_SIZE];
		  int priority = 0;

		  printf("Type in a description of the new task\n");
		
		  fgets(description, sizeof(description), stdin);
		  //while (getchar() != '\n');
		  printf("Type in the priority of the new task (0-999)\n");
		  
		  scanf("%d", &priority);
		  while (getchar() != '\n');

		  newTask = createTask(priority, description);
		  addHeap(mainList, newTask, compare);

		  

	  }

	  if (cmd == 'g')
	  {
		  if (sizeDynArr(mainList) != 0)
		  {
			  printf("The first task: %s\n",getMinHeap(mainList));
		  }
		  else
			  printf("List is empty\n");
	  }

	  if (cmd == 'r')
	  {
		  if (sizeDynArr(mainList) != 0)
		  {
			  removeMinHeap(mainList,compare);
		  }
		  else
			  printf("List is empty. Nothing to remove\n");

	  }

	  if (cmd == 'p')
	  {
		  if (sizeDynArr(mainList) != 0)
		  {
			  printList(mainList);
		  }
		  else
			  printf("List is empty. Please Add an item\n");

	  }

	  if (cmd == 'e')
	  {
		  printf("Program is ending\n");
		  break;


	  }

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
