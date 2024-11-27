Approach-1
select name from Customer where referee_id != 2 or referee_id is null;


Approach-2
SELECT name FROM Customer 
WHERE id NOT IN (SELECT id FROM Customer WHERE referee_id = 2);
