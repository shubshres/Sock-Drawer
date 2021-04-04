//Shubhayu Shrestha 1001724804
#include "DresserLib.h"

void DisplayMyDresser(SockDrawer Dresser[])
{
    //initializing variable
    int dresserNum = 0;

    printf("\nMy Dresser\n");

    while(dresserNum < NumDrawers)
    {
        //displaying the drawer number
        printf("\nDrawer %d", (Dresser[dresserNum].DrawerID));
        
        //displaying the contents -- how many socks there are
        printf("\n\tContents : %d %s socks", Dresser[dresserNum].NumberOfSocks, Dresser[dresserNum].SockColor); 
        
        //displaying the maximum capacity of the dresser for each drawer
        printf("\n\tCapacity : %d socks", Dresser[dresserNum].MaxDrawerCapacity);
        
        //incrementing the dresser number variable so we can see the next drawer
        dresserNum++;
    }
}
