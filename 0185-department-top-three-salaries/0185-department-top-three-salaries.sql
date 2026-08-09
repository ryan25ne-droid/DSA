# Write your MySQL query statement below

WITH combTable AS (
    SELECT e.id AS empId, d.name as Dep, e.name as Emp, e.salary AS sal,
    DENSE_RANK() OVER (Partition BY d.name ORDER BY e.salary DESC) AS rnk
    FROM Employee e
    JOIN Department d
    ON e.departmentId= d.id
)

SELECT c.Dep AS Department, c.Emp as Employee, c.sal AS Salary
FROM combTable c
WHERE rnk<=3;