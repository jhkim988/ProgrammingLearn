package com.springboot.test.controller;

import com.google.gson.Gson;
import com.springboot.test.data.dto.ProductDto;
import com.springboot.test.data.dto.ProductResponseDto;
import com.springboot.test.service.impl.ProductServiceImpl;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.http.MediaType;
import org.springframework.test.web.servlet.MockMvc;
import static org.mockito.BDDMockito.given;
import static org.mockito.Mockito.verify;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.post;
import static org.springframework.test.web.servlet.result.MockMvcResultHandlers.print;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.jsonPath;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;


@WebMvcTest(ProductController.class)
public class ProductControllerTest {
    @Autowired
    private MockMvc mockMvc;

    @MockBean
    ProductServiceImpl productService;

    @Test
    @DisplayName("MockMvc 를 통한 Product 데이터 가져오기 테스트")
    void getProductTest() throws Exception {
        given(productService.getProduct(123L)).willReturn(
                ProductResponseDto.builder()
                .number(123L).name("pen").price(5000).stock(2000).build());
        String productId = "123";
        mockMvc.perform(get("/product?number="+productId))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.number").exists())
                .andExpect(jsonPath("$.name").exists())
                .andExpect(jsonPath("$.price").exists())
                .andExpect(jsonPath("$.stock").exists())
                .andDo(print());
        verify(productService).getProduct(123L);
    }

    @Test
    @DisplayName("Product 데이터 생성 테스트")
    void createProductTest() throws Exception {
        given(productService.saveProduct(ProductDto.builder().name("pen").price(5000).stock(2000).build()))
                .willReturn(ProductResponseDto.builder().number(12315L).name("pen").price(5000).stock(2000).build());
        ProductDto productDto = ProductDto.builder()
                .name("pen").price(5000).stock(2000).build();
        Gson gson = new Gson();
        String content = gson.toJson(productDto);

        mockMvc.perform(post("/product").content(content).contentType(MediaType.APPLICATION_JSON))
                .andExpect(status().isOk())
//                .andExpect(jsonPath("$.number").exists())
//                .andExpect(jsonPath("$.name").exists())
//                .andExpect(jsonPath("$.price").exists())
//                .andExpect(jsonPath("$.stock").exists())
                .andDo(print());
        verify(productService).saveProduct(ProductDto.builder().name("pen").price(5000).stock(2000).build());
    }
}
