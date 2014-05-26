/*Bag.java to implement a class of objects which contain an array and count of the elements
Written by Heintze, Darrell R. 6544
09/04/2011
*/

import java.util.Random;
class Bag
{
  public static Random randomObject = new Random();
  public final int MAX = 100;
  public final int NOT_FOUND = -1;
  public int count;  // the current number of elements in the set
  public String bag[];

  //constructors, a default & one with a specificied starting size
  public Bag() {
      bag = new String[MAX];
      count = MAX;
  }
  public Bag(int size) {
      bag = new String[size];
      count = size;
  }

  //tests to see if the bag is full & expands it if so
  //then adds a new element to the bag
  public void add(String newElement) {
      if (!(contains(newElement))) {
          if (size() == bag.length)
              expandMAX();


          bag[count] = newElement;
          count++;
          System.out.println("add complexity: 3");
        }
  }

  //method to create a larger bag if count gets too big for bag.length
  private void expandMAX()
  {
    String[] biggerBag = (String[])(new String[bag.length*2]);
        System.arraycopy(bag, 0, biggerBag, 0, bag.length);

    bag = biggerBag;
    System.out.println("expandMax complexity: "+ bag.length+1);
  }

  //method to remove a random element from the array
  public void removeRandom() throws Exception{
    if (isEmpty())
      throw new Exception("Bag is Empty");

    int choice = randomObject.nextInt(count);

    String result = bag[choice];

    bag[choice] = bag[count-1];  // fill the gap
    bag[count-1] = null;
    count--;
    System.out.println("removeRandom complexity: " + 6);
    }

  //method to remove a specific element (target) from the bag
  public void remove(String target) throws Exception{

    if (isEmpty())
      throw new Exception("Bag is Empty");
    int index=-1;
    for (int i=0; i < count ; i++)
      if (bag[i].equals(target)) {
          index = i;
          break;
      }

    if (index==-1)
      throw new Exception("Item not found");

    String result = bag[index];

    bag[index] = bag[count-1];
    bag[count-1] = null;
    count--;
    System.out.println("remove complexity: " + ((index<0)?count:index)+7);
    }

  //returns true if the bag is empty, false otherwise
  public boolean isEmpty() {
      System.out.println("isEmpty complexity: 1");
      return (count == 0);
  }

  //checks to see if a specific element (target) appears in the bag
  public boolean contains(String target) {
    int search = NOT_FOUND;

    for (int i=0; i < count && search == NOT_FOUND; i++)
      if (bag[i].equals(target))
        search = i;
    System.out.println("contains complexity: " + ((search<0)?count:search)+1);
    return (search != NOT_FOUND);
  }

  //accessor for number of elements in our bag
  public int size() {
      System.out.println("size complexity: 1");
      return count;
  }

  //method to add all of the elements of the element to a new bag
  public Bag addAll(Bag addingFrom) {
      Bag newBag = new Bag(addingFrom.size()*2);
      for(int i=0;i<addingFrom.size();i++) {
          newBag.add(addingFrom.bag[i]);
      }
     for(int i=0;i<this.size();i++) {
          newBag.add(this.bag[i]);
      }
      System.out.println("addAll complexity: " + this.count+addingFrom.count);
      return newBag;
  }

  //method to combine the elements of two bags all into one larger one, bagUnion
  public static Bag union(Bag bag1, Bag bag2) {
    Bag bagUnion = new Bag();
    for(int i=0;i<bag1.size();i++) {
        bagUnion.add(bag1.bag[i]);
    }
    for(int i=0;i < bag2.size(); i++) {
        bagUnion.add(bag2.bag[i]);
    }
    System.out.println("union complexity: " + bag1.count+bag2.count);
    return bagUnion;
  }

  //method that compares two bags to see if they contain the same elements
  public boolean equals(Bag bag2) {
      if (this.count!=bag2.count) {
          System.out.println("equals complexity: 1");
          return false;
      }
      Bag copy1 = this.addAll(new Bag());
      Bag copy2 = bag2.addAll(new Bag());
      for(int i=0; i<this.count; i++) {
          if (!bag2.contains(this.bag[i])) {
              System.out.println("equals complexity: "+4+i);
              return false;
          }
      }
      System.out.println("equals complexity: " + this.count+3);
      return true;
  }
}