{
  var sum; // var: 선언자
  var a, b; // 여러 개를 한 문장으로 선언

  var x; // 선언만 하면 undefined
  console.log(x); // undefined
  x = 2; // 값 대입
}

{
  var x = 5; // 선언과 동시에 할당
  var a = 1, b = 2; c = 3;
}

{
  console.log(x); // 선언하지 않은 변수, 참조오류
  x = 2;
  // 선언하지 않은 변수에 값 대입, 오류 발생하지 않는다.
  // 선언하지 않은 상태에서 값을 대입하면, js 엔진이 자동으로 전역 변수로 선언하기 때문
  // Strict 모드에서는 선언하지 않은 변수에 값을 대입할 때 오류가 발생한다.
}

{
  // Hoisting(변수 선언 끌어올림)
  console.log(x); // undefined, 오류 발생하지 않음
  var x;
}

{
  // 프로그램 중간에서 변수를 선언하더라도 변수가 프로그램 첫 머리에 선언된 것처럼 다른 문장 앞에 생성된다.
  // 그러나 선언과 동시에 대입하는 코드는 끌어올리지 않는다.
  // 즉 var x;는 끌어올리지만, x = 5는 끌어올리지 않는다.
  console.log(x); // undefined
  var x = 5;
  console.log(x); // 5
}

{
  // 동적 타이핑, 변수에 모든 타입의 데이터를 대입할 수 있다.
  var pi = 3.14;
  console.log(pi);
  pi = "원주율";
  console.log(pi);
}

{
  // 데이터 타입의 분류
  // 원시타입 - 숫자, 문자열, 논리값, 특수한 값(undefined, null), Symbol
  // 객체타입 - 배열, 함수, 정규 표현식 등
  
  // 숫자 - 64비트 부동소수점, C/Java의 double 타입과 같다.
  // 배열 인덱스, 비트연산은 32비트 정수로 처리한다.
  
  // 특별한 숫자를 표현하기 위한 문자열, 읽기 전용이므로 수정할 수 없다.
  // Infinity, NaN: 전역변수
  // Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY ...

  // 문자열
  // 큰따옴표/작은따옴표
  // JS를 HTML 요소에 넣을 때는 JS 프로그램을 문자열로 작성한다
  // <input type="button" value="Click" onclick="alert('Thanks!')"></input>
  // 이스케이프 시퀀스
  // 써로게이트 페어의 다섯 자리수 코드 포인트
  // UTF-16 유니코드로 표현할 수 있는 범위를 넘어서는 문자들은 써로게이트 페어를 사용하여 표현한다.

  // 논리값 - true/false
  // 특수한 값
  // "값이 없음"을 표현하기 위한 특수한 값: null, undefined
  // undefined는 정의되지 않은 상태
    // 값을 할당하지 않는 변수의 값
    // 없는 객체의 프로퍼티를 읽으려고 시도했을 때의 값
    // 없는 배열의 요소를 읽으려고 시도했을 때의 값
    // 아무것도 반환하지 않는 함수가 반환하는 값
    // 함수를 호출했을 때 전달받지 못한 인수의 값
  // null은 "아무것도 없음"을 표현한 리터럴
}

{
  // Symbol
  // Iterator, instanceof 재정의, 메서드의 다양한 확장 방법 등을 이해하기 위해 필요한 기초지식
  // Symbol: 자기 자신을 제외한 그 어떤 값과도 다른 유일무이한 값
  var sym1 = Symbol(); // Symbol()은 호출할 때마다 새로운 값을 만든다.
  var sym2 = Symbol();
  console.log(sym1 == sym2); // false

  var HEART = Symbol("하트"); // 생성된 심벌의 설명을 덧붙일 수 있다. 설명은 toString() 메서드를 사용하여 확인할 수 있다.
  console.log(HEART.toString());

  // 오셀로 게임을 만든다면...
  var NONE = 0; // 칸에 돌이 놓여있지 않은 상태
  var BLACK = -1; // 검은 돌이 놓여있는 상태
  var WHITE = 1; // 흰 돌이 놓여있는 상태
  var cell = WHITE; // 칸에 흰 돌이 놓여있는 상태
  
  // cell의 값을 알기 위해서는...
  cell == WHITE; // 이렇게 작성해야 읽기 쉽다.
  cell == 1; // 문제없이 작동하지만 읽기 어렵다.

  // Symbol을 이용한다.

  var NONE = Symbol("none");
  var BLACK = Symbol("black");
  var WHITE = Symbol("white");
  // cell의 값을 확인할 때 NONE, BLACK, WHITE만 사용하도록 제한한다.
}

{
  // 심벌과 문자열 연결하기
  // Symbol.for()를 활용하여 문자열과 연결된 심벌을 생성한다.
  var sym1 = Symbol.for("club"); // 전역 레지스트리에 심벌이 만들어진다.
  var sym2 = Symbol.for("club"); // 전역 레지스트리에서 그 심벌을 지정한 문자열로 불러올 수 있다.
  console.log(sym1 == sym2); // true
  // 이 기능을 활용하면 같은 심벌을 공유할 수 있다.
}

{
  // 심벌과 연결된 문자열은 Symbol.keyFor()으로 구할 수 있다.
  var sym1 = Symbol.for("club");
  var sym2 = Symbol("club");
  console.log(Symbol.keyFor(sym1)); // club
  console.log(Symbol.keyFor(sym2)); // undefined
}

{
  // 템플릿 리터럴
  `I'm going to learn JavaScript`; // 백틱 ``을 사용
  var t = `Man errs as long as
  he strives.`; // 줄바꿈이 자유롭다.
  `Man errs as long as\nhe strives.`; // 이스케이프 시퀀스를 사용할 수 있다.
  String.raw`Man errs as long as\nhe strives.`; // 이스케이프 시퀀스를 그대로 출력하고 싶다면 String.raw를 이용한다.
  // String.raw를 태그함수라고 한다.

  // 보간 표현식
  var a = 2, b = 3;
  console.log(`${a} + ${b} = ${a + b}`);
  var now = new Date();
  console.log(`오늘은 ${now.getMonth() + 1} 월 ${now.getDate()} 일 입니다.`);
  // ${...}을 플레이스 홀더라고 한다.(실제 내용물을 나중에 삽입할 수 있도록 일단 확보한 장소라는 뜻)
  // 실행 시점에 외부에서 주어지는 값을 표현식에 반영하고자 할 때, 그것이 들어갈 수 있도록 마련한 장소
}