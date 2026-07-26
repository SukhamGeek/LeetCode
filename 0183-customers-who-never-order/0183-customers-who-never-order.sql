
select name as customers from Customers as c
left join 
Orders as o
on o.customerId= c.id
where customerId is null
