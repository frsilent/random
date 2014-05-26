/* Drop existing Tables */
DROP TABLE person;
DROP TABLE pet;
DROP TABLE person_pet;
/* Setup DB Scheme */
CREATE TABLE person (
	id INTEGER PRIMARY KEY,
	first_name TEXT,
	last_name TEXT,
	age INTEGER
);
CREATE TABLE pet (
	id INTEGER PRIMARY KEY,
	name TEXT,
	breed TEXT,
	age INTEGER,
	dead INTEGER
);
CREATE TABLE person_pet (
	person_id INTEGER,
	pet_id INTEGER
);
/* Add some data */
INSERT INTO person (id, first_name, last_name, age)
	VALUES (0, "Zed", "Shaw", 37);
INSERT INTO pet (id, name, breed, age, dead)
	VALUES (0, "Fluffy", "Unicorn", 1000, 0);
INSERT INTO pet VALUES (1,"Gigantor", "Robot", 1, 1);
INSERT INTO person_pet (person_id, pet_id) VALUES (0,0);
INSERT INTO person_pet VALUES (0,1);
/* Some neato stuff but doesn't need to be run */ 
/*SELECT * FROM person;
SELECT name,age FROM pet;
SELECT name, age FROM pet WHERE dead = 0;
SELECT * FROM person WHERE first_name != "Zed";
SELECT pet.id,pet.name,pet.age,pet.dead
	FROM pet,person_pet,person
	WHERE
	pet.id = person_pet.pet_id AND
	person_pet.person_id = person.id AND
	person.first_name = "Zed";
*/
/* make sure there's dead pets */
--SELECT name, age FROM pet WHERE dead=1;
/* there is, the robot */
--DELETE FROM pet WHERE dead=1;
/* make sure robot's gone */
--SELECT * FROM pet;
/* add robot again */
--INSERT INTO pet VALUES(1,"Gigantor","Robot",1,0);
/* show robot */
--SELECT * FROM pet;

