public class InterfaceTest3 {
  public static void main(String[] args) {
    A a = new A();
    a.methodA();
  } 
}
class A {
  void methodA() {
    I i = InstanceManager.getInstance(); // instance를 직접 생성하지 않고, getInstance() 메서드를 통해 제공받는다.
    i.methodB();
    System.out.println(i.toString()); // Object 메서드 호출
  }
}
interface I {
  public abstract void methodB();
}

class B implements I {
  public void methodB() {
    System.out.println("methodB in B class");
  }
  public String toString() {
    return "class B";
  }
}

class InstanceManager {
  public static I getInstance() {
    return new B(); // 다른 클래스의 인스턴스로 바꾸려면 여기만 변경하면 된다.
  }
}


