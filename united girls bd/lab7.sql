CREATE INDEX idx_member_age ON MEMBER(age);
SELECT * FROM MEMBER WHERE age = 18;

ALTER TABLE DISCUSSION ADD COLUMN content_tsv tsvector;
UPDATE DISCUSSION SET content_tsv = to_tsvector(content);
CREATE INDEX idx_discussion_content_gin ON DISCUSSION USING GIN(content_tsv);
SELECT * FROM DISCUSSION WHERE content_tsv @@ to_tsquery('events');

CREATE INDEX idx_member_email_hash ON MEMBER USING HASH(email);
SELECT * FROM MEMBER WHERE email = 'alice@mail.com';

CREATE INDEX idx_event_date_brin ON EVENT USING BRIN(date);
SELECT * FROM EVENT WHERE date BETWEEN '2022-12-01' AND '2023-01-31';

ALTER TABLE EVENT ADD COLUMN location_point POINT;
UPDATE EVENT SET location_point = POINT(RANDOM()*100, RANDOM()*100);
CREATE INDEX idx_event_location_gist ON EVENT USING GiST(location_point);
SELECT * FROM EVENT WHERE location_point <@ BOX(POINT(0,0), POINT(50,50));

SELECT indexname, indexdef FROM pg_indexes WHERE schemaname='public';


