package com.springboot.test.controller;

import com.springboot.test.data.dto.ChangeProductNameDto;
import com.springboot.test.data.dto.ProductDto;
import com.springboot.test.data.dto.ProductResponseDto;
import com.springboot.test.service.ProductService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

@Controller
@RequestMapping(value="/product")
public class ProductController {
    private ProductService productService;

    @Autowired
    ProductController(ProductService productService) {
        this.productService = productService;
    }

    @GetMapping
    public ResponseEntity<ProductResponseDto> getProduct(Long number) {
        ProductResponseDto productResponseDto = productService.getProduct(number);
        return ResponseEntity.status(HttpStatus.OK).body(productResponseDto);
    }

    @PostMapping
    public ResponseEntity<ProductResponseDto> saveProduct(@RequestBody ProductDto productDto) {
        ProductResponseDto productResponseDto = productService.saveProduct(productDto);
        return ResponseEntity.status(HttpStatus.OK).body(productResponseDto);
    }

    @PutMapping
    public ResponseEntity<ProductResponseDto> changeProductName(@RequestBody ChangeProductNameDto changeProductNameDto) {
        ProductResponseDto productResponseDto = productService.changeProductName(changeProductNameDto);
        return ResponseEntity.status(HttpStatus.OK).body(productResponseDto);
    }

    @DeleteMapping
    public ResponseEntity<String> deleteProduct(Long number) {
        productService.deleteProduct(number);
        return ResponseEntity.status(HttpStatus.OK).body("상품이 제거됐습니다.");
    }
}
