class Tv {
  String color;
  boolean power;
  int channel;
  
  void power() {
    power = !power;
  }

  void channelUp() {
    channel++;
  }
  void channelDown() {
    channel--;
  }
}

public class TvTest {
  // 객체지향 언어의 특징
  // 1. 코드의 재사용성이 높다.
  // - 새로운 코드를 작성할 때 기존의 코드를 이용하여 쉽게 작성할 수 있다.
  // 2. 코드의 관리가 용이하다.
  // - 코드간의 관계를 이용해서 적은 노력으로 쉽게 코드를 변경할 수 있다.
  // 3. 신뢰성이 높은 프로그래밍을 기능하게 한다.
  // - 제어자와 메서드를 이용해서 데이터를 보호하고 올바른 값을 유지;한다.
  // - 코드의 중복을 제거하여 코드 불일치로 인한 오동작을 방지할 수 있다.

  public static void main(String[] args) {
    Tv t;
    t = new Tv();
    t.channel = 7;
    t.channelDown();
    System.out.println("현재 채널은 " + t.channel + " 입니다.");
  }
}