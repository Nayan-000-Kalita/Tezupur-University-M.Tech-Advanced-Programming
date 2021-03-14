/* Write a program that computes the topological ordering of a graph if it is a Directed Acyclic Graph and computes a cycle if it is not a DAG.*/

import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class DAG {
	
	private final int V;
	private final List<List<Integer>> adj;


	public DAG(int V)
	{
		this.V = V;
		adj = new ArrayList<>(V);

		for (int i = 0; i < V; i++)
			adj.add(new LinkedList<>());
	}
	private boolean isCyclicUtil(int i, boolean[] visited,boolean[] recStack)
	{

				if (recStack[i])
			return true;

		if (visited[i])
			return false;

		visited[i] = true;

		recStack[i] = true;
		List<Integer> children = adj.get(i);

		for (Integer c: children)
			if (isCyclicUtil(c, visited, recStack))
				return true;

		recStack[i] = false;

		return false;
	}

	private void addEdge(int source, int dest) {
		adj.get(source).add(dest);
	}

	// Returns true if the graph contains a cycle, else false.
	private boolean isCyclic()
	{

		// Mark all the vertices as not visited and
		// not part of recursion stack
		boolean[] visited = new boolean[V];
		boolean[] recStack = new boolean[V];


		// Call the recursive helper function to
		// detect cycle in different DFS trees
		for (int i = 0; i < V; i++)
			if (isCyclicUtil(i, visited, recStack))
				return true;

		return false;
	}
	@SuppressWarnings("deprecation")
	void topologicalSortUtil(int v, boolean visited[],
                              Stack<Integer> stack)
     {
         // Mark the current node as visited.
         visited[v] = true;
         Integer i;

         // Recur for all the vertices adjacent
         // to this vertex
         Iterator<Integer> it = adj.get(v).iterator();
         while (it.hasNext()) {
             i = it.next();
             if (!visited[i])
                 topologicalSortUtil(i, visited, stack);
         }

         // Push current vertex to stack
         // which stores result
         stack.push(new Integer(v));
     }

     // The function to do Topological Sort.
     // It uses recursive topologicalSortUtil()
     void topologicalSort()
     {
         Stack<Integer> stack = new Stack<Integer>();

         // Mark all the vertices as not visited
         boolean visited[] = new boolean[V];
         for (int i = 0; i < V; i++)
             visited[i] = false;

         // Call the recursive helper
         // function to store
         // Topological Sort starting
         // from all vertices one by one
         for (int i = 0; i < V; i++)
             if (visited[i] == false)
                 topologicalSortUtil(i, visited, stack);

         // Print contents of stack
         while (stack.empty() == false)
             System.out.print(stack.pop() + " ");
     }

	// Driver code
	public static void main(String[] args)throws IOException
	{


		DAG graphob = new DAG(7);
	       
		
		//Reading from a file
	    Scanner myReader = new Scanner(new File("asn3c_x.txt"));
	    

	    ArrayList <Integer>[] graph = new ArrayList[8];
	    ArrayList <Integer> temp = new ArrayList <Integer>();
	    int row =0;
	    
	  	    
	    while (myReader.hasNextLine()) {
	        String data = myReader.nextLine();
	        //System.out.println(data);
	        //System.out.println("Return Value :" );
	        for (String retval: data.split(" ")){
	        int i=Integer.parseInt(retval);  
	        temp.add(i);
	        //System.out.println(i);
	        }
	        //System.out.println(temp);
	        //System.out.println("\n\n");
	        temp.add(0);
	        graph[row] = new ArrayList<Integer>(); 
	        graph[row].addAll(temp);
	        row++;
	        temp.clear();
	        
	    }
	    myReader.close();
	    
		System.out.println("Contents of Graph: ");

        for (int i = 0; i < row; i++) { 
            for (int j = 0; j < graph[i].size()-1; j++) { 
                System.out.print(graph[i].get(j) + " "); 
            } 
            System.out.println(); 
        }
        
        //Creating Edges
        for (int i = 0; i < row; i++) { 
            for (int j = 0; j < graph[i].size()-1; j++) { 
                
            	if(graph[i].get(j) == 1)
            		graphob.addEdge(i, j);
            } 
            
        }
		
	        if(graphob.isCyclic())
	            System.out.println("\nThe given Graph is not a Directed Acyclic Graph");
	        else
					{
	            System.out.println("\nThe given Graph is a Directed Acyclic Graph therefore, the Topological order of the  graph is" );
				graphob.topologicalSort(); 	
				}
	        
	        myReader.close();
	        System.out.println("\n\n");
	        
	         graphob = new DAG(6);
		       
			
			//Reading from a file
		     myReader = new Scanner(new File("asn3c_y.txt"));
		    

		    
		     row =0;
		    
		  	    
		    while (myReader.hasNextLine()) {
		        String data = myReader.nextLine();
		        //System.out.println(data);
		        //System.out.println("Return Value :" );
		        for (String retval: data.split(" ")){
		        int i=Integer.parseInt(retval);  
		        temp.add(i);
		        //System.out.println(i);
		        }
		        temp.add(0);
		        graph[row] = new ArrayList<Integer>(); 
		        graph[row].addAll(temp);
		        row++;
		        temp.clear();
		        
		    }
		    myReader.close();
		    
			System.out.println("Contents of Graph: ");

	        for (int i = 0; i < row; i++) { 
	            for (int j = 0; j < graph[i].size()-1; j++) { 
	                System.out.print(graph[i].get(j) + " "); 
	            } 
	            System.out.println(); 
	        }
	        
	        //Creating Edges
	        for (int i = 0; i < row; i++) { 
	            for (int j = 0; j < graph[i].size()-1; j++) { 
	                
	            	if(graph[i].get(j) == 1)
	            		graphob.addEdge(i, j);
	            } 
	            
	        }
			
		        if(graphob.isCyclic())
		            System.out.println("Graph contains cycle");
		        else
						{
		            System.out.println("Graph doesn't contain cycle therefore , the Topological sort of the given graph" );
					graphob.topologicalSort(); 	
					}
		        
		        myReader.close();
	    }
}