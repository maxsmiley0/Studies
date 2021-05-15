//
//  main.cpp
//  threadfuck
//
//  Created by Max Smiley on 5/6/21.
//

#include <stdio.h>
#include <pthread.h>

void* run(void*)
{
    printf("In run \n");
    return NULL;
}

int main(int argc, const char * argv[]) {
    pthread_t thread;
    pthread_create(&thread, NULL, &run, NULL);
    printf("In main\n");
    pthread_join(thread, NULL);
}
