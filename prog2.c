#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_NUM_LINES      10
#define MAX_LINE_LEN           1000

static void cat(FILE* f) {
  int c ;
  while(EOF != (c = getc(f))) {
    if (EOF == putchar(c)) {
     // perror("cat");
      return;
    }
  }
  if (ferror(f)) {
   // perror("cat");
    return;
  }
}


int main(int argc, char *argv[])
{
char buf [1024]={0};
int i;  

int num_line =10;

if (argc==1) return cat(stdin), 0;
  for(i=1; i<argc; i++) {
    if (!strcmp("-", argv[i])) {
      //cat(stdin);
      continue;
    }
    FILE *f = fopen(argv[i], "r");
    if (!f) {
      //perror("cat");
      continue;
    }
    cat(f);
    fclose(f);
  }

if (argc > 1){

num_line = atoi(argv[1]);
if (num_line >=0){

fprintf (stderr ,"must enter -n\n");
return EXIT_FAILURE;
}

num_line=-num_line;
}





sprintf(buf,"tail %s %s" ,argv[1] , argv[2]);
system (buf);
  return 0;
  }



