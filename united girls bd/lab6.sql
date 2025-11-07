SELECT e.title AS event_title, COUNT(a.memberID) AS total_participants
FROM EVENT e
LEFT JOIN ATTENDANCE a ON e.eventID = a.eventID
GROUP BY e.title;

SELECT e.title AS event_title, m.name, a.status
FROM MEMBER m
RIGHT JOIN ATTENDANCE a ON m.memberID = a.memberID
RIGHT JOIN EVENT e ON a.eventID = e.eventID;

SELECT m.name, e.title AS event_title, a.status
FROM MEMBER m
INNER JOIN ATTENDANCE a ON m.memberID = a.memberID
INNER JOIN EVENT e ON a.eventID = e.eventID;

SELECT m.name, e.title AS event_title, a.status
FROM MEMBER m
FULL OUTER JOIN ATTENDANCE a ON m.memberID = a.memberID
FULL OUTER JOIN EVENT e ON a.eventID = e.eventID;

SELECT m.name, e.title AS event_title
FROM MEMBER m
CROSS JOIN EVENT e;

SELECT a.status, COUNT(a.attendanceID) AS total_status
FROM ATTENDANCE a
GROUP BY a.status;

SELECT m.name, COUNT(e.eventID) AS organized_events
FROM MEMBER m
LEFT JOIN EVENT e ON m.memberID = e.organizerID
GROUP BY m.name;

SELECT m.name, COUNT(e.eventID) AS organized_events
FROM MEMBER m
LEFT JOIN EVENT e ON m.memberID = e.organizerID
GROUP BY m.name
HAVING COUNT(e.eventID) >= 2;

SELECT e.title, AVG(m.AGE) AS avg_age_id
FROM EVENT e
JOIN MEMBER m ON e.eventID = m.memberID
GROUP BY e.title
HAVING AVG(m.AGE) > 3;

SELECT MIN(date) AS first_event, MAX(date) AS last_event
FROM EVENT;
