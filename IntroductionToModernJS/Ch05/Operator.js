// 표현식: 어떤 값으로 평가되는 것
// 숫자, 문자열, 논리값 등 원시값
// 변수, 프로퍼티, 배열 요소, 함수 호출, 메서드 호출
// 연산자를 사용하면 표현식을 조합하여 더 복잡한 표현식을 만들어낼 수 있다.

// 연산자의 우선순위
// 그룹연산자 (...)을 이용하여 계산 순서를 명시적으로 지정할 수 있다.

// 연산자의 결합법칙
// 우선순위가 같은 연산자가 나열돼 있으면 왼쪽부터 오른쪽으로 연산한다.

// 부수효과가 있는 표현식
// : 대입연산자, 증가연산자, 감소연산자, delete

// 산술 연산자: 피연산자가 숫자인 연산자
// 피연산자가 숫자가 아닐 때는 연산자가 피연산자 타입을 숫자 타입으로 바꾼다.
// 피연산자가 숫자로 바꿀 수 없는 값이거나, 계산할 수 없을 때는 NaN을 반환한다.
// 모든 산술연산은 64비트 부동소수점 연산으로 이루어진다.

// 일부 언어와 차이점:
// 정수끼리 나누어도 결과가 부동소수점이 된다.
// %의 피연산자는 부동소수점이다. a % b = sign(a) * abs(a - kb)
// + 연산자는 피연산자 중 하나가 문자열이면 나머지 피연산자를 문자열로 만들어 연결한다.
// 계산할 수 없으면 NaN, true -> 1, false -> 0, null -> 0, undefined -> NaN

// 증감 연산자를 연속으로 사용하면 참조 오류 발생
// (a++)++

// 뺄셈을 하면 정밀도 손실이 발생한다.
// 10진법으로 딱 떨어지는 값도 오차가 발생한다.(내부적으로는 2진법 연산을 하기 때문)
// (0.16 / 0.2 == 0.8) // false
// Math.abs(0.16 / 0.2 - 0.8) < 1e-10 // use this

// 문자열 연결
// 1. 피연산자가 모두 문자열이라면 문자열 연결을 한다.
// 2. 피연산자 중 하나가 문자열 혹은 문자열로 변환할 수 있는 객체라면 다른 피연산자의 타입을 문자열로 바꾼 다음 연결한다.
// 3. 그렇지 않으면 피연산자 두 개를 숫자 또는 NaN으로 타입을 바꿔 더한다.(JS 실행 환경에 따라 다르다.)

// 문자열을 String 객체로
var msgObj = new String("Everything is practice."); // 래핑: 원시값을 객체로 변환하는 행위
console.log(msgObj.length);
console.log(msgObj.charAt(3));

// 원시값인 문자열에서 프로퍼티를 사용하려고 하면 자동으로 String 객체로 바뀐다.
var msg = "Everything is practice.";
console.log(msg.length);
console.log(msg.charAt(3));
// JS에서는 원시값을 처리할 때 래퍼 객체로 자동 변환한다.(String/Number/Boolean)
// null 과 undefined는 래퍼 객체가 없다.
console.log(msgObj); // String 객체가 출력된다.
console.log(msgObj.valueOf()); // valueOf 메서드를 사용해야 문자열이 출력된다.

msg.substring(7, 10);
msg.slice(7, 10);
msg.slice(-3);
msg.slice(-9, -6);
msg.indexOf("t"); // first index
msg.indexOf("i", 10);// after 10'th char
msg.lastIndexOf("t"); // last index
msg.split(" ");
msg.replace("p", "P");
msg.toUpperCase();
msg.endsWith("."); // boolean whether last char is "." or not.
msg.includes("thing");
msg.charCodeAt(0);
msg.codePointAt(0);
// JS의 문자열은 불변이다. replace, toUpperCase 등은 기존 문자열을 수정하지 않고 새로운 문자열을 반환한다.
// codePointAt()은 써로게이트 페어를 지원한다.

// String 생성자의 프로퍼티
String.length; // 1
String.fromCharCode(65, 66, 67); // ABC, UTF-16 인코딩 값 -> 문자열
String.fromCharCode(0xd83d, 0xdcd6); // 써로게이트 페어, 5자릿수 코드 포인트 표현은 지원하지 않는다.
String.fromCodePoint(0x1f4d6); // UTF-16, 유니코드 코드포인트 스칼라값 모두 지원
"\u{1f4d6}"; // 유니코드 리터럴 사용