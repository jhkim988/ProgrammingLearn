public class TryWithResourceEx {
  // try with resources 구문
  // 자동으로 close()를 해서 자원을 반환한다.

  // try() 안에 객체를 생성하는 문장을 넣는다.
  // try 블럭을 벗어나면(예외없이 try-catch 밖으로 or 예외가 생겨 catch로) 자동으로 close 메서드를 호출하여 자원을 반환한다.
  // try with resource문에 의해 자동으로 close를 호출하기 위해서는 객체가 AutoCloseable 인터페이스를 구현한 것이어야 한다.
  // 자동 호출된 close()에서도 예외가 발생할 수 있다.
  public static void main(String[] args) {
    try (CloseableResource cr = new CloseableResource()) { 
      // close에서만 예외를 발생시킨다.
      cr.exceptionWork(false);
    } catch (WorkException e) {
      e.printStackTrace();
    } catch(CloseException e) {
      e.printStackTrace();
    }
    System.out.println();

    try (CloseableResource cr = new CloseableResource()) {
      // work, close 모두 예외를 발생시킨다.
      // WorkException이 발생하고, suppressed ClosedException이 함께 발생한다.
      // 두 예외를 동시에 발생할 수 없기 때문에, 억제된(suppressed) 예외로 다룬다.
      // Throwable에는 addSuppressed(Throwable exception)와 getSuppressed() 메서드가 정의돼 있다.
      // 만일 try with resource가 아닌 기존의 try-catch문을 사용하면 ClosedException에 대한 내용만 출력된다.
      cr.exceptionWork(true);
    } catch (WorkException e) {
      e.printStackTrace();
    } catch (CloseException e) {
      e.printStackTrace();
    }
  }  
}

class CloseableResource implements AutoCloseable {
  public void exceptionWork(boolean exception) throws WorkException {
    System.out.println("exceptionWork(" + exception +") 호출");
    if (exception) throw new WorkException("WorkException 발생");
  }
  public void close()  throws CloseException {
    System.out.println("close()가 호출됨");
    throw new CloseException("CloseException 발생");
  }
}

class WorkException extends Exception {
  WorkException(String msg) { super(msg); }
}

class CloseException extends Exception {
  CloseException(String msg) { super(msg); }
}