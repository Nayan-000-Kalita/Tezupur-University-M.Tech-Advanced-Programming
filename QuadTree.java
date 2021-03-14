/* The attached file contains detail of restaurants in a city. Use the coordinates of the restaurant (latitude and longitude) to store the date using Quadtree
For this cases write a functions that allow searching for restaurants -
i) within a user-given radius
ii) within a user-given radius above a specified rating
iii) within a user given radius that serve a specified cuisine
iv) within a user given radius above a specified rating and having more than a specified number of votes that serve a specified cuisine (Bonus)
*/

import java.util.*;
import java.io.*;
class QuadTree{ 


	//Used to hold details of Point
	static class Point
	{
		double x;
		double y;
		
		public Point(double a,double b)
		{
			x = a;
			y = b;
		}
		
		public Point()
		{
			x = 0;
			y = 0;
		}
	}


	/* Class containing left 
	and right child of current node 
	* and key value*/
	static class Node 
	{ 
		Point pos;
		int rid;
		String cuisines;
		int price;
		double rat;
		String rattxt;
		int votes;
		
		public Node(Point ps, int rid1,String cuisines1, int price1,double rat1,String rattxt1,int votes1) 
		{ 
			pos = ps;
			rid = rid1;
			cuisines = cuisines1;
			price = price1;
			rat = rat1;
			rattxt = rattxt1;
			votes = votes1;
			
			
		} 
		
		public Node()
		{
			pos = null;
			rid = 0;
			cuisines = "null";
			price = 0;
			rat = 0;
			rattxt = "null";
			votes = 0;
		}
	} 
	
	Point topLeft;
    Point botRight;
	
	// Contains details of Node
	Node n; 
	
	// Children of this tree
    QuadTree topLeftTree;
    QuadTree topRightTree;
    QuadTree botLeftTree;
    QuadTree botRightTree;

	// Constructor 
	QuadTree() 
	{ 
		Point topLeft = new Point(0, 0);
        Point botRight = new Point(0, 0);
        n = null;
        topLeftTree  = null;
        topRightTree = null;
        botLeftTree  = null;
        botRightTree = null;
	} 
	
