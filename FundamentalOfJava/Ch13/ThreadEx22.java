public class ThreadEx22 {
  public static void main(String[] args) {
    Runnable r = new RunnableEx22();
    new Thread(r).start();
    new Thread(r).start();
  }
}

class Account {
  private int balance = 1000;
  public int getBalance() { return balance; }
  public synchronized void withdraw(int money) {
    if (balance >= money) {
      // 다른 스레드가 끼어들어서 출금을 먼저 하는 일을 방지하기 위해 synchronized 키워드를 붙인다
      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {}
      balance -= money;
    }
  }
}

class RunnableEx22 implements Runnable {
  Account acc = new Account();
  public void run() {
    while(acc.getBalance() > 0) {
      int money = (int)( Math.random() * 3 + 1) * 100;
      acc.withdraw(money);
      System.out.println("balance:" + acc.getBalance());
    }
  }
}