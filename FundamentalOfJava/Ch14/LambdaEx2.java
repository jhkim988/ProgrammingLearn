@FunctionalInterface
interface MyFunction {
  void myMethod();
}
public class LambdaEx2 {
  public static void main(String[] args) {
    MyFunction f = () -> {}; // (MyFunction) (() -> {});
    Object obj = (MyFunction) (() -> {});
    String str = ((Object) (MyFunction) (() -> {})).toString();
    // 람다식은 Object로 형변환 하지 못한다. 형변환을 하기 위해서는 MyFunction을 한 번 거쳐야한다.

    System.out.println(f);
    System.out.println(obj);
    System.out.println(str);

    // System.out.println(() -> {}); // Exception
    System.out.println((MyFunction) (() -> {}));
    // System.out.println((MyFunction) (() -> {}).toString());
    System.out.println(((Object) (MyFunction) (() -> {})).toString());
  
    // 익명 객체라면 객체타입이 "외부클래스$번호"로 설정되는데, 이를 확인할 수 있다.
  } 
}
