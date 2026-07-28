# Write your MySQL query statement below
select customer_id, count(visit_id) as count_no_trans
from
(select *
from visits as a
left join (select transaction_id, visit_id as v,amount from transactions) as b
on a.visit_id = b.v
where transaction_id is NULL) t
group by customer_id