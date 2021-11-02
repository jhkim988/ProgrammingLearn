// Object 클래스에 있는 toString 메서드는
// getClass().getName() + "@" + Integer.toHexString(hashCode()); 를 반환한다.

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
}

public class CardToString {
  public static void main(String[] args) {
    Card c1 = new Card();
    Card c2 = new Card("HEART", 10);

    System.out.println(c1.toString());
    System.out.println(c2.toString());
  } 
}
