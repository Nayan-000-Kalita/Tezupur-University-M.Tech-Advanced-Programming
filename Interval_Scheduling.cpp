/*
Write a program that has functions solving the Interval scheduling problem as well as Interval Scheduling to minimize lateness.
The file asn2d_x.txt contains a set of intervals for 30 activities - the first column corresponds to the start time and the second column corresponds to the finish time. This is for the Interval Scheduling Problem.
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


// FUNCTIONS to sort based on finish time
void interval_sch(vector <vector<int>> stuff)
{
   //result
		string res = "";

		//algo
		for(int i=0;i<stuff.size();i++)
		{
			if(stuff[i][0]==-1) //skip removed indices
				continue;

			// adding to the list
			res = res+to_string(i)+" ";
			for(int j=i+1;j<stuff.size();j++)
			{
			    //reject if start of j is less than finish of selected
				if(stuff[j][0]<stuff[i][1])
				{
				    //remove those activities
					stuff[j][0]=-1;
					stuff[j][1]=-1;


				}
			}
			//removing the selected activity from array also
			stuff[i][0]=-1;
			stuff[i][1]=-1;
		}

		cout<<"The indices of the activitites executed is: "<<res;
		cout<<endl<<endl;

}









//UTILITY FUNCTIONS to sort based on finish time
void bubble(vector <vector<int>> &stuff)
{
    int tnum;
    for (int i = 0; i < (stuff.size()-1); i++)
    {


        for (int j = 0; j < (stuff.size()-i-1); j++)
        {

            if (stuff[j][1] > stuff[j+1][1])
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


void display(vector <vector<int>>stuff)
{
    cout<<"Index\tStartTime\tFinishTime\n";
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
    vector <string> row;
    vector <vector<int>>stuff;
    int count=0;
    fio.open("asn2d_x.txt",  ios::in);
    string line,data;

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
        cout<<"Interval Scheduling Algorithm"<<endl;
        cout<<"Input - ans2d_x.txt"<<endl<<endl;
        bubble(stuff);
        cout<<"After Sorting :"<<endl<<endl;
        display(stuff);
        interval_sch(stuff);
        fio.close();















}
