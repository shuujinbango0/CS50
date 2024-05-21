SELECT title
FROM movies m0
JOIN stars s0 ON s0.movie_id = m0.id
JOIN stars s1 ON s1.movie_id = m0.id
JOIN people p0 ON s0.person_id = p0.id
JOIN people p1 ON s1.person_id = p1.id
WHERE p0.name = 'Jennifer Lawrence'
AND p1.name = 'Bradley Cooper';
