-- aliace
SELECT name AS Fname
FROM MEMBER;

-- between
SELECT e.eventID, e.title AS event_title, e.date
FROM EVENT e
WHERE e.date BETWEEN '2022-11-01' AND '2022-12-31'
ORDER BY e.date ASC;

-- in
SELECT m.name, m.email
FROM MEMBER m
WHERE m.memberID IN (
    SELECT a.memberID
    FROM ATTENDANCE a
    JOIN EVENT e ON e.eventID = a.eventID
    WHERE e.title LIKE '%Fair%'
    --% любой
    -- _1элемент
);

-- like
SELECT d.title, d.content
FROM DISCUSSION d
WHERE LOWER(d.title) LIKE '%tech%';

-- exists
SELECT m.name, m.role
FROM MEMBER m
WHERE EXISTS (
    SELECT 1
    FROM DISCUSSION d
    WHERE d.memberID = m.memberID
);

-- all
SELECT e.title, e.date
FROM EVENT e
WHERE e.date > ALL (
    SELECT e2.date
    FROM EVENT e2
    JOIN MEMBER m ON m.memberID = e2.organizerID
    WHERE m.name = 'Alice'
);

-- any
SELECT m.name, m.email
FROM MEMBER m
WHERE m.memberID = ANY (
    SELECT a.memberID
    FROM ATTENDANCE a
    JOIN EVENT e ON e.eventID = a.eventID
    WHERE e.date BETWEEN '2023-01-01' AND '2023-01-31'
);

-- not
SELECT m.name
FROM MEMBER m
WHERE m.memberID NOT IN (
    SELECT a.memberID
    FROM ATTENDANCE a
);

-- order
SELECT e.eventID, e.title, e.date
FROM EVENT e
ORDER BY e.date ASC, e.title DESC;
