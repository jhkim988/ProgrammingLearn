package main;

import org.springframework.context.annotation.*;

import chap07.*;
import config.*;

public class MainAspect {
	public static void main(String[] args) {
		AnnotationConfigApplicationContext ctx = new AnnotationConfigApplicationContext(AppCtx.class);
		Calculator cal = ctx.getBean("calculator", Calculator.class);
//		RecCalculator cal = ctx.getBean("calculator", RecCalculator.class); // Exception 발생, Proxy는 Calculator를 상속받는다.
		long fiveFact = cal.factorial(5);
		System.out.println("cal.factorial(5) = " + fiveFact);
		System.out.println(cal.getClass().getName()); // Proxy 타입, RecCalculator 가 아니다
		ctx.close();
	}
}
