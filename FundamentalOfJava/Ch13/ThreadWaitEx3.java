import java.util.*;

class Customer implements Runnable { 
  private Table table;
  private String food;
  Customer(Table table, String food) {
    this.table = table;
    this.food = food;
  }
  public void run() {
    while (true) {
      try {Thread.sleep(100); } catch (InterruptedException e) {}
      String name = Thread.currentThread().getName();
      table.remove(food);
      System.out.println(name + " ate a " + food);
    }
  }
}

class Cook implements Runnable {
  private Table table;
  Cook(Table table) {this.table = table;}
  public void run() {
    while (true) {
      int idx = (int) (Math.random() * table.dishNum());
      table.add(table.dishNames[idx]);
      try { Thread.sleep(10); } catch (InterruptedException e) {}
    }
  }
}

class Table {
  String[] dishNames = {"donut", "donut", "burger"};
  final int MAX_FOOD = 6;
  private ArrayList<String> dishes = new ArrayList<>();
  // Cook과 Customer둘 다 같은 waiting pool에서 대기하기 때문에 
  // notify()가 누가 될 지 알 수 없다.
  // 운이 나쁘면 계속 기다리는 스레드가 생기고, 이를 기아(starvation)현상이라고 한다.
  // notifyAll()을 사용하면 되지만, 원치 않은 스레드와 lock을 얻기 위해 경쟁한다. 이를 경쟁(race condition)이라고 한다.
  // Lock과 condition을 이용하면 wait()와 notify()로는 불가능한 선별적인 통지가 가능하다.
  public synchronized void add(String dish) {
    while (dishes.size() >= MAX_FOOD) {
      String name = Thread.currentThread().getName();
      System.out.println(name + " is waiting.");
      try {
        wait();
        Thread.sleep(500);
      } catch (InterruptedException e) {}
    }
    dishes.add(dish);
    notify();
    System.out.println("Dishes: " + dishes.toString());
  }
  public void remove(String dishName) {
    synchronized (this) {
      String name = Thread.currentThread().getName();
      while (dishes.size() == 0) {
        System.out.println(name + " is waiting.");
        try {
          wait();
          Thread.sleep(500);
        } catch (InterruptedException e) {}
      }
      while (true) {
        for (int i = 0; i < dishes.size(); i++) {
          if (dishName.equals(dishes.get(i))) {
            dishes.remove(i);
            notify();
            return;
          }
        }
        try {
          System.out.println(name + " is waiting.");
          wait();
          Thread.sleep(500);
        } catch (InterruptedException e) {}
      }
    }
  }
  public int dishNum() { return dishNames.length; }
}
public class ThreadWaitEx3 {
  public static void main(String[] args) throws Exception {
    Table table = new Table();
    new Thread(new Cook(table), "COOK1").start();
    new Thread(new Customer(table, "donut"), "CUST1").start();
    new Thread(new Customer(table, "burger"), "CUST2").start();
    Thread.sleep(2000);
    System.exit(0);
  }
}
