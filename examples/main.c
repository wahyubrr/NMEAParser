#include "../NMEAParser.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Write C code here
    char data[6][100] = {
      "$GPGSV,8,1,25,21,44,141,47,15,14,049,44,6,31,255,46,3,25,280,44*75",
      "$GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A",
      "$GNGSA,A,3,21,5,29,25,12,10,26,2,,,,,1.2,0.7,1.0*27",
      "$GPGGA,172814.0,3723.46587704,N,12202.26957864,W,2,6,1.2,18.893,M,-25.669,M,2.0,0031*4F",
      "$GPGLL,3953.88008971,N,10506.75318910,W,034138.00,A,D*7A",
      "$GPVTG,140.88,T,,M,8.04,N,14.89,K,D*05"
    };
    // char gsv[] = "$GPGSV,8,1,25,21,44,141,47,15,14,049,44,6,31,255,46,3,25,280,44*75";
    // char rmc[] = "$GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A";
    // char gsa[] = "$GNGSA,A,3,21,5,29,25,12,10,26,2,,,,,1.2,0.7,1.0*27";
    // char gga[] = "$GPGGA,172814.0,3723.46587704,N,12202.26957864,W,2,6,1.2,18.893,M,-25.669,M,2.0,0031*4F";
    // char gll[] = "$GPGLL,3953.88008971,N,10506.75318910,W,034138.00,A,D*7A";
    // char vtg[] = "$GPVTG,140.88,T,,M,8.04,N,14.89,K,D*05";
    
    // print all raw data
    for (int i = 0; i < 6; i++) {
        printf("%s\n", data[i]);
    }
    printf("\n");
    
    //parsing
    for (int j = 0; j < 6; j++) {
        printf("%s\nParsed data: \n", data[j]);
        char* res = parseNMEA(data[j], 0);
        int i = 1;
        while (res != NULL) {
            printf("result: %s\n", res);
            res = parseNMEA(data[j], i++);
        }
        printf("checksum: %02x\n\n", checksum(data[j]));
    }
    // free(res);
    
    return 0;
}
