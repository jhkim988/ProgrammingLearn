package chap02;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class Main2 {
	public static void main(String[] args) {
		AnnotationConfigApplicationContext ctx = new AnnotationConfigApplicationContext(AppContext.class);
		Greeter g1 = ctx.getBean("greeter", Greeter.class);
		Greeter g2 = ctx.getBean("greeter", Greeter.class);
		System.out.println("g1 == g2 " + (g1 == g2));
		ctx.close();
		// 별도 설정을 하지 않을 경우 스프링은 한 개의 빈 객체를 생성하고, 이 때 빈 객체는 "싱글톤 범위를 갖는다"라고 표현한다.
		// 스프링은 기본적으로 한 개의 @Bean 애노테이션에 대해 한 개의 빈 객체를 생성한다.
	}
}
