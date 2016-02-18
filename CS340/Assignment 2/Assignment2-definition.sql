-- For part one of this assignment you are to make a database with the following specifications and run the following queries
-- Table creation queries should immedatley follow the drop table queries, this is to facilitate testing on my end

DROP TABLE IF EXISTS `works_on`;
DROP TABLE IF EXISTS `project`;
DROP TABLE IF EXISTS `client`;
DROP TABLE IF EXISTS `employee`;



-- Create a table called client with the following properties:
-- id - an auto incrementing integer which is the primary key
-- first_name - a varchar with a maximum length of 255 characters, cannot be null
-- last_name - a varchar with a maximum length of 255 characters, cannot be null
-- dob - a date type (you can read about it here http://dev.mysql.com/doc/refman/5.0/en/datetime.html)
-- the combination of the first_name and last_name must be unique in this table

-- client table creation query replaces this text
CREATE TABLE client(
ID	 int AUTO_INCREMENT,
first_name varchar(255) NOT NULL,
last_name varchar(255) NOT NULL,
dob DATE,
PRIMARY KEY(ID)
) ENGINE = InnoDB;



-- Create a table called employee with the following properties:
-- id - an auto incrementing integer which is the primary key
-- first_name - a varchar of maximum length 255, cannot be null
-- last_name - a varchar of maximum length 255, cannot be null
-- dob - a date type 
-- date_joined - a date type 
-- the combination of the first_name and last_name must be unique in this table

-- employee table creation query replaces this text
CREATE TABLE employee(
ID	 int AUTO_INCREMENT,
first_name varchar(255) NOT NULL,
last_name varchar(255) NOT NULL,
dob DATE,
date_joined DATE,
PRIMARY KEY(ID)
) ENGINE = InnoDB;



-- Create a table called project with the following properties:
-- id - an auto incrementing integer which is the primary key
-- cid - an integer which is a foreign key reference to the client table
-- name - a varchar of maximum length 255, cannot be null
-- notes - a text type
-- the name of the project should be unique in this table

-- project table creation query replaces this text
CREATE TABLE project(
ID int AUTO_INCREMENT,
cid int,
name varchar(255) NOT NULL,
notes text,
PRIMARY KEY(ID),
FOREIGN KEY(cid) REFERENCES client(ID) 
) ENGINE = InnoDB;


-- Create a table called works_on with the following properties, this is a table representing a many-to-many relationship
-- between employees and projects:
-- eid - an integer which is a foreign key reference to employee
-- pid - an integer which is a foreign key reference to project
-- start_date - a date type 
-- The primary key is a combination of eid and pid

-- works_on table creation query replaces this text
CREATE TABLE works_on(
eid int,
pid int,
start_date DATETIME,
FOREIGN KEY(eid) REFERENCES employee(ID),
FOREIGN KEY(pid) REFERENCES project(ID),
PRIMARY KEY(eid, pid)
) ENGINE = InnoDB;


-- insert the following into the client table:

-- first_name: Sara
-- last_name: Smith
-- dob: 1/2/1970
INSERT INTO client(first_name, last_name, dob) 
VALUES('Sara', 'Smith', 19700102);

-- first_name: David
-- last_name: Atkins
-- dob: 11/18/1979
INSERT INTO client(first_name, last_name, dob) 
VALUES('David', 'Atkins', 19791118);

-- first_name: Daniel
-- last_name: Jensen
-- dob: 3/2/1985
INSERT INTO client(first_name, last_name, dob) 
VALUES('Daniel', 'Jensen', 19850302)



-- insert the following into the employee table:

-- first_name: Adam
-- last_name: Lowd
-- dob: 1/2/1975
-- date_joined: 1/1/2009
INSERT INTO employee(first_name, last_name, dob, date_joined)
VALUES('Adam', 'Lowd', 19750102, 20090101)

-- first_name: Michael
-- last_name: Fern
-- dob: 10/18/1980
-- date_joined: 6/5/2013
INSERT INTO employee(first_name, last_name, dob, date_joined)
VALUES('Michael', 'Fern', 19801018, 20130605);

-- first_name: Deena
-- last_name: Young
-- dob: 3/21/1984
-- date_joined: 11/10/2013
INSERT INTO employee(first_name, last_name, dob, date_joined)
VALUES('Deena', 'Young', 19840321, 20131110);



-- insert the following project instances into the project table (you should use a subquery to set up foriegn key referecnes, no hard coded numbers):

-- cid - reference to first_name: Sara last_name: Smith
-- name - Diamond
-- notes - Should be done by Jan 2017
INSERT INTO project (cid, name, notes)
VALUES((SELECT ID FROM client where first_name = 'Sara'AND last_name = 'Smith'), 'Diamond', "Should be done by Jan 2017");

-- cid - reference to first_name: David last_name: Atkins
-- name - Eclipse
-- notes - NULL
INSERT INTO project (cid, name)
VALUES((SELECT ID FROM client where first_name = 'David' AND last_name = 'Atkins'), 'Eclipse');

-- cid - reference to first_name: Daniel last_name: Jensen
-- name - Moon 
-- notes - NULL
INSERT INTO project (cid, name)
VALUES((SELECT ID FROM client where first_name = 'Daniel' AND last_name = 'Jensen'), 'Moon');



-- insert the following into the works_on table using subqueries to look up data as needed:

-- employee: Adam Lowd
-- project: Diamond
-- start_date: 1/1/2012
INSERT INTO works_on(eid, pid, start_date)
VALUES((SELECT ID from employee WHERE first_name = 'Adam' AND last_name = 'Lowd'), (SELECT ID from project WHERE name = 'Diamond'), 20120101);

-- employee: Michael Fern
-- project: Eclipse
-- start_date: 8/8/2013
INSERT INTO works_on(eid, pid, start_date)
VALUES((SELECT ID from employee WHERE first_name = 'Michael' AND last_name = 'Fern'), (SELECT ID from project WHERE name = 'Eclipse'), 20130808);


-- employee: Michael Fern
-- project: Moon
-- start_date: 9/11/2014
INSERT INTO works_on(eid, pid, start_date)
VALUES((SELECT ID from employee WHERE first_name = 'Michael' AND last_name = 'Fern'), (SELECT ID from project WHERE name = 'Moon'), 20141109);