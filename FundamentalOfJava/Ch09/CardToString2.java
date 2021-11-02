class Card {
  String kind;
  int number;

  Card() {
    this("SPADE", 1);
  }
  Card(String kind, int number) {
    this.kind = kind;
    this.number = number;
  }

  // 오버라이딩 할 때 조상 클래스 메서드의 접근제어자 범위와 같거나 보다 더 넓게 설정해야한다.
  // Object의 toString() 메서드는 접근 제어자가 public 이므로, 오버라이딩 할 때 public 으로 설정해야한다.
  public String toString() {
    return "kind: " + kind + ", number: " + number;
  }
}

public class CardToString2 {
  public static void main(String[] args) {
    Card c1 = new Card();
    Card c2 = new Card("HEART", 10);

    System.out.println(c1.toString());
    System.out.println(c2.toString());
  } 
}
