
#include <stdio.h>
#include <fstream>

int main()
    {
        FILE *fp;
        int count = 0;
        char data[50];
        fp = fopen("example.txt","r");
        // fputs("whtats wrong man please minde your own business\n",fp);
        // fscanf(fp,"%s",data);        // puts(char(*data));
        // puts(data);
        while(fscanf(fp,"%s",data))
            {
                // if(*data!='\n')
                   
                    puts(data);
                // puts(char(*data));
                count++;
                // if(count>20)
                    // break;
            }
        
        // puts(data);
        fclose(fp);
        return 0;
    }
