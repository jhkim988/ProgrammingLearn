package config;

import java.time.LocalDateTime;
import java.util.List;

import org.springframework.context.MessageSource;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.support.ResourceBundleMessageSource;
import org.springframework.http.converter.HttpMessageConverter;
import org.springframework.http.converter.json.Jackson2ObjectMapperBuilder;
import org.springframework.http.converter.json.MappingJackson2HttpMessageConverter;
import org.springframework.web.servlet.config.annotation.DefaultServletHandlerConfigurer;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;
import org.springframework.web.servlet.config.annotation.InterceptorRegistry;
import org.springframework.web.servlet.config.annotation.ViewControllerRegistry;
import org.springframework.web.servlet.config.annotation.ViewResolverRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import com.fasterxml.jackson.datatype.jsr310.ser.LocalDateTimeSerializer;

import interceptor.AuthCheckInterceptor;

@Configuration
@EnableWebMvc
public class MvcConfig implements WebMvcConfigurer {
	
	@Override
	public void configureDefaultServletHandling(DefaultServletHandlerConfigurer configurer) {
		configurer.enable();
	}
	
	@Override
	public void configureViewResolvers(ViewResolverRegistry registry) {
		registry.jsp("/WEB-INF/view/", ".jsp");
	}
	
	// 컨트롤러 구현 없이 경로 매핑
	@Override
	public void addViewControllers(ViewControllerRegistry registry) {
		registry.addViewController("/main").setViewName("main");
	}
	
	@Bean
	public MessageSource messageSource() {
		ResourceBundleMessageSource ms = new ResourceBundleMessageSource();
		ms.setBasenames("message.label");
		ms.setDefaultEncoding("UTF-8");
		return ms;
	}
	
	// Global 범위 Validator
//	@Override
//	public Validator getValidator() {
//		return new RegisterRequestValidator();
//	}
	
	@Override
	public void addInterceptors(InterceptorRegistry registry) {
		registry.addInterceptor(authCheckInterceptor()).addPathPatterns("/edit/**");
	}
	@Bean
	public AuthCheckInterceptor authCheckInterceptor() {
		return new AuthCheckInterceptor();
	}
	
	// HttpMessageConverter: Java 객체 -> Http 응답 변환할 때 사용한다.
	// MappingJackson2HttpMessageConverter를 새로 등록해서 날짜형식을 원하는 형식으로 변환하도록 설정한다.
	@Override
	public void extendMessageConverters(List<HttpMessageConverter<?>> converters) {
		ObjectMapper objectMapper = Jackson2ObjectMapperBuilder
										.json()
										.featuresToDisable(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS) // 유닉스 타임스탬프로 출력하는 기능 비활성화
//										.simpleDateFormat("yyyyMMddHHmmss") // Java.util.Date 타입을 변환한다. LocalDateTime 타입은 변환해주지 않는다.
//										.serializerByType(LocalDateTime.class, new LocalDateTimeSerializer(formatter)); // DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
										.build();
		converters.add(0, new MappingJackson2HttpMessageConverter(objectMapper));
		// converters 리스트에 들어있는 순서대로 변환을 실행한다. 새로 추가한 규칙을 목록의 제일 앞에 위치시킨다. 따라서 0번 인덱스에 추가한다.
		// Member의 @JsonFormat을 삭제하고 적용되는지 확인한다.
	}
}
