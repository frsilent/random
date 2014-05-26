/**
 * Instructions to run this code:
 * compile BagRunner.java and run in a terminal or IDE.
 * Output appears in the console.
 * @author Tim Elam
 */
import java.util.Scanner;
import java.io.*;

public class BagRunner {
    static long timer;
    static Bag bag1, bag2;
    
    public static void main(String[] args) throws Exception {
        PrintStream stdOut = System.out;
        /* Turn console output off
         */
        System.setOut(new PrintStream(new ByteArrayOutputStream()));
        //Initialize 2 small test bags
        bag1=new Bag();
        for(int i=0; i<30; i++) {
            bag1.add("i="+i%7);
        }
        bag2 = new Bag();
        for(int i=30; i<60; i++) {
            bag2.add("i="+i%4);
        }
        //Turn console output on
        System.setOut(stdOut);
        System.out.println("Small Bag Test");
        testBags();
        //Turn console output off
        System.setOut(new PrintStream(new ByteArrayOutputStream()));
        //Initialize 2 large test bags
        bag1=new Bag(500000);
        for(int i=0; i<400000; i++) {
            bag1.add("i="+i%1000);
        }
        bag2=new Bag(500000);
        for(int i=0; i<400000; i++) {
            bag2.add("i="+i%9740);
        }
        //Turn console output on
        System.setOut(stdOut);
        System.out.println("Large Bag Test");
        testBags(); 
    }
    //Prints out the complexity and run-times of every method
    public static void testBags() throws Exception{
        timer = System.currentTimeMillis();
        System.out.println("Add Information");
        bag1.add("i=0");
        resetTimer();
        System.out.println("Remove Random Information");
        bag1.removeRandom();
        resetTimer();
        System.out.println("Remove Information");
        bag1.remove("i=0");
        resetTimer();
        System.out.println("Is Empty Information");
        bag1.isEmpty();
        resetTimer();
        System.out.println("Contains Information");
        bag1.contains("asdf");
        resetTimer();
        System.out.println("Size Information");
        bag1.size();
        resetTimer();
        System.out.println("Add All Information");
        bag1.addAll(bag2);
        resetTimer();
        System.out.println("Union Information");
        Bag.union(bag1, bag2);
        resetTimer();
        System.out.println("Equals Information");
        bag1.equals(bag2);
        resetTimer();
    }
    //Displays elapsed time and resets the timer
    public static void resetTimer() {
        System.out.println("Elapsed time in milliseconds= "+(System.currentTimeMillis()-timer)+"\n");
        timer=System.currentTimeMillis();
    }
}
class Bag {
    private int max, count;
    private String[] b;
    public Bag() {
        max=100;
        b=new String[max];
    }
    public Bag(int size) {
        max=size;
        b=new String[max];
    }
    //Adds String str to this if space is available, throws exception otherwise
    public void add(String str) throws Exception {
        if (count==max) {
            System.out.println("Add complexity: 2");
            throw new Exception("Error: Out of bounds");
        } else {
            b[count]=str;
            count++;
            System.out.println("Add complexity: 3");
        }
        
    }
    //Retrieves str from this, throws exception if str is not found
    public String get(String str) throws Exception {
        System.out.println("Get complexity: 1");
        return b[locate(str)];
        
    }
    //Returns true if str is in this, false otherwise
    public boolean contains(String str) {
        System.out.println("Contains complexity: 1");
        return locate(str)!=-1;
    }
    //Helper function the returns the location of str, -1 if str is not present
    private int locate(String str) {
        int complexity=0;
        for(int i=0;i<count;i++) {
            complexity++;
            if (str.equals(b[i])) {
                System.out.println("Locate complexity: "+complexity);
                return i;
            }
        }
        System.out.println("Locate complexity: "+complexity);
        return -1;
    }
    //Removes a random String from this
    public void removeRandom() {
        int index=(int)(Math.random()*count);
        try {
        removeAtIndex(index);
        }
        catch(Exception e) {}
       System.out.println("Remove Random complexity: 2"); 
        
    }
    //Removes str if present, throws exception otherwise
    public void remove(String str) throws Exception{
        removeAtIndex(locate(str));
        System.out.println("Remove complexity: 1");
        
    }
    /* Helper function that removes the object at the specified index, throws
     * exception if the index is invalid
     */
    private void removeAtIndex(int index) throws Exception {
        if (index<0 || index>=max) {
            System.out.println("Remove at Index complexity: 2");
            throw new Exception("Error: item not present");
        }
        b[index]=b[count--];
        System.out.println("removeAtIndex complexity: 1");
    }
    //Returns true if this is empty, false otherwise
    public boolean isEmpty() {
        System.out.println("Is Empty complexity: 1");
        return count==0;
    }
    //Returns the number of Strings this contains
    public int size() {
        System.out.println("Size complexity: 1");
        return count;
    }
    //Returns a new Bag consisting of this followed by bag2
    public Bag addAll(Bag bag2) throws Exception{
        int complexity=2;
        Bag newBag = new Bag(max*2);
        for(int i=0; i<count; i++) {
            complexity++;
            newBag.b[i]=b[i];
        }
        for(int i=0; i<bag2.count; i++) {
            complexity++;
            newBag.b[i+count]=bag2.b[i];
        }
        System.out.println("Add all complexity: "+complexity);
        return newBag;       
    }
    //Returns a new Bag by combining b1 and b2 and eliminating duplicate elements
    public static Bag union(Bag b1, Bag b2) throws Exception {
        int complexity=2;
        Bag newBag;
        newBag = b1.addAll(b2);
        for(int i=0; i<newBag.count-1; i++) {
            for(int j=i+1; j<newBag.count; j++) {
                complexity++;
                if (newBag.b[i].equals(newBag.b[j])) {
                    complexity++;
                    newBag.removeAtIndex(j);
                    j--;
                }
            }
        }
        System.out.println("Union complexity: "+complexity);
        return newBag;
    }
    //Compares two bags by content for equivalence
    public boolean equals(Bag bag2) {
        if (count!=bag2.count) {
            System.out.println("Equals complexity: 1");
            return false;
        }
        Bag copyBag=(Bag)clone();
        Bag copyBag2=(Bag)bag2.clone();
        Bag bigBag= new Bag(2*max);
        try {
            bigBag=copyBag.addAll(bag2);
        }
        catch (Exception e) {}
        int index1, index2;
        int complexity=6;
        try {
            for(int i=0; i<bigBag.count; i++) {
                complexity+=2;
                index1=copyBag.locate(bigBag.b[i]);
                index2=copyBag2.locate(bigBag.b[i]);
                if (index1 != -1 && index2!= -1) {
                    copyBag.removeAtIndex(i);
                    copyBag2.removeAtIndex(i);
                    i--;
                    complexity+=3;
                } else {
                    System.out.println("Equals complexity: "+ complexity);
                    return false;
                }
            }
        } catch (Exception e) {}
        System.out.println("Equals complexity: "+ complexity);
        return true;
    }
    protected Object clone() {
        Bag newBag = new Bag(max);
        System.arraycopy(b, 0, newBag.b, 0, count);
        System.out.append("Clone complexity: 2 (+System.arraycopy complexity)");
        return newBag;
    }
}