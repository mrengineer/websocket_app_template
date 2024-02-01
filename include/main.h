
#include <iio/iio.h>
#include <iio/iio-debug.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <malloc.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>



//Program state machine
enum STATE {
    IDLE, 
    GAINS_ADJUSTING, 
    CALIBRATION, 
    PULSE_WAITING,
    PULSE,
    FAILURE
};


void set_device_state (enum STATE s);
void get_device_state(void);