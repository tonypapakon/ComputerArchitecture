    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    int main()
    {

        //random generator//
        srand(time(NULL));   
        int r = rand();
       
        printf("My random number is %d:/",r);
        return 0;
    }
