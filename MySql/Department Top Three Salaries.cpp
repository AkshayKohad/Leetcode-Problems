# Write your MySQL query statement below

with cte as(
select d.name Department, e.name Employee,e.salary Salary,

dense_rank() over (partition by d.id order by Salary desc) rnk
from 
Employee e
inner join
Department d

on e.departmentID = d.id

)

select Department,Employee,Salary
from 
cte where rnk <=3;
