//********************************************************************//  LinkedList.java       Authors: Lewis/Chase////  Represents a linked implementation of a list.//********************************************************************package jss2;import jss2.exceptions.*;import java.util.*;public class LinkedList<T> implements ListADT<T>, Iterable<T>{   protected int count;   protected LinearNode<T> head, tail;      /******************************************************************     Creates an empty list.   ******************************************************************/   public LinkedList()   {   }      /******************************************************************     Removes the first element in this list and returns a reference     to it.  Throws an EmptyListException if the list is empty.   ******************************************************************/   public T removeFirst() throws EmptyCollectionException   {   }      /******************************************************************     Removes the last element in this list and returns a reference     to it.  Throws an EmptyListException if the list is empty.   ******************************************************************/   public T removeLast() throws EmptyCollectionException   {   }      /******************************************************************     Removes the first instance of the specified element from this     list and returns a reference to it.  Throws an EmptyListException      if the list is empty.  Throws a NoSuchElementException if the      specified element is not found in the list.   ******************************************************************/   public T remove (T targetElement) throws EmptyCollectionException,          ElementNotFoundException    {      if (isEmpty())         throw new EmptyCollectionException ("List");            boolean found = false;      LinearNode<T> previous = null;      LinearNode<T> current = head;            while (current != null && !found)         if (targetElement.equals (current.getElement()))            found = true;         else         {            previous = current;            current = current.getNext();         }                  if (!found)         throw new ElementNotFoundException ("List");            if (size() == 1)         head = tail = null;      else if (current.equals (head))         head = current.getNext();      else if (current.equals (tail))      {         tail = previous;         tail.setNext(null);      }      else         previous.setNext(current.getNext());            count--;            return current.getElement();   }      /******************************************************************     Returns true if the specified element is found in this list and      false otherwise.  Throws an EmptyListException if the specified     element is not found in the list.                                        ******************************************************************/   public boolean contains (T targetElement) throws          EmptyCollectionException    {   }      /******************************************************************     Returns true if this list is empty and false otherwise.   ******************************************************************/   public boolean isEmpty()   {   }   /******************************************************************     Returns the number of elements in this list.   ******************************************************************/   public int size()   {   }   /******************************************************************     Returns a string representation of this list.   ******************************************************************/   public String toString()   {   }   /******************************************************************     Returns an iterator for the elements currently in this list.    ******************************************************************/   public Iterator<T> iterator()   {   }   /******************************************************************     Returns the first element in this list.    ******************************************************************/   public T first()   {   }   /******************************************************************     Returns the last element in this list.    ******************************************************************/   public T last()   {   }}