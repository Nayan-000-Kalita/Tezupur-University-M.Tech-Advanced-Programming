/*
Write a program that can perform the following operations on a simple linked list of integers - insert (any position), delete (any position), append (last position), search, and display.

Bonus: Modify the program to allow creation of a linked list of structures/class objects. Each node in the linked list can hold data of a single student with - roll number and marks of 4 subjects.
Create the linked list using the data from the Students.csv file given the previous assignment.
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


struct node
{
        int rollno,m1,m2,m3,m4;
        struct node *next;
};
struct node *start=NULL;

 fstream fio;

void create(vector <string> row)
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                cout<<endl<<"Out of Memory Space\n";
                exit(0);
        }

        temp->rollno=stoi(row[0]);
        temp->m1=stoi(row[1]);
        temp->m2=stoi(row[2]);
        temp->m3=stoi(row[3]);
        temp->m4=stoi(row[4]);
        temp->next=NULL;

        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}


void insert_pos()               //Insert data at any position
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                cout<<"Out of Memory Space\n";
                return;
        }
        cout<<"\nEnter the position for the new node to be inserted\t";
        cin>>pos;

        pos=pos-1; //otherwise it gets inserted after the 5th Position and not in 5 th position
        cout<<"\nEnter roll number :\t";
        cin>>temp->rollno;
        cout<<"\nEnter marks of 4 subjects : \n";
        cin>>temp->m1;
        cin>>temp->m2;
        cin>>temp->m3;
        cin>>temp->m4;


        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;    //Traverse the pointer to the desired position
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++) { ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found \n");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}




void insert_end()               //Insert at end
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                cout<<"\nOut of Memory Space\n";
                return;
        }

        cout<<"\nEnter roll number :\t";
        cin>>temp->rollno;
        cout<<"\nEnter marks of 4 subjects : \n";
        cin>>temp->m1;
        cin>>temp->m2;
        cin>>temp->m3;
        cin>>temp->m4;
        temp->next =NULL;


        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}



void delete_pos()           //Delete data from any position
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                cout<<"\nThe List is Empty\n";
                exit(0);
        }
        else
        {
                cout<<"\nEnter the position of the node to be deleted\t";
                cin>>pos;
                pos=pos-1;

                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        cout<<"The deleted Roll No is :"<<ptr->rollno<<endl;
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        cout<<"\nPosition not Found\n";
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        cout<<"The deleted Roll No is :"<<ptr->rollno<<endl;
                        free(ptr);
                }
        }
}


void display()          //Display the data
{
        struct node *ptr;
        if(start==NULL)
        {
                cout<<endl<<"List is Empty"<<endl;
                return;
        }
        else
        {
                ptr=start;
                cout<<endl<<"The list elements are\n";
                while(ptr!=NULL)
                {
                        cout<<ptr->rollno<<"\t"<<ptr->m1<<"\t"<<ptr->m2<<"\t"
                            <<ptr->m3<<"\t"<<ptr->m4<<endl;

                        ptr=ptr->next ;
                }
        }
}


void searchAny() //Search any data
{
        int roll;
        int flag = 0;
        struct node *ptr;
        if(start==NULL)
        {
                cout<<endl<<"List is Empty"<<endl;
                return;
        }
        else
        {
                cout<<endl<<"Enter Roll Number to be Searched :\t";
                cin>>roll;
                ptr=start;

                while(ptr!=NULL)
                {
                        if(ptr->rollno==roll)
                        {
                            cout<<"\n\nDetails of Student :\n\n";
                            cout<<"Roll no:\t"<<ptr->rollno<<endl;
                            cout<<"Marks in Subjects1:\t"<<ptr->m1<<endl;
                            cout<<"Marks in Subjects2:\t"<<ptr->m2<<endl;
                            cout<<"Marks in Subjects3:\t"<<ptr->m3<<endl;
                            cout<<"Marks in Subjects4:\t"<<ptr->m4<<endl;
                            flag =1;
                            break;
                        }

                        ptr=ptr->next ;
                }
        }
        if(flag==0)
        cout<<"Roll no not found";
}


void menu()
{
    cout<<"MENU OPTIONS"<<endl;
    cout<<"1\tInsert(Any Position)\n";
    cout<<"2\tDelete(Any Position)\n";
    cout<<"3\tAppend(Last Position)\n";
    cout<<"4\tSearch Item\n";
    cout<<"5\tDisplay\n";
    cout<<"0\tExit\n"<<endl;



}



int main()
{
    vector <string> row;
    int count=0;
    fio.open("Students.csv", ios::app | ios::out | ios::in);
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
            row.push_back(data);
        }
        count++;

        create(row);
    }
    fio.close();

    int ch;
    menu();



    while(1)
    {
    cout<<"Enter Your Choice\t";
    cin>>ch;
    cout<<"\n\n";

    switch(ch)
    {
    case 1:
        insert_pos();
        cout<<endl<<"Press any key to continue."<<endl;
        getch();
        //sleep(2000);    //Waits the system for 2s
        system("cls");
        menu();
        break;

    case 2:
        delete_pos();
        cout<<endl<<"Press any key to continue."<<endl;
        getch();
        //sleep(2000);    //Waits the system for 2s
        system("cls");
        menu();
        break;

    case 3:
        insert_end();
        cout<<endl<<"Press any key to continue."<<endl;
        getch();
        //sleep(2000);    //Waits the system for 2s
        system("cls");
        menu();
        break;

    case 4:
        searchAny();
        cout<<endl<<"Press any key to continue."<<endl;
        getch();
        //sleep(3000);    //Waits the system for 2s
        system("cls");
        menu();
        break;

    case 5:
        display();
        cout<<endl<<"Press any key to continue."<<endl;
        getch();
        system("cls");
        menu();
        break;

    case 0:
        break;

    default:
        cout<<"Invalid format Try Again\t";
    }

    if(ch==0)
        break;
    }
    return 0;
}

