    #include <stdio.h>
    #include <pthread.h>
    #include <semaphore.h>
    #include <unistd.h>

    sem_t runway;

    void *aircraft(void *arg){
        int id = *(int*)arg;
        printf("Aircraft A%d is requesting landing...\n", id);
        
        sem_wait(&runway);
        printf("Aircraft A%d has been granted landing permission.\n", id);
        
        printf("Aircraft A%d is landing...(Using Runway)\n", id);
        sleep(2);
        
        printf("Aircraft A%d has landed and released the runway.\n\n", id);
        sem_post(&runway);
        
        return NULL;
    }

    int main() {
        pthread_t planes[3];
        int ids[3] = {1,2,3};
        
        sem_init(&runway, 0, 1);
        
        for(int i = 0; i < 3; i++){
            pthread_create(&planes[i], NULL, aircraft, &ids[i]);
        }
        
        for (int i = 0; i < 3; i++){
            pthread_join(planes[i], NULL);
        }
        
        sem_destroy(&runway);
        
        return 0;
    }