#ifndef NMEA_PARSER_H
#define NMEA_PARSER_H

#include <stdlib.h>

unsigned int strLength(char* data) {
    unsigned int i = 0;
    while (1) {
        if (data[i] == '\0') {
            break;
        }
        i++;
    }
    return i;
}

unsigned int checksum(char* data) {
    unsigned int n = strLength(data), checksum = 0;
    for (unsigned int i = 1; i < n - 3; i++) {
        checksum ^= data[i];
    }
    return checksum;
}

char* parseNMEA(char* data, int index) {
    unsigned int n = strLength(data), lowerIndex, higherIndex, comma = 0;
    int lowerFlag = 0, higherFlag = 0;
    for (int i = 0; i < n; i++) {
        if (comma == index && lowerFlag == 0) {
            lowerIndex = i;
            lowerFlag++;
        }
        if (comma == (index + 1)) {
            higherIndex = i - 1;
            higherFlag++;
            break;
        }
        if (data[i] == ',' || data[i] == '*') {
            comma++;
        }
    }
    // if at the end higher flag still zero, fill it with string length
    if (higherFlag == 0) {
        higherIndex = n;
    }
    // if the data is a parity data (last index), print the '*' tag too
    if (lowerIndex != 0 && data[lowerIndex - 1] == '*') {
        lowerIndex--;
    }
    // if at the end higher flag and lower flag not found, return NULL
    // usually it is 
    if (higherFlag == 0 && lowerFlag == 0) {
        return NULL;
    }
    char* res = (char*)malloc(sizeof(char));
    int i = 0;
    for (int iData = lowerIndex; iData < higherIndex; iData++) {
        res[i] = data[iData];
        i++;
    }
    res[i] = '\0';
    return res;
}

#endif
