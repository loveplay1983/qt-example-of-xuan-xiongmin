CREATE DATABASE simpleLogin;

SHOW DATABASES;

USE simpleLogin;

SHOW TABLES;

CREATE TABLE passwd(
	id INT unsigned NOT NULL auto_increment,
    userId varchar(20) NOT NULL,
    userName varchar(20) NOT NULL,
    passwd varchar(20) NOT NULL,
	primary key(id)
);

INSERT INTO passwd(userId, userName, passwd) VALUE('0000', 'admin', 'passwd');
INSERT INTO passwd(userId, userName, passwd) VALUE('0001', 'user', 'user');

SELECT * FROM passwd;

DROP TABLE passwd;

DELETE FROM passwd WHERE id = 1;


show variables like '%version_%';

-- drop schema simplelogin;