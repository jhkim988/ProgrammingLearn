public class FinallyTest {
  public static void main(String[] args) {
    try {
      startInstall();
      copyFiles();
      deleteTempFiles();
    } catch (Exception e) {
      e.printStackTrace();
      deleteTempFiles();
    }
    // deleteTempFiles()는 예외의 발생 여부에 상관없이 실행돼야 한다.
  } 
  static void startInstall() { }
  static void copyFiles() { }
  static void deleteTempFiles() { } 
}
