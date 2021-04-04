//Shubhayu Shrestha 1001724804
#include "SockLib.h"
#include "DrawerLib.h"


void SortMySocks(SockDrawer Dresser[])
{
    //initizalizing choice variable
    int choice; 

    //creating array of function pointers
    int (*PtrArray[])(const void *a, const void *b) = {DrawerIDCompare, NumberOfSocksCompare, MaxCapacityCompare, SockColorCompare};

    //printing the menu
    printf("\nDo you want to sort by..\n\n");
    printf("0. Change my mind - don't want to sort\n");  
    printf("1. Drawer ID?\n");  
    printf("2. Number of socks in drawer?\n");  
    printf("3. Max capacity of the drawers?\n");  
    printf("4. Sock color\n\n");  

    do
    {
        //entering the action choice
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n\n"); 
    }while(!((choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4)));

    if(choice == 0)
    {
       //printing out this statement if the user does not want to organize their sock drawer
       printf("\n\nYour sock drawer is a mess!\n\n");
    }
    else
    {
        //doing qsort
        qsort(Dresser, NumDrawers, sizeof(SockDrawer), *PtrArray[choice-1]); 
    }
}

void PutAwayMySocks(SockDrawer Dresser[])
{
    //initializing variables
    int drawerChoice; 
    int numOfSocks; 
    int totalSocks; 

    //printing that print statement so the user knows what they are doing after they enter the getdrawer function 
    printf("\nWhich drawer are you putting the socks into?  ");

    //the first thing this function does is ask the user to enter the drawer, in which that returned integer will now be store into a local variable
    drawerChoice = GetDrawer(Dresser);

    //asking the user to enter how many socks they are putting away
    printf("\nHow many socks are you putting away?  ");

    //asking the user to enter the number of socks and will be stored into a local numOfSocks variable
    scanf("%d", &numOfSocks);
    printf("\n\n");

    //finding the total socks
    totalSocks = numOfSocks + Dresser[drawerChoice].NumberOfSocks; 

    //seeing if those socks will all fit in the drawer, if not we will print out how many fell
    if(totalSocks > Dresser[drawerChoice].MaxDrawerCapacity)
    {
        printf("\n%d socks fit in the drawer and %d fell on the floor\n\n", 
            (Dresser[drawerChoice].MaxDrawerCapacity - 
            Dresser[drawerChoice].NumberOfSocks), 
            (totalSocks - Dresser[drawerChoice].MaxDrawerCapacity)); 
    }
    else
    {
        //if they fit fine we will just add the socks normally
        Dresser[drawerChoice].NumberOfSocks += numOfSocks; 
    }
} 


void PutOnMySocks(SockDrawer Dresser[])
{
    //initializing local variables
    int drawer; 
    int numOfSocks; 
    int totalSocks; 

    //printing that print statement so the user knows what they are doing after they enter the getdrawer function 
    printf("\nWhich drawer do you want to get the socks from?  ");

    //the first thing this function does is ask the user to enter the drawer, in which that returned integer will now be store into a local variable
    drawer = GetDrawer(Dresser);

    //asking the user how many sock they are taking out and holding that input into a local int variable
    printf("\nHow many socks are you getting out?  ");
    scanf("%d", &numOfSocks);
    printf("\n\n");

    //finding the total socks
    totalSocks = Dresser[drawer].NumberOfSocks - numOfSocks; 
    
    //seeing if the user has that many socks and if the user takes out too many then we will print out this error
    if(totalSocks < 0)
    {
        printf("\nYou do not have that many socks!! You only get %d socks.", Dresser[drawer].NumberOfSocks);
        Dresser[drawer].NumberOfSocks = 0; 
    }    
    else
    {
        //make the total socks the new number of socks in the droor
        Dresser[drawer].NumberOfSocks = totalSocks;
    }
}
