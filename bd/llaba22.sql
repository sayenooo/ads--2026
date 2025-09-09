
CREATE DATABASE lab2_2;

CREATE TABLE employes (
    employee_id SERIAL PRIMARY KEY,
    first_name VARCHAR(100),
    last_name VARCHAR(100),
    department_id INT,
    salary INT
);


INSERT INTO employes (first_name, last_name, department_id, salary)
VALUES ('Azat', 'Zhumagulov', 1, 55000);


INSERT INTO employes (first_name, last_name)
VALUES ('Baurzhan', 'Azat');

INSERT INTO employes (first_name, last_name, department_id, salary)
VALUES ('Sanzhar', 'Baurzhan', NULL, 45000);

INSERT INTO employes (first_name, last_name, department_id, salary)
VALUES
('Azamat', 'Sanzhar', 2, 60000),
('Erasyl', 'Azamat', 3, 70000),
('Asylkhan', 'Yearrasyl', NULL, 40000),
('Gauhar', 'Asylkhan', 4, 80000),
('Nursultan', 'Nazar', 5, 90000);


ALTER TABLE employees
ALTER COLUMN first_name SET DEFAULT 'John';


INSERT INTO employes (last_name, department_id, salary)
VALUES ('Mariyam', 2, 50000);


INSERT INTO employes DEFAULT VALUES;


CREATE TABLE employes_archive (LIKE employees INCLUDING ALL);


INSERT INTO employes_archive SELECT * FROM employees;

UPDATE employes
SET department_id = 1
WHERE department_id IS NULL;


SELECT first_name, last_name, salary * 1.15 AS "Updated Salary"
FROM employes;


DELETE FROM employes
WHERE salary < 50000;


DELETE FROM employes_archive
WHERE employee_id IN (SELECT employee_id FROM employees);

DELETE FROM employes
RETURNING employee_id, first_name, last_name, department_id, salary;


DROP DATABASE lab2_2;

















INSERT INTO  employees(employee_id,fisrt_name,last_name,department_id,salary)
VALUES (3,"Azaatt","Zhuu",2,30000)
WHERE department_id IS NULL;



UPDATE employee
SET department_id = 1
WHERE department_id IS NULL

