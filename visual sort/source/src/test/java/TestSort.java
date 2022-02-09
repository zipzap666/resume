import algorithms.BubbleSort;
import algorithms.CocktailSort;
import algorithms.HeapSort;
import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;


public class TestSort {
    @Test
    public void testBubble(){
        int[] arr = new int[]{9,5,7,9,8,1,6,10,5,9,78,9,2,6,1,5,8};
        BubbleSort testSort = new BubbleSort(Arrays.copyOf(arr, arr.length));

        Arrays.sort(arr);

        testSort.setStepSort();
        Assert.assertArrayEquals(arr, testSort.stepSort.get(testSort.stepSort.size()-1));
    }

    @Test
    public void testHeap(){
        int[] arr = new int[]{9,5,7,9,8,1,6,10,5,9,78,9,2,6,1,5,8};
        HeapSort testSort = new HeapSort(Arrays.copyOf(arr, arr.length));

        Arrays.sort(arr);

        testSort.setStepSort();
        Assert.assertArrayEquals(arr, testSort.stepSort.get(testSort.stepSort.size()-1));
    }

    @Test
    public void testCocktail(){
        int[] arr = new int[]{9,5,7,9,8,1,6,10,5,9,78,9,2,6,1,5,8};
        CocktailSort testSort = new CocktailSort(Arrays.copyOf(arr, arr.length));

        Arrays.sort(arr);

        testSort.setStepSort();
        Assert.assertArrayEquals(arr, testSort.stepSort.get(testSort.stepSort.size()-1));
    }

    @Test
    public void testBubbleEmpty(){
        int[] arr = new int[]{};
        BubbleSort testSort = new BubbleSort(Arrays.copyOf(arr, arr.length));

        Arrays.sort(arr);

        testSort.setStepSort();
        Assert.assertArrayEquals(arr, testSort.stepSort.get(testSort.stepSort.size()-1));
    }

    @Test
    public void testHeapEmpty(){
        int[] arr = new int[]{};
        HeapSort testSort = new HeapSort(Arrays.copyOf(arr, arr.length));

        Arrays.sort(arr);

        testSort.setStepSort();
        Assert.assertArrayEquals(arr, testSort.stepSort.get(testSort.stepSort.size()-1));
    }

    @Test
    public void testCocktailEmpty(){
        int[] arr = new int[]{};
        CocktailSort testSort = new CocktailSort(Arrays.copyOf(arr, arr.length));

        Arrays.sort(arr);

        testSort.setStepSort();
        Assert.assertArrayEquals(arr, testSort.stepSort.get(testSort.stepSort.size()-1));
    }

    @Test
    public void testBubbleSameEl(){
        int[] arr = new int[]{9,9,9,9,9,9,9,9,9,9,9,9,9};
        BubbleSort testSort = new BubbleSort(Arrays.copyOf(arr, arr.length));

        Arrays.sort(arr);

        testSort.setStepSort();
        Assert.assertArrayEquals(arr, testSort.stepSort.get(testSort.stepSort.size()-1));
    }

    @Test
    public void testHeapSameEl(){
        int[] arr = new int[]{9,9,9,9,9,9,9,9,9,9,9,9,9};
        HeapSort testSort = new HeapSort(Arrays.copyOf(arr, arr.length));

        Arrays.sort(arr);

        testSort.setStepSort();
        Assert.assertArrayEquals(arr, testSort.stepSort.get(testSort.stepSort.size()-1));
    }

    @Test
    public void testCocktailSameEl(){
        int[] arr = new int[]{9,9,9,9,9,9,9,9,9,9,9,9,9};
        CocktailSort testSort = new CocktailSort(Arrays.copyOf(arr, arr.length));

        Arrays.sort(arr);

        testSort.setStepSort();
        Assert.assertArrayEquals(arr, testSort.stepSort.get(testSort.stepSort.size()-1));
    }

    @Test
    public void testMove(){
        int[] arr = new int[]{9,5,7,9,8,1,6,10,5,9,78,9,2,6,1,5,8};
        BubbleSort testSort = new BubbleSort(Arrays.copyOf(arr, arr.length));

        Arrays.sort(arr);

        testSort.setStepSort();

        for(int i = 0; i < testSort.stepSort.size(); i++){
            Assert.assertArrayEquals(testSort.stepSort.get(i), testSort.getCurrentStep());
            testSort.getNextStep();
        }

        Assert.assertArrayEquals(testSort.getNextStep(), testSort.getLastStep());
        //System.out.println(Arrays.toString(testSort.getNextStep()));

        for(int i = testSort.stepSort.size()-1; i >= 0; i--){
            Assert.assertArrayEquals(testSort.stepSort.get(i), testSort.getCurrentStep());
            testSort.getPrevStep();
        }

        Assert.assertArrayEquals(testSort.getPrevStep(), testSort.getFirstStep());
        //System.out.println(Arrays.toString(testSort.getPrevStep()));
    }
}
