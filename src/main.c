#include <stdio.h>
#include <stdlib.h>

void find_end_and_print(char* str){

      int i = 0;
      for(; str[i] != '\n'; ++i);
      printf("%d", i);
      for(i-=1; i >= 0; --i){
        printf("%c", str[i]);
      }
      printf("\n");
}

int main(int argv, char** argc){
  // maximum line length allowed: 100 characters
  char buf[100];
  if(argv > 1){
    printf("Reading from file!\n\n");
    FILE* fp = fopen(argc[1], "r");

    if(!fp){
      printf("File does not exist\n");
      exit(EXIT_FAILURE);
    }

    while(!feof(fp)){
      if(fgets(buf, sizeof(buf), fp) == NULL){
        break;
      }
      find_end_and_print(buf);
    }
    fclose(fp);
  }
  else{
    printf("Reading from stdin\n");
    while(1){
      if(fgets(buf, 100, stdin) == NULL){
        exit(EXIT_FAILURE);
      }

      find_end_and_print(buf);

    }
  }
}
