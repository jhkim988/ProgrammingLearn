public class ThreadEx12 {
  public static void main(String[] args) {
  ThreadEx12_1 th1 = new ThreadEx12_1();
  ThreadEx12_2 th2 = new ThreadEx12_2();
  th1.start();
  th2.start();
  try {
    // th1.sleep(2000); // sleep은 static 메서드이고, 실제 영향 받는 것은 main 스레드이다.
    Thread.sleep(2000);
  } catch(InterruptedException e) { }
  System.out.print("<< main 종료 >>");
  }
}

class ThreadEx12_1 extends Thread {
  public void run() {
    for (int i = 0; i < 300; i++) {
      System.out.print("-");
    }
    System.out.print("<< th1 종료 >>");
  }
}

class ThreadEx12_2 extends Thread {
  public void run() {
    for (int i = 0; i < 300; i++) {
      System.out.print("|");
    }
    System.out.print("<< th2 종료 >>");
  }
}