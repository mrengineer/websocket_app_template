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


void set_term_quiet_input(){
  struct termios tc;
  tcgetattr(0, &tc);
  tc.c_lflag &= ~(ICANON | ECHO);
  tc.c_cc[VMIN] = 0;
  tc.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &tc);
}

int main (void){ //(int argc, char **argv) {

    char input[32];         //stdin input commands from websocketd
    input[0] = 0;
    char ch;

    struct pollfd pfd = { .fd = 0, .events = POLLIN };
    set_term_quiet_input();

    setbuf(stdout, NULL);   //Disable buffering on stdout by using or will be problem with sockets and output

    printf("CONSOLE Starting...\n");
    printf("CONSOLE Done\n");

    while (1) {

        printf("US %li\n", now_us());
        printf ("GRAPH %i\n", randr(0, 100));


        if (poll(&pfd, 1, 0)>0) {
            int c = getchar();
            ch = (char)c;
            if (ch == '\n') {
                printf("CONSOLE input='%s'\n", input);
                input[0] = 0;
            } else strncat(input, &ch, 1);
        }        

        usleep(10000);
    }

    return 0;
}