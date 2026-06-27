/* Write your T-SQL query statement below */
Select customer_id, count(Visits.visit_id)[count_no_trans] from Visits left join Transactions 
on Visits.visit_id=transactions.visit_id where Transactions.transaction_id is null
group by customer_id;