------------------------------------------------
-- WEEK 3: SQL FOUNDATIONS (DDL & DML)
------------------------------------------------

-- ------------------------------------------------
-- 1. DATA DEFINITION LANGUAGE (DDL)
-- ------------------------------------------------

-- DDL: CREATE TABLE - Basic Principles: Column Name, Data Type, and Constraints
CREATE TABLE students (
    student_id  CHAR(5)       PRIMARY KEY,   -- Primary Key Constraint
    first_name  VARCHAR(50)   NOT NULL,      -- NOT NULL Constraint
    major       VARCHAR(30)   DEFAULT 'Undeclared',
    credits     NUMERIC(3)    CHECK (credits >= 0) -- CHECK Constraint
);

-- DDL: ALTER TABLE - Basic Principle: Modify Structure
-- Add a new column to track email addresses.
ALTER TABLE students
ADD COLUMN email VARCHAR(100) UNIQUE;

-- DDL: CREATE VIEW - Define a virtual table for abstracted access
CREATE VIEW active_students AS
SELECT student_id, first_name, major
FROM students
WHERE credits > 0;


------------------------------------------------
-- 2. DATA MANIPULATION LANGUAGE (DML)
------------------------------------------------

-- DML: INSERT - Basic Principle: Add New Rows
-- Explicit column listing is best practice for reliability.
INSERT INTO students (student_id, first_name, major, credits, email)
VALUES ('98765', 'Alice', 'Computer Science', 15, 'alice@uni.edu');

-- DML: SELECT - Basic Principle: Query Data (Select What, From Where, Filter How)
-- Overview of Basic SQL Operators:
-- * (star) operator retrieves ALL columns
SELECT *
FROM students;

-- Filtering with the WHERE operator
SELECT first_name, major
FROM students
WHERE major = 'Computer Science' AND credits > 10;


-- DML: UPDATE - Basic Principle: Modify Existing Data (SET and WHERE)
-- Use WHERE to specify which row(s) to change.
UPDATE students
SET major = 'Data Science', credits = 18
WHERE student_id = '98765';


-- DML: DELETE - Basic Principle: Remove Rows (FROM and WHERE)
-- Use WHERE to prevent deleting ALL records.
DELETE FROM students
WHERE student_id = '98765';


------------------------------------------------
-- 3. DDL CLEANUP (For a complete session)
------------------------------------------------

-- DDL: DROP VIEW - Delete a database object
DROP VIEW active_students;

-- DDL: DROP TABLE - Permanently remove the entire table and all data
DROP TABLE students;