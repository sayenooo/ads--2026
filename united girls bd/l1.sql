------------------------------------------------
-- DATABASE LECTURE 1: INTRODUCTION TO DATABASES
------------------------------------------------

-- THEME 1: DATABASE APPLICATIONS EXAMPLES [cite: 3, 19]
-- Databases are used extensively across various industries:
-- Enterprise (Sales, HR, Manufacturing) [cite: 5, 8, 9, 10], Banking/Finance (Accounts, Loans, Stocks)[cite: 11, 14, 15, 16],
-- Universities (Registration, Grades) [cite: 18], Airlines (Reservations)[cite: 20],
-- Telecommunication (Call Records, Billing) [cite: 21], and Web Services (Online Retailers, Navigation)[cite: 22, 23, 26].

-- THEME 2: PURPOSE OF DATABASE SYSTEMS: SOLVING FILE SYSTEM PROBLEMS [cite: 27]
-- Database systems address issues from older file systems:
-- 1. Data redundancy and inconsistency [cite: 29]
-- 2. Difficulty in accessing data [cite: 30]
-- 3. Data isolation (multiple files and formats) [cite: 32, 33]
-- 4. Integrity problems (constraints "buried" in program code) [cite: 35, 38]
-- 5. Atomicity of updates (partial updates on failure) [cite: 42, 45]
-- 6. Concurrent access by multiple users (inconsistencies) [cite: 48, 52]
-- 7. Security problems (hard to provide fine-grained access) [cite: 54, 55]

------------------------------------------------
-- I. DATABASE LANGUAGES: DDL (Data Definition Language)
-- DDL is the specification notation for defining the database schema (structure)[cite: 123, 132].
-- DDL solves "Integrity Problems" by making constraints explicit, and solves
-- "Data Redundancy" by defining a consistent, centralized schema.
------------------------------------------------

-- Example 1: Creating the primary entity (Instructor) for a University Database [cite: 57, 124]
-- ID is the PRIMARY KEY (a critical integrity constraint)[cite: 134].
CREATE TABLE instructor (
    ID          char(5)       PRIMARY KEY,              -- Solves Integrity: Unique ID constraint [cite: 134]
    name        varchar(20),
    dept_name   varchar(20),
    salary      numeric(8,2)  CHECK (salary >= 0)       -- Solves Integrity: Explicit constraint (e.g., salary > 0) [cite: 37, 38]
);

-- Example 2: Creating a second table for related data (Department)
CREATE TABLE department (
    dept_name   varchar(20)   PRIMARY KEY,
    building    varchar(15),
    budget      numeric(12,2)
);

-- DDL Compiler generates table templates in a Data Dictionary, which stores metadata (data about data)[cite: 130, 131, 200].
-- DDL also specifies Authorization (Who can access what)[cite: 135, 136].


------------------------------------------------
-- II. DATABASE LANGUAGES: DML (Data Manipulation Language)
-- DML (or Query Language) is for accessing and updating data[cite: 142, 143].
-- SQL is a nonprocedural (declarative) DML: specify WHAT is needed, not HOW[cite: 147, 149, 162].
------------------------------------------------

-- DML: INSERT (Updating the data)
INSERT INTO department (dept_name, building, budget) VALUES ('Comp. Sci.', 'Taylor', 100000);
INSERT INTO department (dept_name, building, budget) VALUES ('Physics', 'Watson', 90000);
INSERT INTO instructor (ID, name, dept_name, salary) VALUES ('10101', 'Srinivasan', 'Comp. Sci.', 65000);
INSERT INTO instructor (ID, name, dept_name, salary) VALUES ('45565', 'Katz', 'Comp. Sci.', 75000);
INSERT INTO instructor (ID, name, dept_name, salary) VALUES ('22222', 'Einstein', 'Physics', 95000);

-- DML: SELECT (Query) - Information Retrieval [cite: 150, 151]
-- Example: Retrieve names of all instructors in the 'Comp. Sci.' department [cite: 163]
SELECT name
FROM instructor
WHERE dept_name = 'Comp. Sci.';

------------------------------------------------
-- III. VIEW OF DATA (Data Abstraction) & SECURITY
-- Provides an abstract view of the data, hiding the complexity[cite: 70, 74].
-- Levels: Physical, Logical, and View[cite: 101].
------------------------------------------------

-- View Level: Hides details and information (like salary) for security purposes[cite: 108].
CREATE VIEW instructor_public_view AS
SELECT ID, name, dept_name
FROM instructor;

-- Querying the View: The user doesn't see the salary column.
SELECT *
FROM instructor_public_view;


------------------------------------------------
-- IV. TRANSACTION MANAGEMENT (TCL - Transaction Control Language)
-- A transaction is a collection of operations performing a single logical function[cite: 213].
-- The Transaction Manager ensures database consistency despite failures[cite: 214].
-- It enforces Atomicity: all steps complete, or none do[cite: 42, 47].
------------------------------------------------

-- Setup an accounts table for the transaction example
CREATE TABLE accounts (
    name    varchar(20) PRIMARY KEY,
    balance numeric(10,2)
);
INSERT INTO accounts (name, balance) VALUES ('Alice', 500.00);
INSERT INTO accounts (name, balance) VALUES ('Bob', 100.00);

-- Example: Transfer of funds (must either complete or not happen at all) [cite: 46, 47]
-- This also demonstrates controlling concurrent access issues[cite: 48].
BEGIN;

-- 1. Debit Alice's account
UPDATE accounts
SET balance = balance - 100.00
WHERE name = 'Alice';

-- 2. Credit Bob's account
UPDATE accounts
SET balance = balance + 100.00
WHERE name = 'Bob';

-- Finalize the atomic update (makes changes permanent)
COMMIT;

-- Use ROLLBACK to undo all changes since BEGIN if a failure or inconsistency is detected[cite: 219].
-- Example of ROLLBACK syntax (if the transfer failed):
-- ROLLBACK;


------------------------------------------------
-- V. DATABASE DESIGN & DATABASE ENGINE
------------------------------------------------

-- Database Design involves:
-- 1. Logical Design (Schema structure, attributes) [cite: 177]
-- 2. Physical Design (Physical layout) [cite: 180]
-- Data Models (e.g., Relational, E-R, Object-based) are conceptual tools for design[cite: 71, 72, 81].

-- The Database Engine functional components include[cite: 183]:
-- 1. Storage Manager (interfaces with OS, manages data files, indices, buffer, etc.) [cite: 187, 190, 192, 199, 201]
-- 2. Query Processor (DDL interpreter, DML compiler, Query evaluation engine) [cite: 185, 203, 205]
-- 3. Transaction Management Component (ensures consistency and controls concurrency) [cite: 186, 214, 215]

------------------------------------------------
-- VI. TOOLKIT FOR THIS COURSE
------------------------------------------------

-- DBMS (Database Management Systems) Examples[cite: 220]:
-- MySQL [cite: 221], MS SQL Server [cite: 222], Oracle DB [cite: 223], DB2 [cite: 224], PostgreSQL [cite: 225]

-- Primary DBMS for the Course: PostgreSQL [cite: 226]
-- Reasons: Enterprise-class, Open source (large community), Fast, Cross platform, Supports various languages/data types[cite: 227, 229, 230, 231, 232, 233].

-- Management Tools[cite: 235]:
-- pgAdmin [cite: 239], psql [cite: 236], DataGrip [cite: 237], phpPgAdmin [cite: 238]