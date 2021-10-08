#include <iostream>
#include<cmath>

using namespace std;

class heap
{
private:
    int arr[10];
    int last;

public:
    heap()
    {
        last = -1;
    }
    void insert(int n);
    void removeMax();
    void displayMax();
    int getsize();
    bool isEmpty();

    int parent(int x);
    int leftchild(int x);
    int rightchild(int x);
};

//NOTE:
//For an element at index i, left child is at 2i+1, right child is at 2i+2, parent at ([i+1/2]-1)

int heap::rightchild(int i) //returns rc if exists.
{
    return ((2 * i + 2) <= last) ? (2 * i + 2) : -1;
}

int heap::leftchild(int i) //return lc if exists
{
    return ((2 * i + 1) <= last) ? (2 * i + 1) : -1;
}

int heap::parent(int i) //return parent
{
    int ans = ((i + 1) / 2) - 1;
    return ans;
}

bool heap:: isEmpty()
{
    return (last==-1)?true:false;
}

void heap::insert(int n) //insert data
{
    if (last >= 9)
    {
        cout << "Overflow :(";
        return;
    }

    int save = last;
    last++;
    arr[last] = n;
    while (last >= 0)
    {
        int j = parent(last);
        if (arr[last] > arr[j])
        {
            int k = arr[j];
            arr[j] = arr[last];
            arr[last] = k;
        }

        if (!last)
            break;

        last = j;
    }
    last = save + 1;
}

void heap::removeMax() //removeMax the greatest value
{
    if (last == 0)
    {        
        last--;
        return;
    }
    //Single element

    if(last==-1)
    {
    cout << INT32_MIN;
    return;
    }
    // EMPTY HEAP

    arr[0] = arr[last];
    last--;
    //removeMaxping the top element(root element) and bringing in the last element at this position

    int flag = 1;
    int index = 0;

    //we will now implement a loop to swap values with children until the heap is a max heap
    while (flag)
    {
        int saveindex=index;

        if (index > last)
            break;
        //Prevent Overflow of iterator

        if (leftchild(index) == -1 && rightchild(index) == -1)
            break;
        //End of tree as both childs missing

        else if (rightchild(index) == -1) //if only left child exists
        {
            int x = leftchild(index);
            if (arr[x] > arr[index])
            //swap if value at child greater than parent
                {
                    int k = arr[x];
                    arr[x] = arr[index];
                    arr[index] = k;
                    index=x;
                }
        }

        else if (leftchild(index) == -1) //if only right child exists
        {
            int x = rightchild(index);
            if (arr[x] > arr[index])
            //swap if value at child greater than parent
                {
                    int k = arr[x];
                    arr[x] = arr[index];
                    arr[index] = k;
                    index=x;
                }
        }

        else //When both the children exist
        {
            int k;

            if(arr[leftchild(index)]>arr[rightchild(index)])
            k=leftchild(index);
            else
            k=rightchild(index);
            //determining the greater child

            if (arr[k] > arr[index])
            //swap if value at child greater than parent
                {
                    int j = arr[k];
                    arr[k] = arr[index];
                    arr[index] = j;
                    index=k;
                    //set index at child
                }


        }

        if(saveindex==index) // if no swaps done,max heap achieved. Exit loop
        {
            // cout<<"\nNo Swaps Done. Hence Max Heap Achieved."<<endl;
            flag=0;
        }
    }
}


void heap::displayMax()
{
    cout<<arr[0];
}

int heap::getsize()
{
    return last+1;
}

int main()
{
    heap maxheap;

    //inserting data into the heap
    maxheap.insert(1);
    maxheap.insert(2);
    maxheap.insert(3);
    maxheap.insert(8);
    maxheap.insert(5);
    maxheap.insert(6);
    maxheap.insert(7);

    //display maximum data present
    maxheap.displayMax();

    //removeMaxping the maximum data out from the heap
    maxheap.removeMax();

    //geeting size of heap
    cout<<maxheap.getsize()<<endl;

    //empty check
    cout<<maxheap.isEmpty();
}