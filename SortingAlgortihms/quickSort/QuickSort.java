public class QuickSort {

    public static void main(String[] args) 
    {
	int[] array = {5,6,2,1,0,-5,10,11,12,1};
	System.out.println(Arrays.toString(array));
	quickSort(array,0,array.length -1);
	System.out.println(Arrays.toString(array));
	
    }
    
    public static void quickSort(int[] array , int start , int finish)
    {
        if(start < finish)
        {
            int pIndex = partition(array, start, finish);
            quickSort(array, start , pIndex - 1);
            quickSort(array, pIndex + 1, finish);
        }
    }
    public static int partition(int [] array, int start , int finish)
    {
        int pIndex = start;
        int pivot = array[finish];
        for(int i = start ; i <= finish -1 ; i++)
        {
            // we compare the current element with the pivot , if true we increment the pIndex
            if(array[i] < pivot)
            {
                swap(array, pIndex, i);
                pIndex++;
            }
        }
        swap(array, pIndex , finish);
        return pIndex;
    }
    public static void swap(int[] array, int a, int b)
    {
        int temp = array[b];
        array[b] = array[a];
        array[a] = temp;
    }
}
