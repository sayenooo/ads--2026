-- additional table
CREATE TABLE MEMBER_SKILLS (
    skillID SERIAL PRIMARY KEY,
    memberID INT REFERENCES MEMBER(memberID) 
        ON DELETE CASCADE 
        ON UPDATE CASCADE,
    skills TEXT[] CHECK (array_length(skills, 1) <= 5)
);


INSERT INTO MEMBER_SKILLS (memberID, skills) VALUES
(1, ARRAY['SQL', 'Leadership', 'Management']),
(2, ARRAY['Guitar', 'Singing']),
(3, ARRAY['Python', 'C++', 'Algorithms']),
(4, ARRAY['Football', 'Basketball']),
(5, ARRAY['Robotics', 'Science']),
(6, ARRAY['Acting', 'Drama']),
(7, ARRAY['Running', 'Charity', 'Organization']);

SELECT
    m.memberID,
    INITCAP(m.name) AS formatted_name,                                   -- 1st letter-capital
    UPPER(SUBSTRING(m.email FROM 1 FOR 5)) AS email_prefix,              -- 1st 5letters-capital
    TO_CHAR(m.dateJoined, 'YYYY/MM/DD') AS formatted_date,               -- data type formatting
    ROUND((RANDOM() * 100)::numeric, 2) AS random_score,                 -- random function + math function (ROUND)
    ABS(EXTRACT(YEAR FROM AGE(CURRENT_DATE, m.dateJoined))) AS years_in_group,  -- math func (ABS)
    CEIL(AVG(LENGTH(d.content)) OVER()) AS avg_post_length,              -- math func (CEIL)
    POWER(LENGTH(m.name), 2) AS name_power,                              -- math func (POWER)
    MOD(m.memberID, 3) AS mod_group,                                     -- math func (MOD)
    
    CASE                                                                 -- case statement
        WHEN m.isActive AND m.role = 'Admin' THEN 'Active Admin'
        WHEN NOT m.isActive THEN 'Inactive Member'
        ELSE 'Regular User'
    END AS member_status,
    
    NULLIF(m.phoneNumber, '+77000000000') AS checked_phone,              -- NULLIF usage
    s.skills,                                                            -- array column
    s.skills @> ARRAY['SQL'] AS has_sql,                                 -- array operator 1 (@> contains)
    ARRAY_LENGTH(s.skills, 1) AS num_of_skills,                          -- array function 1
    ARRAY_TO_STRING(s.skills, ', ') AS skills_list,                      -- array function 2
    CARDINALITY(s.skills) AS skill_count,                                -- array function 3
    
    (SELECT COUNT(*) 
     FROM ATTENDANCE a 
     WHERE a.memberID = m.memberID 
     AND a.status = 'Attended') AS attended_events                       -- subquery
     
FROM MEMBER m
LEFT JOIN MEMBER_SKILLS s ON m.memberID = s.memberID
LEFT JOIN DISCUSSION d ON d.memberID = m.memberID                       -- добавлено, чтобы работала AVG(LENGTH(d.content))
WHERE (m.isActive = TRUE AND m.role <> 'Moderator')                     -- logical + comparison operators
   OR m.dateJoined < '2020-04-01'
ORDER BY random_score DESC;


-- exp of check
ALTER TABLE EVENT
ADD CONSTRAINT check_event_date CHECK (date >= '2020-01-01');

-- exp foreign key
CREATE TABLE EVENT_LOG (
    logID SERIAL PRIMARY KEY,
    eventID INT REFERENCES EVENT(eventID)
        ON DELETE RESTRICT
        ON UPDATE CASCADE,
    organizerID INT REFERENCES MEMBER(memberID)
        ON DELETE SET DEFAULT
        ON UPDATE NO ACTION,
    notes TEXT DEFAULT 'No notes'
);





