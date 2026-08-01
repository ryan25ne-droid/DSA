# Write your MySQL query statement below

-- SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary
-- FROM EMPLOYEE e
-- LEFT JOIN Department d
-- ON e.departmentId= d.id
-- GROUP BY d.name
-- HAVING e.salary= MAX(e.salary);

-- 1st Sub Query
-- SELECT d.id, MAX(e.salary)
-- FROM Employee e
-- LEFT JOIN Department d
-- ON e.departmentId= d.id
-- GROUP BY d.id;

-- 2nd Sub Query
-- SELECT e1.departmentId 
-- FROM Employee e1
-- JOIN (
--     SELECT d.id AS DID, MAX(e.salary) AS SAL
--     FROM Employee e
--     LEFT JOIN Department d
--     ON e.departmentId= d.id
--     GROUP BY d.id
-- ) AS Tab

-- ON e1.salary= Tab.SAL AND e1.departmentId= Tab.DID;

SELECT d.name AS Department, e1.name AS Employee, e1.salary AS Salary
FROM Employee e1
JOIN (
    SELECT d.id AS DID, MAX(e.salary) AS SAL
    FROM Employee e
    LEFT JOIN Department d
    ON e.departmentId= d.id
    GROUP BY d.id
) AS Tab

ON e1.salary= Tab.SAL AND e1.departmentId= Tab.DID

LEFT JOIN Department d
ON e1.departmentId= d.id;



-- SELECT d.id, MAX(e.salary)
-- FROM Employee e
-- LEFT JOIN Department d
-- ON e.departmentId= d.id
-- GROUP BY d.name;

-- We select d.id, but group by d.name. If 2 departments have the same name, or if d.id isn't in the GROUP BY clause, MySQL in strict mode will flag this. It is safer to group directly by departmentId (or d.id).

-- Handling Nulls. Since an employee might not have a department (or a department might not have employees), joining on e.departmentId = d.id and grouping by departmentId directly on the Employee table gives you the exact (departmentId, max_salary) pairs you need.
