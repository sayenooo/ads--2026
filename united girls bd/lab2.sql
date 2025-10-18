-- delete?
DROP TABLE IF EXISTS ATTENDANCE CASCADE;
DROP TABLE IF EXISTS ACTIVITY CASCADE;
DROP TABLE IF EXISTS EVENT CASCADE;
DROP TABLE IF EXISTS DISCUSSION CASCADE;
DROP TABLE IF EXISTS MEMBER CASCADE;

CREATE TABLE MEMBER (
    memberID SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    phoneNumber VARCHAR(20),
    dateJoined DATE NOT NULL DEFAULT CURRENT_DATE,
    role VARCHAR(50) DEFAULT 'User',
    isActive BOOLEAN DEFAULT TRUE
);

CREATE TABLE DISCUSSION (
    discussionID SERIAL PRIMARY KEY,
    title VARCHAR(200) NOT NULL,
    content TEXT,
    createdDate DATE NOT NULL DEFAULT CURRENT_DATE,
    memberID INT REFERENCES MEMBER(memberID) ON DELETE CASCADE
);

CREATE TABLE EVENT (
    eventID SERIAL PRIMARY KEY,
    title VARCHAR(200) NOT NULL,
    description TEXT,
    date DATE NOT NULL,
    location VARCHAR(200),
    organizerID INT REFERENCES MEMBER(memberID) ON DELETE SET NULL
);

CREATE TABLE ACTIVITY (
    activityID SERIAL PRIMARY KEY,
    title VARCHAR(200) NOT NULL,
    description TEXT,
    activityDate DATE NOT NULL DEFAULT CURRENT_DATE,
    eventID INT REFERENCES EVENT(eventID) ON DELETE CASCADE
);

CREATE TABLE ATTENDANCE (
    attendanceID SERIAL PRIMARY KEY,
    memberID INT REFERENCES MEMBER(memberID) ON DELETE CASCADE,
    eventID INT REFERENCES EVENT(eventID) ON DELETE CASCADE,
    status VARCHAR(20) DEFAULT 'Registered',
    UNIQUE(memberID, eventID) -- один участник не может дважды зарегистрироваться на одно событие
);

--insert
INSERT INTO MEMBER (name, email, phoneNumber, dateJoined, role, isActive) VALUES
('Alice', 'alice@mail.com', '+77001111111', '2020-01-01', 'Admin', TRUE),
('Bob', 'bob@mail.com', '+77002222222', '2020-01-05', 'User', TRUE),
('Charlie', 'charlie@mail.com', '+77003333333', '2020-02-01', 'Moderator', FALSE),
('Diana', 'diana@mail.com', '+77004444444', '2020-03-10', 'User', TRUE),
('Eric', 'eric@mail.com', '+77005555555', '2020-04-15', 'User', TRUE),
('Fiona', 'fiona@mail.com', '+77006666666', '2020-05-20', 'Admin', TRUE),
('George', 'george@mail.com', '+77007777777', '2020-06-25', 'User', FALSE);

INSERT INTO DISCUSSION (title, content, memberID) VALUES
('First discussion', 'Hello everyone!', 1),
('Ideas for events', 'What events should we plan?', 2),
('Activity feedback', 'Share your thoughts about activities.', 3),
('Future plans', 'What should we improve?', 4),
('Tech talk', 'Discussing new tech.', 5),
('Social meetup', 'Plan a social event.', 6),
('Music festival', 'Who likes concerts?', 7);

INSERT INTO EVENT (title, description, date, location, organizerID) VALUES
('Hackathon', 'Coding event for 24 hours', '2022-10-01', 'KBTU Hall', 1),
('Music Night', 'Live music by students', '2022-11-15', 'Auditorium', 2),
('Sports Day', 'Football and basketball tournaments', '2022-12-01', 'Sports Complex', 3),
('Book Fair', 'Book exchange and sales', '2022-12-20', 'Library', 4),
('Science Fair', 'Showcase student projects', '2023-01-10', 'Lab 101', 5),
('Theatre Play', 'Drama performance by students', '2023-02-01', 'Main Stage', 6),
('Charity Run', 'Run for a cause', '2023-03-01', 'City Park', 7);

INSERT INTO ACTIVITY (title, description, eventID) VALUES
('Team Registration', 'Teams register for hackathon', 1),
('Opening Ceremony', 'Hackathon starts officially', 1),
('Live Band', 'Music concert opening', 2),
('Football Match', 'Quarter finals', 3),
('Book Signing', 'Local authors sign books', 4),
('Robotics Demo', 'Robots made by students', 5),
('Rehearsal', 'Preparation for theatre play', 6);

INSERT INTO ATTENDANCE (memberID, eventID, status) VALUES
(1, 1, 'Attended'),
(2, 1, 'Registered'),
(3, 2, 'Attended'),
(4, 3, 'Registered'),
(5, 4, 'Attended'),
(6, 5, 'Registered'),
(7, 6, 'Attended');






