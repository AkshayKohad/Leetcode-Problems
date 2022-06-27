

#using concept of limit and offset
# offset is like starting point from where limit starts the considerations next to offset points

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
 SET N = N-1;
  RETURN (
      
      select IFNULL((select distinct salary from Employee
                       order by salary desc limit N,1
                    ),NULL) as 'getNthHighestSalary(N+1)'
      # Write your MySQL query statement below.
      
  );
END


#approach2

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
        select min(salary)
        from 
            (select distinct salary from employee 
            order by salary desc
            limit N) t 
        having count(*) >= N
        
  );
END
