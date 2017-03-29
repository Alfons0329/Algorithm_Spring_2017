// change this to your id
//
// do your homework here
//
//
//all use zero base, it is troublesome while changing between 0 and 1 base
#include <iostream>
#include <algorithm>
static const char* student_id = "0416324" ;
using namespace std;
//for printing data and debugging
void show_cur_heap(int * input_heap,int size)
{
    printf("\nCurrent heap:  ");
    for(int i=0;i<size;i++)
    {
        cout<<input_heap[i]<<" ";
    }
    cout<<endl;
}
void min_heapify(int * input_array, int size, int position)
{
	// I'll give you an array without ordered
	// please adjust the subtree which root is position
	//
	// Example:
	//      input : { 7, 14, 6, 5, 1, 3, 8 } ,7, 2
	//   expected : { 7, 14, 3, 5, 1, 6, 8 }
    int parent_index=position,child_index=parent_index*2+1;
    while(child_index<=size)
    {
        if(child_index+1<=size/*in the range, even the right*/&&input_array[child_index]>input_array[child_index+1])
            child_index++;
        //go to the smaller child
        if(input_array[parent_index]<input_array[child_index])//adjust is done
            return;
        else
        {
            //printf("Swap %d and %d",input_array[parent_index],input_array[child_index]);
            swap(input_array[parent_index],input_array[child_index]);
            parent_index=child_index;
            child_index=parent_index*2+1;
        }
   }
}

void min_heap_build(int * input_array, int size)
{
	// I'll give you an array without ordered
	// please make this whole array as a min-heap tree
	//
	// Example:
	//      input : { 7, 14, 6, 5, 1, 3, 8 } ,7
	//   expected : { 1, 5, 3, 7, 14, 6, 8 }
    for(int i=(size)/2;i>=0;i--)
    {
        min_heapify(input_array,size-1 /*0 base system*/,i);
    }
}

void min_heap_insert(int * input_heap, int size, int key)
{
	// I'll give you an array which is a min heap has one more space
	// (finally value 999 is not a true value)
	// please change the 999 into key
	// and make this array as a min-heap tree
	//
	// Example:
	//      input : { 1, 5, 3, 7, 14, 6, 8, 999 }, 8, 4
	//   expected : { 1, 4, 3, 5, 14, 6, 8 ,7}
    input_heap[size-1]=key;
    for(int i=(size)/2;i>=0;i--)
    {
        min_heapify(input_heap,size-1 /*0 base system*/,i);  //re heapify the array again
    }
}

void min_heap_minimum(int * input_heap, int size, int * output_key)
{
	// I'll give you an array which is a min heap
	// please show the smallest value
	//
	// Example:
	//      input : { 1, 4, 3, 5, 14, 6, 8 ,7} , 8, &output_key
	//   expected : output_key == 1
	*output_key =input_heap[0];
}

void min_heap_extract(int * input_heap, int size, int * output_key)
{
	// I'll give you an array which is a min heap
	// please tell me which is the smallest value
	// and delete that value , then adjust as heap
	// (make the final value 999 as fake)
	//
	// Example:
	//      input : { 1, 4, 3, 5, 14, 6, 8 ,7} , 8, &output_key
	//   expected : { 3, 4, 6, 5, 14, 7, 8, 999} ,output_key == 1
    //new root is 1, so heapify from the leaves till 1

    //if  the given input is ACCIDENTALLY NOT A HEAP!!!!!!!!!!!!! XDDDDDDDDDDD
    //A PREVENTION
    for(int i=(size)/2;i>=0;i--)
    {
        min_heapify(input_heap,size-1 /*0 base system*/,i);
    }
    //A PREVENTION IS ENDED LMAO





    *output_key=input_heap[0];
    swap(input_heap[0],input_heap[size-1]);
    input_heap[size-1]=999;
    //input_heap[size-1]=999;
    for(int i=(size)/2;i>=0;i--)
    {
        min_heapify(input_heap,size-2 /*0 base system 999 as boundary*/,i);
    }
}

void min_heap_sort(int* input_heap, int size)
{
	//
	// you cannot use library sort function!
	//
	// I'll give you an array which is a min heap
	// please sort it
	//
	// Example:
	//      input : { 1, 4, 3, 5, 14, 6, 8 ,7} ,8
	//   expected : { 1, 3, 4, 5, 6, 7, 8, 14}
    int t_size=size;

    //if  the given input is ACCIDENTALLY NOT A HEAP!!!!!!!!!!!!! XDDDDDDDDDDD
    //A PREVENTION
    for(int i=(size)/2;i>=0;i--)
    {
        min_heapify(input_heap,size-1 /*0 base system*/,i);
    }
    //A PREVENTION IS ENDED LMAO


    for(int j=0;t_size>=1;j++)
    {
        swap(input_heap[0],input_heap[t_size-1]);//take the last element and re-min_heapify
        t_size--; //swapping upper bound decrement by 1
        min_heapify(input_heap,t_size-1,0);
    }
    for(int i=0;i<size/2;i++)
    {
        swap(input_heap[i],input_heap[size-i-1]);
    }

}


void min_heap_decrease_key(int * input_heap, int size, int position, int decrease)
{
	// I'll give you an array which is a min heap
	// the position need to be decrease by a value
	// please adjust the result as a min-heap
	//
	// Example:
	//      input : { 1, 4, 3, 5, 14, 6, 8, 7}, 8, 3, 5
	//   expected : { 0, 1, 3, 4, 14, 6, 8, 7}
    input_heap[position]-=decrease;
    for(int i= (size)/2 ;i>=0;i--)
    {
        min_heapify(input_heap,size-1,i);
    }
}
//for self_debugging
