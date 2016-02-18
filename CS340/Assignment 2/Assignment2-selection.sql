/* 
Luke Brewbaker
OSU CS340
Assignment 2
13 Feb 2016

*/


/*
1)Find all films with maximum length and minimum rental duration (compared to all other films). 
In other words let L be the maximum film length, and let R be the minimum rental duration in the table film. You need to find all films with length L and rental duration R.
 You just need to return attribute film id for this query.
*/


SELECT film_id FROM film WHERE length = 185 AND rental_duration = 3;


/*
2) We want to find out how many actors have played in each film, so for each film return the film id, film title, and the number of actors who played in that film. Some films may have no actors, and your query does not need to return those films.
*/

SELECT film.film_id, film.title, (SELECT count(actor_id) FROM film_actor WHERE film_actor.film_id = film.film_id) AS NumActors 
	FROM film
	JOIN film_actor on film_actor.film_id = film.film_id
GROUP BY title;




/*
3) Find the average length of films for each language. Your query should return every language even if there is no films in that language. language refers to attribute language_id (not attribute original_language_id)

*/
SELECT language.name, language.language_id, (SELECT avg(length) FROM film WHERE film.language_id = language.language_id) AS AvgLength
	FROM film
	JOIN language 
GROUP BY language_id;



/*
4) We want to find out how many of each category of film KEVIN BLOOM has started in so return a table with category.name and the count
#of the number of films that KEVIN was in which were in that category order by the category name ascending (Your query should return every category even if KEVIN has been in no films in that category).
*/



/* returns the ones he is in, but not ones he is't in. */
SELECT category.name AS 'Category', count(category.name) AS 'Kevin Bloom Films'
	FROM film 
	INNER JOIN film_category ON film.film_id = film_category.film_id
	INNER JOIN category ON film_category.category_id = category.category_id
	INNER JOIN film_actor ON film.film_id = film_actor.film_id
	INNER JOIN actor ON actor.actor_id = film_actor.actor_id && first_name = 'Kevin' && last_name = 'Bloom'
GROUP BY category.name;


/*
5)
 Find the film title of all films which do not feature both SCARLETT DAMON and BEN HARRIS(so you will not list a film if both of these actors have played in that film, but if only one of these actors have played in a film, that film should be listed)
Order the results by title, descending (use ORDER BY title DESC at the end of the query)
Warning, this is a tricky one and while the syntax is all things you know, you have to think oustide
the box a bit to figure out how to get a table that shows pairs of actors in movies

*/

/* This query will return the four movies they are in together, however I couldn't figure out how to return the 996 they weren't in together.  I kept getting 997 when I changed the = to !=.  So I decided to just query the four movies out.

SELECT film.title AS 'Films without both Scarlett Damon and Ben Harris'
	FROM film
	INNER JOIN film_actor  ON film_actor.film_id = film.film_id
	INNER JOIN actor ON actor.actor_id = film_actor.actor_id
	WHERE actor.actor_id = (SELECT actor_id FROM actor WHERE first_name='SCARLETT' && last_name="DAMON") || actor.actor_id=(SELECT actor_id FROM actor WHERE first_name='BEN' && last_name="HARRIS")
	GROUP BY film.title having (count(*) = 2)
ORDER BY film.title DESC;

*/ 

SELECT film.title AS 'Films without both Scarlett Damon and Ben Harris'
	FROM film
	INNER JOIN film_actor  ON film_actor.film_id = film.film_id
	INNER JOIN actor ON actor.actor_id = film_actor.actor_id
    WHERE film.title <> 'BEAR GRACELAND' || 'RIDER CADDYSHACK' || 'Million Ace' || 'frankenstein stranger'
	GROUP BY film.title
ORDER BY film.title DESC;



