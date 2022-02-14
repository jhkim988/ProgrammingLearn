public class Ch05_SyncEx4 {
  static class Counter {
    static int count = 0;
    void increment() { 
      synchronized (this) {
        Counter.count++;
      } 
    }
  }
  static class MyRunnable implements Runnable {
    Counter counter;
    MyRunnable(Counter counter) {
      this.counter = counter;
    }
    @Override
    public void run() {
      for (int i = 0; i < 10_000; i++) {
        counter.increment();
      }
    }
  }
  public static void main(String[] args) throws Exception {
    Thread[] threads = new Thread[5];
    for (int i = 0; i < threads.length; i++) {
      threads[i] = new Thread(new MyRunnable(new Counter()));
      threads[i].start();
    }
    for (int  i = 0; i < threads.length; i++) {
      threads[i].join();
    }
    System.out.println("counter = " + Counter.count);
  }
}
