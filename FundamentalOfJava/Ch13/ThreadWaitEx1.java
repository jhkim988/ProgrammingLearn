import java.util.*;

public class ThreadWaitEx1 {
  public static void main(String[] args) throws Exception {
    // Cook이 table에 추가하는 도중에 Customer가 접근해서 발생하는 예외
    // Customer가 table에서 dish를 제거했는데 다른 Customer가 접근하면서 생기는 예외
    
    Table table = new Table(); // 여러 스레드가 공유하는 객체
    new Thread(new Cook(table), "COOK1").start();
    new Thread(new Customer(table, "donut"), "CUST1").start();
    new Thread(new Customer(table, "burger"), "CUST2").start();
    Thread.sleep(100);
    System.exit(0);
  }
}

class Customer implements Runnable {
  private Table table;
  private String food;
  Customer(Table table, String food) {
    this.table = table;
    this.food = food;
  }
  public void run() {
    while (true) {
      try { Thread.sleep(10); } catch (InterruptedException e) {}
      String name = Thread.currentThread().getName();
      if (eatFood()) {
        System.out.println(name + " ate a " + food);
      } else {
        System.out.println(name + " failed to eat. :(");
      }
    }
  }
  boolean eatFood() { return table.remove(food); }
}

class Cook implements Runnable {
  private Table table;
  Cook(Table table) { this.table = table; }
  public void run() {
    while (true) {
      int idx = (int) (Math.random() * table.dishNum());
      table.add(table.dishNames[idx]);
      try { Thread.sleep(1); } catch (InterruptedException e) {}
    }
  }
}

class Table {
  String[] dishNames = {"donut", "donut", "burger"};
  final int MAX_FOOD = 6;
  private ArrayList<String> dishes = new ArrayList<>();
  public void add(String dish) {
    if (dishes.size() >= MAX_FOOD) return;
    dishes.add(dish);
    System.out.println("Dishes:" + dishes.toString());
  }
  public boolean remove(String dishName) {
    for (int i = 0; i < dishes.size(); i++) {
      if (dishName.equals(dishes.get(i))) {
        dishes.remove(i);
        return true;
      }
    }
    return false;
  }
  public int dishNum() { return dishNames.length; }
}
