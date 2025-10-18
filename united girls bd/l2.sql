------------------------------------------------
-- WEEK 2 CONCEPTS: NORMALIZATION, KEYS, & ER MAPPING
------------------------------------------------

-- THEME: ER Mapping and Normalization (3NF/BCNF)
-- The schema is split into three tables to enforce 3NF/BCNF:
-- 1. instructor: Stores data dependent only on instructor_ID.
-- 2. department: Stores data dependent only on dept_name.
-- 3. teaches: Resolves a Many-to-Many relationship (Instructor <-> Course).

-- 1. Create the Department Entity Table
CREATE TABLE department (
    dept_name   VARCHAR(20)   PRIMARY KEY, -- Primary Key (PK) for the Department table
    building    VARCHAR(15)   NOT NULL,
    budget      NUMERIC(12,2)
);

-- 2. Create the Instructor Entity Table
CREATE TABLE instructor (
    instructor_ID   CHAR(5)        PRIMARY KEY,     -- Primary Key (PK) for the Instructor table
    name            VARCHAR(20)    NOT NULL,
    salary          NUMERIC(8,2),
    dept_name       VARCHAR(20),
    -- Foreign Key (FK) links Instructor to Department.
    -- This enforces the 1:N relationship (one department has many instructors).
    FOREIGN KEY (dept_name) REFERENCES department(dept_name)
);

-- 3. Create the Course Entity Table
CREATE TABLE course (
    course_ID       VARCHAR(8)    PRIMARY KEY,      -- Primary Key (PK) for the Course table
    title           VARCHAR(50)   NOT NULL,
    credits         NUMERIC(2,0)
);

-- 4. Create the Junction/Intersection Table (ER Mapping: Many-to-Many)
-- This table is required to resolve the Many-to-Many relationship between
-- Instructor and Course (e.g., an instructor teaches many courses, a course is taught by many instructors).
-- The Primary Key is a composite key, combining two Foreign Keys.
CREATE TABLE teaches (
    instructor_ID   CHAR(5),
    course_ID       VARCHAR(8),
    semester        VARCHAR(6),
    year            NUMERIC(4,0),
    
    -- Composite Primary Key (PK) combines all attributes for unique identification.
    PRIMARY KEY (instructor_ID, course_ID, semester, year),

    -- Foreign Key (FK) references the Instructor table.
    FOREIGN KEY (instructor_ID) REFERENCES instructor(instructor_ID),
    
    -- Foreign Key (FK) references the Course table.
    FOREIGN KEY (course_ID) REFERENCES course(course_ID)
);


-- THEME: PRACTICE NORMALIZING (INSERTION/UPDATE)

-- DML to illustrate the benefits of a normalized schema:
-- When a department name changes (e.g., 'Comp. Sci.' becomes 'Computer Science'),
-- we only update ONE row in the 'department' table, not multiple rows in 'instructor'.
-- This prevents the 'Update Anomaly' that occurs in unnormalized tables.

-- Insert some data
INSERT INTO department (dept_name, building, budget) VALUES ('Comp. Sci.', 'Taylor', 100000);
INSERT INTO instructor (instructor_ID, name, dept_name) VALUES ('10101', 'Srinivasan', 'Comp. Sci.');
INSERT INTO instructor (instructor_ID, name, dept_name) VALUES ('45565', 'Katz', 'Comp. Sci.');

-- DML to update the Department name (Only one change needed!)
UPDATE department
SET dept_name = 'Computer Science'
WHERE dept_name = 'Comp. Sci.';

-- The Foreign Key constraint ensures that the 'instructor' records are either
-- updated automatically (if CASCADE is set) or must be updated manually
-- to maintain integrity, preventing inconsistent data (a benefit of the FK constraint).