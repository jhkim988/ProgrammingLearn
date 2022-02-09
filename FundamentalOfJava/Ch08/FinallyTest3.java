public class FinallyTest3 {
  public static void main(String[] args) {
    FinallyTest3.method1();
    System.out.println("method1() 의 수행을 마치고 main 메서드로 돌아왔습니다.");
  } 
  static void method1() {
    try {
      System.out.println("method1()이 호출되었습니다.");
      return; // return 하기 전, finally 블럭이 먼저 실행된다.(catch에서 return을 만나도 마찬가지)
    } catch (Exception e) {
      e.printStackTrace();
    } finally {
      System.out.println("method1()의 finally 블럭이 실행되었습니다.");
    }
  }
}
