CREATE DATABASE LAB4;

CREATE TABLE Warehouses (
    code SERIAL PRIMARY KEY,
    location VARCHAR(255),
    capacity INTEGER
);

CREATE TABLE Packs (
    code varchar(4),
    contents VARCHAR(255),
    value DECIMAL(10, 2),
    warehouses INTEGER,
    FOREIGN KEY (warehouses) REFERENCES Warehouses(code)
);


INSERT INTO Warehouses(code, location, capacity) VALUES(1, 'Chicago', 3);
INSERT INTO Warehouses(code, location, capacity) VALUES(2, 'Rocks', 4);
INSERT INTO Warehouses(code, location, capacity) VALUES(3, 'New York', 7);
INSERT INTO Warehouses(code, location, capacity) VALUES(4, 'Los Angeles', 2);
INSERT INTO Warehouses(code, location, capacity) VALUES(5, 'San Francisko', 8);

INSERT INTO Packs(code, contents, value, warehouses) VALUES ('OMN7', 'Rocks', 180, 3);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('4H8P', 'Rocks', 250, 1);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('4RT3', 'Scissors', 190, 4);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('7G3H', 'Rocks', 200, 1);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('8JN6', 'Papers', 75, 1);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('8Y6U', 'Papers', 50, 3);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('9J6F', 'Papers', 175, 2);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('LL08', 'Rocks', 140, 4);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('P0H6', 'Scissors', 125, 1);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('P2T6', 'Scissors', 150, 2);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('TUSS', 'Papers', 90, 5);


SELECT * FROM Warehouses;


SELECT * FROM Packs WHERE value > 150;


SELECT DISTINCT contents FROM Packs;


SELECT warehouses AS warehouse_code, COUNT(*) AS number_of_packs
FROM Packs
GROUP BY warehouses;


SELECT warehouses AS warehouse_code, COUNT(*) AS number_of_packs
FROM Packs
GROUP BY warehouses
HAVING COUNT(*) > 2;


INSERT INTO Warehouses (location, capacity)
VALUES ('New York', 3);


INSERT INTO Packs (code, contents, value, warehouses)
VALUES ('H5RT', 'Papers', 200, 2);


UPDATE Packs
SET value = value * 0.85
WHERE code = (
    SELECT code
    FROM Packs
    ORDER BY value DESC
    OFFSET 2 LIMIT 1
);


DELETE FROM Packs
WHERE value < 150;


DELETE FROM Packs
USING Warehouses
WHERE Packs.warehouses = Warehouses.code
AND Warehouses.location = 'New York'
RETURNING *;





DELETE FROM Packs
USING Warehouses
WHERE Packs.warehouses = Warehouses.code AND location = 'New York'
RETURNING *;









