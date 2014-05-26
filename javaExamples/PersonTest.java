public class PersonTest {
    public static void main(String[] args) throws Exception{
        Person personA = new Person("Bob");
        Person personB = new Person("Sally",personA);
        Person personC = new Person("Jill",personB);
        Person personD = new Person("Jim",personC);
        
    }
}
/*
search
        insert
                delete*/