package Lecture06;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Ch06_Dining_Philosopher {
  enum State {
    THINKING, HUNGRY, EATING
  }
  private static class Philosopher implements Runnable {
    private int id;
    private DiningPhilosopherMonitor monitor;
    Philosopher(int i, DiningPhilosopherMonitor monitor) {
      this.id = id;
      this.monitor = monitor;
    }
    @Override
    public void run() {
      while (true) {
        think();
        monitor.pickup(id);
        eat();
        monitor.putdown(id);        
      }
    }
    void think() {
      try {
        System.out.println(id + ": Now, I'm thinking.");
        Thread.sleep((long) (Math.random()*500));
      } catch (InterruptedException e) { }
    }
    void eat() {
      try {
        System.out.println(id + ": Now, I'm eating");
        Thread.sleep((long) (Math.random()*500));
      } catch (InterruptedException e) { }
    }
  }
  private static class DiningPhilosopherMonitor {
    private int numOfPhils;
    private State[] state;
    private Condition[] self;
    private Lock lock;
    DiningPhilosopherMonitor(int num) {
      numOfPhils = num;
      state = new State[num];
      self = new Condition[num];
      lock = new ReentrantLock();
      for (int i = 0; i < num; i++) {
        state[i] = State.THINKING;
        self[i] = lock.newCondition();
      } 
    }
    int leftOf(int i) {
      return (i + numOfPhils-1) % numOfPhils;
    } 
    int rightOf(int i) {
      return (i + 1) % numOfPhils;
    }
    void test(int i) {
      if (state[i] == State.HUNGRY && state[leftOf(i)] != State.EATING && state[rightOf(i)] != State.EATING) {
        state[i] = State.EATING;
        self[i].signal();
      }
    }
    void pickup(int id) {
      lock.lock();
      try {
        state[id] = State.HUNGRY;
        test(id);
        if (state[id] != State.EATING) {
          self[id].await();
        }
      } catch (InterruptedException e) {

      } finally {
        lock.unlock();
      }
    }
    void putdown(int id) {
      lock.lock();
      try {
        state[id] = State.THINKING;
        test(leftOf(id));
        test(rightOf(id));
      } finally {
        lock.unlock();
      }
    }
  }
  public static void main(String[] args) throws Exception {
    int numOfPhils = 5;
    Philosopher[] philosophers = new Philosopher[numOfPhils];
    DiningPhilosopherMonitor monitor = new DiningPhilosopherMonitor(numOfPhils);
    for (int i = 0; i < philosophers.length; i++) {
      new Thread(new Philosopher(i, monitor)).start();
    }
  }
}