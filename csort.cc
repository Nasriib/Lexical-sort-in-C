//Include file
//
#include "sort.h"

//Function
//
int compare (const void *a, const void *b);

//Main Program
//
int main(int argc, char **argv) {
  //Error message
  //
  if(argc < 2 || argc > 2){
    printf("Invalid arguments\n");
  }
  //File to be sorted is argv[1]
  //
  char *filename = argv[1];
  //Opening and reading file
  //
  FILE *file = fopen(filename, "r");
  //Error if file is null
  //
  if (file == NULL) {
    fprintf(stderr, "Could not open file %s\n", filename);
    return EXIT_FAILURE;
  }
  //Alloctaing memory due to the large size of the file
  //
  int size = 16;
  char **lines = (char **) calloc(size, sizeof(char *));
  //Error if memory is already allocated in that specific block
  //
  if (lines == NULL){
    fprintf(stderr, "Could not allocate the requested block of memory\n");
    return EXIT_FAILURE;
  }
 //Storing all the buffer memory
  //
  char *buffer = (char *) calloc(MAX_LINE_LENGTH + 1, sizeof(char));
  //Error checking to prevent seg fault
  //
  if (buffer == NULL) {
    fprintf(stderr, "Could not allocate the requested block of memory\n");
    return EXIT_FAILURE;
  }
  //Counting lines
  //
  int counter = 0;
  //Reading lines into buffer
  //
  while(fgets(buffer, MAX_LINE_LENGTH + 1, file) != NULL) {
    //Measuring string length
    //
    int length = strlen(buffer);
    if (buffer[length - 1] == '\n') {
      //Replacing blank new line with '\0', and '\0' already included into length
      //
      buffer[length - 1] = '\0';
    } else {
      length++;
    }
     //Counter can be increased
    //
    if (counter + 1 == size){
      size *= 2;
      lines = (char **) realloc(lines, size*sizeof(char *));
      //Error checking
      //
      if (lines == NULL) {
        fprintf(stderr, "Could not allocate the requested block of memory\n");
 return EXIT_FAILURE;
      }
    }

    //Allocating space for the lines
    //
    lines[counter] = (char *) malloc(length*sizeof(char));
    strcpy(lines[counter], buffer);

    counter++;
  }
  //Using qsort function from stdlib.h to sort the file
  //
  qsort(lines, counter, sizeof(char *), compare);

  int i;
  for (i = 0; i < counter; i++) {
    puts(lines[i]);
  }
  //Exits the program if it's successful
  //
  return EXIT_SUCCESS;
}
