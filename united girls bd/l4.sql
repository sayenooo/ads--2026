------------------------------------------------
-- WEEK 4: SQL CORE OPERATIONS (SELECT, WHERE, ORDER BY)
------------------------------------------------

-- Setup: Create and populate tables for demonstration (DDL & DML)

CREATE TABLE student (
    s_id        CHAR(5)       PRIMARY KEY,
    s_name      VARCHAR(50)   NOT NULL,
    dept_name   VARCHAR(30),
    tot_cred    NUMERIC(3)
);

CREATE TABLE course (
    c_id        CHAR(8)       PRIMARY KEY,
    title       VARCHAR(50),
    dept_name   VARCHAR(30),
    credits     NUMERIC(2)
);

INSERT INTO student VALUES ('12345', 'Shreya', 'Comp. Sci.', 45);
INSERT INTO student VALUES ('54321', 'Priya', 'Physics', 60);
INSERT INTO student VALUES ('67890', 'Rohan', 'History', 15);
INSERT INTO student VALUES ('11111', 'Arjun', 'Comp. Sci.', 90);
INSERT INTO course VALUES ('CS-101', 'Intro to CS', 'Comp. Sci.', 4);
INSERT INTO course VALUES ('PH-200', 'Quantum Physics', 'Physics', 3);
INSERT INTO course VALUES ('HI-101', 'World History', 'History', 3);
INSERT INTO course VALUES ('CS-315', 'Database Systems', 'Comp. Sci.', 4);


-- ------------------------------------------------
-- 1. DATA TABLE SELECTION (FROM Clause)
-- ------------------------------------------------

-- Simple Selection: Selecting all columns from a single table.
SELECT *
FROM student;

-- Specific Column Selection: Selecting only the name and ID.
SELECT s_name, s_id
FROM student;


-- ------------------------------------------------
-- 2. DATA FILTERING (WHERE Clause)
-- ------------------------------------------------

-- Filtering by Equality (=) and Logical AND
-- Selects students who are in 'Comp. Sci.' AND have more than 50 credits.
SELECT s_name, tot_cred
FROM student
WHERE dept_name = 'Comp. Sci.' AND tot_cred > 50;

-- Filtering with OR
-- Selects courses either in 'Physics' OR 'History'.
SELECT title, dept_name
FROM course
WHERE dept_name = 'Physics' OR dept_name = 'History';

-- Filtering using the LIKE Operator (Pattern Matching)
-- Selects students whose names start with 'A'.
SELECT s_name
FROM student
WHERE s_name LIKE 'A%';

-- Filtering using the IN Operator (Membership Test)
-- Selects students whose department is in the list.
SELECT s_name
FROM student
WHERE dept_name IN ('Comp. Sci.', 'Physics');


-- ------------------------------------------------
-- 3. ORDERING OF OUTPUT DATA (ORDER BY Clause)
-- ------------------------------------------------

-- Ordering Ascending (ASC - default)
-- Sorts all students alphabetically by name.
SELECT s_name, dept_name
FROM student
ORDER BY s_name ASC;

-- Ordering Descending (DESC)
-- Sorts all students by total credits, highest first.
SELECT s_name, tot_cred
FROM student
ORDER BY tot_cred DESC;

-- Ordering by Multiple Columns
-- 1. Sort by department name (ASC)
-- 2. Then, for students within the same department, sort by total credits (DESC)
SELECT s_name, dept_name, tot_cred
FROM student
ORDER BY dept_name ASC, tot_cred DESC;

-- Cleanup (DDL)
DROP TABLE student;
DROP TABLE course;