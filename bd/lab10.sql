CREATE TABLE Movies (
    movie_id SERIAL PRIMARY KEY,
    title VARCHAR(100),
    genre VARCHAR(50),
    price_per_day DECIMAL(10, 2),
    available_copies INT
);

CREATE TABLE Rentals (
    rental_id SERIAL PRIMARY KEY,
    movie_id INT REFERENCES Movies(movie_id),
    customer_id INT,
    rental_date DATE,
    quantity INT
);

CREATE TABLE Customers1 (
    customer_id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100)
);

INSERT INTO Movies (movie_id, title, genre, price_per_day, available_copies)
VALUES
(1, 'The Matrix', 'Sci-Fi', 5.00, 8),
(2, 'Titanic', 'Romance', 3.50, 12),
(3, 'Avengers: Endgame', 'Action', 6.00, 5);

INSERT INTO Rentals (rental_id, movie_id, customer_id, rental_date, quantity)
VALUES
(1, 1, 201, '2024-11-01', 2),
(2, 2, 202, '2024-11-03', 1),
(3, 3, 201, '2024-11-05', 3);


INSERT INTO Customers1 (customer_id, name, email)
VALUES
(201, 'Alice Johnson', 'alice.j@example.com'),
(202, 'Bob Smith', 'bob.smith@example.com');



BEGIN;


INSERT INTO Rentals (rental_id, movie_id, customer_id, rental_date, quantity)
VALUES (4, 1, 201, '2024-11-06', 2);


UPDATE Movies
SET available_copies = available_copies - 2
WHERE movie_id = 1;

COMMIT;


BEGIN;

DO $$
BEGIN

    IF (SELECT available_copies FROM Movies WHERE movie_id = 3) < 10 THEN
        RAISE EXCEPTION 'Not enough copies available';
    ELSE

        INSERT INTO Rentals (rental_id, movie_id, customer_id, rental_date, quantity)
        VALUES (5, 3, 202, '2024-11-06', 10);


        UPDATE Movies
        SET available_copies = available_copies - 10
        WHERE movie_id = 3;
    END IF;
END;
$$;

ROLLBACK;


BEGIN TRANSACTION ISOLATION LEVEL READ COMMITTED;


UPDATE Movies
SET price_per_day = 7.00
WHERE movie_id = 1;


BEGIN TRANSACTION ISOLATION LEVEL READ COMMITTED;


SELECT price_per_day FROM Movies WHERE movie_id = 1;


COMMIT;


SELECT price_per_day FROM Movies WHERE movie_id = 1;


COMMIT;


ROLLBACK;
BEGIN;


UPDATE Customers1
SET email = 'alice.new@example.com'
WHERE customer_id = 201;

COMMIT;


SELECT * FROM Customers1 WHERE customer_id = 201;










BEGIN;
DO $$
BEGIN
    IF (SELECT Movies.available_copies FROM Movies WHERE movies_id= 3 ) <10 THEN
        RAISE EXCEPTION 'Not enough copies';
    ELSE
        INSERT INTO Rentals(rental_id, movie_id, customer_id,quantity)
        VALUES(5,3,201,10 );

        UPDATE Movies
        SET available_copies= available_copies -10
        WHERE movie_id = 3;
    end if;
END $$;

ROLLBACK;












