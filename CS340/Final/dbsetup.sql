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
	moduletype varchar(255) NOT NULL,
	factionid int(11),
	PRIMARY KEY (deffmodid),
	FOREIGN KEY (factionid) REFERENCES factions(factionid)
	) ENGINE=InnoDB;

CREATE TABLE allegiances (
	allegianceid int(11) NOT NULL AUTO_INCREMENT,
	factionid int(11),
	allyfaction int(11),
	warfaction int(11),
	PRIMARY KEY (allegianceid),
	FOREIGN KEY (factionid) REFERENCES factions(factionid),
	FOREIGN KEY (allyfaction) REFERENCES factions(factionid),
	FOREIGN KEY (warfaction) REFERENCES factions(factionid),
	) ENGINE=InnoDB;



