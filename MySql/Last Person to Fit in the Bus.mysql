# Write your MySQL query statement below
with weight_bus as
(
    select turn,person_name,
    sum(weight) over (order by turn asc) cumulative_wgt
    from queue
   
)
select person_name
from weight_bus
where turn = (
    select max(turn) from weight_bus
    where cumulative_wgt <= 1000
)
