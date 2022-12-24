#include<ctype.h>
#include<cs50.h>
#include<stdio.h>
#include<string.h>

int POINTS[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
int compute_score(string word);
int main(void)
{
    //get input from the user
    string word1=get_string("player1:");
    string word2=get_string("player2:");

    //score both words
    int score1=compute_score(word1);
    int score2=compute_score(word2);
//TODO print the winner
if (score1>score2)
{
    printf("%s\n","player1 wins");
}
else if(score2>score1)
{
    printf("%s\n","player2 wins");
}
else
{
    printf("%s\n","tie");
    }
}
int compute_score(string word)
{
int score=0;
int len=strlen(word);
for(int i=0;i<len;i++)
{
    if(isupper(word[i]))
    {
        score+=POINTS[word[i]-65];
    }
    else if(islower(word[i]))
    {
        score+=POINTS[word[i]-97];
    }
}
return score;
}
