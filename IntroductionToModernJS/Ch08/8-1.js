// Hoisting: JS 엔진이 함수 선언문을 프로그램/함수의 맨 처음으로 끌어올린다.
// 함수 리터럴, Function 생성자, 화살표 함수는 Hoisting이 되지 않는다.
// 함수의 참조를 변수에 할당해야 사용할 수 있다.

// Nested Function: 함수 내부에 선언된 함수
// C/Java에서는 중첩함수를 사용할 수 없지만, JS에서는 사용할 수 있다.
// 외부 함수의 최상위 레벨에만 중첩함수를 작성할 수 있다.(if문, while문 등의 문장 블록 안에서는 사용 불가)
// 중첩함수의 참조는 외부함수의 지역 변수에 저장되기 때문에, 외부 함수 바깥에서는 읽거나 쓸 수 없다.
// 중첩함수에서는 자신을 둘러싸고 있는 외부함수의 인수와 지역변수에 접근할 수 있다.
function norm(x) {
  var sum2 = sumSquare();
  return Math.sqrt(sum2);
  function sumSquare() {
    sum = 0;
    for (var i = 0; i < x.length; i++) {
      sum += x[i] * x[i];
    }
    return sum;
  }
}

var a = [2, 1, 3, 5, 7];
var n = norm(a);
console.log(n);


// 함수를 호출하는 방법
// 1. 직접 호출: var s = sqare(5);
// 2. 메서드 호출: obj.m();
// 3. 생성자 호출: var obj = new Object();
// 4. call, apply를 사용한 간접호출

// 즉시 실행 함수
// (function() {...})()
// +function() {...}()
// 함수 이름이 함수 내부에서만 유효하다.

// 인수 생략
function f(x, y) {
  console.log(`x = ${x}, y = ${y}`)
}
f(2); // 생략한 인수는 undefined가 된다.

function multiply(a, b) {
  b = b || 1;
  return a * b;
}
multiply(2, 3); // 6
multiply(2); // 2