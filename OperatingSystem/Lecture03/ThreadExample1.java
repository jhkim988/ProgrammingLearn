import java.lang.Thread;

class MyThread1 extends Thread {
    public void run() {
        try {
            while (true) {
                System.out.println("Hello, Thread!");
                Thread.sleep(500);
            }
        } catch (InterruptedException ie) {
            System.out.println("I'm interrupted.");
        }
    }
}

public class ThreadExample1 {
    public static final void main(String[] args) {
        MyThread1 thread = new MyThread1();
        thread.start(); // run()을 호출하는 것이 아니라, start()를 호출한다. fork()와 비슷한 과정
        System.out.println("Hello, My Child!");
    }
}