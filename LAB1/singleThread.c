#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int singleThread(char* file, char* needle);

  int main(int argc, char *argv[]){
    
    (void)argc; // helps out with the error for unused
    /**
     * Setting up the argv's, for the file name and the needles
     **/
    char *needle = argv[2];//finding the "needle"
    char *file = argv[1]; //file name
    char *seccondNeedle = argv[4];
    char *seccondFile = argv[3];

    /**
     * Setting up the counters for the file's and the words that we are looking for
     * */
    int firstword_counter = singleThread(file, needle);
    int seccondWord_counter = singleThread(seccondFile, seccondNeedle); 

    /**
     * printing out the counters
     * **/
    printf("%d\n", firstword_counter);
    printf("%d\n", seccondWord_counter);

    fflush(stdout);
    exit(EXIT_SUCCESS);
  }

int singleThread(char* file, char* needle){

  // open file 
  FILE *fileName; 
  fileName = fopen(file, "r"); //opening the files
  if(fileName == NULL){
    exit(EXIT_FAILURE); // if the file is not found exit
  }
  int counter = 0;
  char* helper = NULL;
  size_t len = 0;
  ssize_t read;
  char *buf = NULL;
 while((read = getline(&buf, &len, fileName)) != -1){
   helper = strstr(buf, needle);
   while(helper != NULL){
       counter ++;
       strcpy(buf,( helper + strlen(needle)));
       helper = strstr(buf, needle);
       }
        } 
  fclose(fileName); // close file
  return counter;
  exit(EXIT_SUCCESS);
}
