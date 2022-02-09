package algorithms;

import org.apache.log4j.Logger;

import java.util.Arrays;

public class CocktailSort extends SortVariant {

    private static final Logger log = Logger.getLogger(CocktailSort.class);

    public CocktailSort(int[] a){
        super(a);
    }

    @Override
    public void setStepSort() {
        log.info("Cocktail steps");
        int buffV;
        int[] buff = Arrays.copyOf(stepSort.get(0), stepSort.get(0).length);
        int left = 0;
        int right = buff.length - 1;
        do {
            for (int i = left; i < right; i++) {
                if (buff[i] > buff[i + 1]) {
                    buffV = buff[i];
                    buff[i] = buff[i + 1];
                    buff[i + 1] = buffV;
                    pair.add(new int[] {i, i + 1});
                    stepSort.add(Arrays.copyOf(buff,buff.length));
                }
            }
            right--;
            for (int i = right; i > left; i--) {
                if (buff[i] < buff[i - 1]) {
                    buffV = buff[i];
                    buff[i] = buff[i - 1];
                    buff[i - 1] = buffV;
                    pair.add(new int[] {i, i - 1});
                    stepSort.add(Arrays.copyOf(buff,buff.length));
                }
            }
            left++;
        } while (left < right);
    }
}
