#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,string argv[])
{
    if(argc!=4)
    {
        printf(" Usage:./caeser key");
        return 1;
    }
    for(int i=0;i<strlen(argv[3]);i++)
    {
        if(!isdigit(argv[3][i] ))
        {
             printf(" Usage:./caeser key");
        return 1;
        }
        int k=atoi( argv[3]);
        string plaintext=get_string("plain text:");
        printf("cipher text:");

        for(int j=0;j<strlen(plaintext);j++)
        {
           if(isupper(plaintext[j])) 
           {
                printf("%c",(plaintext[j]-65+k)%26+65);
            }
           else if(islower(plaintext[j]))
           {
            printf("%c",(plaintext[j]-97+k)%26+97);
           }
           else{
            printf("%c",plaintext[j]);
           }
        
        }
    }
}
