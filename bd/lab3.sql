
CREATE TABLE students (
    student_id SERIAL PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    date_of_birth DATE,
    email VARCHAR(100) UNIQUE,
    city VARCHAR(50)
);

-- 3. Create table for Courses
CREATE TABLE courses (
    course_id SERIAL PRIMARY KEY,
    course_code VARCHAR(10) UNIQUE,
    course_name VARCHAR(100),
    credits INT
);

-- 4. Create table for Registration (link between students and courses)
CREATE TABLE registration (
    registration_id SERIAL PRIMARY KEY,
    student_id INT,
    course_id INT,
    registration_date DATE,
    grade VARCHAR(2),
    FOREIGN KEY (student_id) REFERENCES students(student_id) ON DELETE CASCADE,
    FOREIGN KEY (course_id) REFERENCES courses(course_id) ON DELETE CASCADE
);

-- 5. Insert sample data into students table
INSERT INTO students (first_name, last_name, date_of_birth, email, city) VALUES
('Alice', 'Johnson', '2001-05-14', 'alice.johnson@example.com', 'Almaty'),
('Bob', 'Smith', '2000-09-20', 'bob.smith@example.com', 'New York'),
('Cathy', 'Williams', '2002-01-10', 'cathy.williams@example.com', 'Almaty'),
('David', 'Brown', '1999-03-22', 'david.brown@example.com', 'Los Angeles');

-- 6. Insert sample data into courses table
INSERT INTO courses (course_code, course_name, credits) VALUES
('CS101', 'Introduction to Computer Science', 4),
('MATH201', 'Calculus I', 3),
('PHYS301', 'General Physics', 3),
('HIST101', 'World History', 2);

-- 7. Insert sample data into registration table
INSERT INTO registration (student_id, course_id, registration_date, grade) VALUES
(1, 1, '2023-09-01', NULL),  -- Alice registered for CS101
(2, 2, '2023-09-01', NULL),  -- Bob registered for MATH201
(3, 3, '2023-09-01', NULL),  -- Cathy registered for PHYS301
(4, 1, '2023-09-01', NULL),  -- David registered for CS101
(1, 4, '2023-09-01', NULL);  -- Alice registered for HIST101

SELECT last_name FROM students;

SELECT DISTINCT last_name FROM students;

SELECT * FROM students WHERE last_name = 'Johnson';

SELECT * FROM students WHERE last_name IN ('Johnson', 'Smith');


SELECT students.*
FROM students
JOIN registration ON students.student_id = registration.student_id
JOIN courses ON registration.course_id = courses.course_id
WHERE courses.course_code = 'CS101';


SELECT students.*
FROM students
JOIN registration ON students.student_id = registration.student_id
JOIN courses ON registration.course_id = courses.course_id
WHERE courses.course_code IN ('MATH201', 'PHYS301');


SELECT SUM(credits) AS sum FROM courses;

SELECT course_id, COUNT(*) AS student_count
FROM registration
GROUP BY course_id;

SELECT course_id
FROM registration
GROUP BY course_id
HAVING COUNT(*) > 2;

SELECT course_name
FROM courses
ORDER BY credits DESC
LIMIT 1 OFFSET 1;

SELECT students.first_name, students.last_name
FROM students
JOIN registration ON students.student_id = registration.student_id
JOIN courses ON registration.course_id = courses.course_id
WHERE courses.credits = (SELECT MIN(credits) FROM courses);


SELECT first_name, last_name
FROM students
WHERE city = 'Almaty';

SELECT *
FROM courses
WHERE credits > 3
ORDER BY credits ASC, course_id DESC;


UPDATE courses
SET credits = credits - 1
WHERE credits = (SELECT MIN(credits) FROM courses);


UPDATE registration
SET course_id = (SELECT course_id FROM courses WHERE course_code = 'CS101')
WHERE course_id = (SELECT course_id FROM courses WHERE course_code = 'MATH201');


DELETE FROM students
WHERE student_id IN (
    SELECT student_id FROM registration
    JOIN courses ON registration.course_id = courses.course_id
    WHERE courses.course_code = 'CS101'
);


DELETE FROM students;









