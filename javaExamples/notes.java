//linked lists
/*A linked list has no upper bound on its capacity. It's dynamic, growing & shrinking as needed
the heap stores the structure; array is faster but linked list is more flexible
According to its context, linked list can have slightly different structures:
circular, doubly-linked, without front object (dummy), etc
*/

//notes for the magicsquare

int [] x = new int( 2 * size + 2)
	boolean result = true;
for(int i=0; i < x.length - 1; i++)
  {
	int a = x[i];
	int b = x[i+1];
	if (a != b)
	  {
	  result = false;
	  return result;
	  }
	return result;
  }
  
//notes for magicsquare
int count = 0;
for(int row=0; row<size; row++)
{
	x[count] = sumRow(row);
	count++;
}

for(int col=0; col<size; col++)
{
	x[count] = sumCol(col);
	count++;
}

x[count]=sumMD();
x[count+1]=sumOtherD();

//Random Notes
//super reference can be used to reference parent class & is often used to invoke parent's constructor

//*******************************************************
//			READ 9.1, 10.1-10.7
//*******************************************************

// Interface Polymorphism in chp 9

//*******************************************************
//		BIO LAB
//	labs 6 & 7 & Chi-square
//*******************************************************

//You should find that the first, second, and third squares in the input are magic, and that the rest (fourth
//through seventh) are not.




//*******************************************************
//			____cols____
//		rows| 1 2 3
//			| 4 5 6

