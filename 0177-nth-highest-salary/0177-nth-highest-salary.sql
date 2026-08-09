CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    SELECT sub.salary
    FROM (SELECT e.salary, DENSE_RANK() OVER (ORDER BY e.salary DESC) AS rnk
        FROM Employee e
    ) AS sub

    WHERE sub.rnk= N  
    LIMIT 1  
  );
END

# in mySQL, Window functions are computed after filtering, so we need to wrap them in a subquery/CTE first.