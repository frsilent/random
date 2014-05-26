
/**
 * DominoTester.java
 * A program that tests the Domino class to make
 * sure that it is working correctly. 
 */
public class DominoTester 
{
	
    public static void main(String [] args) 
    {
    	
		int domino1Minor = 0;  //minor suit of first domino
		int domino1Major = 6;  //major suit of first domino
		int domino2Major = 3;  //major suit of second domino		
		int domino2Minor = 3;  //minor suit of second domino
	
		Domino domino1 = new Domino(domino1Minor,domino1Major);
		Domino domino2 = new Domino(domino2Major, domino2Minor);
	
		//check the major and minor suits to make sure that the
		//domino was created correctly
		if(domino1.getMajor() != domino1Major)
		{
			System.out.println("Major suit of Domino 1 is incorrect.");
		}
		
		else
		{
			System.out.println("Major suit of Domino 1 is correct!");
		}
	
	
		if(domino1.getMinor() != domino1Minor)
		{
			System.out.println("Minor suit of Domino 1 is incorrect.");
		}
		else
		{
			System.out.println("Minor suit of Domino 1 is correct!");
		}
		 
	  
		if(domino2.getMajor() != domino2Major)
		{
			System.out.println("Major suit of Domino 2 is incorrect.");
		}
		
		else
		{
			System.out.println("Major suit of Domino 2 is correct!");
		}
	
	
		if(domino2.getMinor() != domino2Minor)
		{
			System.out.println("Minor suit of Domino 2 is incorrect.");
		}
		else
		{
			System.out.println("Minor suit of Domino 2 is correct!");
		}

		//
		//check the domino prints out correctly
		//
			    
		System.out.println("Domino 1: " + domino1);
		if(domino1.toString().equals("6 - 0")) 
		{
			System.out.println("toString is working correctly for domino 1");
		}	    
		else 
		{
			System.out.println("toString is not working correctly for domino 1");
		}
		
	
		System.out.println("Domino 2: " + domino2);
		if(domino2.toString().equals("3 - 3"))
		{
		    System.out.println("toString is working correctly for domino 2");		
		}
		else
		{
			System.out.println("toString is not working correctly for domino 2");
		}
	
		//
		//check the method isBlank
		//		
		if(domino1.isBlank())
		{
		    System.out.println("isBlank is working correctly for domino 1");		
		}
		else
		{
			System.out.println("isBlank is not working correctly for domino 1");
		}	    

		//
		//check the method isDouble
		//			
	    if(domino2.isDouble())
		{
		    System.out.println("isDouble is working correctly for domino 2");		
		}
		else
		{
			System.out.println("isDouble is not working correctly for domino 2");
		}

		//
		//check the method getWeight
		//				
		if(domino1.getWeight() == 6)
		{
		    System.out.println("getWeight is working correctly for domino 1");		
		}
		else
		{
			System.out.println("getWeight is not working correctly for domino 1");
		}	    
	
	    if(domino2.getWeight() == 6)
		{
		    System.out.println("getWeight is working correctly for domino 2");		
		}
		else
		{
			System.out.println("getWeight is not working correctly for domino 2");
		}
	
		//
		//Random generated Domino objects
		//		
		Domino domino3 = new Domino();
	
		System.out.println("Randomly Generated domino: " + domino3);
	
		Domino domino4 = new Domino(-100, 1000);
	
		System.out.println("Invalid domino defaulted to: " + domino4);


		//insert your code to test the isHigher method here.

    }
    //end main
}
//end class
