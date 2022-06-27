# Write your MySQL query statement below

select d.name as Department,e.name as Employee,salary from Employee e inner join Department d on e.departmentId = d.id
where (e.departmentId,salary) in (
                                   Select departmentId,max(salary)
                                   from Employee
                                    Group by departmentId
                                  )
