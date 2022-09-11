package com.springboot.test.service.impl;

import com.springboot.test.data.dto.ChangeProductNameDto;
import com.springboot.test.data.dto.ProductDto;
import com.springboot.test.data.dto.ProductResponseDto;
import com.springboot.test.data.entity.Product;
import com.springboot.test.data.repository.ProductRepository;
import com.springboot.test.service.ProductService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;

public class ProductServiceImpl implements ProductService {
    private final Logger LOGGER = LoggerFactory.getLogger(ProductServiceImpl.class);
    private final ProductRepository productRepository;

    @Autowired
    ProductServiceImpl(ProductRepository productRepository) {
        this.productRepository = productRepository;
    }
    @Override
    public ProductResponseDto getProduct(Long number) {
        LOGGER.info("[getProduct] input number: {}", number);
        Product product = productRepository.findById(number).orElseThrow(() -> {
                    throw new IllegalArgumentException("상품이 존재하지 않습니다.");
                }
        );
        LOGGER.info("[getProduct] product number: {}, name: {}", product.getNumber(), product.getName());
        ProductResponseDto productResponseDto = ProductResponseDto.builder()
                .number(product.getNumber())
                .name(product.getName())
                .price(product.getPrice())
                .stock(product.getStock())
                .build();
        return productResponseDto;
    }

    @Override
    public ProductResponseDto saveProduct(ProductDto productDto) {
        LOGGER.info("[saveProduct] productDTO: {}", productDto);
        Product product = Product.builder()
                .name(productDto.getName())
                .price(productDto.getPrice())
                .stock(productDto.getStock())
                .build();
        Product savedProduct = productRepository.save(product);
        LOGGER.info("[saveProduct] saveProduct: {}", savedProduct.toString());
        ProductResponseDto productResponseDto = ProductResponseDto.builder()
                .number(savedProduct.getNumber())
                .name(savedProduct.getName())
                .price(savedProduct.getPrice())
                .stock(savedProduct.getStock())
                .build();
        return productResponseDto;
    }

    @Override
    public ProductResponseDto changeProductName(ChangeProductNameDto changeProductNameDto) {
        LOGGER.info("[changeProductName] number: {}, name: {}", changeProductNameDto.getNumber(), changeProductNameDto.getName());
        Product foundProduct = productRepository.findById(changeProductNameDto.getNumber()).orElseThrow(() -> {
            throw new IllegalArgumentException("상품이 존재하지 않습니다.");
        });
        foundProduct.update(changeProductNameDto.getName());
        Product changedProduct = productRepository.save(foundProduct);
        LOGGER.info("[changeProductName] changedProduct: {} ", changedProduct.toString());
        ProductResponseDto productResponseDto = ProductResponseDto.builder()
                .number(changedProduct.getNumber())
                .name(changedProduct.getName())
                .price(changedProduct.getPrice())
                .stock(changedProduct.getStock())
                .build();
        return productResponseDto;
    }

    @Override
    public void deleteProduct(Long number) {
        productRepository.deleteById(number);
    }
}
