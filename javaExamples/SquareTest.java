// ****************************************************************
// SquareTest.java
//
// Uses the Square class to read in square data and tell if
// each square is magic.
//
// ****************************************************************
import java.util.Scanner;
import java.io.*;

public class SquareTest
{
	public static void main(String[] args) throws IOException
	{
		Scanner scan = new Scanner(new File("magicData.txt"));
		
		int count = 1; //count which square we're on
		int size = scan.nextInt(); //size of next square
		
		//Expecting -1 at bottom of input file
		while (size != -1)
		{
			//create a new Square of the given size
			Square magic = new Square(size);
			//call its read method to read the values of the square
			magic.readSquare(scan);
			
			System.out.println("\n******** Square " + count + " ********");
			//print the square
			magic.printSquare();
			
			//print the sums of its rows
			for(int row = 0; row < size; row++)
	      	{
	      		System.out.println("The sum of row " + row + ":");
		      	System.out.println( magic.sumRow(row) );
	      	}
			
			//print the sums of its columns
			for(int col = 0; col < size; col++)
	      	{
	      		System.out.println("The sum of column " + col + ":");
		      	System.out.println( magic.sumCol(col) );
	      	}
	      	
			//print the sum of the main diagonal
			System.out.println("The sum of the main diagonal: ");
			System.out.println( magic.sumMainDiag() );
			
			//print the sum of the other diagonal
			System.out.println("The sum of the other diagonal: ");
			System.out.println( magic.sumOtherDiag() );
			
			//determine if it's a magic square
		/*	String magicResult;
			if (magic.magic(size) == true) {
				magicResult = " is";
     		} else {
          			magicResult = " is not";
     		}
     		//print if it's a magic square
			System.out.println("Square " + count + magicResult + " a magic square.");
		*/
			System.out.println("Square " + count + ": " + magic.magic(size));
			//get size of next square
			size = scan.nextInt();
			count++;
		}
	}
}