/* Write your T-SQL query statement below */
Select max(salary) as 'SecondHighestSalary' From 
(select salary, dense_rank() over(order by salary desc )as 'DR'From employee )as T
Where DR =2 

