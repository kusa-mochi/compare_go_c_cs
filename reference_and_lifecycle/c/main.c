#include "stdio.h"
#include "pthread.h"

void *TestRoutine(void *p) {
    int testVar = 123;
    printf("TestRoutine - testVar:%d\n", testVar);
    int *ip = (int *)p;
    ip = &testVar;
}

int main(void) {
    pthread_t pthread;
    int *testPointer = NULL;
    pthread_create(&pthread, NULL, &TestRoutine, testPointer);
    pthread_join(pthread, NULL);
    printf("main - testVar:%d\n", *testPointer);
}
