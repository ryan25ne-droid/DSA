# Write your MySQL query statement below

WITH combTable AS (
    SELECT d.id as DepId, e.name as Emp, e.salary AS sal,
    DENSE_RANK() OVER (Partition BY d.id ORDER BY e.salary DESC) AS rnk
    FROM Employee e
    JOIN Department d
    ON e.departmentId= d.id
)

SELECT d.name AS Department, c.Emp as Employee, c.sal AS Salary
FROM combTable c
JOIN Department d
ON c.DepId= d.id
WHERE rnk<=3;
