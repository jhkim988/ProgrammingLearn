public class InnerEx3 {
  private int outerIv = 0;
  static int outerCv = 0;
  
  class InstanceInner {
    int iiv = outerIv;
    int iiv2 = outerCv;
  }

  static class StaticInner {
    // static class 는 외부 클래스의 인스턴스 멤버에 접근할 수 없다.
    // int siv = outerIv;
    static int scv = outerCv;
  }

  void myMethod() {
    int lv = 0;
    final int Lv = 0; // JDK1.8에서 생략 가능

    class LocalInner {
      int lliv = outerIv;
      int liv2 = outerCv;
      // int liv3 = lv; // 외부 클래스의 지역변수는 final이 붙은 상수만 접근 가능하다. JDK1.8에선 허용
      int liv4 = Lv;
    }
  }
}
