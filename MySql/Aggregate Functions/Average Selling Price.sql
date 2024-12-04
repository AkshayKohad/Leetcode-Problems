# Write your MySQL query statement below
with Updated_price as 
(select Prices.product_id,price,units,price*units as total_cost ,units as cnt_units from Prices left join UnitsSold on Prices.product_id = UnitsSold.product_id and purchase_date >= start_date and purchase_date<=end_date)


select product_id,IFNULL(round(sum(total_cost)/sum(cnt_units),2),0) as average_price  from Updated_price group by product_id

