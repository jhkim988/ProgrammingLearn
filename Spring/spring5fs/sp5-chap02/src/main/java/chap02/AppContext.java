package chap02;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration // Spring 설정 클래스로 지정한다.
public class AppContext {
	@Bean // 스프링이 생성하는 객체를 Bean 객체라고 한다. 이 메서드가 생성한 객체를 Spring이 관리하는 Bean 객체로 등록한다.
	public Greeter greeter() {
		Greeter g = new Greeter();
		g.setFormat("%s, 안녕하세요");
		return g;
	}
}
