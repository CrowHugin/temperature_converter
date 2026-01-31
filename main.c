#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char** argv){
  int i;
  int opt;

  opterr = 0;



  for ( i=1;i<argc;i++)
  {
    if (strcmp(argv[i],"-h") == 0 || strcmp(argv[i], "--help") == 0)
    {
      printf("This is the help :)\n");

    }
  }

  while((opt = getopt(argc, argv,"tu")) != -1)
  {
    switch (opt) 
    {
      case 'u':
        printf("u\n");
        break;

      case 't':
        printf("t\n");
        break;
    }
  }

  return 0;
}
