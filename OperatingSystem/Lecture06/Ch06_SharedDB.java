package Lecture06;

public class Ch06_SharedDB {
  private static class SharedDB {
    private int readCount = 0;
    private boolean isWriting = false;
    public void read() {
  
    }
    public void write() {
  
    }
    synchronized public void acquireReadLock() {
      while (isWriting) {
        try {
          wait();
        } catch (InterruptedException e) { }
      }
      readCount++;
    }
    synchronized public void releaseReadLock() {
      readCount--;
      if (readCount == 0) notify();
    }
    synchronized public void acquireWriteLock() {
      while (readCount > 0 || isWriting) {
        try {
          wait();
        } catch(InterruptedException e) { }
      }
      isWriting = true;
    }
    synchronized public void releaseWriteLock() {
      isWriting = false;
      notifyAll();
    }
  }
  public static void main(String[] args) {
    SharedDB sdb = new SharedDB();
    sdb.acquireReadLock();
    sdb.read();
    sdb.releaseReadLock();
    
    sdb.acquireWriteLock();
    sdb.write();
    sdb.releaseWriteLock();
  }
}
