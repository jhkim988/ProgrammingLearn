import javax.swing.JOptionPane;

public class ThreadEx14 {
  public static void main(String[] args) throws Exception {
    ThreadEx14_1 th1 = new ThreadEx14_1();
    th1.start();

    String input = JOptionPane.showInputDialog("아무 값이나 입력하세요");
    System.out.println("입력하신 값은 " + input + "입니다.");
    th1.interrupt();
    System.out.println("isInterrupted(): " + th1.isInterrupted());
  }
}

class ThreadEx14_1 extends Thread {
  public void run() {
    int i = 10;
    while (i != 0 && !isInterrupted()) {
      System.out.println(i--);
      try {
        Thread.sleep(1000); // InterruptedException 발생, false로 자동초기화 된다.
      } catch (InterruptedException e) {
        // 자동 초기화되기 때문에 여기서 다시 한 번 interrupt 해준다.
        interrupt();  
      }
    }
    System.out.println("카운트가 종료되었습니다.");
  }
}
