#include <bits/stdc++.h>
#include "algo_hw1.hpp"
/*Revisied from TA's */
using namespace std;
int main()
{

    cout<<"Test key 1:min_heapify with pos 2:min_heapify the whole structure \n 3:insert something 4:show the minium"
    <<" 5:extract minium and delete it 6:heapsort 7:decrease the key at pos i and re-heapify it\n";
    int control;
    while(cin>>control)
    {
        int pos,key;
        fflush(stdin);
        switch(control)
        {
            case 1:
            {
                int input[7] = { 7, 14, 6, 5, 1, 3, 8 };
                cout<<"\nInput pos for root:";
                cin>>pos;
                min_heapify(input,sizeof(input) / sizeof(int),pos);
                show_cur_heap(input,sizeof(input) / sizeof(int));
                break;
            }
            case 2:
            {
                int input[7] = { 7, 14, 6, 5, 1, 3, 8 };
                min_heap_build(input,sizeof(input) / sizeof(int));
                show_cur_heap(input,sizeof(input) / sizeof(int));
                break;
            }
            case 3:
            {
                int input[8] = { 1, 5, 3, 7, 14, 6, 8 ,999 };
                min_heap_insert(input, sizeof(input) / sizeof(int), 4);
                show_cur_heap(input,sizeof(input) / sizeof(int));
                break;
            }
            case 4:
            {
                int input[8] = { 1, 4, 3, 5, 14, 6, 8 ,7 };
                int expected;
                min_heap_minimum(input, sizeof(input) / sizeof(int), &expected);
                printf("\nThe minium is %d",expected);
                show_cur_heap(input,sizeof(input) / sizeof(int));
                break;
            }
            case 5:
            {
                int input[8] = { 1, 4, 3, 5, 14, 6, 8 ,7 };
                int expected_out;

                min_heap_extract(input, sizeof(input) / sizeof(int), &expected_out);
                printf("\nThe minium is %d and to be deleted",expected_out);
                show_cur_heap(input,sizeof(input) / sizeof(int));
                break;
            }
            case 6:
            {
                int input[8] = { 1, 4, 3, 5, 14, 6, 8 ,7 };
                min_heap_sort(input, sizeof(input) / sizeof(int));
                printf("\nAfter the heap_sort");
                show_cur_heap(input,sizeof(input) / sizeof(int));
                break;
            }
            case 7:
            {
                int input[8] = { 1, 4, 3, 5, 14, 6, 8 ,7 };
                min_heap_decrease_key(input, sizeof(input) / sizeof(int), 3, 5);
                show_cur_heap(input,sizeof(input) / sizeof(int));
                break;
            }
        }
    }

    return 0;
}
