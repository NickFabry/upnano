// Copied from https://stackoverflow.com/questions/16465702/using-shell-bsd-date-command-for-conversion-to-nanoseconds
// Thank you, ghoti!
//
// To compile, just run "$ make upnano" in the directory where upnano.c is. 

#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

#include <mach/mach_time.h>

int main(void)
{
        uint64_t t = mach_absolute_time();

        // Get ratio between mach_absolute_time units and nanoseconds.
        mach_timebase_info_data_t data;
        mach_timebase_info(&data);

        // Convert to nanoseconds.
        t *= data.numer;
        t /= data.denom;

        printf("%" PRIu64 "\n", t);

        return 0;
}