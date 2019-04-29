#include <stdio.h> //Functions for input & output.
#include <stdlib.h> //Functions for general functions.
#include <string.h>  //Functions for control arrays of characters.

void UPPERCASE(char t[]); //function prototype for lowercase to uppercase
void caesarcipherencrypt(char inputt[], char rk); //function prototype for encrypting a text by rotation cipher
void caesarcipherdecrypt(char inputt1[], char rk); //function prototype for decrypting a encrypted text by rotation cipher
void subsitutionencrypt(char inputt2[], char sub[]); //function prototype for encrypting a text by subsitution cipher
void subsitutiondecrypt(char inputt3[], char sub2[]); //function prototype for decrypting a encrypted text by rotation cipher


int main(){
    FILE *way; //pointer to file which control menu
    FILE *input; //pointer to file which types the text for encryption and decryption
    FILE *keyforcc; //pointer to file which is key for rotation chiper
    FILE *subkey; //pointer to file which is the key for subsitution chiper
    FILE *text; //pointer to file which is
// provide a menu for users to choose which function they want to use by printf(...)
    printf("Please choose the number below for encryption or decryption by enter number in menuselect.txt\n");
    printf("1. Encrypt to a rotation cipher.\n");
    printf("2. decrypt a rotiation cipher.\n");
    printf("3. Encrypt to a subsitution cipher.\n");
    printf("4. decrypt a subsitution cipher.\n");
    
    way = fopen("menuselect.txt", "r"); 
    int w;
    fscanf(way, "%d", &w);
//switch statment for different cases
    switch(w){
        case(1):  //case1 will run when 1 was typed in menuselect.txt
        printf("you chose 1.\n");
        keyforcc = fopen("keyforcc.txt","r");  //open the file keyforcc.txt and read
        int rk;                                //intialise rk which is short form of rotation key
        fscanf(keyforcc, "%d", &rk);           //scan the file keyforcc and save as rk as a number        
        char inputt[1024];                     //inputt is array of char which save each character in inputt, 1024 is to minimise the character 
        text = fopen("input.txt", "r");        //read input.txt and save as text
        fscanf(text, "%[^\n]s", inputt);            
        UPPERCASE(inputt);                     //change all lowercases to uppercase
        
        caesarcipherencrypt(inputt, rk);        //run the prototype function
        break;
        
        case(2):        //case2 will run when 2 was typed in menuselect.txt
        printf("you chose 2.\n");
        keyforcc = fopen("keyforcc.txt", "r");  //open the file of keyforcc.txt and read and save for keyforcc
        fscanf(keyforcc, "%d", &rk);
        char inputt1[1023];
        input = fopen("input.txt", "r");
        fscanf(input, "%[^\n]s", inputt1);
        UPPERCASE(inputt1);
        caesarcipherdecrypt(inputt1, rk);
        
        break;
        
        case(3):
        printf("you chose 3.\n");
        subkey = fopen("subkey.txt", "r");
        char sub[26];
        fscanf(subkey, "%[^\n]s", sub);
        char inputt2[1024];
        text = fopen("input.txt", "r");
        fscanf(text, "%[^\n]s", inputt2);
        UPPERCASE(sub);
        UPPERCASE(inputt2);
        subsitutionencrypt(inputt2, sub);
        break;
        
        case(4):
        printf("you chose 4.\n");
        subkey = fopen("subkey.txt", "r");
        char sub2[26];
        fscanf(subkey, "%[^\n]s", sub2);
        char inputt3[1024];
        input = fopen("input.txt", "r");
        fscanf(input, "%[^\n]s", inputt3);
        
        UPPERCASE(sub2);
        UPPERCASE(inputt3);
        subsitutiondecrypt(inputt3, sub2);
        break;
        
        default:
        printf("wrong Number!!\n");
    }
    fclose(way);
    return 0;
}
void UPPERCASE(char t[])
{
    int i=0;
    int l;
    l = strlen (t);
    while(i < l){
        if((t[i]<123) && (t[i]>96)){
            t[i] = t[i] -32;
        }
        i++;
        }
        printf("the text is changed to UPPERCASE text: %s\n", t);
    }
    
