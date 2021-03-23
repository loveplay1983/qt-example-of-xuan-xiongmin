CREATE DATABASE labelScan;
SHOW DATABASES;
USE labelScan;
SHOW TABLES;

-- start sql for login 

CREATE TABLE login(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT,
    userId VARCHAR(20) NOT NULL,
    userName VARCHAR(20) NOT NULL,
    passwd VARCHAR(20) NOT NULL,
    loginFlag VARCHAR(2) NOT NULL,
    userComment VARCHAR(20) NOT NULL,
	PRIMARY KEY(id)
);

INSERT INTO login(userId, userName, passwd, loginFlag, userComment) VALUE('adm00', 'admin', '58511913', '0', '管理员');
INSERT INTO login(userId, userName, passwd, loginFlag, userComment) VALUE('w0500', 'ward05', 'ward05', '0', '全科医学病区');
INSERT INTO login(userId, userName, passwd, loginFlag, userComment) VALUE('w0600', 'ward06', 'ward06', '0', '风湿老年科');
INSERT INTO login(userId, userName, passwd, loginFlag, userComment) VALUE('w0700', 'ward07', 'ward07', '0', '神经内科三');
INSERT INTO login(userId, userName, passwd, loginFlag, userComment) VALUE('w0800', 'ward08', 'ward08', '0', '呼吸内科三');
INSERT INTO login(userId, userName, passwd, loginFlag, userComment) VALUE('lab00', 'lab00', 'lab00', '0', '病区送血');

SELECT * FROM login;
SELECT * FROM login WHERE userName = 'admin' AND passwd = '58511913';
UPDATE login SET loginFlag = '0' WHERE userName = 'admin' AND passwd='58511913';
UPDATE login SET loginFlag = '0' WHERE userName = 'ward05' AND passwd='ward05';
UPDATE login SET loginFlag = '0' WHERE userName = 'ward06' AND passwd='ward06';
UPDATE login SET loginFlag = '0' WHERE userName = 'ward07' AND passwd='ward07';
UPDATE login SET loginFlag = '0' WHERE userName = 'ward08' AND passwd='ward08';

DROP TABLE login;
-- DROP SCHEMA labelScan;

DELETE FROM passwd WHERE id = 1;

SHOW VARIABLES LIKE '%version_%';
-- end sql for login

-- start sql for labelscan wardside
CREATE TABLE wardScan(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT,
    label INT UNSIGNED NOT NULL UNIQUE,
    operator VARCHAR(20) NOT NULL,
    eventTime  TEXT NOT NULL,
    scanMark VARCHAR(2) NOT NULL,
	PRIMARY KEY(id)
);
DROP TABLE wardScan;


SHOW CREATE TABLE wardScan;
DESCRIBE wardScan;

SELECT * FROM wardScan;
DELETE FROM wardScan;

SELECT 
	id, label, operator, eventTime, 
	(CASE WHEN scanMark='1' THEN '已扫描' 
		WHEN scanMark='NULL' THEN '未扫描' END) AS scanMark
FROM wardScan WHERE label = '11'






-- end sql for labelscan wardside



-- start sql for labelscan labside
CREATE TABLE labScan(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT,
    label INT UNSIGNED NOT NULL UNIQUE,
    operator VARCHAR(20) NOT NULL,
    eventTime  TEXT NOT NULL,
    scanMark VARCHAR(2) NOT NULL,
	PRIMARY KEY(id)
);

DELETE  FROM labscan;


SELECT * FROM labScan
-- end sql for labelscan labside




-- start sql for mysql configuration
-- You are using safe update mode
SET SQL_SAFE_UPDATES=0;