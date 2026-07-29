# Write your MySQL query statement below
SELECT p1.email 
FROM Person p1
GROUP BY p1.email 
HAVING COUNT(p1.email)>1; 