#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int guess,n,i;
    printf("enter number of users to play this game");
    scanf("%d",&n);
    int number[n];
    int ngusses[n];
    for(i=0;i<n;i++)
    {
    srand(time(0));
    number[i]=rand()%100+1;
    ngusses[i]=1;

    printf("user %d:enter a number to guess ordinal number",i+1);
    scanf("%d",&guess);
    while(guess!=number[i])
    {
    if(guess<number[i])
    {
        printf("your guess is less than the number please enter larger number\n");

    }
    else if(guess>number[i])
    {
        printf("your guess is grater than the number please enter lower number\n");

    }
    scanf("%d",&guess);
    ngusses[i]++;
    }
    }
    int min = ngusses[0];
    int winnerindex[n]; 
    int winner_count = 0;

    for(i = 0; i < n; i++) {
        if(ngusses[i] < min) {
            min = ngusses[i];
            winnerindex[0] = i;
            winner_count = 1;
        } else if (ngusses[i] == min) {
            winnerindex[winner_count++] = i;
        }
    }
    
    printf("Winners: ");
    for (i = 0; i < winner_count; i++) {
        printf("User %d ", winnerindex[i] + 1);
    }
    printf("made it in %d guesses which is less than everyone else.\n", min);
    return 0;
}