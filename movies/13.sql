SELECT p2.name
FROM people p2
WHERE p2.id IN
(SELECT id AS idp
FROM people p1
JOIN stars s2 ON s2.person_id = p1.id
JOIN
(SELECT m1.id AS idm
FROM movies m1
JOIN stars s1 ON s1.movie_id = m1.id
JOIN
(SELECT DISTINCT p0.id AS i0
FROM people p0
JOIN stars s0 ON p0.id = s0.person_id
JOIN movies m0 ON m0.id = s0.movie_id
WHERE p0.name = 'Kevin Bacon'
AND p0.birth = 1958)
AS table4i0 ON s1.person_id = table4i0.i0)
AS table4m1id ON s2.movie_id = table4m1id.idm)
EXCEPT
SELECT p2.name
FROM people p2
WHERE p2.name = 'Kevin Bacon';
