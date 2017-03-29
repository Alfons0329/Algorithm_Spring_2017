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
                int input[100] = { 533, 1890, 27, 1913, 1598, 669, 1955, 1497, 1856, 1105, 429, 942, 291, 513, 228, 1581, 1520, 1213, 1967, 1743, 1887, 906, 34, 1305, 998, 1212, 886, 1005, 295, 1194, 163, 605, 1041, 847, 49, 188, 1482, 1508, 591, 1667, 1889, 410, 1949, 293, 581, 1050, 246, 1593, 721, 806, 19, 491, 486, 1423, 553, 803, 1332, 221, 236, 1349, 1730, 1874, 512, 795, 508, 1142, 1220, 1030, 1458, 597, 255, 271, 1051, 249, 832, 355, 575, 1657, 584, 1676, 316, 1107, 113, 955, 1448, 1013, 1353, 1613, 1813, 1872, 1171, 1098, 1326, 1337, 1198, 1063, 133, 195, 800, 730};
                cout<<"\nInput pos for root:";
                cin>>pos;
                min_heapify(input,sizeof(input) / sizeof(int),pos);
                show_cur_heap(input,sizeof(input) / sizeof(int));
                break;
            }
            case 2:
            {
                int input[20] = {167, 991, 1569, 1620, 1053, 669, 1410, 1772, 274, 1496, 741, 95, 1668, 1647, 114, 1943, 1883, 545, 1859, 807};
                min_heap_build(input,sizeof(input) / sizeof(int));
                show_cur_heap(input,sizeof(input) / sizeof(int));
                break;
            }
            case 3:
            {
                int input[21] = {167, 991, 1569, 1620, 1053, 669, 1410, 1772, 274, 1496, 741, 95, 1668, 1647, 114, 1943, 1883, 545, 1859, 807, 999 };
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
                int input[50] = {1068, 341, 1157, 1311, 1330, 96, 733, 1994, 1434, 330, 1226, 547, 456, 731, 1925, 1821, 1356, 1796, 849, 790, 1550, 279, 904, 258, 860, 111, 1052, 1829, 940, 1543, 1802, 1960, 487, 1279, 287, 1385, 1470, 1690, 608, 1872, 502, 492, 1047, 1524, 819, 1565, 1167, 205, 1034, 1460 };
                min_heap_sort(input, 50);
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
