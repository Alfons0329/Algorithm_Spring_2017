#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
// change this to your id
using namespace std;
static const char* student_id = "0416324" ;

// do not edit prototype
void LCS(int *, int*, int*);

// X,Y are input strings, C is answer string
//
// data structure :
// length of array X is m+1, length of array Y is n+1, length of array C is m+n
// X[0] = m+1, Y[0] = n+1,
// all element of C are "-1"
// other datas are in [0,255] means the symble in ASCII or ANSI table


// you only allow declare a table with size (m+1)*(n+1)
//
// do your homework here
//
void LCS(int* xarr, int* yarr, int* carr) //find the length
{
    unsigned int xlen=xarr[0],ylen=yarr[0],LCS_length=0;
    string LCS_string = " ";

    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //(m+1)*(n+1) table ***********************I HAVE ONLY ONE TABLE NOW**********************************
    //**************************************************************************************************//
    vector<vector<int> > dplist(xlen, vector<int>(ylen));//2d dp array for character matching increase by one for convenience
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
	for (int i = 0; i < dplist.size(); i++)
		for (int j = 0; j < dplist[i].size(); j++)
			dplist[i][j] = 0;
    //dp traverse
    for (int i = 1; i < xlen/*was increment by 1, so no equal*/; i++)
        for (int j = 1; j < ylen/*was increment by 1, so no equal*/; j++)
        {

            if (xarr[i] == yarr[j]) //since 0 is as size for both
            {
                //printf("Find equal  %c and i is now %d j is now %d ",xarr[i],i,j);
                dplist[i][j] = dplist[i - 1][j - 1] + 1; //increase by one, the encountered pattern

                if(dplist[i][j]>LCS_length)
                {
                    LCS_length=dplist[i][j];
                    LCS_string+=(char)xarr[i];
                    //printf("LCS_length is now being updated to %c  and i is now %d j is now %d \n",xarr[i],i,j);
                }
            }
            else
            {
                if(dplist[i-1][j] < dplist[i][j-1]) //Non equal, from L
                {
                    dplist[i][j] = dplist[i][j-1];
                }
                else
                {
                    dplist[i][j] = dplist[i-1][j];
                }
            }
        }
    /*int LCS_length =  dplist[xlen-1][ylen-1];*/
    carr[0] = LCS_length;
    //cout<<"LCS is "<<LCS_string<<"      with its length "<<LCS_length<<endl;
    for(int i=1;i<LCS_string.length();i++)
    {
        carr[i] = LCS_string[i];
    }
}
