/*@Heintze, Darrell R. 6544
 *Assignment:
 * Build binary search trees for arrays of integers, and use in-order traversal to sort the arrays.
 */

import java.io.*;
import java.util.*;

class Node {
   public int value;
   public Node leftChild;
   public Node rightChild;
   }

class bstEx {
   private Node root;
   public bstEx() { root = null; }
   
   public Node find(int key) {
      Node current = root;
      while(current.value != key) {
         if(key < current.value)
            current = current.leftChild;
         else
            current = current.rightChild;
         if(current == null)
            return null;
         }
      return current;
      }
   
   public void insert(int id) {
      Node newNode = new Node();
      newNode.value = id;
      if(root==null)
         root = newNode;
      else {
         Node current = root;
         Node parent;
         while(true) {
            parent = current;
            if(id < current.value) {
               current = current.leftChild;
               if(current == null) {
                  parent.leftChild = newNode;
                  return;
               }
            } else {
               current = current.rightChild;
               if(current == null) {
                  parent.rightChild = newNode;
                  return;
               }
            }
         }
      }
   }
   public void inOrderSort(int x[]) {

       if(x != null)
         {
         inOrderSort(x.leftChild);
         System.out.print(x.value + " ");
         inOrderSort(x.rightChild);
         }
      }
   }
class bstExApp
   {
   public static void main(String[] args) throws IOException {
       Random rGen = new Random();
       int elements = 100;
       int[] ourArray = new int[elements];
       for(int i=0;i<elements;i++) {
           ourArray[i]=rGen.nextInt(50) + 1;
       }
       inOrderSort(ourArray);
   }

   }