	QuadTree(Point topL, Point botR)
    {
        n = null;
        topLeftTree  = null;
        topRightTree = null;
        botLeftTree  = null;
        botRightTree = null;
        topLeft = topL;
        botRight = botR;
    }

	
	/* A recursive function to 
	insert a new node in QuadTree*/
	void insert(Node node) 
	{ 
		
		if (node == null)
        return;
		
		if (!inBoundary(node.pos))
        return;

		
        if (Math.abs(topLeft.x - botRight.x) <= 0.000000000001 && Math.abs(topLeft.y - botRight.y) <= 0.000000000001) 
    { 
        if (n == null) 
		
		{
			System.out.println("\nRestaurant ID :"+node.rid+"\n"+
								"Longitude :"+node.pos.x+"\n"+
								"Latitude :"+node.pos.y+"\n"+
								"Cuisines :"+node.cuisines+"\n"+
								"Price Range :"+node.price+"\n"+
								"Aggregrate Rating :"+node.rat+"\n"+
								"Rating Text :"+node.rattxt+"\n"+
								"Votes :"+node.votes+"\n\n");
			n = node; 
		}
        return; 
    } 
  
           
	
	
	if ((topLeft.x + botRight.x) / 2.0 >= node.pos.x)
    {
        // Indicates topLeftTree
        if ((topLeft.y + botRight.y) / 2.0 >= node.pos.y)
        {
            if (topLeftTree == null)
			{
				Point p = new Point(topLeft.x, topLeft.y);
				Point q = new Point((topLeft.x + botRight.x) / 2.0,(topLeft.y + botRight.y) / 2.0);
                topLeftTree = new QuadTree(p,q);
				
			}
            topLeftTree.insert(node);
        }
		
		// Indicates botLeftTree
        else
        {
            if (botLeftTree == null)
			{
				Point p = new Point(topLeft.x, (topLeft.y + botRight.y) / 2.0);
				Point q = new Point((topLeft.x + botRight.x) / 2.0, botRight.y);
				botLeftTree = new QuadTree(p, q);
				
			}
            botLeftTree.insert(node);
        }
    }
	
	else if ((topLeft.x + botRight.x) / 2.0 <= node.pos.x)
    {
        // Indicates topRightTree
        if ((topLeft.y + botRight.y) / 2.0 >= node.pos.y)
        {
            if (topRightTree == null)
			{
				Point p = new Point((topLeft.x + botRight.x) / 2.0,topLeft.y);
				Point q = new Point(botRight.x, (topLeft.y + botRight.y) / 2.0);
                topRightTree = new QuadTree(p, q);
				
			}
            topRightTree.insert(node);
        }
		
		// Indicates botRightTree
        else
        {
            if (botRightTree == null)
			{
				Point p = new Point((topLeft.x + botRight.x) / 2.0,  (topLeft.y + botRight.y) / 2.0);
				Point q = new Point(botRight.x, botRight.y);
                botRightTree = new QuadTree(p, q);
			}
            botRightTree.insert(node);
        }
	}
	}
	
	
	// Check if current CSE20006_Quadtree contains the point
	boolean inBoundary(Point p)
	{
		return (p.x >= topLeft.x && p.x <= botRight.x && p.y >= topLeft.y && p.y <= botRight.y);
	}
	

public static void main(String[] args)throws IOException
	{
	Scanner sc = new Scanner(System.in);
	Scanner sc1 = new Scanner(System.in);
	Scanner sc2 = new Scanner(System.in);
	Scanner sc3 = new Scanner(System.in);
	Scanner myReader = new Scanner(new File("asn4b.csv"));
	ArrayList <String> temp = new ArrayList <String>();
	 ArrayList <String>[] record = new ArrayList [100];
	 int row = 0;
   
	while (myReader.hasNextLine()) {
	        String data = myReader.nextLine();
			//System.out.println(data);
	for (String retval: data.split(",")){
	        //System.out.print(retval+" , ");
			temp.add(retval);
	        }
			//System.out.println(temp+"\n");
			record[row] = new ArrayList<String>(); 
	        record[row].addAll(temp);
	        row++;
			temp.clear();
		
		} 
		myReader.close();
		
	
	
	/*for(int i=0;i<row;i++)
	{
		for(int j=0;j<record[i].size()-1;j++)
		System.out.print(record[i].get(j)+" ");
		System.out.println("\n");
	}*/
	
	System.out.println("Enter Search Range P(x1,y1)");
	System.out.print("x1 :");
	double x1=sc1.nextDouble();
	System.out.print("y1 :");
	double y1=sc1.nextDouble();
	
	
	System.out.println("Enter Search Range Q(x2,y2): \n(x2 >x1 ) and (y2 >y1) ");
	System.out.print("x2 :");
	double x2=sc1.nextDouble();
	System.out.print("y2 :");
	double y2=sc1.nextDouble();
	
	if(x2 <  x1 && y2 < y1)
	{
	System.out.println("Condition not satisfied : Plane not created");
	return;
	}
	
	
	Point p =new Point(x1, y1);
	Point q= new Point(x2, y2);
	QuadTree center = new QuadTree(p, q);
	int count =0;
	
	
	System.out.println("Do you want to add Rating (0 - 5) as a filter : Y/N ?");
	
	char ch = sc2.next().charAt(0);
	
	switch(ch)
	{
		case 'y':
		case 'Y':
		System.out.println("Enter Rating (0 - 5) :");
		double rating = sc1.nextDouble();
		for(int i=1;i<row;i++)
	{
		for(int j=0;j<record[i].size()-1;j++)
		{
			Point x = new Point(Double.valueOf(record[i].get(1)), Double.valueOf(record[i].get(2)));
			Node a = new Node(x, Integer.valueOf(record[i].get(0)), 
								record[i].get(3), 
								Integer.valueOf(record[i].get(4)), 
								Double.valueOf(record[i].get(5)), 
								record[i].get(6), 
								Integer.valueOf(record[i].get(7)));
			if(Double.valueOf(record[i].get(5))>= rating)
			{
			count=1;
			center.insert(a);
			}
			
			
		}
		
	}
	if(count == 0)
	System.out.println("No data points available");
	return;
		
	}
	
	System.out.println("Do you want to add Cuisines as a filter : Y/N ?");
	
	char ch1 = sc2.next().charAt(0);
	
	switch(ch1)
	{
		case 'y':
		case 'Y':
		System.out.println("Enter Cuisines :");
		String cuisines = sc3.next();
		for(int i=1;i<row;i++)
	{
		for(int j=0;j<record[i].size()-1;j++)
		{
			Point x = new Point(Double.valueOf(record[i].get(1)), Double.valueOf(record[i].get(2)));
			Node a = new Node(x, Integer.valueOf(record[i].get(0)), 
								record[i].get(3), 
								Integer.valueOf(record[i].get(4)), 
								Double.valueOf(record[i].get(5)), 
								record[i].get(6), 
								Integer.valueOf(record[i].get(7)));
			if(record[i].get(3).toLowerCase().contains(cuisines.toLowerCase()))
			{
			count = 1;
				
			center.insert(a);
			}
			
		}
		
	}
	if(count == 0)
	System.out.println("No data points available");
	return;
		
	}
	
		
	for(int i=1;i<row;i++)
	{
		for(int j=0;j<record[i].size()-1;j++)
		{
			Point x = new Point(Double.valueOf(record[i].get(1)), Double.valueOf(record[i].get(2)));
			Node a = new Node(x, Integer.valueOf(record[i].get(0)), 
								record[i].get(3), 
								Integer.valueOf(record[i].get(4)), 
								Double.valueOf(record[i].get(5)), 
								record[i].get(6), 
								Integer.valueOf(record[i].get(7)));
			center.insert(a);
			
		}
		
	}
		
	}
	}