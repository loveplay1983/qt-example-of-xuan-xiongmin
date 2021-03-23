# labScan project database definition

* wardScan

  ```mariaDb
  CREATE TABLE `wardScan` (
    `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `label` int(10) unsigned NOT NULL,
    `operator` varchar(10) NOT NULL,
    `time` text NOT NULL,
    `scanMark` tinyint(1) NOT NULL,
    PRIMARY KEY (`id`)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4
  ```

* labScan

  ```mariaDb
  CREATE TABLE `labScan` (
    `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `label` int(10) unsigned NOT NULL,
    `operator` varchar(10) NOT NULL,
    `time` text NOT NULL,
    `scanMark` tinyint(1) NOT NULL,
    PRIMARY KEY (`id`)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4
  ```

  

* login

  ```mariaDb
  CREATE TABLE `login` (
    `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `userID` int(10) unsigned NOT NULL,
    `userName` varchar(20) NOT NULL,
    `passwd` varchar(20) NOT NULL,
    `logMark` tinyint(1) DEFAULT NULL,
    PRIMARY KEY (`id`)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4
  ```

* login_stats

  ```mariaDb
  CREATE TABLE `loginStats` (
    `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `loginId` int(10) unsigned DEFAULT NULL,
    `loginMark` tinyint(1) DEFAULT NULL,
    `loginHost` varchar(20) DEFAULT NULL,
    PRIMARY KEY (`id`),
    KEY `fk_login_tbl_id` (`loginId`),
    CONSTRAINT `fk_login_tbl_id` FOREIGN KEY (`loginId`) REFERENCES `login` (`id`)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4
  ```

  