package com.springboot.test.data.entity;

import lombok.Builder;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.ToString;
import org.springframework.lang.Nullable;

import javax.persistence.*;
import java.time.LocalDateTime;

@Getter
@ToString
@NoArgsConstructor
@Entity
@Table(name="product")
public class Product {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    Long number;

    @Column(nullable=false)
    String name;

    @Column(nullable=false)
    Integer price;

    @Column(nullable=false)
    Integer stock;

    private LocalDateTime createdAt;
    private LocalDateTime updatedAt;

    @Builder
    public Product(Long number, String name, Integer price, Integer stock) {
        this.number = number;
        this.name = name;
        this.price = price;
        this.stock = stock;
    }
    public void update(String name) {
        this.name = name;
    }

}
