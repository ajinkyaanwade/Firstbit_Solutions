#include <stdio.h>
#include <string.h>
#define size 20
typedef struct task
{
  int taskID;
  char description[100];
  char status[20];
} task;

void addTask(task[], int, int *);
void displayTask(task[], int);
void updateTask(task[], int);

void main()
{
  int choice = -1;
  task tasks[size];
  int count = 0;
  while (choice != 0)
  {
    printf("1.Add new task\n");
    printf("2.update task\n");
    printf("3.Display all tasks\n");
    printf("0.exit\n");
    printf("Enter choice\n");
    scanf("%d", &choice);
    fflush(stdin);
    if (choice == 1)
    {
      addTask(tasks, size, &count);
    }
    else if (choice == 2)
    {
      updateTask(tasks, count);
    }
    else if (choice == 3)
    {
      displayTask(tasks, count);
    }
    else if (choice == 0)
    {
      printf("exiting program\n");
    }
    else
    {
      printf("invalid input\n");
    }
  }
}

void addTask(task tasks[], int s, int *count)
{
  if (*count >= s)
  {
    printf("Task list is full\n");
    return;
  }
  printf("enter task id\n");
  scanf("%d", &tasks[*count].taskID);
  fflush(stdin);
  printf("enter description\n");
  scanf("%[^\n]s", tasks[*count].description);
  fflush(stdin);
  printf("enter status\n");
  scanf("%s", tasks[*count].status);
  fflush(stdin);
  (*count)++;
  printf("task added successfully\n");
}

void displayTask(task tasks[], int count)
{
  if (count == 0)
  {
    printf("empty tasks list\n");
    return;
  }
  printf("------tasks------\n");
  for (int i = 0; i < count; i++)
  {
    printf("Task Id=%d\n", tasks[i].taskID);
    printf("Task description : %s\n", tasks[i].description);
    printf("Task status : %s\n", tasks[i].status);
  }
}

void updateTask(task tasks[], int count)
{
  if (count == 0)
  {
    printf("empty list\n");
    return;
  }
  int id, found = 0;
  printf("enter id you want to update\n");
  scanf("%d", &id);
  fflush(stdin);
  for (int i = 0; i < count; i++)
  {
    if (tasks[i].taskID == id)
    {
      found = 1;
      printf("enter new task id\n");
      scanf("%d", &tasks[i].taskID);
      fflush(stdin);
      printf("enter new description\n");
      scanf("%[^\n]s", tasks[i].description);
      fflush(stdin);
      printf("enter new status(completed or pending)\n");
      scanf("%s", tasks[i].status);
      fflush(stdin);
      printf("Task updated successfully\n");
      break;
    }
  }
  if (found == 0)
  {
    printf("id not found\n");
  }
}
/*
1.Add new task
2.update task
3.Display all tasks
0.exit
Enter choice
1
enter task id
121
enter description
complete book management system project
enter status
pending
task added successfully
1.Add new task
2.update task
3.Display all tasks
0.exit
Enter choice
3
------tasks------
Task Id=121
Task description : complete book management system project
Task status : pending
1.Add new task
2.update task
3.Display all tasks
0.exit
Enter choice
2
enter id you want to update
121
enter new task id
122
enter new description
complete project till monday
enter new status(completed or pending)
completed
Task updated successfully
1.Add new task
2.update task
3.Display all tasks
0.exit
Enter choice
3
------tasks------
Task Id=122
Task description : complete project till monday
Task status : completed
1.Add new task
2.update task
3.Display all tasks
0.exit
Enter choice
0
exiting program
*/