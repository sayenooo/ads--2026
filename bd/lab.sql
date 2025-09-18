-- Создание таблицы MEMBER
CREATE TABLE Member (
    memberID SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    phoneNumber VARCHAR(20),
    dateJoined DATE DEFAULT CURRENT_DATE,
    role VARCHAR(50),
    isActive BOOLEAN DEFAULT TRUE
);

-- Таблица DISCUSSION
CREATE TABLE Discussion (
    discussionID SERIAL PRIMARY KEY,
    title VARCHAR(200) NOT NULL,
    content TEXT,
    createdDate TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    memberID INT,
    FOREIGN KEY (memberID) REFERENCES Member(memberID) ON DELETE SET NULL
);

-- Таблица EVENT
CREATE TABLE Event (
    eventID SERIAL PRIMARY KEY,
    title VARCHAR(200) NOT NULL,
    description TEXT,
    date TIMESTAMP NOT NULL,
    location VARCHAR(200),
    organizerID INT,
    FOREIGN KEY (organizerID) REFERENCES Member(memberID) ON DELETE CASCADE
);

-- Таблица ACTIVITY
CREATE TABLE Activity (
    activityID SERIAL PRIMARY KEY,
    title VARCHAR(200) NOT NULL,
    description TEXT,
    activityDate TIMESTAMP,
    eventID INT,
    FOREIGN KEY (eventID) REFERENCES Event(eventID) ON DELETE CASCADE
);
