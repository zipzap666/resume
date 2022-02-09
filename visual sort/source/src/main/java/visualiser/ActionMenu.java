package visualiser;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.util.Objects;

public class ActionMenu extends JPanel {
    static JButton playStep;
    static ImageIcon playIcon;
    JButton helpButton, settingsButton, startStep, endStep, nextStep, prevStep, infoButton;
    ImageIcon pauseIcon;

    ActionMenu() {
        setBounds(0, 800, 1600, 100);
        setBackground(Color.darkGray);
        setLayout(null);

        helpButton = new JButton();
        settingsButton = new JButton();
        startStep = new JButton();
        endStep = new JButton();
        nextStep = new JButton();
        prevStep = new JButton();
        playStep = new JButton();
        infoButton = new JButton();

        helpButton.setBounds(10, 18, 64, 64);
        settingsButton.setBounds(1524, 18, 64, 64);
        playStep.setBounds(768, 18, 64, 64);
        prevStep.setBounds(664, 18, 64, 64);
        startStep.setBounds(560, 18, 64, 64);
        nextStep.setBounds(872, 18, 64, 64);
        endStep.setBounds(976, 18, 64, 64);
        infoButton.setBounds(1430, 18, 64, 64);
        try {
            Image rightArrow = ImageIO.read(Objects.requireNonNull(getClass().getClassLoader().getResource("right-icon.png")));
            Image leftArrow = ImageIO.read(Objects.requireNonNull(getClass().getClassLoader().getResource("left-icon.png")));
            Image playIMG = ImageIO.read(Objects.requireNonNull(getClass().getClassLoader().getResource("play-icon.png")));
            Image startArrow = ImageIO.read(Objects.requireNonNull(getClass().getClassLoader().getResource("double-left-icon.png")));
            Image endArrow = ImageIO.read(Objects.requireNonNull(getClass().getClassLoader().getResource("double-right-icon.png")));
            Image helpIMG = ImageIO.read(Objects.requireNonNull(getClass().getClassLoader().getResource("help-icon.png")));
            Image consoleIMG = ImageIO.read(Objects.requireNonNull(getClass().getClassLoader().getResource("console-icon.png")));
            Image settingsIMG = ImageIO.read(Objects.requireNonNull(getClass().getClassLoader().getResource("setting-icon.png")));
            Image pauseIMG = ImageIO.read(Objects.requireNonNull(getClass().getClassLoader().getResource("pause-icon.png")));
            pauseIcon = new ImageIcon(pauseIMG);
            playIcon = new ImageIcon(playIMG);
            prevStep.setIcon(new ImageIcon(leftArrow));
            nextStep.setIcon(new ImageIcon(rightArrow));
            helpButton.setIcon(new ImageIcon(helpIMG));
            settingsButton.setIcon(new ImageIcon(settingsIMG));
            startStep.setIcon(new ImageIcon(startArrow));
            endStep.setIcon(new ImageIcon(endArrow));
            infoButton.setIcon(new ImageIcon(consoleIMG));
            playStep.setIcon(playIcon);

        } catch (Exception e) {
            System.out.println(e);
            // ERROR HANDLING #TODO
        }

        add(helpButton);
        add(settingsButton);
        add(playStep);
        add(prevStep);
        add(startStep);
        add(nextStep);
        add(endStep);
        add(infoButton);

        helpButton.addActionListener(e -> {
            JFrame helpWindow = new JFrame();
            helpWindow.setResizable(false);

            JPanel panel1 = new JPanel();
            panel1.add(new JLabel(playIcon));
            panel1.add(new JLabel(" - play animation of sorting"));
            JPanel panel2 = new JPanel();
            panel2.add(new JLabel(pauseIcon));
            panel2.add(new JLabel(" - pause animation of sorting"));
            JPanel panel3 = new JPanel();
            panel3.add(new JLabel(prevStep.getIcon()));
            panel3.add(new JLabel(" - display previous step of sorting"));
            JPanel panel4 = new JPanel();
            panel4.add(new JLabel(nextStep.getIcon()));
            panel4.add(new JLabel(" - display next step of sorting"));
            JPanel panel5 = new JPanel();
            panel5.add(new JLabel(startStep.getIcon()));
            panel5.add(new JLabel(" - display first step of sorting"));
            JPanel panel6 = new JPanel();
            panel6.add(new JLabel(endStep.getIcon()));
            panel6.add(new JLabel(" - display last step of sorting"));
            JPanel panel7 = new JPanel();
            panel7.add(new JLabel(infoButton.getIcon()));
            panel7.add(new JLabel(" - display panel with information of sorting"));
            JPanel panel8 = new JPanel();
            panel8.add(new JLabel(settingsButton.getIcon()));
            panel8.add(new JLabel(" - change array values and sorting algorithm"));

            JPanel mainPanel = new JPanel();

            mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.PAGE_AXIS));
            mainPanel.add(panel1);
            mainPanel.add(panel2);
            mainPanel.add(panel3);
            mainPanel.add(panel4);
            mainPanel.add(panel5);
            mainPanel.add(panel6);
            mainPanel.add(panel7);
            mainPanel.add(panel8);

            helpWindow.add(mainPanel);

            helpWindow.pack();
            helpWindow.setLocationRelativeTo(null);
            helpWindow.setVisible(true);
        });
    }

}
