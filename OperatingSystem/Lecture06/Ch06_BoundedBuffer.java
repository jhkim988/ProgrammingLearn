package Lecture06;

public class Ch06_BoundedBuffer {
  private static class CashBox {
    private int[] buffer;
    private int count, in, out;
    CashBox(int bufferSize) {
      buffer = new int[bufferSize];
      count = in = out = 0;
    }
    // CashBox 인스턴스가 monitor lock을 획득한다
    synchronized void give(int money) throws InterruptedException {
      while (count == buffer.length) {
        try {
          wait();
        } catch (InterruptedException e) { }
      }
      buffer[in] = money;
      in = (in + 1) % buffer.length;
      count++;
      System.out.printf("Give: %d\n", money);
      notify();
    }
    synchronized int take() throws InterruptedException {
      while (count == 0) {
        try {
          wait();
        } catch (InterruptedException e) { }
      }
      int money = buffer[out];
      out = (out + 1) % buffer.length;
      count--;
      System.out.printf("Take: %d\n", money);
      notify();
      return money;
    }
  }
  private static class Producer implements Runnable {
    CashBox cashBox;
    Producer(CashBox cashBox) {
      this.cashBox = cashBox;
    }
    @Override
    public void run() {
      try {
        while (true) {
          Thread.sleep((long) (Math.random() * 500));
          int money = ((int) (1 + Math.random() * 9)) * 10000;
          cashBox.give(money);
        }
      } catch (InterruptedException e) {

      }
    }
  }
  private static class Consumer implements Runnable {
    CashBox cashBox;
    Consumer(CashBox cashBox) {
      this.cashBox = cashBox;
    }
    @Override
    public void run() {
      try {
        while (true) {
          Thread.sleep((long) (Math.random() * 500));
          int money = cashBox.take();
        }
      } catch (InterruptedException e) { }
    }
  }
  public static void main(String[] args) {
    CashBox cashBox = new CashBox(1);
    int numProducers = 1, numConsumers = 1;
    Thread[] producers = new Thread[numProducers];
    Thread[] consumers = new Thread[numConsumers];
    for (int i = 0; i < numProducers; i++) {
      producers[i] = new Thread(new Producer(cashBox));
      producers[i].start();
    }
    for (int i = 0; i < numConsumers; i++) {
      consumers[i] = new Thread(new Consumer(cashBox));
      consumers[i].start();
    }
  }
}