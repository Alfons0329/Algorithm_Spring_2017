#include "algo_hw3.hpp"
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int* s1,s2,s3;
    int s1_length,s2_length,s3_length,tmp;
    while(1)
    {
        cout<<"Enter string s1 length,and s2 length (enter -1 to terminate) ";
        cin>>s1_length>>s2_length;
        if(s1_length<0 || s2_length<0)
            break;
        s3_length=s1_length+s2_length+1;
        s1_length++;
        s2+length++;
        s1=new int[s1_length];
        s2=new int[s2_length];
        s1[0]=s1_length;
        s2[0]=s2_length;
        cout<<"Enter string s1: ";
        for(int i=1;i<=s1_length;i++)
        {
            cin>>tmp;
            s1[i]=tmp;
        }
        cout<<"Enter string s2: ";
        for(int i=1;i<=s2_length;i++)
        {
            cin>>tmp;
            s2[i]=tmp;
        }
        for(int i=0;i<s3_length;i++)
            s3[i]=-1;

        LCS(s1,s2,s3);
    }
    return 0;
}
