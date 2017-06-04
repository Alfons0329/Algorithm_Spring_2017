#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
// change this to your id
using namespace std;
static const char* student_id = "0416324" ;

// do not edit prototype
void LCS(int *, int*, int*);
void getLCS(int* , int* , int*  ,vector<vector <int> >,string& );
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
    string LCS_string;
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //**************************************************************************************************//
    vector<vector<int> > dplist(xlen, vector<int>(ylen));//2d dp array for character matching increase by one for convenience
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
    //*************I HAVE ONLY ONE TABLE NOW*************I HAVE ONLY ONE TABLE NOW**********************//
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
                dplist[i][j] = dplist[i - 1][j - 1] + 1; //increase by one, the encountered pattern
            else
                dplist[i][j] = max(dplist[i][j-1],dplist[i-1][j]);
        }
    getLCS(xarr,yarr,carr,dplist,LCS_string);
    reverse(LCS_string.begin(),LCS_string.end());
    for(int i=0;i<LCS_string.length();i++)
    {
        carr[i] = LCS_string[i];
    }
}
void getLCS(int* xarr, int* yarr, int* carr ,vector<vector <int> >dplist,string& LCS_string)
{
    unsigned int xlen=xarr[0],ylen=yarr[0];
    int current_row=xlen-1,current_col=ylen-1;
    while(dplist[current_row][current_col])
    {
        if(dplist[current_row][current_col]==dplist[current_row-1][current_col])//from up
        {
            current_row--;
        }
        else if(dplist[current_row][current_col]==dplist[current_row][current_col-1])//from left
        {
            current_col--;
        }
        else if(dplist[current_row][current_col]==dplist[current_row-1][current_col-1]+1)//from left up
        {
            LCS_string+=(char)xarr[current_row];
            current_row--;
            current_col--;
        }
    }
}
