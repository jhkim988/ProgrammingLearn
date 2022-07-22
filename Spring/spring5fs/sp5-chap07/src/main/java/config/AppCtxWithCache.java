package config;

import org.springframework.context.annotation.*;

import aspect.*;
import chap07.*;

@Configuration
@EnableAspectJAutoProxy
public class AppCtxWithCache {
	@Bean
	public CacheAspect cacheAspect() {
		return new CacheAspect();
	}
	@Bean
	public ExeTimeAspect exeTimeAspect() {
		return new ExeTimeAspect();
	}
	@Bean
	public Calculator calculator() {
		return new RecCalculator();
	}
}
