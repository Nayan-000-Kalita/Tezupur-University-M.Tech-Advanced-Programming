/*
Write a program in C/C++ to read a CSV file containing the marks of 4 tests each of 60(say) students and calculate the mean,
standard deviation, percentage and percentile of each student. 
Write the output in a new CSV file.
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    fstream fio;
    vector <string> row;
    string line,data; //Extract row and data of each row
    int count=0,count1=0;
    fio.open("Students.csv", ios::app | ios::out | ios::in);
    float sum5=0;


    //Count total records
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

    }

    count=count-1;

    cout<<"Total number of records data \t"<<count<<endl;
    fio.close();

    //Mean of each test overall
    fio.open("Students.csv", ios::app | ios::out | ios::in);
    count1=0;
    int total=0;
    float sum1=0,sum2=0,sum3=0,sum4=0;
    float mean1=0,mean2=0,mean3=0,mean4=0;
    while(count!=count1)
    {
        count1++;
        row.clear();
        fio>>line;
        stringstream s(line);
        while (getline(s,data, ','))
            {
            row.push_back(data);
        }
        sum1=sum1+stof(row[1]);
        sum2=sum2+stof(row[2]);
        sum3=sum3+stof(row[3]);
        sum4=sum4+stof(row[4]);

    }
    mean1=sum1/count;
    mean2=sum2/count;
    mean3=sum3/count;
    mean4=sum4/count;

    cout<<"Mean of Test 1 \t"<<mean1<<endl;
    cout<<"Mean of Test 2 \t"<<mean2<<endl;
    cout<<"Mean of Test 3 \t"<<mean3<<endl;
    cout<<"Mean of Test 4 \t"<<mean4<<endl;

    fio.close();


    //Standard Deviation of tests
     float sd1=0,sd2=0,sd3=0,sd4=0;
     fio.open("Students.csv", ios::app | ios::out | ios::in);
     count1=0;
     while(count!=count1)
        {
        count1++;
        row.clear();
        fio>>line;
        stringstream s(line);
        while (getline(s,data, ','))
            {
            row.push_back(data);
        }
        sum1=sum1+pow((stof(row[1])-mean1),2);
        sum2=sum2+pow((stof(row[2])-mean2),2);
        sum3=sum3+pow((stof(row[3])-mean3),2);
        sum4=sum4+pow((stof(row[4])-mean4),2);
    }
    sd1=sqrt(sum1/count);
    sd2=sqrt(sum2/count);
    sd3=sqrt(sum3/count);
    sd4=sqrt(sum4/count);

    sum5=sd1+sd2+sd3+sd4;

    cout<<"Standard Deviation of Test 1 \t"<<sd1<<endl;
    cout<<"Standard Deviation of Test 2 \t"<<sd2<<endl;
    cout<<"Standard Deviation of Test 3 \t"<<sd3<<endl;
    cout<<"Standard Deviation of Test 4 \t"<<sd4<<endl;

    fio.close();

    //Percentage and Mean and standard deviation calculation of each student
    float per=0,mean=0;
    float total1=0;
    fio.open("Students.csv", ios::app | ios::out | ios::in);
    fstream fio1;
    fio1.open("StudentsPER.csv", ios::trunc | ios::out | ios::in);
    count1=0;
    float stddev=0;
    sum2=0;

     while(count!=count1)
    {
        count1++;
        per=0;
        row.clear();
        fio>>line;
        stringstream s(line);
        while (getline(s,data, ','))
            {
            row.push_back(data);
        }
        sum1=stof(row[1])+stof(row[2])+stof(row[3])+stof(row[4]);
        total=total+sum1;
        mean=sum1/4;

       // sum5=sum5+pow((sum1-mean),2);

        per=((sum1/(50*4))*100);
        sum2=pow(((stof(row[1]))-mean),2)+pow(((stof(row[2]))-mean),2)+pow(((stof(row[3]))-mean),2)+pow(((stof(row[4]))-mean),2);
        stddev=sqrt(sum2/4);
        fio1<<count1<<","
        <<row[1]<<","
        <<row[2]<<","
        <<row[3]<<","
        <<row[4]<<","
        <<mean<<","
        <<per<<","
        <<stddev<<","
        <<sum1<<"\n";
    }




        fio1<<" "<<","
        <<" "<<","
        <<" "<<","
        <<" "<<","
        <<" "<<","
        <<" "<<","
        <<" "<<","
        <<"Average"<<","
        <<(total/60.0)<<"\n";

        fio1<<" "<<","
        <<" "<<","
        <<" "<<","
        <<" "<<","
        <<" "<<","
        <<" "<<","
        <<" "<<","
        <<"Std Devn"<<","
        <<(sum5/4)<<"\n";

    cout<<"average\t"<<(total/60.0);
    cout<<endl<<endl;

    cout<<"standard deviation\t"<<(sum5/4);
    cout<<endl<<endl;

    fio.close();
    fio1.close();





    //Percentile using vector arrays
    float percntl=0,tnum;
    fio.open("StudentsPER.csv", ios::app | ios::out | ios::in);
    fio1.open("StudentsPercentileWise.csv", ios::trunc | ios::out | ios::in);
    count1=0;

    vector <vector<float>>stuff;

        for(int i=0;i<count;i++)
        {
        row.clear();
        fio>>line;
        stringstream s(line);
        while (getline(s,data, ','))
            {
            row.push_back(data);
        }


            vector <float> temp;

            for(int j=0;j<9;j++)
            {
                temp.push_back(stof(row[j]));
            }
            stuff.push_back(temp);
            temp.clear();
        }


        //bubble wise sorting using percentage in descending order

        for(int i=0;i<count-1;i++)
        {
            for(int j=0;j<count-i-1;j++)
            {
                if(stuff[j][6]<stuff[j+1][6])
                {
                    tnum=stuff[j][0];
                    stuff[j][0]=stuff[j+1][0];
                    stuff[j+1][0]=tnum;

                    tnum=stuff[j][1];
                    stuff[j][1]=stuff[j+1][1];
                    stuff[j+1][1]=tnum;

                    tnum=stuff[j][2];
                    stuff[j][2]=stuff[j+1][2];
                    stuff[j+1][2]=tnum;

                    tnum=stuff[j][3];
                    stuff[j][3]=stuff[j+1][3];
                    stuff[j+1][3]=tnum;

                    tnum=stuff[j][4];
                    stuff[j][4]=stuff[j+1][4];
                    stuff[j+1][4]=tnum;

                    tnum=stuff[j][5];
                    stuff[j][5]=stuff[j+1][5];
                    stuff[j+1][5]=tnum;

                    tnum=stuff[j][6];
                    stuff[j][6]=stuff[j+1][6];
                    stuff[j+1][6]=tnum;

                    tnum=stuff[j][7];
                    stuff[j][7]=stuff[j+1][7];
                    stuff[j+1][7]=tnum;

                    tnum=stuff[j][8];
                    stuff[j][8]=stuff[j+1][8];
                    stuff[j+1][8]=tnum;
                }
            }
        }

    //percentile calculation for each student in vector array
    int count2=0;
    for(int i=0;i<stuff.size();i++)
    {

         count1 = 0;count2=0;
        for (int j = 0; j < stuff.size(); j++) {

            // Comparing the marks of student i
            // with all other students
            if (stuff[i][6]>stuff[j][6]) {
                count1++;
            }
            if (stuff[i][6]==stuff[j][6]) {
                count2++;
            }


        }
        percntl = ((count1+0.5*count2) * 100.0) / (count);
        stuff[i].push_back(percntl);

        }


            fio1<<"Roll No"<<","
                <<"M1"<<","
                <<"M2"<<","
                <<"M3"<<","
                <<"M4"<<","
                <<"Mean"<<","
                <<"Percentage"<<","
                <<"Std Devn"<<","
                <<"Total"<<","
                <<"Percentile"<<"\n";

    //writing the entire vector array in a CSV file
   for(int i=0;i<stuff.size();i++)
    {
        for(int j=0;j<stuff[i].size();j++)
        {
        fio1<<stuff[i][j]<<",";
        }
        fio1<<"\n";

    }







 // Used to print vector array

 /* for(int i=0;i<stuff.size();i++)
    {
        for(int j=0;j<stuff[i].size();j++)
            cout<<stuff[i][j]<<"\t";
        cout<<endl;
    }

*/
    fio.close();
    fio1.close();

    cout<<"\n\n2 CSV FILES ARE CREATED AS OUTPUT both unsorted and sorted\n";


}
