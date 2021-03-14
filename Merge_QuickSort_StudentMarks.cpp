/*
Write a program to sort an array of N integers (given as input via a text file) using -
a. Merge Sort
b. Quick Sort
 Sort the list of student records given in Students.csv (based on the total marks) using the two sorting algorithms. Count the number of recursive calls in each case.
*/


#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
fstream fio;

//Merge SORT

void merge(vector <vector<int>> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1][6];
    int R[n2][6];

    // Copy data to temp arrays L[] and R[]
    for(int i = 0; i < n1; i++)
    {
        for(int j=0;j<6;j++)
        {
            L[i][j]=arr[l + i][j] ;

        }
    }

    for(int i = 0; i < n2; i++)
    {
        for(int j=0;j<6;j++)
        {
            R[i][j]=arr[m + 1 + i][j] ;

        }
    }


    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i][5] >= R[j][5])
        {
            arr[k][5]=L[i][5];
            arr[k][0]=L[i][0];
            arr[k][1]=L[i][1];
            arr[k][2]=L[i][2];
            arr[k][3]=L[i][3];
            arr[k][4]=L[i][4];
            i++;
        }
        else
        {
            arr[k][5]=R[j][5];
            arr[k][0]=R[j][0];
            arr[k][1]=R[j][1];
            arr[k][2]=R[j][2];
            arr[k][3]=R[j][3];
            arr[k][4]=R[j][4];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any


    for(;i<n1;i++,k++)
    {
        arr[k][0]=L[i][0];
        arr[k][1]=L[i][1];
        arr[k][2]=L[i][2];
        arr[k][3]=L[i][3];
        arr[k][4]=L[i][4];
        arr[k][5]=L[i][5];
    }
    /*while (i < n1)
    {

        i++;
        k++;
    }*/

    // Copy the remaining elements of
    // R[], if there are any


    for(;j<n2;j++,k++)
    {
        arr[k][0]=R[j][0];
        arr[k][1]=R[j][1];
        arr[k][2]=R[j][2];
        arr[k][3]=R[j][3];
        arr[k][4]=R[j][4];
        arr[k][5]=R[j][5];
    }
    /*while (j < n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }*/
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(vector <vector<int>> &arr, int l, int h)
{
    if (l < h)
    {

        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int m = l + (h - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);

        merge(arr, l, m, h);
    }
}



//QUICK SORT

// A utility function to swap two elements
void swap(int** a, int** b)
{
    int t = **a;
    **a = **b;
    **b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (vector <vector<int>> &arr, int low, int high)
{
    int pivot = arr[high][5]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j][5] > pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i][5], arr[j][5]);
            swap(arr[i][0], arr[j][0]);
            swap(arr[i][1], arr[j][1]);
            swap(arr[i][2], arr[j][2]);
            swap(arr[i][3], arr[j][3]);
            swap(arr[i][4], arr[j][4]);
        }
    }
    swap(arr[i + 1][5], arr[high][5]);
    swap(arr[i + 1][0], arr[high][0]);
    swap(arr[i + 1][1], arr[high][1]);
    swap(arr[i + 1][2], arr[high][2]);
    swap(arr[i + 1][3], arr[high][3]);
    swap(arr[i + 1][4], arr[high][4]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */

void quickSort(vector <vector<int>> &arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void menu()
{
   cout<<"MENU OPTIONS TO SORT"<<endl;
    cout<<"1\tQuick Sort\n";
    cout<<"2\tMerge Sort\n";
    cout<<"3\tExit\n"<<endl;

}



int main()
{
    vector <vector<int>>stuff;
    vector <int> row;
    int count=0;
    fio.open("Students.csv", ios::app | ios::out | ios::in);

    if(fio.fail())
    {
        cout<<"\nFile could not be opened\n";
        return 0;
    }

    string line,data;
    while(fio.good())
    {
        row.clear();
        fio>>line;
        if(fio.eof())
            break;
        stringstream s(line);
        while (getline(s,data, ','))
            {
            row.push_back(stoi(data));
        }

        row.push_back((row[1]+row[2]+row[3]+row[4]));


        count++;

        vector <int> temp;

            for(int j=0;j<row.size();j++)
            {
                temp.push_back(row[j]);
            }
            stuff.push_back(temp);
            temp.clear();
    }


    cout<<"Total number of records data \t"<<count<<endl<<endl;
    fio.close();



    int ch;
    menu();
    cout<<endl<<"Which Sort do you want:\t";
    cin>>ch;
    cout<<endl;
    switch(ch)
    {
        case 1:
            quickSort(stuff,0,(stuff.size()-1));
            /*cout<<endl<<"Press any key to continue."<<endl;
            getch();
            sleep(2000);    //Waits the system for 2s
            system("cls");*/
            break;
        case 2:
            mergeSort(stuff,0,(stuff.size()-1));
            /*cout<<endl<<"Press any key to continue."<<endl;
            getch();
            sleep(2000);    //Waits the system for 2s
            system("cls");*/
            break;

        case 3:
            return 0;

        default:
            cout<<"Invalid format \t";

    }

    fstream fio1;
    fio1.open("StudentsSorting.csv", ios::trunc | ios::out | ios::in);
     fio1<<"Roll No"<<","
                <<"M1"<<","
                <<"M2"<<","
                <<"M3"<<","
                <<"M4"<<","
                <<"Total"<<"\n";
    for(int i=0;i<stuff.size();i++)
    {
        for(int j=0;j<stuff[i].size();j++)
        {
        fio1<<stuff[i][j]<<",";
        }
        fio1<<"\n";

    }

    cout<<endl<<"Output CSV File has been created\n\n";

    return 0;
}
