package com.springboot.test.service;

import com.springboot.test.data.dto.ChangeProductNameDto;
import com.springboot.test.data.dto.ProductDto;
import com.springboot.test.data.dto.ProductResponseDto;

public interface ProductService {
    public ProductResponseDto getProduct(Long number);
    public ProductResponseDto saveProduct(ProductDto productDto);
    public ProductResponseDto changeProductName(ChangeProductNameDto changeProductNameDto);
    public void deleteProduct(Long number);
}
