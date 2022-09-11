package com.springboot.test.data.dto;

import lombok.*;

@Getter
@EqualsAndHashCode
public class ProductDto {
    private String name;
    private Integer price;
    private Integer stock;

    @Builder
    public ProductDto(String name, Integer price, Integer stock) {
        this.name = name;
        this.price = price;
        this.stock = stock;
    }
}
