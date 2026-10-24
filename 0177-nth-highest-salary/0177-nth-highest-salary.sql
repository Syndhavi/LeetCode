CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    /* Write your PL/SQL query statement below */
    select max(salary) into result
    from (select salary,DENSE_RANK() OVER (ORDER BY salary desc) as rnk 
            FROM Employee)
    where rnk=N;
    RETURN result;
END;