//Shubhayu Shrestha 1001724804

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SortLib.h"

#ifndef SockLib_h
#define SockLib_h

#define MAX_DRAWERS 10

typedef struct
{
    int DrawerID;
    int NumberOfSocks; 
    char SockColor[40];
    int MaxDrawerCapacity; 
}SockDrawer;

//function prototypes 
void SortMySocks(SockDrawer Dresser[]);
void PutAwayMySocks(SockDrawer Dresser[]);
void PutOnMySocks(SockDrawer Dresser[]);


#endif
