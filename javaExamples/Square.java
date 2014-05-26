// ****************************************************************
// Square.java
//
// Define a Square class with methods to create and read in
// info for a square matrix and to compute the sum of a row,
// a col, either diagonal, and whether it is magic.
//
// ****************************************************************
import java.util.Scanner;
public class Square
{
	int[][] square;

	//create new square of given size
	public Square(int size)
	{
		square = new int[size][size];
	}
	
	//return the sum of the values in the given row
	public int sumRow(int row)
	{
		int sum = 0;
		for(int col = 0 ; col < square.length; col++)
	      {
	      	sum = sum + square[row][col];
	      }
	      return sum;
	}
	
	//return the sum of the values in the given column
	public int sumCol(int col)
	{
		int sum = 0;
		for(int row = 0; row < square.length; row++)
		{
			sum = sum + square[row][col];
		}      
			return sum;
	}

	//return the sum of the values in the main diagonal
	public int sumMainDiag()
	{
		int sum = 0;
		for(int i = 0; i < square.length; i++)
		{
			sum = sum + square[i][i];
		}
		return sum;
	}

	//return the sum of the values in the other ("reverse") diagonal
	public int sumOtherDiag()
	{
		int sum = 0;
		for(int row = 0 ; row < square.length; row++)
		{
			int col = square.length - 1;
			sum = sum + square[row][col];
			col--;
		}
		return sum;
	}

	//return true if the square is magic (all rows, cols, and diags have
	//same sum), false otherwise
	public boolean magic(int size)
	{
		//make a 1-d array & put the sum values into it
		int[] x = new int[ 2 * size + 2];
		
		//make int s as the index for where we're at in the array
		int s = 0;
			for(int j=0; j < size ; j++)
				{
					x[s] = sumRow(j);
					s++;
				}
			for(int j=0; j < size ; j++)
				{
					x[s] = sumCol(j);
					s++;
				}
			x[s] = sumMainDiag();
			s++;
			x[s] = sumOtherDiag();
		
		//just to check what array is being saved as
		for(int i = 0; i < x.length; i++)
	      {
	      	System.out.print(x[i] + " ");
	      }      
	      System.out.println();
		
		//check to see if every value in the array is the same, if not it returns false
		boolean result = true;
		for(int i=0; i < x.length - 1; i++)
		  {
			int a = x[i];
			int b = x[i+1];
			if (a != b)
			  {
			  result = false;
			  return result;
			  }
			return result;
		  }
		  return result;
}
	
	//read info into the square from the input stream associated with the
	//Scanner parameter
	public void readSquare(Scanner scan)
	{
		for (int row = 0; row < square.length; row++)
		{
			for (int col = 0; col < square.length; col++)
			{
			square[row][col] = scan.nextInt();
			}
		}
	}
	//print the contents of the square, neatly formatted
	public void printSquare()
	{
		for(int row = 0; row < square.length; row++)
      	{
	      for(int col = 0; col < square[row].length; col++)
	      {
	      	System.out.print(square[row][col] + " ");
	      }      
	      System.out.println();
      	}
     }
}