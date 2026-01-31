#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>



void convertion(char* un, double temperature){
  double res;
  double cons  = 1.8; // value of 9/5 for C to F
  double cons_ = 0.55;// value of 5/9 for F to C

  if (strcmp(un,"C")==0 || strcmp(un,"Celsius")==0)
  {
    res = (temperature*cons)+32;
    printf("%.0f°C is %.2f°F\n",temperature, res);

  }else if (strcmp(un,"F")==0 || strcmp(un,"Farenheit")==0)
  {
    res = (temperature-32)*0.55;
    printf("%.0f°F is %.2f°C\n",temperature, res);
  }

}



int main(int argc, char** argv){
  int i;
  int opt;
  double temp;

  char* unity;
  char* unity_;
  char* temp_;

  bool check_unit = false;
  bool check_temp = false;


  opterr = 0;



  for ( i=1;i<argc;i++)
  {
    if (strcmp(argv[i],"-h") == 0 || strcmp(argv[i], "--help") == 0)
    {
      printf("This is the help :)\n");

    }
  }

  while((opt = getopt(argc, argv,"t:u")) != -1)
  {
    switch (opt) 
    {
      case 'u':
        unity = argv[optind];
        if (strcmp(unity,"C") == 0 || strcmp(unity,"Celsius") == 0)
        {
          unity_ = "C";
          check_unit = true;
        }
        else if ((strcmp(unity,"F") == 0 || strcmp(unity,"Farenheit") == 0))
        {
          unity_ = "F";
          check_unit = true;
        }
        else{
          printf("%s is not an option, please retry\n\
For help use -h or --help\n",unity);
          exit(EXIT_FAILURE);
        }
        break;

      case 't':
        temp = atof(optarg);
        if (temp < -273.15 || temp > 212)
        {
          printf("ERROR:\nPlease retry with a value above\
 -273.15°C and under 212°F\n");
        }else{
          check_temp = true;
        }
        break;
    }
  }

  if (check_unit && check_temp)
    convertion(unity_, temp);

  return 0;
}
