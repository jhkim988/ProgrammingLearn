package config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.support.PropertySourcesPlaceholderConfigurer;
import org.springframework.core.io.ClassPathResource;

public class PropertyConfig {
	
	// static method 임을 주의한다. 특수목적의 Bean이기 때문
	@Bean
	public static PropertySourcesPlaceholderConfigurer properties() {
		PropertySourcesPlaceholderConfigurer configurer = new PropertySourcesPlaceholderConfigurer();
		// 스프링의 Resource 타입을 이용하여 경로를 전달한다. ClassPathResource
		// src/main/resources
		configurer.setLocations(new ClassPathResource("db.properties"));
		configurer.setLocations(new ClassPathResource("info.perperties"));
		return configurer;
	}
}
