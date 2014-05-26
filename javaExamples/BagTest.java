/*BagTest.java to implement & test the methods of the Bag class
Written by Heintze, Darrell R. 6544
09/04/2011
*/
//note Bag.java must be compiled in the same folder for this implementation to work!

public class BagTest {
    public static void main(String[] args) throws Exception{
        //call the constructor for two bag objects, one relatively small & the other relatively large
    	Bag smallBag = new Bag(10);
        for(int i=0; i<10; i++) {
            smallBag.bag[i]="lol"+i%3;
        }
        Bag bigBag = new Bag(10000);
        for(int i=0; i<10000; i++) {
            bigBag.bag[i]="lol"+i%3045;
        }

        //test the methods of our Bag class and print the times & complexities of each of them
        Long time = System.currentTimeMillis();
        System.out.println("add Info");
        smallBag.add("i=0");
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
        System.out.println("removeRandom Info");
        smallBag.removeRandom();
        System.out.println(System.currentTimeMillis()-time);
        time= System.currentTimeMillis();
        System.out.println("remove Info");
        smallBag.remove("i=0");
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
        System.out.println("isEmpty Info");
        smallBag.isEmpty();
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
        System.out.println("contains Info");
        smallBag.contains("qwer");
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
        System.out.println("size Info");
        smallBag.size();
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
        System.out.println("addAll Info");
        smallBag.addAll(smallBag);
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
        System.out.println("union Info");
        Bag.union(smallBag, smallBag);
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
        System.out.println("equals Info");
        smallBag.equals(smallBag);
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();

        //now testing the same methods for the same type of object with a larger array
        System.out.println("add Info");
        bigBag.add("i=0");
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
        System.out.println("removeRandom Info");
        bigBag.removeRandom();
        System.out.println(System.currentTimeMillis()-time);
        time= System.currentTimeMillis();
        System.out.println("remove Info");
        bigBag.remove("i=0");
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
        System.out.println("isEmpty Info");
        bigBag.isEmpty();
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
        System.out.println("contains Info");
        bigBag.contains("qwer");
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
        System.out.println("size Info");
        bigBag.size();
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
        System.out.println("addAll Info");
        bigBag.addAll(bigBag);
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
        System.out.println("union Info");
        Bag.union(bigBag, bigBag);
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
        System.out.println("equals Info");
        bigBag.equals(bigBag);
        System.out.println(System.currentTimeMillis()-time);
        time=System.currentTimeMillis();
    }
}