#include "algo_hw3.hpp"
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int* s1;
    int* s2;
    int* s3;
    string str1,str2;
    int s1_length,s2_length,s3_length,tmp;
    while(1)
    {

        cout<<"Enter string s1 length,and s2 length (enter -1 to terminate) ";
        cin>>s1_length>>s2_length;
        if(s1_length<0 || s2_length<0)
            break;
        s3_length=s1_length+s2_length+1;
        s1=new int[s1_length+1];//for s1[0] for size
        s2=new int[s2_length+1];//for s2[0] for size
        s3=new int[s3_length];

        s1[0]=s1_length;
        s2[0]=s2_length;
        //cout<<"Enter string s1 and s2 :";
        //cin>>str1>>str2;
        cout<<"(Debug test) str2 in ptr s2 is :";
        /*for(int i=0;i<s3_length;i++)
            s3[i]=-1;*/

        for(int i=1;i<=s1_length;i++)
            s1[i]=str1[i-1];
        cout<<456;
        /*cout<<"(Debug test) str1 in ptr s1 is with length"<<s1_length<<endl;
        for(int i=0;i<=s1_length;i++)
            cout<<s1[i]<<" AND I IS NOW "<<i<<"   ";*/



        for(int i=1;i<=s2_length;i++)
            s2[i]=str2[i-1];

        cout<<789;
        for(int i=0;i<=s2_length;i++)
            cout<<s2[i]<<" ";

        LCS(s1,s2,s3);
        str1.clear();
        str2.clear();

        delete s1;
        delete s2;
        delete s3;
    }
    return 0;
}
