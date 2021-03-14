/*
Write a program that computes the similarity between two text files by computing the edit distance between the files asn2c_x.txt and asn2c_y.txt using Wagner Fischer Algorithm.
*/


#include<iostream>
#include <fstream>
#include<string>
#include<sstream>

using namespace std;

// Utility function to find the minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }

int editDistDP(string str1, string str2, int m, int n)
{
	// Create a table to store results of subproblems
	int dp[m + 1][n + 1],flag=0;

	// Fill d[][] in bottom up manner
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			// If first string is empty, only option is to
			// insert all characters of second string
			if (i == 0)
				dp[i][j] = j; // Min. operations = j

			// If second string is empty, only option is to
			// remove all characters of second string
			else if (j == 0)
				dp[i][j] = i; // Min. operations = i

			// If last characters are same, ignore last char
			// and recur for remaining string
			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];



            else if (dp[i-1][j-1] == min(dp[i][j - 1], dp[i - 1][j],dp[i - 1][j - 1]))
                dp[i][j]
					= 2
					+ min(dp[i][j - 1], // Insert
							dp[i - 1][j], // Delete
							dp[i - 1][j - 1]); // Substitute




			// If the last character is different, consider
			// all possibilities and find the minimum
			else
				dp[i][j]
					= 1
					+ min(dp[i][j - 1], // Insert
							dp[i - 1][j], // Delete
							dp[i - 1][j - 1]); // Substitute
		}
	}

	return dp[m][n];
}


int main()
{
    fstream fio,fio1;
    fio.open("asn2c_x.txt",  ios::in);
    string str1;
    ostringstream ss,ss1;

    if(fio.good())
    {
    ss << fio.rdbuf(); // reading data of asn2c_x
    str1 = ss.str();

    }
    //cout<<str1<<endl<<endl;

    fio1.open("asn2c_y.txt",  ios::in);
    string str2;

    if(fio1.good())
    {
    ss1 << fio1.rdbuf(); // reading data of asn2c_y
    str2 = ss1.str();

    }
    //cout<<str2<<endl<<endl;
    cout<<"The Edit Distance is:\t"<<editDistDP(str1, str2, str1.length(),str2.length())<<endl<<endl;
    return 0;
}
