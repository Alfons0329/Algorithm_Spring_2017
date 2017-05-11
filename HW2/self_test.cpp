#include "algo_hw2.hpp"
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> test_array(46,-1);
    cout<<"Tree insertion now.....: ";
    for(int i=0;i<test_array.size();i++)
    {
        if((i+1)%3==0)
        {
            Insert(test_array,-999);
        }
    }
    cout<<"\nTest array after insertion result: ";
    for(int i=0;i<test_array.size();i++)
    {
        cout<<test_array[i]<<" ";
    }
    int key_command;
    while(1)
    {
        cout<<"\nDeleteRBT test insert a key to delete, and insertt (-1 to terminate) ";
        cin>>key_command;
        if(key_command==-1)
        {
            break;
        }
        Delete(test_array,key_command);
        cout<<"\nTest array after insertion result: ";
        for(int i=0;i<test_array.size();i++)
        {
            cout<<test_array[i]<<" ";
        }

    }
    cout<<endl;
    while(1)
    {
        cout<<"\nQuery the Order Statistics, find the ith smallest element ,enter i (-1 to terminate)";
        cin>>key_command;
        if(key_command==-1)
        {
            break;
        }
        printf("The %d th smallest element in RBT is %d  ",key_command,Select(test_array,key_command));
    }
    return 0;
}
