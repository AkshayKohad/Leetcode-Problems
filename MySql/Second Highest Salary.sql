# Write your MySQL query statement below


#approach1
Select 
    IFNULL((SELECT salary FROM Employee WHERE salary <(SELECT MAX(salary) FROM Employee)
ORDER BY salary desc limit 1),NULL) as SecondHighestSalary;

#approach2

select 
    IFNULL((select distinct salary from Employee order by salary desc limit 1,1),NULL) as SecondHighestSalary



