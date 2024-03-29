package com.springboot.jpa.data.dto;

import lombok.*;

@Getter
@Setter
@NoArgsConstructor
public class ProductResponseDto {
    private Long number;
    private String name;
    private int price;
    private int stock;

    @Builder
    public ProductResponseDto(Long number, String name, int price, int stock) {
        this.number = number;
        this.name = name;
        this.price = price;
        this.stock = stock;
    }
}
