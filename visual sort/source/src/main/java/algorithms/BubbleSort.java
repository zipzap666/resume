package algorithms;

import java.util.Arrays;

import org.apache.log4j.Logger;

public class BubbleSort extends SortVariant {

    private static final Logger log = Logger.getLogger(BubbleSort.class);

    public BubbleSort(int[] a){
        super(a);
    }

    private void toSwap(int[] buff,int first, int second) {
        int dummy = buff[first];
        buff[first] = buff[second];
        buff[second] = dummy;

    }

    @Override
    public void setStepSort() {
        log.info("Bubble steps");
        for (int out = stepSort.get(0).length - 1; out >= 1; out--){
            for (int in = 0; in < out; in++){
                int size = stepSort.size();
                int[] buff = Arrays.copyOf(stepSort.get(size-1), stepSort.get(size-1).length);
                if(buff[in] > buff[in + 1]) {
                    toSwap(buff, in, in + 1);
                    pair.add(new int[] {in, in + 1});
                    stepSort.add(Arrays.copyOf(buff, buff.length));
                }
            }
        }
    }
}
