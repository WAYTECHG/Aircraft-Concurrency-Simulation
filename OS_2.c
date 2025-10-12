#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_IN_AIRSPACE 3
#define NUM_AIRCRAFT 5

sem_t air_space;
pthread_mutex_t runway;
pthread_mutex_t print_mutex;

void* aircraft(void* arg){
    int id = *(int*)arg;
    int slots;
    
    printf("[A%d] requesting approach clearance...\n", id);
    sem_wait(&air_space);
    
    pthread_mutex_lock(&print_mutex);
    sem_getvalue(&air_space, &slots);
    printf("[A%d] entered controlled airspace (%d slots remain)\n", id, slots);
    pthread_mutex_unlock(&print_mutex);
    
    pthread_mutex_lock(&runway);
    printf("[A%d] cleared for landing...\n", id);
    sleep(2);
    printf("[A%d] Landed and vacating runway\n", id);
    pthread_mutex_unlock(&runway);
    
    sem_post(&air_space);
    
    pthread_mutex_lock(&print_mutex);
    sem_getvalue(&air_space, &slots);
    printf("[A%d] exited airspace           (%d slots remain)\n\n", id, slots);
    pthread_mutex_unlock(&print_mutex);
    
    return NULL;
}

int main(){
    pthread_t planes[NUM_AIRCRAFT];
    int ids[5] = {1, 2, 3, 4, 5};
    
    sem_init(&air_space, 0, MAX_IN_AIRSPACE);
    pthread_mutex_init(&runway, NULL);
    
    for (int i = 0; i < NUM_AIRCRAFT; i++){
        pthread_create(&planes[i], NULL, aircraft, &ids[i]);
    }
    
    for (int i = 0; i < NUM_AIRCRAFT; i++){
        pthread_join(planes[i], NULL);
    }
    
    sem_destroy(&air_space);
    pthread_mutex_destroy(&runway);
    
    return 0;
}