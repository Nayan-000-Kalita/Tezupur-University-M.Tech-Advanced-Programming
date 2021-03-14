/*
Write a program that has functions solving the Interval scheduling problem as well as Interval Scheduling to minimize lateness.
The file asn2d_y.txt contains a set of deadlines and time durations for 30 activities - the first column corresponds to the deadline by which a particular activity is to be completed, and the second column corresponds to the time duration of the activity. This is for the Interval Scheduling to Minimize Lateness problem.
*/



#include<iostream>
#include <algorithm>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
fstream fio;
void display(vector <vector<int>>stuff);

void min_lat(vector <vector<int>> stuff)
{
    //result
		string res = "";
		string res1 ="";
		int late=0,lateness=0;
		int t=0;// clock to monitor time
		int si=t , fi;

		//algo
		for(int i=0;i<stuff.size();i++)
		{
                si = t; //si=start time of i-th activity
                fi = t+stuff[i][1]; //fi = finish time of i-th activity =  clock + duration of i-th activity
                res = res+to_string(i)+" "; //adding to answer list
                t=fi; //updating clock
                stuff[i].push_back(si);
                stuff[i].push_back(fi);
                late=max(0,(fi-stuff[i][0]));
                stuff[i].push_back(late);
                lateness=lateness+late;



            }
            display(stuff);

		cout<<"\nThe most minimised lateness is: "<<lateness<<" unit(s)\n\n";
	}



//UTILITY FUNCTIONS to sort based on finish time
void bubble(vector <vector<int>> &stuff)
{
    int tnum;
    for (int i = 0; i < (stuff.size()-1); i++)
    {


        for (int j = 0; j < (stuff.size()-i-1); j++)
        {

            if (stuff[j][0] > stuff[j+1][0])
            {

                tnum=stuff[j][0];
                stuff[j][0]=stuff[j+1][0];
                stuff[j+1][0]=tnum;

                tnum=stuff[j][1];
                stuff[j][1]=stuff[j+1][1];
                stuff[j+1][1]=tnum;
            }
            if (stuff[j][0] == stuff[j+1][0] && stuff[j][1] > stuff[j+1][1])
            {

                tnum=stuff[j][0];
                stuff[j][0]=stuff[j+1][0];
                stuff[j+1][0]=tnum;

                tnum=stuff[j][1];
                stuff[j][1]=stuff[j+1][1];
                stuff[j+1][1]=tnum;
            }

        }
    }
}


//Utility Function to Display Vector Array
void display(vector <vector<int>>stuff)
{
    cout<<"Index\tDeadline\tBurstTime\tStartTime\tFinishTime\tLate\n";
    for(int i=0;i<stuff.size();i++)
        {
            cout<<i<<".\t";
            for(int j=0;j<stuff[i].size();j++)
            {
                cout<<stuff[i][j]<<"\t\t";
            }

        cout<<endl;
        }
        cout<<endl;
}


int main()
{
//Minimize Lateness
        string line;
        vector <string> row;
        vector <vector<int>>stuff;
        int count=0;
        fio.open("asn2d_y.txt",  ios::in);

        if(fio.fail())
        {
            cout<<"\nFile could not be opened\n";
            return 0;
        }


        while(fio.good())
        {
            getline(fio,line);
            row.push_back(line);
            count++;
        }
        //cout<<count<<endl;
        string delimiter = ",,",s;

        for(int i=0;i<30;i++)
        {
            s=row[i];
            replace( s.begin(), s.end(), '\t', ',');
            //cout<<s<<endl;
            int pos = 0;
            string token;

            vector <int> temp;
            while ((pos = s.find(delimiter)) != string::npos) {
                token = s.substr(0, pos);
                temp.push_back(stoi(token));
                //cout <<stoi(token)  << endl;
                s.erase(0, pos + delimiter.length());
            }
            temp.push_back(stoi(s));
            //cout<<stoi(s)<<endl;
            stuff.push_back(temp);
            temp.clear();
        }
        //display(stuff);
        cout<<"Interval Scheduling Algorithm to Minimize Lateness"<<endl;
        cout<<"Input - ans2d_y.txt"<<endl<<endl;

        //Sorting based on Shortest Jobs
        bubble(stuff);
        cout<<"After Sorting :"<<endl<<endl;

        //display(stuff);

        //Calculate Lateness
        min_lat(stuff);
    }
