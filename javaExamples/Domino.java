/*
 * Include the introductory comments here
 */


/**
 * 	 Domino.java
 *   This is code for a Domino class which represents a domino in a standard
 *   domino set. Each domino has a major and a minor.
 */ 
import java.util.Random;
public class Domino {
    
    // static random object
    static Random ranGenerator=new Random();
    
    // instance data declarations
    private int major;
    private int minor;
    

    /**
     *  Default constructor - it should construct
     *  a random domino (i.e. it should assign random
     *  values to major and minor).  Make sure the
     *  random values make sense for a domino tile.
     */
    public Domino() {
		major = 0;  //default assignment - needs to be changed
		minor = 0;  //default assignment - needs to be changed    	
    
    }

    /*
     *  Constructor that creates a domino bone with a major and a minor 
     *  for two numbers num1 and num2. If any of these numbers
     *  is not in the range 0 - 6, assign 0 to the major and the minor
     */
    public Domino(int num1, int num2) {
		major = 0;  //default assignment - needs to be changed
		minor = 0;  //default assignment - needs to be changed    	
    }

    /*
     *  Returns the major of a domino
     */ 
    public int getMajor() {

		//default return statement - needs to be changed
		return 0;
    }

    /*
     *  Returns the minor of a domino
     */ 
    public int getMinor() {

		//default return statement - needs to be changed
		return 0;
    }
    
    /*
     *  Returns the weight of a domino
     */ 
    public int getWeight() {

		//default return statement - needs to be changed
		return 0;
    }

    /*
     *  Returns true if this domino is a double
     */ 
    public boolean isDouble() {

		//default return statement - needs to be changed
		return true;
    }

    /*
     *  Returns true if this domino is a blank (the minor is zero)
     */ 
    public boolean isBlank() {

		//default return statement - needs to be changed
		return false;
    }

    /**
     *  Returns true if this domino has higher rank than
     *  Domino d.  Returns false otherwise.  So if
     *  this domino's major is higher than d's major, 
     *  it returns true.  If the majors are the same,
     *  then it checks the minor - if this minor is 
     *  higher than d's minor, then it returns true.
     *  Otherwise, it returns false.  
     *  For example, 6 - 0 has higher rank than 3 - 3, and
     *  5 - 3 has higher rank than 5 - 2    
     */
    public boolean isHigher(Domino d) {
    	
    	
		//default return statement - needs to be changed
		return true;
    }
    
    
    /**
     *  Returns a String representation of this
     *  domino.  
     */
    public String toString() {
		
		//default return statement - needs to be changed
		return "0 - 0";
		
    }


}
//end class Domino
