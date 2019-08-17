#include<stdio.h>
#include<stdlib.h>

typedef struct Heap_node
{
    void* data;
    int key;
}heap_node;

typedef struct Heap{
	heap_node* arr;
	int n;
}heap;

void initializeMinHeap(heap* h,int size)
{
	h->arr = (heap_node*) calloc (sizeof(heap_node*),size);
	h->n = -1;
}

void minHeapifyUp(heap* h,int i)
{
    if(i==0)
        return;
    else if(h->arr[i].key < h->arr[(i-1)/2].key)
    {
        heap_node temp = h->arr[i];
        h->arr[i] = h->arr[(i-1)/2];
        h->arr[(i-1)/2] = temp;
        minHeapifyUp(h,(i-1)/2);
    }
}

void minHeapifyDown(heap* h,int i)
{
    int smallIndex = i;
    if((2*i)>=h->n)
        return;
    else
    {

        if(h->arr[2*i+1].key < h->arr[smallIndex].key)
            smallIndex = 2*i+1;
        if(h->arr[2*i+2].key < h->arr[smallIndex].key)
            smallIndex = 2*i+2;
        if(smallIndex == i)
            return;
        else{
            heap_node temp = h->arr[i];
            h->arr[i] =  h->arr[smallIndex];
            h->arr[smallIndex] = temp;
            minHeapifyDown(h,smallIndex);
        }

    }
}

void* extractMin(heap *h)
{
    void* temp = h->arr[0].data;
    if(h->n==-1)
        return NULL;
    else{
        h->arr[0] = h->arr[h->n];
        --(h->n);
        minHeapifyDown(h,0);
    }
    return temp;
}

void minHeapInsert(heap *h,void* data,int key)
{
    ++(h->n);
    h->arr[h->n].data = data;
    h->arr[h->n].key = key;
    minHeapifyUp(h,h->n);
}

void* getMin(heap *h)
{
    if(h->n==-1)
        return NULL;
    else
        return h->arr[0].data;
}

void decreaseKey(heap *h, int index, int newKey)
{
    h->arr[index].key = newKey;
    if(index!=0 && arr[index].key<arr[(index-1)/2])
        minHeapifyUp(h,index);
    else
        minHeapifyDown(h,index);
}

void minHeapDelete(heap *h, int index)
{
    h->arr[index] = h->arr[h->n];
    --(h->n);
    minHeapifyDown(h,index);
}

int main()
{
    heap h;
    initializeMinHeap(&h,10000);
    return 0;
}
