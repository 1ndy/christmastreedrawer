#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void cat(char fn[]) {
  FILE *f = fopen(fn, "r");
  char c;
  do {
    c = getc(f);
    putchar(c);
  } while(c != EOF);
  putchar('\n');
  fclose(f);
  return;
}

int main(int argc, char *argv[]) {
  char red[] = "\033[0;31m";
  char blue[] = "\033[0;34m";
  char green[] = "\033[0;32m";
  char brown[] = "\033[0;33m";
  char yellow[] = "\033[1;33m";
  char white[] = "\033[1;37m";
  srand(time(NULL));
  int i,j,r;

  int height = 43;//atoi(argv[1]);
  int max_width = 2 * height + 1;
  int spaces = max_width / 2;
  spaces += 10;
  int stars = 1;
  int stump_height = (height / 5)-2;
  int stump_width = max_width / 7;
  int stump_indent = (max_width - stump_width) / 2;
  FILE *output;
  char filename[] = ".treetmp";
  getchar();
  while(1) {
    output = fopen(".treetmp","w");
    //srand(time(NULL));
    stars = 1;
    spaces = max_width / 2;
    //print the branches
    while(stars < max_width) {
      for(i = 0; i < spaces; i++) {
        printf(" ");
      }
      for(i = 0; i < stars; i++) {
        if(stars % 8 == 3) {
          printf("%s*%s", yellow, white);
        } else {
          r = (int)(rand()%20 + 1);
          //printf("r=%d\n", r);
          if(r == 9)
            printf("%s@%s", red, white);
          else if(r == 10)
            printf("%s#%s", blue, white);
          else
            printf("%s*%s", green, white);
        }
      }
      stars += 2;
      spaces -= 1;
      printf("\n");
    }
    //print the stump
    for(i = 0; i < stump_height; i++) {
      for(j = 0; j < stump_indent; j++) {
        printf(" ");
      }
      for(j = 0; j < stump_width; j++) {
        printf("%s#%s", brown, white);
      }
      printf("\n");
    }
    //sleep for a little while
    usleep(1300000);
    //getchar();
  }
  return 0;
}
