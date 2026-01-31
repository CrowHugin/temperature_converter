#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char** argv){
  int i;
  int opt;

  char* unity;

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
        unity = argv[optind];
        if (strcmp(unity,"C") == 0 || strcmp(unity,"Celsius") == 0)
        {
          break;
        }
        else{
          printf("%s is not an option, please retry\n\
For help use -h or --help\n",unity);
          exit(EXIT_FAILURE);
        }
        break;

      case 't':
        printf("t\n");
        break;
    }
  }

  return 0;
}
