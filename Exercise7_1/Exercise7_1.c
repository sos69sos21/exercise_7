#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int delay(double timeToDelay);

int main(void){

    printf("Enter the number of seconds you would like to delay.\n");
    printf(">");
    double delayValue;
    scanf("%lf",&delayValue);

    printf("Waiting for your delay, standby...\n");
    int result = delay(delayValue);
    if(result){
        printf("Your delay is complete. Thank you...\n");
        return 1;
    }

    printf("ERROR: Your system is broke, processor time unavailable, failure is imminent...\n");
    return -1;
}

// returns -1 if processor time unavailable / representable.
// returns 1 when delay time is met.
int delay(double timeToDelay){
    clock_t start = clock();

    if(start == -1){
        return -1;
    }

    while(1){
        clock_t end = clock();
        if(end == -1){
            return -1;
        }

        double timeDelayed = (double)(end - start)/CLOCKS_PER_SEC;
        if(timeDelayed >= timeToDelay){
            return 1;
        }
    }
}