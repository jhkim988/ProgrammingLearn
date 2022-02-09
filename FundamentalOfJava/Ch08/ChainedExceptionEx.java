// 예외 A가 예외 B를 발생시켰다면 A를 B의 원인 예외(cause exception) 이라고 한다.
// 원인 예외를 등록하는 방법: B.initCause(A)
// initCause() 메서드는 Exception 클래스의 조상인 Throwable 클래스에 있는 메서드이므로, 모든 예외에서 사용 가능하다.

// 원인 예외로 등록해서 예외를 다시 발생시키는 이유
// 예외를 묶어서 처리할 수 있기 때문이다.
// 예외를 묶어서 처리하기 위해 예외 간의 상속관계를 주면, 실제로 발생한 예외가 어떤 것인지 알 수 없는 경우가 있다.
// 따라서 예외가 원인 예외를 포함할 수 있게하여 상속관계가 아니더라도 한꺼번에 처리가 가능하게 된다.

// 또 다른 이유는 checked 예외를 unchecked 예외로 바꾸기 위해서다.
// 아래의 예시에서 MemoryException은 Exception의 자손이므로 반드시 예외를 처리해줘야 하는 checked 예외인데
// RuntimeException의 생성자로 원인 예외를 등록하여 unchecked 예외로 바꾸었다.

public class ChainedExceptionEx {
  public static void main(String[] args) {
    try {
      install();
    } catch (InstallException e) {
      e.printStackTrace();
    } catch(Exception e) {
      e.printStackTrace();
    }
  } 
  static void install() throws InstallException {
    try {
      startInstall();
      copyFiles();
    } catch (SpaceException se) {
      InstallException ie = new InstallException("설치 중 예외 발생");
      ie.initCause(se);
      throw ie;
    } catch (MemoryException me) {
      InstallException ie = new InstallException("설치 중 예외 발생");
      ie.initCause(me);
      throw ie;
    } finally {
      deleteTempFiles();
    }
  }

  static void startInstall() throws SpaceException, MemoryException {
    if (!enoughSpace()) throw new SpaceException("설치할 공간이 부족합니다.");
    if (!enoughMemory()) {
      // throw new MemoryException("메모리가 부족합니다.");
      throw new RuntimeException(new MemoryException("메모리가 부족합니다."));
      // checked 예외인 MemoryException 예외를 RuntimeException을 이용하여 unchecked 예외로 바꾸었다.
      // 이 때 메서드 선언부의 throws MemoryException을 명시하지 않아도 된다.
    }
  }
  static void copyFiles() { }
  static void deleteTempFiles() { }
  static boolean enoughSpace() { return false; }
  static boolean enoughMemory() { return false; }
}

class InstallException extends Exception {
  InstallException(String msg) { super(msg); }
}

class SpaceException extends Exception {
  SpaceException(String msg) { super(msg); }
}

class MemoryException extends Exception {
  MemoryException(String msg) { super(msg); }
}