void caesarcipherencrypt(char inputt[], char rk){
    FILE *output;
    output = fopen("output.txt", "w");
    char word = 1;
    int l;
    l = strlen(inputt);
    int i = 0;
    printf("text: %s \n key: %d\n the encrypted text:\n", inputt, rk);
    
    while(i < l){
        if((inputt[i]>=65) && (inputt[i]<=90 - rk)){
            word = inputt[i] + rk;
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;
        }
        else if ((inputt[i] > 90 - rk) && (inputt[i] <= 90)){
            word = inputt[i] + rk -26;
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;
        }
        else if(inputt[i] == 32){
            printf(" ");
            fprintf(output, " ");
            i++;
        }
        else{
            word = inputt[i];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;
        }   
    } fclose(output);      
}
void caesarcipherdecrypt(char inputt1[], char rk){
    FILE *output;
    output = fopen("output.txt","w");
    int l;
    l = strlen(inputt1);
    int i=0;
    char word = 1;
    printf("text: %s \n key: %d \n the decrypted text;\n", inputt1, rk);
    while(i<l){
        if((inputt1[i] >= 65) && (inputt1[i] <= 64 + rk)){
            word = inputt1[i] + (26-rk);
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;
        }
        else if((inputt1[i]<=90)&&(inputt1[i]>64+rk)){
            word = inputt1[i] - rk;
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;
        }
       else if(inputt1[i] == 32){
            printf(" ");
            fprintf(output, " ");
            i++;
        }
        else{
            word = inputt1[i];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;
        }   
    }

fclose(output);}
void subsitutionencrypt(char inputt2[], char sub[]){
    FILE *output;
    output = fopen("output.txt","w");
    printf("\n text: %s\n key:%s\n ", inputt2, sub);
    int l;
    int i = 0;
    char word = 1;
    l = strlen(inputt2);
    printf("Encrypted text:\n ");
    while (i < l){
        if(inputt2[i] == 'A'){
            word = sub[0];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
        else if (inputt2[i] == 'B'){
            word = sub[1];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
        else if (inputt2[i] == 'C'){
            word = sub[2];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
        else if (inputt2[i] == 'D'){
            word = sub[3];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
        else if (inputt2[i] == 'E'){
            word = sub[4];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
        else if (inputt2[i] == 'F'){
            word = sub[5];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
        else if (inputt2[i] == 'G'){
            word = sub[6];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
        else if (inputt2[i] == 'H'){
            word = sub[7];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'I'){
            word = sub[8];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
        else if (inputt2[i] == 'J'){
            word = sub[9];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'K'){
            word = sub[10];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'L'){
            word = sub[11];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'M'){
            word = sub[12];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'N'){
            word = sub[13];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'O'){
            word = sub[14];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'P'){
            word = sub[15];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'Q'){
            word = sub[16];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'R'){
            word = sub[17];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'S'){
            word = sub[18];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'T'){
            word = sub[19];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'U'){
            word = sub[20];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'V'){
            word = sub[21];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'W'){
            word = sub[22];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'X'){
            word = sub[23];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'Y'){
            word = sub[24];
            printf("%c", word);
            fprintf(output, "%c", word);
            i++;}
         else if (inputt2[i] == 'Z'){
            word = sub[25];
            fprintf(output, "%c", word);
            printf("%c", word);
            i++;}
        else if (inputt2[i] == 32){
            printf(" ");
            i++;}
        else{ word = inputt2[i];
        printf("%c", word);
        i++;}
       
        }
        fclose(output);
        }
void subsitutiondecrypt(char inputt3[], char sub2[]){
    printf("key: %s\ntext before decrypted:\n %s \n", sub2, inputt3);
    FILE *output;
    output = fopen("output.txt","w");
    int i = 0;
    int length;
    char word;
    length = strlen(inputt3);
    printf("Decrypted text:\n");
    while (i <= length) {
    if (inputt3[i] == sub2[0]){
        printf("A");
        fprintf(output, "A");
        i++;}
    else if (inputt3[i] == sub2[1]){
        printf("B");
        fprintf(output, "B");
        i++;}
    else if (inputt3[i] == sub2[2]){
        printf("C");
        fprintf(output, "C");
        i++;}
    else if (inputt3[i] == sub2[3]){
        printf("D");
        fprintf(output, "D");
        i++;}
    else if (inputt3[i] == sub2[4]){
        printf("E");
        fprintf(output, "E");
        i++;}
    else if (inputt3[i] == sub2[5]){
        printf("F");
        fprintf(output, "F");
        i++;}
    else if (inputt3[i] == sub2[6]){
        printf("G");
        fprintf(output, "G");
        i++;}
    else if (inputt3[i] == sub2[7]){
        printf("H");
        fprintf(output, "H");
        i++;}
    else if (inputt3[i] == sub2[8]){
        printf("I");
        fprintf(output, "I");
        i++;}
    else if (inputt3[i] == sub2[9]){
        printf("J");
        fprintf(output, "J");
        i++;}
    else if (inputt3[i] == sub2[10]){
        printf("K");
        fprintf(output, "K");
        i++;}
    else if (inputt3[i] == sub2[11]){
        printf("L");
        fprintf(output, "L");
        i++;}
    else if (inputt3[i] == sub2[12]){
        printf("M");
        fprintf(output, "M");
        i++;}
    else if (inputt3[i] == sub2[13]){
        printf("N");
        fprintf(output, "N");
        i++;}
    else if (inputt3[i] == sub2[14]){
        printf("O");
        fprintf(output, "O");
        i++;}
    else if (inputt3[i] == sub2[15]){
        printf("P");
        fprintf(output, "P");
        i++;}
    else if (inputt3[i] == sub2[16]){
        printf("Q");
        fprintf(output, "Q");
        i++;}
    else if (inputt3[i] == sub2[17]){
        printf("R");
        fprintf(output, "R");
        i++;}
    else if (inputt3[i] == sub2[18]){
        printf("S");
        fprintf(output, "S");
        i++;}
    else if (inputt3[i] == sub2[19]){
        printf("T");
        fprintf(output, "T");
        i++;}
    else if (inputt3[i] == sub2[20]){
        printf("U");
        fprintf(output, "U");
        i++;}
    else if (inputt3[i] == sub2[21]){
        printf("V");
        fprintf(output, "V");
        i++;}
    else if (inputt3[i] == sub2[22]){
        printf("W");
        fprintf(output, "W");
        i++;}
    else if (inputt3[i] == sub2[23]){
        printf("X");
        fprintf(output, "X");
        i++;}
    else if (inputt3[i] == sub2[24]){
        printf("Y");
        fprintf(output, "Y");
        i++;}
    else if (inputt3[i] == sub2[25]){
        printf("Z");
        fprintf(output, "Z");
        i++;}
    else if(inputt3[i] == 32){
        printf(" ");
        fprintf(output, " ");
        i++;}
    else{
        word = inputt3[i];
        printf("%c", word);
        fprintf(output, "%c", word);
        i++;}  
    }
 fclose(output);}
 
    

    
