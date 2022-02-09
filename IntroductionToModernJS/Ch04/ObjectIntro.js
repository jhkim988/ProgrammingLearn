{
  // 트럼프 카드를 표현하는 객체를 생성하는 생성자
  function Card(suit, rank) {
    this.suit = suit;
    this.rank = rank;
  }

  // 생성자로 객체를 생성할 때는 new 연산자를 사용한다.
  var card = new Card("하트", "A");

  // {suit : "하트", rank: "A"}라는 객체가 생성되고, 그 참조가 변수 card에 할당된다.
  // Card 생성자로 생성한 객체를 Card 객체라고 한다.

  // 위에서 new 연산자로 객체를 생성할 것이라 기대하고 만든 함수를 생성자라고 부른다.
  // 생성자 안에서 this.프로퍼티이름에 값을 대입하면, 그 이름을 가진 프로퍼티에 값이 할당된 객체가 생성된다.
  // 이 때 this는 생성자가 생성하는 객체를 가리킨다.
  // new 연산자로 생성한 객체를 생성자의 인스턴스라고 부른다.
}

{
  // 생성자의 역할
  // 생성자는 객체를 생성하고 초기화하는 역할을 한다.
  // 이름은 같지만, 프로퍼티 값이 다른 인스턴스 여러 개를 간단히 생성할 수 있다.

  var card1 = new Card("하트", "A");
  var card2 = new Card("클럽", "K");
  var card3 = new Card("스페이드", "2");

  // 객체를 생성할 때 초기화 작업을 병행할 수 있다.
  // 메서드를 가진 객체를 생성하는 생성자 - 메서드 안에 있는 this는 생성될 인스턴스를 가리킨다.
}

{
  // Date
  var now = new Date(); // 실행한 시점의 날짜와 시간을 담은 객체를 생성한다.
  console.log(now);

  var then = new Date(2008, 5, 10); // 해당 날짜와 시간을 기리키는 Date 객체 생성
  console.log(then);

  var elapsed = now - then;
  console.log(elapsed); // 밀리초 단위 정수로 값의 타입이 바뀐다.

  // 이를 이용하여 프로그램 실행에 걸리는 시간을 밀리초 단위로 구할 수 있다.
  var start = new Date();
  // 실행시간 측정 코드
  var end = new Date();
  var elapsed = end - start;
}

{
  // Function
  var square = new Function("x", "return x * x");
  // 인자의 이름, function body
  // new Function(var1, var2, ..., varn, function body);
  // 전역변수와 자신의 지역 변수만 읽고 쓸 수 있다.
  // 함수를 동적으로 생성해야 하는 특별한 상황 외에는 사용하지 않는다.
  // 사용자 입력 문자열을 function body로 전달하면 보안 문제가 발생할 수 있다.
  // 함수 리터럴에 래퍼 객체를 제공한다는 의미가 있다.
}

{
  // 전역 객체
  // 프로그램 어느 위치에서나 사용할 수 있다.
  // JS 인터프리터가 시작될 때, 혹은 웹브라우저가 새로운 페이지를 읽을 때마다 새로운 전역 객체가 생성된다.
  // 전역 프로퍼티: undefined, NaN, Infinity
  // 생성자: Object(), String(), Number() ...
  // 전역함수: parseInt(), parseFloat(), isNaN()
  // 내장 객체: Math, JSON, Reflect

  // 클라이언트 측 JS에서는 Window 객체가 전역객체이다.
  // 웹 브라우저 고유의 다양한 프로퍼티가 추가돼 있다.
}

{
  // 객체의 분류
  // 네이티브 객체, 호스트 객체, 사용자 정의 객체
  
  // 네이티브 객체:
  // ECAMScript 사양에 정의된 객체, 내장 생성자(Object, String, Number, Boolean, Array, Function), JSON, Math, Reflect 등
  
  // 호스트 객체: ECMAScript에는 정의돼 있지 않지만, JS 실행 환경에 정의된 객체
  // 브라우저 객체(Window, Navigator, History, Location), DOM에 정의된 객체, Ajax를 위한 XMLHttpRequest 객체, HTML5의 API 등
  
  // 사용자 정의 객체
  // 사용자가 정의한 JS 코드를 실행한 결과로 생성된 객체
}