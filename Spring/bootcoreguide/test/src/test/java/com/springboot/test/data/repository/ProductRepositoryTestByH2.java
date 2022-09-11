package com.springboot.test.data.repository;

import com.springboot.test.data.entity.Product;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;

import static org.junit.jupiter.api.Assertions.assertEquals;

@DataJpaTest
public class ProductRepositoryTestByH2 {
    @Autowired
    private ProductRepository productRepository;

    @Test
    void saveTest() {
        Product product = Product.builder()
                .name("펜")
                .price(1000)
                .stock(1000)
                .build();
        Product savedProduct = productRepository.save(product);
        assertEquals(product.getName(), savedProduct.getName());
        assertEquals(product.getPrice(), savedProduct.getPrice());
        assertEquals(product.getStock(), savedProduct.getStock());
    }

    @Test
    void selectTest() {
        Product product = Product.builder()
                .name("펜")
                .price(1000)
                .stock(1000)
                .build();
        Product savedProduct = productRepository.saveAndFlush(product);
        Product foundProduct = productRepository.findById(product.getNumber()).get();

        assertEquals(product.getName(), foundProduct.getName());
        assertEquals(product.getPrice(), foundProduct.getPrice());
        assertEquals(product.getStock(), foundProduct.getStock());
    }
}
