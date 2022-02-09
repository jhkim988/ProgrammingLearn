function binaryOperation(a, b, operator) {
  switch (operator) { // === 으로 case를 비교한다.(타입까지 비교)
    case "+": return a + b;
    case "-": return a - b;
    case "*": return a * b;
    case "/": return a / b;
    case "%": return a % b;
    case "^": return Math.pow(a, b);
    default: return NaN;
  }
}

console.log(binaryOperation(2, 3, "+"));
console.log(binaryOperation(2, 3, "-"));
console.log(binaryOperation(2, 3, "*"));
console.log(binaryOperation(2, 3, "/"));
console.log(binaryOperation(2, 3, "^"));
console.log(binaryOperation(2, 3, "A"));

// fall throgh: break, return을 만날 때까지 아래로 내려가면서 모든 문장을 실행한다.