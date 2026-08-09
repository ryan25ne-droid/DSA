# Write your MySQL query statement below

WITH combTable AS (
    SELECT e.id AS empId,
    DENSE_RANK() OVER (Partition BY d.name ORDER BY e.salary DESC) AS rnk
    FROM Employee e
    JOIN Department d
    ON e.departmentId= d.id
)

SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary
FROM Employee e
JOIN Department d
ON e.departmentId= d.id
JOIN combTable c
ON e.id= c.empId
WHERE c.rnk<=3;
