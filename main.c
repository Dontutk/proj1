
#include <stdio.h>

int main()
{
    FILE * input;
    int k;
    input = fopen("input.txt", "r");
    scanf("%d", &k);
    
    
    printf("The encrypted text (Rotation Cipher) is : \n");
    
    while(feof(input) == 0){
        char c;
        
        fscanf(input, "%c", &c);
        if(c >= 97 && c<=122)
        c = c + k;
        if (c>122 )
        c = c - 26;
        if(c >= 65 && c<=90)
        c = c + k;
        if (c>90 && c <= 90 + k)
        c = c - 26;
        printf("%c", c);
    }

        
        
        printf("The key is: %d ", k);
    

}
