{
  // 객체: 이름-값을 한 쌍으로 묶은 데이터를 여러 개 모은 것
  // 연관배열, 사전이라고도 부른다.
  // 객체에 포함된 데이터 하나(이름과 값의 쌍)을 가리켜 객체의 프로퍼티라고 한다.
  // 프로퍼티의 이름 부분을 key라고 한다.

  // 객체를 생성하는 방법 - 1. 객체 리터럴 / 2. 생성자 함수
  var card = { suit: "하트", rank: "A" }; // {...}: 객체 리터럴
  // 프로퍼티 이름으로는 모든 식별자와 문자열 리터럴(빈 문자열도 가능)
  card = { "suit" : "하트", "rank" : "A" }; // 이렇게 해도 가능

  // 프로퍼티의 값을 읽거나 쓰기: "."이나 []를 사용한다.
  console.log(card.suit); // "."을 쓸 때는 문자열로 접근하지 않는다.
  console.log(card["rank"]); // []을 쓸 때는 문자열로 접근한다.
  console.log(card.color); // undefined, 오류가 발생하지 않는다.

  var obj = {}; // 빈 객체

  card.value = 14; // 없는 프로퍼티 이름에 값을 대입하면 새로운 프로퍼티가 추가된다.
  console.log(card); // { suit: "하트", rank: "A", value: 14 }

  delete card.rank; // delete를 연산자를 사용하여 프로퍼티를 삭제한다.

  // in 연산자로 프로퍼티가 있는지 확인하기
  // in 연산자가 검색하는 대상은 그 객체가 가진 프로퍼티와 그 객체가 상속받은 모든 프로퍼티이다.
  console.log("suit" in card); // true
  console.log("color" in card); // false
  console.log("toString" in card); // true, Object 객체를 상속받았기 때문에
}

{
  // 객체 리터럴 예제
  var p = { x : 1.0, y : 2.5 }; // 좌표평면의 점
  var circle = { center : { x : 1.0, y : 2.0 }, radius: 2.5 }; // 원
  var person = {
    name : "이정규",
    age: 18,
    sex: "남",
    married: false
  };

  // 객체는 참조타입이다.
  // 변수에 객체 타입의 값을 대입하면 그 변수에는 객체의 참조(메모리에서의 위치)가 저장된다.
  var card = {suit: "하트", rank: "A"};
  var a = card;
  // a와 card는 같은 객체를 참조하고 있다.
  console.log(a.suite); // 하트
  a.suit = "스페이드";
  console.log(a.suit); // 스페이드
  console.log(card.suite); // 스페이드
}

{
  // 함수 선언문으로 함수 정의하기
  function square(x) {
    return x * x;
    // return문이 실행되면 제어권이 함수를 호출한 코드로 되돌아가고, return 문에 지정된 값은 함수의 반환값이 된다.
  }

  // 모든 식별자를 함수 이름으로 사용할 수 있다.
  // 함수 이름은 함수의 기능을 이해하기 쉽게 지어야 한다.

  console.log(square(3)); // 함수 호출

  function dist(p, q) { // 인수를 여러 개
    var dx = q.x - p.x;
    var dy = q.y - p.y;
    return Math.sqrt(dx*dx + dy*dy);
  }
  var p1 = {x:1, y:1};
  var p2 = {x:4, y:5};
  var d = dist(p1, p2);
  console.log(d); // 5

  var bark = function() { // 인수가 없는 함수
    console.log("Bow-wow");
  } // return이 없으면 undefined를 리턴한다.
  console.log(bark()); // undefined
}

{
  // 함수의 호이스팅
  // 변수의 선언문과 마찬가지로, 함수 선언문을 프로그램의 첫머리로 끌어오린다.
  console.log(squareTmp(5));
  function squareTmp(x) {
    return x * x;
  }
  // var squareTmp = function(x) {
  //   return x * x;
  // }
  // 선언문이 아니기 때문에 위 대신 아래를 사용하면 에러가 난다. 
}