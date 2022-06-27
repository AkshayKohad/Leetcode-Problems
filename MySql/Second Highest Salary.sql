# Write your MySQL query statement below

Select 
    IFNULL((SELECT salary FROM Employee WHERE salary <(SELECT MAX(salary) FROM Employee)
ORDER BY salary desc limit 1),NULL) as SecondHighestSalary;


