-- 코드를 입력하세요
# SELECT PRODUCT_ID,PRODUCT_NAME,PRODUCT_CD,CATEGORY, price from FOOD_PRODUCT where price = (select max(price) from FOOD_PRODUCT);
SELECT PRODUCT_ID,PRODUCT_NAME,PRODUCT_CD,CATEGORY, price from FOOD_PRODUCT order by price DESC limit 1;