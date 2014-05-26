/*
 * Work during Thursdays� class or at home, turn in next Tuesday (Sep 20)
1. Write a recursive method to reverse a string, and compute the complexity of your method.

2. Write a recursive method that returns the value of N! (N factorial), and compute the complexity of your method. Explain why you would not normally use recursion to solve this problem.

3. Find the exact numbers of comparisons using both linear search and binary search to search target = 3 in the following array:
int[] a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}. Then do the same thing for target =22.
        */

public class recursion {
    public static void main(String[] args) throws Exception{
        int[] a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
        System.out.println("A linear search for target 3: ");
        linearSearch(a,3);
        System.out.println("A binary search for target 3: ");
        binarySearch(a,3);
        System.out.println("A linear search for target 22: ");
        linearSearch(a,22);
        System.out.println("A binary search for target 22: ");
        binarySearch(a,22);
    }
    
    void quicksort(int x[], int l, int r) {
      int i = l-1, j = r, v= x[r];
      if (r <= l) return;
      for (;;)
        { 
           while (x[++i] < v)
           while (v < x[--j]) if (j == l) break;
           if (i >= j) break;
           exch(x[i], x[j]);
        } 
      exch(x[i], x[r]);
    quicksort(x, l, i-1);
    quicksort(x, i+1, r);
    }
    
    static int binarySearch(int x[], int target) {
        int left=0, right=x.length-1, mid=(left+right)/2, complexity=0;
        while(left<=right) {
            if(x[mid]==target) {
                System.out.println("binarySearch complexity: "+complexity);
                return mid;
            } else if(x[mid]>target) {
                right = mid-1;
                complexity+=1;
            } else 
                left = mid+1;
                complexity+=1;
        }
        System.out.println("binarySearch complexity: "+complexity);
        return mid;
    }
    
    static int linearSearch(int x[], int target) {
        int location=0, complexity =0;
        for(int i=0;i<x.length;i++) {
            if(target==x[i]) location = i;
            complexity+=1;
        }
        System.out.println("linearSearch complexity: "+complexity);
        return location;
    }
    
    public String reverseString(String initialString) {
	String reversed = null;
        int complexity = 1;
	if (initialString.length() == 1)
	{
            System.out.println("reverseString complexity: "+ complexity);
            return initialString;
        } else {
            complexity +=1;
            String lastChar = initialString.substring(initialString.length()-1,initialString.length());
            String stringLeft = initialString.substring(0, initialString.length() -1);
            reversed = lastChar + reverseString(stringLeft);
            System.out.println("reverseString complexity: "+ complexity);
            return reversed;
	}
    }
    
    public int factorial(int num) {
        int complexity = 1;
	if (num <= 1) {
            System.out.println("reverseString complexity: "+ complexity);
	    return 1;
	}
	else {
            complexity +=1;
            System.out.println("reverseString complexity: "+ complexity);
	    return num * factorial(num-1);
	}
    }

    private void exch(int i, int j) {
        int t = i; i=j;j=t;
    }
}