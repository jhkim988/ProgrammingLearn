package config;

import org.springframework.context.annotation.*;

import aspect.ExeTimeAspect;
import chap07.*;

@Configuration
@EnableAspectJAutoProxy
// @EnableAspectJAutoProxy(proxyTargetClass = true) // 인터페이스가 아닌 자바 클래스를 상속받아 프록시를 생성한다.
public class AppCtx {
	@Bean
	public ExeTimeAspect exeTimeAspect() {
		return new ExeTimeAspect();
	}
	
	@Bean
	public Calculator calculator() {
		return new RecCalculator();
	}
}
