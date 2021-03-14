/* 
WAP to implement (i) BFS and (ii) DFS in an undirected graph to identify the set of connected components in the graph.
Consider the graphs to be stored in the form of an adjacency list in a text file. Read the file and convert to an adjacency matrix representation if necessary.
A sample test file asn3a.txt is attached.
 */


#include <bits/stdc++.h>
using namespace std;
int vertex=0;
int** matrix =0;
bool* visited = 0;
void DFS(int start, int** adj)
{
    cout << start+1 << "-";
    visited[start] = true;

    for (int i = 0; i < vertex; i++) {
        if (adj[start][i] == 1 && (!visited[i])) {
            DFS(i,adj);
        }
    }
}
void BFS(int start){
	vector<int> q;
    q.push_back(start);
    visited[start] = true;

    int vis;
    while (!q.empty()) {
        vis = q[0];
        cout << vis+1 << " ";
        q.erase(q.begin());


        for (int i = 0; i < vertex; i++) {
            if (matrix[vis][i] == 1 && (!visited[i])) {
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
}
int main(){
	string temp;
	int count = 0;
	list<int> edgelist;
	edgelist.push_back(-1);
	int max_vertex=0;

	try{
		ifstream file("asn3a.txt");
		cin.ignore(0,'\n');

		while(getline(file,temp, '\n'))
		{
			count=0;
			stringstream s_stream(temp);
			while(s_stream.good()) {
		       	string substr;
		       	getline(s_stream, substr, ',');

		       	stringstream geek(substr);
			    int x = 0;
			    geek >> x;
		      	//cout << x <<" ";
		      	edgelist.push_back(x);
		      	max_vertex = (max_vertex<x)?x:max_vertex;
		   	}
		   	edgelist.push_back(-1);
		}
		file.close();
	}
	catch (const ifstream::failure& e) {
	    cout << "Exception opening/reading file";
	}
	vertex = max_vertex;
	cout << "\n";
	list<int>::iterator it;
	int start =-1;

	matrix = new int*[vertex];
	for(int i=0;i<vertex;i++)
		matrix[i] = new int[vertex]{0};

	for(it = edgelist.begin(); it != edgelist.end(); ++it){
		if(*it == -1){
			start++;
		}
		else{
			matrix[start][*it-1]=1;
			matrix[*it-1][start]=1;
		}
	}
	findanother:
	int choice;
	cout << "Press 1 for Adjecency maxtrix \nPress 2 for DFS \nPress 3 for BFS \n";
    cin >> choice;
	switch(choice){
    	case 1:{
    		cout << "Adjecency Matrix :\n";
	    	for(int i=0;i<max_vertex;i++){
				for(int j=0;j<max_vertex;j++)
					cout << matrix[i][j] <<" ";
				cout <<"\n";
			}
			cout << "\n";
			break;
	   	}
	   	case 2:{
	   		cout << "DFS Traversal : \n";
	   		visited = new bool[vertex]{false};
	   		int disconnected = 0  ;
	   		for(int i=0;i<vertex;i++){
		   		if(!visited[i]){
		   			disconnected++;
				    cout << "DFS Traversal from " << (i+1) << " : " ;
		   			DFS(i,matrix);
		   			cout << ".\n";
		   		}
		   	}
		   	cout <<"There are total " << disconnected << " disconnected graph.\n";
	    	break;
	    }
	    case 3:{
	    	cout << "BFS Traversal : \n";
	    	visited = new bool[vertex]{false};
	    	int disconnected = 0  ;
	   		for(int i=0;i<vertex;i++){
		   		if(!visited[i]){
		   			disconnected++;
				    cout << "BFS Traversal from " << (i+1) << " : " ;
		   			BFS(i);
		   			cout << ".\n";
		   		}
		   	}
		   	cout <<"There are total " << disconnected << " disconnected graph.\n";
			break;
		}
	    default:{
	    	cout << "\nEnter right option : ";
	   	}
	}
	string another;
   	cout << "\nPress 1 for find through another choice or press anything to exit : ";
   	cin >> another;

   	if(another == "1"){
   		cout << "\n";
   		goto findanother;
   	}
}
