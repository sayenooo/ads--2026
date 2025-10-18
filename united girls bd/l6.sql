

-- Constraints — это правила, которые обеспечивают целостность и корректность данных в таблице.
-- Они помогают предотвратить ошибки, дублирование, пропуски и нарушения логики данных.

---
 -- 1. TYPES OF CONSTRAINTS (Виды ограничений)

-- ✅ PRIMARY KEY
-- Уникально идентифицирует каждую строку в таблице.
-- Не допускает NULL и дублирующихся значений.

CREATE TABLE students (
student_id CHAR(5) PRIMARY KEY,  -- Уникальный идентификатор студента
full_name  VARCHAR(50),
age        INT
);

-- Альтернативный вариант (через отдельную строку)
CREATE TABLE students_alt (
student_id CHAR(5),
full_name  VARCHAR(50),
age        INT,
CONSTRAINT pk_students PRIMARY KEY (student_id)
);

---

-- 2. FOREIGN KEY

-- Создает связь между двумя таблицами: "родительской" и "дочерней".
-- Значение внешнего ключа должно существовать в связанной таблице.

CREATE TABLE courses (
course_id   CHAR(5) PRIMARY KEY,
course_name VARCHAR(50)
);

CREATE TABLE enrollment (
student_id  CHAR(5),
course_id   CHAR(5),
grade       NUMERIC(3,1),
CONSTRAINT fk_student FOREIGN KEY (student_id) REFERENCES students(student_id),
CONSTRAINT fk_course  FOREIGN KEY (course_id)  REFERENCES courses(course_id)
);

-- Если попробовать вставить данные, где student_id не существует в таблице students, произойдёт ошибка.

---

 -- 3. UNIQUE

-- Гарантирует уникальность значений в указанном столбце.
-- В отличие от PRIMARY KEY, UNIQUE допускает NULL (если не указано иначе).

CREATE TABLE users (
user_id  SERIAL PRIMARY KEY,
email    VARCHAR(100) UNIQUE,   -- Email не может повторяться
username VARCHAR(50) UNIQUE     -- Username тоже уникален
);

---

 -- 4. NOT NULL

-- Запрещает вставлять NULL в указанный столбец.

CREATE TABLE employees (
emp_id   SERIAL PRIMARY KEY,
emp_name VARCHAR(50) NOT NULL,   -- Имя обязательно
position VARCHAR(50),
salary   NUMERIC(8,2) NOT NULL   -- Зарплата обязательна
);

---

-- 5. CHECK

-- Ограничивает допустимые значения в столбце логическим условием.

CREATE TABLE products (
product_id SERIAL PRIMARY KEY,
name       VARCHAR(100),
price      NUMERIC(8,2) CHECK (price > 0),           -- Цена должна быть положительной
stock      INT CHECK (stock >= 0),                   -- Кол-во не может быть отрицательным
category   VARCHAR(30) CHECK (category IN ('food', 'drink', 'tech'))  -- Только определённые категории
);

---

 -- 6. DEFAULT

-- Задает значение по умолчанию, если при вставке оно не указано.

CREATE TABLE orders (
order_id   SERIAL PRIMARY KEY,
order_date DATE DEFAULT CURRENT_DATE,   -- По умолчанию — текущая дата
status     VARCHAR(20) DEFAULT 'Pending'
);

---

-- 7. COMPOSITE KEYS (Составные ключи)

-- Когда уникальность определяется комбинацией нескольких столбцов.

CREATE TABLE enrollment_composite (
student_id CHAR(5),
course_id  CHAR(5),
PRIMARY KEY (student_id, course_id)  -- Комбинация делает запись уникальной
);

---

-- 8. CONSTRAINT NAMING AND MANAGEMENT

-- Все ограничения можно именовать и управлять ими позже (удалять/добавлять).

ALTER TABLE products
ADD CONSTRAINT chk_price_positive CHECK (price > 0);

ALTER TABLE products
DROP CONSTRAINT chk_price_positive;

---

-- 9. EXAMPLE: FULL CONSTRAINT COMBINATION

CREATE TABLE bank_accounts (
account_id   SERIAL PRIMARY KEY,
customer_id  INT NOT NULL,
balance      NUMERIC(10,2) CHECK (balance >= 0) DEFAULT 0.00,
account_type VARCHAR(20) CHECK (account_type IN ('savings', 'checking')),
created_at   DATE DEFAULT CURRENT_DATE,
CONSTRAINT fk_customer FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
);

---

-- 10. CLEANUP

DROP TABLE IF EXISTS bank_accounts, products, orders, enrollment_composite, employees, users, enrollment, courses, students, students_alt;

---

-- SUMMARY

-- PRIMARY KEY → уникальный идентификатор строки, не NULL
-- FOREIGN KEY → связь между таблицами
-- UNIQUE → предотвращает дубликаты
-- NOT NULL → требует обязательное значение
-- CHECK → проверяет условие для значений
-- DEFAULT → задает значение по умолчанию
-- COMPOSITE KEY → уникальность по нескольким столбцам

