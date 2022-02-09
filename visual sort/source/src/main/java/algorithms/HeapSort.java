package algorithms;

import org.apache.log4j.Logger;

import java.util.Arrays;

public class HeapSort extends SortVariant {

    private static final Logger log = Logger.getLogger(HeapSort.class);

    public HeapSort(int[] a){
        super(a);
    }

    @Override
    public void setStepSort(){
        log.info("Heap steps");
        int[] buff = Arrays.copyOf(stepSort.get(0), stepSort.get(0).length);
        int n = buff.length;

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(buff, n, i);

        }

        for (int i=n-1; i>=0; i--){
            int temp = buff[0];
            buff[0] = buff[i];
            buff[i] = temp;

            pair.add(new int[] {0, i});
            stepSort.add(Arrays.copyOf(buff, buff.length));
            heapify(buff, i, 0);
        }
    }


    void heapify(int[] buff,int n, int i) {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n && buff[l] > buff[largest])
            largest = l;

        if (r < n && buff[r] > buff[largest])
            largest = r;

        if (largest != i){
            int swap = buff[i];
            buff[i] = buff[largest];
            buff[largest] = swap;

            pair.add(new int[] {i, largest});
            stepSort.add(Arrays.copyOf(buff, buff.length));
            heapify(buff ,n, largest);
        }
    }

}
