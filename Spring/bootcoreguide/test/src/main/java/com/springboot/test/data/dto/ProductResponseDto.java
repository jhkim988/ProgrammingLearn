package com.springboot.test.data.dto;

import lombok.Builder;
import lombok.EqualsAndHashCode;
import lombok.Getter;
import lombok.ToString;

@ToString
@EqualsAndHashCode
@Getter
public class ProductResponseDto {
    Long number;
    String name;
    Integer price;
    Integer stock;

    @Builder
    public ProductResponseDto(Long number, String name, Integer price, Integer stock) {
        this.number = number;
        this.name = name;
        this.price = price;
        this.stock = stock;
    }
}
