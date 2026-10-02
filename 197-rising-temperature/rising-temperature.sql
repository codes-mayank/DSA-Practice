# Write your MySQL query statement below
select v.id from Weather w
cross join Weather v  where 
datediff(v.recordDate, w.recordDate) = 1 and v.temperature > w.temperature