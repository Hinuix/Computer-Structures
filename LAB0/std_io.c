#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if(argc > 1){
    if(strcmp(argv[1], "printf") == 0)
    {
      printf("You entered: %s\n", argv[2]);
    }
    else if(strcmp(argv[1], "fprintf") == 0)
    {
      FILE *file;
      file = fopen("print.txt", "w+\n");
      fprintf(file, "%s", argv[2]);
      fclose(file);
    }
    else if(strcmp(argv[1], "scanf") == 0)
    {
      char str[100];

      printf("Please enter your input: ");
      scanf("%s", str);

      printf("You entered: %s", str);
    }
  }
   exit(1);
}
