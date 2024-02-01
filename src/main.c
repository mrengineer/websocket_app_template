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

//Random for graph
unsigned int randr(unsigned int min, unsigned int max){
    double scaled = (double)rand()/RAND_MAX;

    return (max - min +1)*scaled + min;
}

int main (int argc, char **argv) {

    char input[32];         //stdin input commands from websocketd
    input[0] = 0;
    char ch;

    setbuf(stdout, NULL);   //Disable buffering on stdout by using or will be problem with sockets and output

    printf("CONSOLE Starting...\n");
    printf("CONSOLE Done\n");

    while (1) {

        printf("US %li\n", now_us());

        printf ("GRAPH %i\n", randr(0, 100));

        int c = read(STDIN_FILENO, &ch, 1);
        printf("%i\n", c);
        while(read(STDIN_FILENO+1, &ch, 1) > 0) {
            if (ch == '\n') {
                printf("CONSOLE input='%s'\n", input);
                input[0] = 0;
            } else strncat(input, &ch, 1);
        }

        printf("CONSOLE LOOP...\n");

        usleep(100000);
    }

    return 0;
}