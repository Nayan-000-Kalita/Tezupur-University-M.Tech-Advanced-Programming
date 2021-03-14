/*
Write a program that recursively looks through all folders (within a certain location to be provided by user as a string) and lists all files with a given extension (say, .doc or .xml). 
The program should write the file names in a text file.
*/

#include<iostream>
#include<string.h>
using namespace std;
int main () {

    cout<<"Enter File Path :\n";
    char filep[100];
    cin.getline(filep,100);

    char command[50] = "chdir /d "; // d display all directories in the current path
    strcat(command,filep); //'strcat'  appends string pointed by source(i.e filep) to destination(i.e command)

    char command1[50] = " && dir /s /b *"; // s is use to display all file in directories n sub-directories
                                        // b is use to display only names of file no additional info
    strcat(command,command1);

    cout<<"Enter File Extension (.txt/.xml/.doc):\n";
    char filee[100];
    cin.getline(filee,100);

    strcat(command,filee);

    char command2[50] = ">Output_files.txt"; // '>' send output to a new file in the given path
    strcat(command,command2);
    cout<<command<<endl<<endl;

    system(command);

    cout<<"\nOutput_files.txt has been created in the given Path\n";

   return 0;
}


