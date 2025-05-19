import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class KeyMouseEventExample extends Frame implements KeyListener, MouseListener {

    public KeyMouseEventExample() {
        setTitle("Key and Mouse Event Example");
        setSize(300, 200);
        addKeyListener(this);
        addMouseListener(this);
        setVisible(true);
        
    }

    public void keyPressed(KeyEvent e) {
        System.out.println("Key Pressed: " + e.getKeyChar());
    }

    public void keyReleased(KeyEvent e) {
        System.out.println("Key Released: " + e.getKeyChar());
    }

    public void keyTyped(KeyEvent e) {
        System.out.println("Key Typed: " + e.getKeyChar());
    }

    public void mouseEntered(MouseEvent e) {
        System.out.println("Mouse Entered");
    }

    public void mouseExited(MouseEvent e) {
        System.out.println("Mouse Exited");
    }

    public void mouseClicked(MouseEvent e) {
        System.out.println("Mouse Clicked");
    }

    public void mousePressed(MouseEvent e) {
        System.out.println("Mouse Pressed");
    }

    public void mouseReleased(MouseEvent e) {
        System.out.println("Mouse Released");
    }

    public static void main(String[] args) {
        new KeyMouseEventExample();
    }
}
