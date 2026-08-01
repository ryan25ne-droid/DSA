# Write your MySQL query statement below

-- SELECT Customers.name as Customers
-- FROM Customers
-- WHERE Customers.id NOT IN 
--     (SELECT Customers.id
--     FROM Customers 
--     RIGHT JOIN Orders
--     ON Customers.id= Orders.customerId);

SELECT Customers.name AS Customers
FROM Customers
LEFT JOIN Orders
ON Customers.id= Orders.customerId
WHERE Orders.customerId IS NULL;