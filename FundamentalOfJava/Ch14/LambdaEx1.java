@FunctionalInterface
interface MyFunction {
  void run();
}

public class LambdaEx1 {
  static void execute(MyFunction f) {
    f.run();
  }
  static MyFunction getMyFunction() {
    MyFunction f = () -> System.out.println("f3.run()");
    return f;
  }
  public static void main(String[] args) {
    MyFunction f1 = () -> System.out.println("f1.run()");
    MyFunction f2 = new MyFunction() { // 익명클래스로 구현
      public void run() {
        System.out.println("f2.run()");
      }
    };
    MyFunction f3 = getMyFunction();
    execute(f1);
    execute(() -> System.out.println("run()"));
  }
}
