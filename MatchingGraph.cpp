/* Write a program to find all possible matchings in a graph. The input to the program is given as an adjacency matrix. */

#include <iostream>
#include <string.h>
using namespace std;
// M is number of applicants
// and N is number of jobs
#define M 7
#define N 7

bool bpm(bool bpGraph[M][N], int u,
		bool seen[], int matchR[])
{
	for (int v = 0; v < N; v++)
	{
		if (bpGraph[u][v] && !seen[v])
		{
			// Mark v as visited
			seen[v] = true;
			if (matchR[v] < 0 || bpm(bpGraph, matchR[v],
									seen, matchR))
			{
				matchR[v] = u;
				return true;
			}
		}
	}
	return false;
}

// Returns maximum number
// of matching from M to N
int maxBPM(bool bpGraph[M][N])
{
	int matchR[N];
	memset(matchR, -1, sizeof(matchR));
	int result = 0;
	for (int u = 0; u < M; u++)
	{
		bool seen[N];
		memset(seen, 0, sizeof(seen));
		if (bpm(bpGraph, u, seen, matchR))
			result++;
	}
	return result;
}
int main()
{
	bool bpGraph[M][N] =    {{0,1,1,1,0,0,0},
                            {0,0,0,1,1,0,0},
                            {0,0,0,0,0,1,0},
                            {0,0,1,0,0,1,0},
                            {0,0,0,1,0,0,0},
                            {0,0,0,0,0,0,0},
                            {0,0,0,1,1,1,0}};

    cout<<"\nThe given adjacency matrix is: "<<endl<<"0 1 1 1 0 0 0"
                                       "\n0 0 0 1 1 0 0"
                                        "\n0 0 0 0 0 1 0"
                                        "\n0 0 1 0 0 1 0"
                                        "\n0 0 0 1 0 0 0"
                                        "\n0 0 0 0 0 0 0"
                                        "\n0 0 0 1 1 1 0";

	cout << "\n \nMaximum number of matching in the given matrix  is "
		<< maxBPM(bpGraph);

	return 0;
}