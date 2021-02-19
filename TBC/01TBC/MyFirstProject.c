#include <stdio.h> // standard input output

// 컴파일러: c 파일을 obj 파일로 바꿔준다.
// 링커: 여러 개의 obj 파일을 엮어서 하나의 실행파일 exe로 만든다.
// 라이브러리 코드, 착수 코드(start-up)

// c파일과 같은 위치에 있는 debug 폴더에 MyFirstProject.obj 파일을 발견할 수 있다.
// c파일의 하나 위에 있는 debug 폴더에 MyFirstSolution.exe 파일을 발견할 수 있다.

// Build >> Clean Solution: obj 파일과 exe 파일이 사라진다.
// Project >> Export Template
int main() 
{
	printf("I Love Programming");
	return 0;
}