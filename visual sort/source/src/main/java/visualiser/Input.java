package visualiser;

import algorithms.BubbleSort;
import algorithms.CocktailSort;
import algorithms.HeapSort;
import com.jidesoft.swing.RangeSlider;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ItemEvent;

public class Input {
    public Visualise visWindow;
    JFrame window;
    JPanel mainPanel, generatePanel, inputPanel, radioBoxPanel;
    JLabel infoSort, infoArray, infoSize, infoRange, infoInputMethod;
    JComboBox chooseSort;
    JSlider sizeSlider;
    RangeSlider rangeSlider;
    JTextField arrayInput;
    JButton okButton;
    ButtonGroup group;
    JRadioButton inputElements, generateElements;
    JCheckBox sequenceArray;

    public Input() {
        window = new JFrame();
        visWindow = new Visualise();
        mainPanel = new JPanel();
        generatePanel = new JPanel();
        inputPanel = new JPanel();
        radioBoxPanel = new JPanel();
        infoSort = new JLabel("Sorting Algorithm:");
        infoArray = new JLabel("Array Settings:");
        infoSize = new JLabel("Size of Array:");
        infoRange = new JLabel("Range of Array Generation:");
        infoInputMethod = new JLabel("Input array:");
        String[] algStr = {"Bubble Sort", "Cocktail Sort", "Heap Sort"};
        chooseSort = new JComboBox(algStr);
        sizeSlider = new JSlider(2, 200);
        group = new ButtonGroup();
        inputElements = new JRadioButton("Input");
        generateElements = new JRadioButton("Generate");
        rangeSlider = new RangeSlider(0, 800);
        arrayInput = new JTextField();
        okButton = new JButton("Create");
        sequenceArray = new JCheckBox("Create Sequence Array");

        inputElements.addItemListener(e -> {
            if (e.getStateChange() == ItemEvent.SELECTED) {
                generatePanel.setVisible(false);
                inputPanel.setVisible(true);
            } else if (e.getStateChange() == ItemEvent.DESELECTED) {
                generatePanel.setVisible(true);
                inputPanel.setVisible(false);
            }
        });
        generateElements.addItemListener(e -> {
            if (e.getStateChange() == ItemEvent.SELECTED) {
                generatePanel.setVisible(true);
                inputPanel.setVisible(false);
            } else if (e.getStateChange() == ItemEvent.DESELECTED) {
                generatePanel.setVisible(false);
                inputPanel.setVisible(true);
            }
        });

        okButton.addActionListener(e -> {
            visWindow.drawMenu.setArraySize(sizeSlider.getValue());
            if (inputElements.isSelected()) {
                try {
                    visWindow.drawMenu.setArrayFromString(arrayInput.getText());
                } catch (IndexOutOfBoundsException | NumberFormatException ex) {
                    System.out.println("ERROR!");
                    return;  //#TODO
                }
            } else {
                if (sequenceArray.isSelected()) {
                    visWindow.drawMenu.generateSequenceArray();
                } else {
                    visWindow.drawMenu.generateInRange(rangeSlider.getLowValue(), rangeSlider.getHighValue());
                }
            }
            switch (chooseSort.getSelectedIndex()) {
                case 0:
                    visWindow.drawMenu.setAlgorithm(new BubbleSort(visWindow.drawMenu.array));
                    System.out.println("Bubble");
                    break;
                case 1:
                    visWindow.drawMenu.setAlgorithm(new CocktailSort(visWindow.drawMenu.array));
                    System.out.println("Cocktail");
                    break;
                case 2:
                    visWindow.drawMenu.setAlgorithm(new HeapSort(visWindow.drawMenu.array));
                    System.out.println("Heap");
                    break;
            }
            visWindow.drawMenu.startSorting();
            visWindow.setVisible(true);
            window.setVisible(false);
        });

        visWindow.actionMenu.settingsButton.addActionListener(e -> {
            visWindow.setVisible(false);
            window.setVisible(true);
        });

        generatePanel.setLayout(new BoxLayout(generatePanel, BoxLayout.PAGE_AXIS));
        generatePanel.add(infoRange);
        generatePanel.add(rangeSlider);
        generatePanel.add(sequenceArray);
        arrayInput.setPreferredSize(new Dimension(300, 20));
        inputPanel.setVisible(false);
        inputPanel.add(infoInputMethod);
        inputPanel.add(arrayInput);
        group.add(inputElements);
        group.add(generateElements);
        generateElements.setSelected(true);
        sizeSlider.setPaintTicks(true);
        sizeSlider.setPaintLabels(true);
        sizeSlider.setMajorTickSpacing(18);
        sizeSlider.setMinorTickSpacing(2);
        rangeSlider.setLowValue(300);
        rangeSlider.setHighValue(500);
        rangeSlider.setPaintTicks(true);
        rangeSlider.setPaintLabels(true);
        rangeSlider.setMajorTickSpacing(100);
        rangeSlider.setMinorTickSpacing(50);
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.PAGE_AXIS));
        mainPanel.add(infoSort);
        mainPanel.add(chooseSort);
        mainPanel.add(infoArray);
        mainPanel.add(infoSize);
        mainPanel.add(sizeSlider);
        radioBoxPanel.add(inputElements);
        radioBoxPanel.add(generateElements);
        mainPanel.add(radioBoxPanel);
        mainPanel.add(generatePanel);
        mainPanel.add(inputPanel);
        mainPanel.add(okButton);
        window.setPreferredSize(new Dimension(400, 300));
        window.setResizable(false);
        window.add(mainPanel);
        window.pack();
        window.setLocationRelativeTo(null);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setVisible(true);
    }

}
