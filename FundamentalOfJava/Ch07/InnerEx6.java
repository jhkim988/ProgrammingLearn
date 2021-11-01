public class InnerEx6 {
  // 익명클래스
  // 조상클래스 이름/구현 인터페이스 이름
  Object iv = new Object() { void method() { } };
  static Object cv = new Object() { void method() { } };  

  void myMethod() {
    Object lv = new Object() { void method() { } };
  }
}
