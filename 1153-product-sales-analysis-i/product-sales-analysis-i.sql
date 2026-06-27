# Write your MySQL query statement below
Select product_name, year, price from Product inner join Sales 
on Product.product_id=sales.product_id;