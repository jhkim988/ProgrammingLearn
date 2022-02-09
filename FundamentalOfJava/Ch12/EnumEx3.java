enum Transportation {
  BUS(100) { int fare(int distance) { return distance * BASIC_FARE; } },
  TRAIN(150) { int fare(int distance) { return distance * BASIC_FARE; } },
  SHIP(100) { int fare(int distance) { return distance * BASIC_FARE; } },
  AIRPLANE(300) { int fare(int distance) { return distance * BASIC_FARE; } };
  protected final int BASIC_FARE; // 각 상수에서 접근 가능하기 위해서는 protected
  Transportation(int basicFare) { BASIC_FARE = basicFare; } // private 생략
  public int getBasicFare() { return BASIC_FARE; }
  abstract int fare(int distance); // 각 열거형 상수가 이 추상메서드를 구현해야한다.
}

public class EnumEx3 {
  public static void main(String[] args) {
    System.out.println("bus fare = " + Transportation.BUS.fare(100));
    System.out.print("train fare = " + Transportation.TRAIN.fare(100));
    System.out.print("ship fare = " + Transportation.SHIP.fare(100));
    System.out.print("airplane fare = " + Transportation.AIRPLANE.fare(100));

  }
}
