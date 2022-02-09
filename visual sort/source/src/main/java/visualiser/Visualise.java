package visualiser;

import javax.swing.*;
import java.awt.*;
import java.util.Arrays;

public class Visualise extends JFrame {

    ActionMenu actionMenu;
    SortMenu drawMenu;
    JPanel panel;
    JTextArea text = new JTextArea();

    Visualise() {
        actionMenu = new ActionMenu();
        drawMenu = new SortMenu();
        panel = new JPanel();

        panel.setBounds(1600, 0, 200, 900);

        setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        getContentPane().setPreferredSize(new Dimension(1600, 900));
        setResizable(false);

        text.setText(">> Start Of Program\n");
        text.setPreferredSize(new Dimension(200, 900));
        text.setBackground(Color.black);
        text.setForeground(Color.green);
        text.setLineWrap(true);
        text.setWrapStyleWord(true);

        panel.setBackground(Color.black);
        panel.add(text);
        add(drawMenu);
        add(actionMenu);
        add(panel);

        actionMenu.infoButton.addActionListener(e -> {
            if (getContentPane().getPreferredSize().width == 1600) {
                text.append(">> Show Console\n");
                getContentPane().setPreferredSize(new Dimension(1800, 900));
            } else {
                text.append(">> Hide Console\n");
                getContentPane().setPreferredSize(new Dimension(1600, 900));
            }
            pack();
            setLocationRelativeTo(null);
        });

        ActionMenu.playStep.addActionListener(e -> {
            text.append(">> Start of Animation:\n");
            text.append("Sorted array: " + Arrays.toString(drawMenu.array) + "\n");
            drawMenu.pause.set(!drawMenu.pause.get());
            if (!drawMenu.pause.get()) {
                ActionMenu.playStep.setIcon(actionMenu.pauseIcon);
                drawMenu.animate();
            } else {
                ActionMenu.playStep.setIcon(ActionMenu.playIcon);
            }
            text.append("Swapped elements: " + (drawMenu.algorithm.stepSort.size() - 1) + "\n");
        });

        actionMenu.prevStep.addActionListener(e -> drawMenu.prevStep());

        actionMenu.nextStep.addActionListener(e -> drawMenu.nextStep());

        actionMenu.startStep.addActionListener(e -> drawMenu.startStep());

        actionMenu.endStep.addActionListener(e -> drawMenu.endStep());

        pack();
        setLocationRelativeTo(null);
    }
}

