#include "main.h"

struct timeval GetTimeStamp()  {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv;
}

signed long now_us() {
 struct timeval tv= GetTimeStamp(); // Calculate time
 return 1000000 * tv.tv_sec + tv.tv_usec; // Store time in microseconds
}

unsigned int randr(unsigned int min, unsigned int max){
    double scaled = (double)rand()/RAND_MAX;

    return (max - min +1)*scaled + min;
}

int main (int argc, char **argv) {
    setbuf(stdout, NULL);   //Disable buffering on stdout by using or will be problem with sockets and output

    while (1) {
        printf("US %li\n", now_us());

        printf ("GRAPH %li\n", randr(0, 100));
        usleep(10000);
    }

    return 0;
}