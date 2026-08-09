# in mySQL, Window functions are computed after filtering, so we need to wrap them in a subquery/CTE first

-- CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
-- BEGIN
--   RETURN (
--     SELECT sub.salary
--     FROM (SELECT e.salary, DENSE_RANK() OVER (ORDER BY e.salary DESC) AS rnk
--         FROM Employee e
--     ) AS sub
    
--     WHERE sub.rnk= N  
--     LIMIT 1
--   );
-- END

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE M INT;
  SET M= N-1;  
  RETURN (
    SELECT DISTINCT e.salary
    FROM EMPLOYEE e
    ORDER BY salary DESC
    LIMIT 1 OFFSET M
  );
END

# In MySQL, we can't write math expressions like (N-1) directly inside the LIMIT/ OFFSET clauses. It requires a hardcoded integer or a plain variable name. To fix it declare a variable, perform arithmetic before the RETURN statement, and then use that variable in OFFSET