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
void find_LCS(int* xarr,int xlen, int ylen,int* carr,vector<vector<int> > prevlist,string& LCS_string)
{
    if(xlen==0||ylen==0)
        return ; //print until one str is end

    if(prevlist[xlen][ylen]==0) //from LU,equal
    {
        LCS_string+=xarr[xlen];
        //cout<<"LCS STRING IS CURRENT NOW "<<LCS_string<<endl;
        find_LCS(xarr,xlen-1,ylen-1,carr,prevlist,LCS_string);
    }
    else if(prevlist[xlen][ylen]==1)//from L side
    {
        find_LCS(xarr,xlen,ylen-1,carr,prevlist,LCS_string);
    }
    else if(prevlist[xlen][ylen]==2)//from U side
    {
        find_LCS(xarr,xlen-1,ylen,carr,prevlist,LCS_string);
    }
}
void LCS(int* xarr, int* yarr, int* carr) //find the length
{
    unsigned int xlen=xarr[0],ylen=yarr[0];

    //(m+1)*(n+1) table
    vector<vector<int> > dplist(xlen, vector<int>(ylen));//2d dp array for character matching increase by one for convenience
    vector<vector<int> > prevlist(xlen, vector<int>(ylen));
    //dplist initialization
	for (int i = 0; i < dplist.size(); i++)
		for (int j = 0; j < dplist[i].size(); j++)
			dplist[i][j] = 0;
    //dp traverse
    for (int i = 1; i < xlen/*was increment by 1, so no equal*/; i++)
        for (int j = 1; j < ylen/*was increment by 1, so no equal*/; j++)
        {

            if (xarr[i] == yarr[j]) //since 0 is as size for both
            {
                dplist[i][j] = dplist[i - 1][j - 1] + 1; //increase by one, the encountered pattern
                prevlist[i][j] = 0; //from LU
            }
            else
            {
                if(dplist[i-1][j] < dplist[i][j-1]) //Non equal, from L
                {
                    dplist[i][j] = dplist[i][j-1];
                    prevlist[i][j]=1; //from L
                }
                else
                {
                    dplist[i][j] = dplist[i-1][j];
                    prevlist[i][j]=2;//fomr U
                }
            }
        }
    int LCS_length =  dplist[xlen-1][ylen-1];
    carr[0] = LCS_length;
    string LCS_string = " ";
    LCS_string[0] = LCS_length;
    find_LCS(xarr,xlen-1, ylen-1, carr, prevlist,LCS_string);
    reverse(LCS_string.begin()+1,LCS_string.end());
    //cout<<"LCS_string ,where the first character is the LCS_length"<<LCS_string;
    for(int i=0;i<LCS_string.length();i++)
    {
        carr[i] = LCS_string[i];
    }
}
