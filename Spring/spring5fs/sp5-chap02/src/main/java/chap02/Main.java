package chap02;

//Java 설정에서 정보를 읽어와 Bean 객체를 생성하고 관리한다.
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class Main {
	public static void main(String[] args) {
		// AppContext 클래스를 생성자에 전달한다.
		// AppContext에 정의한 @Bean 설정 정보를 읽어와 Greeter 객체를 생성하고 초기화한다.
		AnnotationConfigApplicationContext ctx = new AnnotationConfigApplicationContext(AppContext.class);
		Greeter g = ctx.getBean("greeter", Greeter.class); // 메서드 이름(Bean 객체 이름), 검색할 Bean 객체의 타입
		String msg = g.greet("스프링");
		System.out.println(msg);
		ctx.close();
		// BeanFactory <- AnnotationContext <- AnnotationConfigApplicationContext
		// BeanFactory, ApplicationContext는 Bean 객체의 생성, 초기화, 보관 제거 등을 관리한다. 이를 Spring 컨테이너라고 표현한다.
		// 스프링 컨테이너는 내부적으로 빈 객체와 빈 이름을 연결하는 정보를 갖는다.
	}
}
