/*@Heintze, Darrell R. 6544
 *Assignment:
 *  Build heaps using the array implementation, and finally sort the array using heap sort.
 */
public class heapEx {
    public int[] data;
    public int size;

    public heapEx(int size) {
        data=new int[size];
        size=0;
    }
    public boolean isEmpty() {
            return (size == 0);
      }
    int getLeftIndex(int nodeIndex) {
        return 2*nodeIndex+1;
    }
    int getRightIndex(int nodeIndex) {
        return 2*nodeIndex+2;
    }
    int getParentIndex(int nodeIndex) {
        return (nodeIndex-1)/2;
    }

    public static void sortHeap(int array[], int arr_ubound){
        int i, o;
        int leftChild, rightChild, mChild, root, temp;
        root = (arr_ubound-1)/2;

        for(o = root; o >= 0; o--) {
            for(i=root;i>=0;i--){
                leftChild = (2*i)+1;
                rightChild = (2*i)+2;
            if((leftChild <= arr_ubound) && (rightChild <= arr_ubound)){
                    if(array[rightChild] >= array[leftChild]) mChild = rightChild;
                    else mChild = leftChild;
                } else{
                if(rightChild > arr_ubound) mChild = leftChild;
                else mChild = rightChild;
                }
                if(array[i] < array[mChild]){
                    temp = array[i];
                    array[i] = array[mChild];
                    array[mChild] = temp;
                }
            }
        }
        temp = array[0];
        array[0] = array[arr_ubound];
        array[arr_ubound] = temp;
        return;
    }

    public static void main(String a[]){
        int i;
        int[] ourArray = {5,9,2,12,3,9};
        
        System.out.println("Our array unsorted: ");
        for (i = 0; i < ourArray.length+1; i++) {
            System.out.println(" "+ourArray[i]); }

        sortHeap(ourArray,ourArray.length);
        System.out.println("Our array sorted: ");
        for (i = 0; i < ourArray.length+1; i++) {
            System.out.println(" "+ourArray[i]); }
    }
}