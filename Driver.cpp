#include <iostream>
#include <ctime>

using namespace std;

void printArray(int* ar, int begin, int end)
{
    for(int i = begin; i <= end; i++)
    {
        cout << ar[i] << " ";
    }
    cout<< "\n";
}

void merge(int* ar, int begin1, int begin2, int end2)
{
        cout<<"Beginning merge...\n";   

        //two arrays created to sort
        //unsorted holds the half that needs to be sorted
        //sorted holds the sorted elements
        int unsorted[(end2 - begin1) + 1];
        int sorted[(end2 - begin1) + 1];
        //begin1 will be incremented so we hold its initial value till later
        int holder = begin1;
        
        //fill in unsorted array
        for(int i = begin1; i <= end2; i++)
        {
            unsorted[i] = ar[i];
        }

        //sort the elements from unsorted to sorted
        int val = begin2;
        for(int i = begin1; i <= end2; i++)
        {
            
            if(begin2 > end2)
            {
                sorted[i] = unsorted[begin1];
                begin1++;
            }
            else
            {
                if(unsorted[begin2] < unsorted[begin1])
                {
                    sorted[i] = unsorted[begin2];
                    begin2++;
                }
                else
                {
                    if(begin1 >= val)
                    {
                        sorted[i] = unsorted[begin2];
                        begin2++;
                        val = begin2;
                    }
                    else
                    {
                        sorted[i] = unsorted[begin1];
                        begin1++;
                    }
                }
            }
        }
        //update array using sorted array
        for(int i = holder; i <= end2; i++)
        {
            ar[i] = sorted[i];
        } 
        printArray(ar, 0 , end2);
}

//which portion of the array am I merge sorting?
void mergeSort(int* ar, int begin, int end)
{
    cout<< "Merge Sorting\n";
    printArray(ar, begin, end);
    if(begin != end) //not trivially sorted
    {
        //divide in half and call mergeSort on each half
        int begin1 = begin;
        int end1 = (begin + end) / 2; 
        int begin2 = end1 + 1;
        int end2 = end;
        //call mergeSort on first half
        mergeSort(ar, begin1, end1);

        //call mergeSort on second half
        //will not activate until the above mergeSort is resolved
        mergeSort(ar, begin2, end2); 

        merge(ar, begin1, begin2, end2);
    }
    else
    {
        cout<<"Trivially sorted! Do nothing.\n";
    }
}

int main()
{
    int ar[10] = {10,9,8,7,6,5,4,3,2,1};
    mergeSort(ar, 0 , 9);
    cout << "Sorted Array: ";
    printArray(ar, 0 , 9);

    return 0;
}