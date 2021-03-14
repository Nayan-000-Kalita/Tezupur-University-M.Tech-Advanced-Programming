/* Write a program to compute the Minimum Spanning Tree of a graph using i)Prim's and ii)Kruskal's algorithm. Assume that the input is given as an adjacency matrix.*/

import java.util.*;
public class MinSpanTree {
	static int V = 8; //Number of vertex
	  static int[] parent = new int[V];
	  static int INF = Integer.MAX_VALUE;

	  static int find(int i)
	  {
	      while (parent[i] != i)
	          i = parent[i];
	      return i;
	  }

	  // Does union of i and j. It returns
	  // false if i and j are already in same
	  // set.
	  static void union1(int i, int j)
	  {
	      int a = find(i);
	      int b = find(j);
	      parent[a] = b;
	  }

	  //  Kruskal's algorithm
	  static void kruskalMST(int cost[][])
	  {
	      int mincost = 0; // Cost of min MST.

	      // Initialize sets of disjoint sets.
	      for (int i = 0; i < V; i++)
	          parent[i] = i;

	      // Include minimum weight edges one by one
	      int edge_count = 0;
	      while (edge_count < V - 1)
	      {
	          int min = INF, a = -1, b = -1;
	          for (int i = 0; i < V; i++)
	          {
	              for (int j = 0; j < V; j++)
	              {
	                  if (find(i) != find(j) && cost[i][j] < min)
	                  {
	                      min = cost[i][j];
	                      a = i;
	                      b = j;
	                  }
	              }
	          }

	          union1(a, b);
	          System.out.printf("Edge %d:(%d, %d) cost:%d \n",
	              edge_count++, a, b, min);
	          mincost += min;
	      }
	      System.out.printf("\n Minimum cost= %d \n", mincost);
	  }
	  static boolean isValidEdge(int u, int v,
	                             boolean[] inMST)
	  {
	      if (u == v)
	          return false;
	      if (inMST[u] == false && inMST[v] == false)
	          return false;
	      else if (inMST[u] == true && inMST[v] == true)
	          return false;
	      return true;
	  }
	  //Prim's algorithm
	  static void primMST(int cost[][])
	  {
	      boolean []inMST = new boolean[V];

	      // Include first vertex in MST
	      inMST[0] = true;

	      int edge_count = 0, mincost = 0;
	      while (edge_count < V - 1)    // Keep adding edges while number of included edges does not become V-1.
	      {

	          // Find minimum weight valid edge.
	          int min = INF, a = -1, b = -1;
	          for (int i = 0; i < V; i++)
	          {
	              for (int j = 0; j < V; j++)
	              {
	                  if (cost[i][j] < min)
	                  {
	                      if (isValidEdge(i, j, inMST))
	                      {
	                          min = cost[i][j];
	                          a = i;
	                          b = j;
	                      }
	                  }
	              }
	          }

	          if (a != -1 && b != -1)
	          {
	              System.out.printf("Edge %d:(%d, %d) cost: %d \n",
	                                      edge_count++, a, b, min);
	              mincost = mincost + min;
	              inMST[b] = inMST[a] = true;
	          }
	      }
	      System.out.printf("\n Minimum cost = %d \n", mincost);
	  }
	  public static void main(String[] args)
	  {
	  Scanner s = new Scanner(System.in);
	  System.out.println("For the Adjacency matrix: \n\n0 4 1 0 0 0 0 0\r\n"
											  		+ "4 0 2 3 1 0 0 0\r\n"
											  		+ "1 2 0 0 2 0 1 3\r\n"
											  		+ "0 3 0 0 3 0 0 0\r\n"
											  		+ "0 1 2 3 0 4 0 0\r\n"
											  		+ "0 0 0 0 4 0 0 0\r\n"
											  		+ "0 0 1 0 0 0 0 5\r\n"
											  		+ "0 0 3 0 0 0 5 0");
	  while(true)
	  {
	    int cost[][] ={
	                /*0*//*1*//*2*//*3*//*4*//*5*//*6*//*7*/
	           /*0*/ {0,  4, 1, INF, INF,  INF, INF, INF},
	           /*1*/ {4,  0,  2,  3,   1,  INF, INF, INF},
	           /*2*/ {1,  2,  0, INF,  2, INF,   1,   3},
	           /*3*/ {INF, 3, INF, 0,  3,  INF,  INF, INF},
	           /*4*/ {INF, 1,  2,  3,  0,   4,   INF, INF},
	           /*5*/ {INF, INF,INF,INF, 4,  0,   INF, INF},
	           /*6*/ {INF, INF, 1,  INF, INF,  INF,  0, 5},
	           /*7*/ {INF, INF, 3, INF, INF,  INF , 5, 0},
	     };
	    System.out.print("\n-------MENU-------\nFind the Minimum Spanning Tree using:\n1.Kruscal's Algorithm\n2.Prim's Algorithm\n3.Exit\nChoose: ");
	    int ch = s.nextInt();

	    switch(ch)
	    {
	      case 1:kruskalMST(cost);
	             break;

	     case 2:primMST(cost);
	             break;

	    case 3:return;

	    default: System.out.println("Incorrect Option entered! Choose again");
	  }}
	}
}