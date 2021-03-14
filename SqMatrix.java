/*Write a program to take as input a square matrix, A, and compute the following:
i) |A|
ii) c*A , where c is a scalar value given as user input
iii) The transpose of A
iv) The square of A i.e. A*A
v) The inverse of A
Note that A can be of any dimension n x n and will be given as input via a text file. You can consider the attached file as a sample input.
 */

import java.util.*;
import java.io.*;
class SqMatrix
{
// Function to get cofactor of A[p][q] in temp[][]. n is current 
// dimension of A[][] 
static void getCofactor(int A[][], int temp[][], int p, int q, int n) 
{ 
    int i = 0, j = 0; 
  
    // Looping for each element of the matrix 
    for (int row = 0; row < n; row++) 
    { 
        for (int col = 0; col < n; col++) 
        { 
            // Copying into temporary matrix only those element 
            // which are not in given row and column 
            if (row != p && col != q) 
            { 
                temp[i][j++] = A[row][col]; 
  
                // Row is filled, so increase row index and 
                // reset col index 
                if (j == n - 1) 
                { 
                    j = 0; 
                    i++; 
                } 
            } 
        } 
    } 
} 
  
/* Recursive function for finding determinant of matrix. 
n is current dimension of A[][]. */
static int determinant(int A[][], int n) 
{ 
    int D = 0; // Initialize result 
  
    // Base case : if matrix contains single element 
    if (n == 1) 
        return A[0][0]; 
  
    int [][]temp = new int[n][n]; // To store cofactors 
  
    int sign = 1; // To store sign multiplier 
  
    // Iterate for each element of first row 
    for (int f = 0; f < n; f++) 
    { 
        // Getting Cofactor of A[0][f] 
        getCofactor(A, temp, 0, f, n); 
        D += sign * A[0][f] * determinant(temp, n - 1); 
  
        // terms are to be added with alternate sign 
        sign = -sign; 
    } 
  
    return D; 
} 

//Calculate Square of a matrix// This function multiplies mat1[][]
   

    static void multiply(int mat1[][], int res[][],int N)
    {
        int i, j, k;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                res[i][j] = 0;
                for (k = 0; k < N; k++)
                    res[i][j] += mat1[i][k]
                                 * mat1[k][j];
            }
        }
    }

// Function to get adjoint of A[N][N] in adj[N][N]. 
static void adjoint(int A[][],int [][]adj,int N) 
{ 
    if (N == 1) 
    { 
        adj[0][0] = 1; 
        return; 
    } 
  
    // temp is used to store cofactors of A[][] 
    int sign = 1; 
    int [][]temp = new int[N][N]; 
  
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
        { 
            // Get cofactor of A[i][j] 
            getCofactor(A, temp, i, j, N); 
  
            // sign of adj[j][i] positive if sum of row 
            // and column indexes is even. 
            sign = ((i + j) % 2 == 0)? 1: -1; 
  
            // Interchanging rows and columns to get the 
            // transpose of the cofactor matrix 
            adj[j][i] = (sign)*(determinant(temp, N-1)); 
        } 
    } 
} 
  
// Function to calculate and store inverse, returns false if 
// matrix is singular 
static boolean inverse(int A[][], float [][]inverse, int N) 
{ 
    // Find determinant of A[][] 
    int det = determinant(A, N); 
    if (det == 0) 
    { 
        System.out.print("Singular matrix, can't find its inverse"); 
        return false; 
    } 
  
    // Find adjoint 
    int [][]adj = new int[N][N]; 
    adjoint(A, adj,N); 
  
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)" 
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            inverse[i][j] = adj[i][j]/(float)det; 
  
    return true; 
} 	
	
	
	
	
	
	
	
	public static void main(String[] args)throws IOException
	{
	Scanner sc = new Scanner(System.in);
	
	Scanner myReader = new Scanner(new File("asn5.txt"));
	ArrayList <Integer> temp = new ArrayList <Integer>();
	
	int row = 0;
   
	while (myReader.hasNextLine()) {
	        String data = myReader.nextLine();
			//System.out.println(data);
	for (String retval: data.split(" ")){
	        //System.out.print(retval+" , ");
			temp.add(Integer.parseInt(retval));
	        }
			//System.out.println(temp+"\n");
	        row++;
			temp.clear();
		
		} 
		myReader.close();
		myReader = new Scanner(new File("asn5.txt"));
		ArrayList <Integer>[] mat = new ArrayList [row];
		row = 0;
		
		while (myReader.hasNextLine()) {
	        String data = myReader.nextLine();
			//System.out.println(data);
			for (String retval: data.split(" ")){
	        //System.out.print(retval+" , ");
			temp.add(Integer.parseInt(retval));
	        }
			//System.out.println("Matrix: "+"\n"+temp+"\n");
			mat[row] = new ArrayList<Integer>(); 
	        mat[row].addAll(temp);
	        row++;
			temp.clear();
		
		} 
		myReader.close();
		
		int[][] matrix = new int[row][row]; 
		System.out.print("Given Matrix: "+"\n");		
		for(int i=0;i < row; i++)
		{
			for(int j=0;j<mat[i].size(); j++)
			{
			System.out.print(mat[i].get(j)+"\t");
			matrix[i][j] = mat[i].get(j);
			}
			System.out.println();
		}
		
		System.out.println("\nDeterminant of Matrix: "+determinant(matrix, row) );
		
		System.out.println("\nTranspose Matrix");
		for(int i=0;i < row; i++)
		{
			for(int j=0;j<row; j++)
			{
			System.out.print(matrix[j][i]+"\t");
			
			}
			System.out.println();
		}
		
		int[][] res = new int[row][row]; 
		multiply(matrix, res, row);
		
		System.out.println("\nSquare of Matrix");
		for(int i=0;i < row; i++)
		{
			for(int j=0;j<row; j++)
			{
			System.out.print(res[i][j]+"\t");
			
			}
			System.out.println();
		}
		
		
		float[][] inv = new float[row][row]; 
		inverse(matrix, inv, row);
		
		System.out.println("\nInverse of Matrix");
		for(int i=0;i < row; i++)
		{
			for(int j=0;j<row; j++)
			{
			System.out.print(inv[i][j]+"\t");
			
			}
			System.out.println();
		}
		
		System.out.println("\nEnter a Scalar value ");
		int c = sc.nextInt();
		System.out.println("\nScalar Multiplication");
		
		for(int i=0;i < row; i++)
		{
			for(int j=0;j<row; j++)
			{
			System.out.print((c * matrix[i][j])+"\t");
			
			}
			System.out.println();
		}