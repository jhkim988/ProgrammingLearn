package config;

import spring.*;
import org.springframework.context.annotation.*;
import org.springframework.context.annotation.ComponentScan.*;

@Configuration
@ComponentScan(basePackages = {"spring"},
	excludeFilters = @Filter(type = FilterType.ASPECTJ, pattern = "spring.*Dao"))
public class AppCtxWithExclude {
	@Bean
	public MemberDao memberDao() {
		return new MemberDao();
	}
}
// AspectJ 패턴이 동작하려면 의존 대상에 aspectjweaver 모듈을 추가해야한다.
// pom.xml에 dependency 추가
// 패턴을 여러 개 지정하려면 patterns(String[]) 속성을 이용한다.

// 특정 애노테이션을 붙인 타입을 컴포넌트 대상에서 제외할 때는
//excludeFilters = @Filter(type = FilterType.ANNOTATION, classes = {NoProduct.class, ManualBean.class})

// 특정 타입이나 그 하위 타입을 컴포넌트 대상에서 제외할 때는
//excludeFilters = @Filter(type = FilterType.ASSIGNABLE_TYPE, classes = MemberDao.class)

// 여러 필터를 적용하고 싶다면 excludeFilters를 배열로 사용하여 @Filter 목록을 전달하면 된다.

// 자동으로 스캔되는 대상
// @Component, @Controller, @Service, @Repository, @Aspect, @Configuration