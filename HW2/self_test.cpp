#include "algo_hw2.hpp"
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> test_array = {
     46,
     0,48, 5,
     0, 5, 1,
     1,66, 3,
     0, 0, 0,
     0, 0, 0,
     0,50, 1,
     0,79, 1,
    -1,-1,-1,
    -1,-1,-1,
    -1,-1,-1,
    -1,-1,-1,
     0, 0, 0,
     0, 0, 0,
     0, 0, 0,
     0, 0, 0};
    int *test_array_ptr=new int[test_array.size()];

    cout<<"Tree insertion now.....: "<<"Test array size "<<test_array.size();
    for(int i=0;i<test_array.size();i++)
    {
        test_array_ptr[i]=test_array[i];
        if((i+1)%3==0)
        {
            cout<<" Inserting: "<<test_array[i];
            Insert(test_array_ptr,-999);

            cout<<"\nTest array after insertion result: ";
            for(int i=0;i<test_array.size();i++)
            {
                cout<<test_array_ptr[i]<<" ";
            }
        }

    }
    cout<<"\nTest array after insertion DONE FOR ALL result: ";
    for(int i=0;i<test_array.size();i++)
    {
        cout<<test_array_ptr[i]<<" ";
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
        Delete(test_array_ptr,key_command);
        cout<<"\nTest array after insertion result: ";
        for(int i=0;i<test_array.size();i++)
        {
            cout<<test_array_ptr[i]<<" ";
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
        printf("The %d th smallest element in RBT is %d  ",key_command,Select(test_array_ptr,key_command));
    }
    return 0;
}
