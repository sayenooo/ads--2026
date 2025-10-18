------------------------------------------------
-- WEEK 5: SQL FUNCTIONS AND OPERATORS
------------------------------------------------

-- Setup: Create and populate a table with some numeric and string data.
CREATE TABLE enrollment (
    student_id  CHAR(5),
    course_name VARCHAR(50),
    grade_pts   NUMERIC(3,1),  -- E.g., 3.7 for an A-, 4.0 for A
    enroll_date DATE
);

INSERT INTO enrollment VALUES
('10001', 'Database Systems', 3.7, '2024-09-01'),
('10001', 'Web Development', 3.0, '2024-09-01'),
('10002', 'Database Systems', 4.0, '2024-09-01'),
('10003', 'Database Systems', 2.3, '2024-09-01'),
('10003', 'Calculus I', 2.0, '2024-08-20');


------------------------------------------------
-- 1. AGGREGATE FUNCTIONS (Summarizing Data)
------------------------------------------------

-- COUNT: Calculate the total number of students enrolled in 'Database Systems'.
SELECT COUNT(student_id) AS total_enrolled
FROM enrollment
WHERE course_name = 'Database Systems';

-- AVG / SUM: Calculate the average grade points and the total credits (conceptual).
-- ROUND() is used to format the numeric output.
SELECT
    ROUND(AVG(grade_pts), 2) AS average_gpa,  -- Numeric function (ROUND) on aggregate (AVG)
    SUM(grade_pts) AS total_grade_pts_earned
FROM enrollment
WHERE student_id = '10001';

-- MIN / MAX: Find the highest and lowest grade points recorded.
SELECT
    MAX(grade_pts) AS highest_grade,
    MIN(grade_pts) AS lowest_grade
FROM enrollment;


------------------------------------------------
-- 2. SCALAR FUNCTIONS AND OPERATORS (Data Transformation)
------------------------------------------------

-- STRING FUNCTIONS (UPPER/LOWER) and Concatenation Operator (|| in PostgreSQL)
-- Changes the case and combines (concatenates) two strings.
SELECT
    UPPER(course_name) AS COURSE_TITLE_UC,
    LOWER(course_name) || ' for ' || student_id AS combined_info
FROM enrollment
WHERE student_id = '10002';


-- NUMERIC OPERATORS AND FUNCTIONS
-- Use arithmetic operator (+) and numeric function (ABS) to calculate hypothetical change.
SELECT
    course_name,
    grade_pts + 0.3 AS hypothetical_increase, -- Arithmetic Operator (+)
    ABS(grade_pts - 4.0) AS points_from_perfect -- Numeric Function (ABS)
FROM enrollment;


-- DATE/TIME FUNCTIONS
-- Calculate the current date and extract the month from the enrollment date.
SELECT
    course_name,
    enroll_date,
    EXTRACT(MONTH FROM enroll_date) AS enroll_month, -- Extracts part of a date
    NOW()::date AS today_date                       -- Gets current system date/time
FROM enrollment
WHERE EXTRACT(MONTH FROM enroll_date) = 9;


------------------------------------------------
-- Cleanup (DDL)
------------------------------------------------
DROP TABLE enrollment;