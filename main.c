
#include <stdio.h>

int main()
{
    FILE * input;
    char fn[256];
    scanf("%s", fn);
    input = fopen(fn, "r");
    
    while(feof(input) == 0){
        char c;
        
        fscanf(input, "%c", &c);
        
        doEncryption(&c);
        
        printf("%c\n", c);
    }
}
