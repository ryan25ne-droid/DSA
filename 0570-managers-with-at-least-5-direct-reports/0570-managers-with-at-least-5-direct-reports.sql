# Write your MySQL query statement below

-- SELECT e1.name AS name
-- FROM Employee e1
-- JOIN (
--     SELECT e.managerId AS mId,
--     COUNT(*) AS cnt
--     FROM Employee e
--     GROUP BY e.managerId
-- ) AS e2

-- ON e1.id= e2.mId
-- WHERE e2.cnt>=5

SELECT e1.name AS name
FROM Employee e1
JOIN Employee e2
ON e1.id= e2.managerId
GROUP BY e2.managerId
HAVING COUNT(e2.managerId)>=5