@FunctionalInterface
interface MyFucntion {
  void myMethod();
}

class Outer {
  int val = 10; // Outer.this.val
  class Inner {
    int val = 20; // this.val
    void method(int i) { // final int i
      int val = 30; // final int val
      // i = 10;
      MyFucntion f = () -> {
        // 람다식 내에서 참조하는 지역변수는 final로 간주된다.
        // 람다식에서 i와 val을 참조하고 있기 때문에, method(람다식 외부)에서도 이 값을 바꿀 수 없다.
        System.out.println("\ti : " + i);
        System.out.println("\tval : " + val);
        System.out.println("\tthis.val: " + this.val);
        System.out.println("\tOuter.this.val: " + Outer.this.val);
      };
      f.myMethod();
    }
  }
}
// Inner class
// NoClassDefFoundError
// Class path re-setting.
public class LambdaEx3 {
  public static void main(String[] args) {
    Outer outer = new Outer();
    Outer.Inner inner = outer.new Inner();
    inner.method(100);
  }
}
