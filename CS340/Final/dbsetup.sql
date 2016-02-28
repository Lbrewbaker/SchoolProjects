CREATE TABLE factions (
	factionid int(11) NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	description text,
	PRIMARY KEY (factionid)
	) ENGINE=InnoDB;

CREATE TABLE offensivemods (
	offmodid int(11) NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	weapontype varchar(255) NOT NULL,
	description text,
	fact_id int(11),
	PRIMARY KEY (offmodid),
	FOREIGN KEY (fact_id) REFERENCES factions(factionid)
	) ENGINE=InnoDB;

CREATE TABLE defensivemods (
	deffmodid int(11) NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	deftype varchar(255) NOT NULL,
	description text,
	fact_id int(11),
	PRIMARY KEY (deffmodid),
	FOREIGN KEY (fact_id) REFERENCES factions(factionid)
	) ENGINE=InnoDB;

CREATE TABLE alliances (
	allianceid int(11) NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	description text,
	primary_faction int(11),
    secondary_faction int(11),
	PRIMARY KEY (allianceid),
	FOREIGN KEY (primary_faction) REFERENCES factions(factionid),
	FOREIGN KEY (secondary_faction) REFERENCES factions(factionid)
	) ENGINE=InnoDB;



