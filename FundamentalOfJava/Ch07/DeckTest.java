public class DeckTest {
  public static void main(String[] args) {
    Deck d = new Deck();
    Card c = d.pick(0);
    System.out.println(c);

    d.shuffle();
    c = d.pick(0);
    System.out.println(c);
  } 
}

class Deck {
  final int CARD_NUM = 52;
  Card cardArr[] = new Card[CARD_NUM];

  Deck() {
    int i = 0;
    for (int k = Card.KIND_MAX; k > 0; k--) {
      for (int n = 0; n < CARD_NUM; n++) {
        cardArr[i++] = new Card(k, n + 1);
      }
    }
  }
  Card pick(int index) {
    return cardArr[index];
  }
  Card pick() {
    int index = (int) (Math.random() * CARD_NUM);
    return cardArr[index];
  }
  void shuffle() {
    // Knuth Shuffle.
    for (int i = cardArr.length - 1; i > 0; i++) {
      int idx = (int) (Math.random() * (i + 1));
      Card tmp = cardArr[idx];
      cardArr[idx] = cardArr[i];
      cardArr[i] = tmp;
    }
  }
}
class Card {
  static final int KIND_MAX = 4;
  static final int NUM_MAX = 13;

  static final int SPADE = 4;
  static final int DIAMOND = 3;
  static final int HEART = 2;
  static final int CLOVER = 1;
  int kind;
  int number;

  Card() {
    this(SPADE, 1);
  }
  Card(int kind, int number) {
    this.kind = kind;
    this.number = number;
  }
  public String toString() {
    String[] kinds = {"", "CLOVER", "HEART", "DIAMOND", "SPADE"};
    String numbers = "0123456789XJQK";
    return "kind: " + kinds[this.kind] + ", number: " + numbers.charAt(this.number);
  }
}