/*Write a program to sort an array of N integers (given as input via a text file) using -
a. Merge Sort
b. Quick Sort
*/



#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<conio.h>
#include<unistd.h>
using namespace std;
fstream fio;
int part(vector<int> &arr, int lb, int ub);

//Quick sort algorithm
void quick_sort(vector<int> &arr, int lb, int ub)
{
    int location;
    if(lb<ub)
    {
        location=part(arr,lb,ub);
        quick_sort(arr,lb,location-1); //sort the sub array independently
        quick_sort(arr,location+1,ub);
    }
}
//Quick sort initiation
int part(vector<int> &arr, int lb, int ub)
{
   int pivot=arr[ub];       //partition the array using last elt as pivot
   int i=(lb-1);
   for(int j=lb;j<=ub-1;j++)
   {
       if(arr[j]<=pivot)
       {
           i++;
           swap(arr[i],arr[j]);
       }
   }
    swap(arr[i+1],arr[ub]);
    return(i+1);
}

//Merge Sorting
void merge_alg(vector<int> &arr, int lb , int ub, int mid );
void merge_sort(vector<int> &arr, int lb, int ub) //Merge algorithm
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        merge_sort(arr,lb,mid);
        merge_sort(arr,mid+1,ub);
        merge_alg(arr,lb,ub,mid);
    }

}
void merge_alg(vector<int> &arr, int lb, int ub, int mid) //Merge sorting initiation
{
   int i,j,k;
   int b[500];
   i=lb;
   k=lb;
   j=mid+1;
   while(i<=mid && j<=ub)
   {
       if(arr[i]<=arr[j])
       {
           b[k]=arr[i];
           i++;
           k++;
       }
       else
       {
           b[k]=arr[j];
           j++;
           k++;
       }
   }
   if(i>mid)
   {
   while(j<=ub)
   {
       b[k]=arr[j];
       j++;
       k++;
   }
   }
   else
   {
       while(i<=mid)
       {
           b[k]=arr[i];
           k++;
           i++;
       }
   }
   for(k=lb;k<=ub;k++)
   {
       arr[k]=b[k];
   }
}
void menu()
{
   cout<<"MENU OPTIONS TO SORT"<<endl;
    cout<<"1\tQuick Sort\n";
    cout<<"2\tMerge Sort\n"<<endl;
}
int main()
{
    vector<int> arr;
    int count=0;
    string s;
    cout<<"List of Available Files :\n"<<endl;
    char command[50] = "dir /a-d *.txt /b";
   system(command);
    cout<<endl<<"Enter Filename:\t";
    cin>>s;
    fio.open(s,  ios::in);
    string line,data;
    while(fio.good())
    {
        //row.clear();
        fio>>line;
        //if(fio.eof())
            //break;
        stringstream s(line);
        while (getline(s,data, ','))
            {
            arr.push_back(stoi(data));
        }
        count++;
    }
    cout<<"Total number of records data \t"<<count<<endl;
    fio.close();
    cout<<"Elements of the array are:\n";
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<endl;
    }
    int ch;
    menu();
    cout<<"Which Sort do you want:\n";
    cin>>ch;
    switch(ch)
    {
        case 1:
            quick_sort(arr,0,count-1);
            cout<<endl<<"Press any key to continue."<<endl;
            getch();
            //sleep(2000);    //Waits the system for 2s
            system("cls");
            menu();
            break;
        case 2:
            merge_sort(arr,0,count-1);
            cout<<endl<<"Press any key to continue."<<endl;
            getch();
            //sleep(2000);    //Waits the system for 2s
            system("cls");
            menu();

        default:
            cout<<"Invalid format Try Again\t";

    }
    cout<<"Sorted array are:\n";
   for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<"\t";
    }
    return 0;
}









