#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int main(int argc, char* argv[]){

  int counter = 0;  
  char helper = NULL;
  FILE *fileName;
  size_t length = 0;
  ssize_t read = 0;

  char *buf;
  char *needle = argv[2]; // setting the string as the needle point "find this"
  
  //opening file
  fileName = fopen(argv[1], "r"); //assigning argv[1] to the file name that inputed
  if(fileName == NULL){
    printf("No file found %s", argv[1]);
    exit(EXIT_FAILURE); // if the file is not found exit 
  }
  //while loop to parse throuhg file and finde the "needle" assigned in argv[2]
  while((read = getline(&buf, &length, fileName))  != -1){
    helper = strstr(buf, needle);
    if(helper != NULL){
      counter++; // if the needle is found its added to the counter
    }
  }
  fclose(fileName);
  printf("%d\n", counter);//print the count
  exit(EXIT_SUCCESS);
}
