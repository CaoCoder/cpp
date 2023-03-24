#include <iostream>
using namespace std;

// Function to partially sort an array so that every 5 is immediately followed by a 6

/*The first while loop iterates through the array, 
and the second while loop swaps after it finds the element to swap.*/
void fix56(int*& arr, int size)
{
    int temp = 0;
    int i = 0;
    while (i < size - 1)
    {
        if (arr[i] == 5 && arr[i + 1] != 6)
        {
            int j = i + 1;
            while (j < size)
            {
                if (arr[j] == 6 && arr[j - 1] != 5)
                {
                    temp = arr[i + 1];
                    arr[i + 1] = arr[j];
                    arr[j] = temp;
                    break;
                }
                j++;
            }
        }
        i++;
    }
}


// Function to print out an array
// Loop through groups of numbers and output
void printArray(int arr[], int size)
{
    int i = 0;
    while (i < size)
    {
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;
}

int main()
{
    int arr1[] = { 1, 5, 1, 4, 6 };
    int* pArr1 = arr1;//Change array name variable
    fix56(pArr1, sizeof(arr1) / sizeof(arr1[0]));
    printArray(arr1, sizeof(arr1) / sizeof(arr1[0]));

    int arr2[] = { 1, 5, 1, 4, 4, 5, 1, 6, 6 };
    int* pArr2 = arr2;
    fix56(pArr2, sizeof(arr2) / sizeof(arr2[0]));
    printArray(arr2, sizeof(arr2) / sizeof(arr2[0]));

    int arr3[] = { 5, 2, 6, 2, 4 };
    int* pArr3 = arr3;
    fix56(pArr3, sizeof(arr3) / sizeof(arr3[0]));
    printArray(arr3, sizeof(arr3) / sizeof(arr3[0]));
}