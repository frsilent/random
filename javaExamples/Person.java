/*Person.java to implement a doubly linked list
Written by Heintze, Darrell R. 6544
09/18/2011
*/
public class Person {
    String name;

    Person prev;
    Person next;
    
    //constructor for the first element
    public Person(String personName) {
        this.name = personName;
    }
    //constructor for following elements, initializing the prev & next
    public Person(String currentPerson, Person previousPerson, Person nextPerson) {
    this.prev = previousPerson;
    this.name = currentPerson;
    this.next = nextPerson;
    }
    //constructor for last element
    public Person(String currentPerson, Person previousPerson) {
        this.prev = previousPerson;
        this.name = currentPerson;
    }
    //a main method to test the methods
    public static void main(String[] args) throws Exception{
        //create a set to work with
        Person personA = new Person("Bob");
        Person personB = new Person("Sally",personA);
        Person personC = new Person("Jill",personB);
        Person personD = new Person("Jim",personC);
        personA.next = personB;
        personB.next = personC;
        System.out.println("Sally is located at: " + search(personA, "Sally"));
        System.out.println("Adding a new person after Sally.");
        insert("Joseph",personB);
        System.out.println("Deleting a person now.");
        delete(personB);
    }
    
    //setter methods
    void setPrev(Person prev) {
	this.prev = prev;
    }
    void setNext(Person next) {
	this.next = next;
    }
    
    public static Person search(Person index, String target) {
    while (index != null && (index.name == null ? target != null : !index.name.equals(target))) {
        index = index.next;
        }
        return index;
    }
    
    public static void insert(String newPerson, Person insertPoint) {
        Person insertedPerson = new Person(newPerson,insertPoint.prev,insertPoint);
    }

    public static void delete(Person x) {
        next.prev = x.prev;
        prev.next = x.next;
    }
}