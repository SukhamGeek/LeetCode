# Write your MySQL query statement below
select(
select SecondHighestSalary from
(select salary as SecondHighestSalary, dense_rank() over(order by salary desc) as rnk from 
(select distinct salary 
from Employee)m) t
where rnk=2) as SecondHighestSalary;
