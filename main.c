#include <stdio.h>
#include <unistd.h>



int main(int argc, char** argv){
  int i;
  int opt;

  for ( i=1;i<argc;i++)
  {
    printf("%s\n", argv[i]);
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
