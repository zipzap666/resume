package algorithms;

import org.apache.log4j.Logger;

import java.util.ArrayList;
import java.util.Arrays;

public abstract class SortVariant {

    private static final Logger log = Logger.getLogger(SortVariant.class);

    public ArrayList<int[]> stepSort;
    public int position;
    public ArrayList<int[]> pair;

    public SortVariant(int[] a) {
        this.stepSort = new ArrayList<>();
        this.pair = new ArrayList<>();
        this.pair.add(new int[]{0, 0});
        this.stepSort.add(Arrays.copyOf(a, a.length));
        this.position = 0;
    }

    abstract public void setStepSort();

    public int[] getNextStep() {
        if (position < stepSort.size() - 1) {
            log.info("Change position");
            position++;
        } else {
            log.error("Cant go next");
        }
        return stepSort.get(position);
    }

    public int[] getPrevStep() {
        if (position > 0) {
            log.info("Change position");
            position--;
        } else {
            log.error("Cant go prev");
        }
        return stepSort.get(position);
    }

    public int[] getLastStep() {
        log.info("Move to last");
        position = stepSort.size() - 1;
        return stepSort.get(stepSort.size() - 1);
    }

    public int[] getFirstStep() {
        log.info("Move to first");
        position = 0;
        return stepSort.get(0);
    }

    public int[] getCurrentStep() {
        log.info("Get current");
        return stepSort.get(position);
    }
}
