/*
Write a program that sorts a list of names and roll numbers on a file in alphabetical order using Quicksort and write the names and corresponding roll numbers onto a new file.
 Use Binary Search to allow the user to search for a name and display the corresponding roll number. 
 Implement both Iterative and Recursive variations of the Binary Search algorithm.
*/

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;


fstream fio,fio1;



//QUICK SORT
void swap(string &a, string &b) //// A utility function to swap two elements
{
    string temp;
    temp.swap(a);
    a.swap(b);
    b.swap(temp);
}

int partition (vector <vector<string>> &arr, int low, int high)
{
    string pivot = arr[high][0];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j][0] < pivot)
        {
            i++;
            swap(arr[i][1], arr[j][1]);
            swap(arr[i][0], arr[j][0]);
            }
    }
    swap(arr[i + 1][1], arr[high][1]);
    swap(arr[i + 1][0], arr[high][0]);
    return (i + 1);
}

void quickSort(vector <vector<string>> &arr, int low, int high)
{
    if (low < high)
    {
    /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



//Binary Search Iterative


int binarySearchIterative(vector <vector<string>> &arr, int l, int r, string x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m][0] == x)
            {
                cout<<"Search Found:\n";
                cout<<"Name:\t"<<arr[m][0]<<endl;
                cout<<"Roll:\t"<<arr[m][1]<<endl;
               return m;
            }


        // If x greater, ignore left half
        if (arr[m][0] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    return -1;
}


//Binary Search Recursive

int binarySearchRecursive(vector <vector<string>> &arr, int l, int r, string x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid][0] == x)
            {
                cout<<"Search Found:\n";
                cout<<"Name:\t"<<arr[mid][0]<<endl;
                cout<<"Roll:\t"<<arr[mid][1]<<endl;
               return mid;
            }

        // If element is smaller than mid, then
        // it can only be present in left sub array
        if (arr[mid][0] > x)
            return binarySearchRecursive(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right sub array
        return binarySearchRecursive(arr, mid + 1, r, x);
    }
    return -1;
}


void menu()
{
   cout<<"\n\nMENU OPTIONS TO SEARCH"<<endl;
    cout<<"1\tIterative Binary Search\n";
    cout<<"2\tRecursive Binary Search\n";
    cout<<"3\tExit\n"<<endl;

}


int main()
{
    char ans='y';
    vector <vector<string>>stuff;
    vector <string> row;
    int count=0;

    fio.open("asn2a.csv", ios::app | ios::out | ios::in);

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
        stringstream s(line);
        while (getline(s,data, ','))
            {
            row.push_back(data);
        }


        count++;

        vector <string> temp;

            for(int j=0;j<row.size();j++)
            {
                temp.push_back(row[j]);
            }
            stuff.push_back(temp);
            temp.clear();
    }


    cout<<"Total number of records data \t"<<count<<endl<<endl;

    //cout<<"Stuff Rows x Columns\t"<<stuff.size()<<"\t"<<stuff[0].size()<<endl;


    fio.close();

    quickSort(stuff,0,(stuff.size()-1));

    fio1.open("asn2aSORT.csv", ios::trunc | ios::out | ios::in);

    for(int i=0;i<stuff.size();i++)
    {
        for(int j=0;j<stuff[i].size();j++)
        {
        fio1<<stuff[i][j]<<",";
        }
        fio1<<"\n";

    }


    cout<<"Sorted Output File asn2aSORT.CSV has been created";

while(ans=='Y' || ans =='y')
{
    string s;
    int ch;
    menu();

    cout<<endl<<"Which Search do you want:\t";
    cin>>ch;

    if(ch==3)
        return 0;

    cout<<endl;
    cout<<"\n\nEnter Student Name to display :\t";
    cin>>s;
    switch(ch)
    {
        case 1:
            if(binarySearchIterative(stuff,0,(stuff.size()-1),s)==-1)
            cout<<"\nSearch Not found"<<endl;
            break;

        case 2:
            if(binarySearchRecursive(stuff,0,(stuff.size()-1),s)==-1)
            cout<<"\nSearch Not found"<<endl;
            break;

        default:
            cout<<"Invalid Input \t";

    }
    cout<<"\nDo you want to search for another student? (Y/N) ";
    cin>>ans;
    cout<<endl;
}
return 0;
}
