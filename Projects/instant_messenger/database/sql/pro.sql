-- MySQL dump 10.13  Distrib 5.1.33, for Win32 (ia32)
--
-- Host: localhost    Database: pro
-- ------------------------------------------------------
-- Server version	5.1.33-community

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `msgdtls`
--

DROP TABLE IF EXISTS `msgdtls`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `msgdtls` (
  `msgid` int(11) NOT NULL,
  `status` int(11) NOT NULL,
  `time` datetime NOT NULL,
  `senderid` int(11) NOT NULL,
  `sender` char(50) NOT NULL,
  `sendermail` char(50) NOT NULL,
  `recieverid` int(11) NOT NULL,
  `reciever` char(25) NOT NULL,
  `msg` blob,
  `recievermail` char(50) NOT NULL,
  `recieverdel` char(5) DEFAULT NULL,
  `senderdel` char(5) DEFAULT NULL,
  PRIMARY KEY (`msgid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `msgdtls`
--

LOCK TABLES `msgdtls` WRITE;
/*!40000 ALTER TABLE `msgdtls` DISABLE KEYS */;
INSERT INTO `msgdtls` VALUES (1,1,'2014-01-10 14:15:26',1,'Suraj','micro@programmer.net',2,'Suraj06','fsgfgsdtrstsret','xyz@abc.in','no','no'),(2,1,'2014-01-12 14:26:18',1,'Suraj','micro@programmer.net',6,'chanunegi','1236dfdsfhjsdfhsudfsdfhu6','chanunegi@kvucmail.in','no','no'),(3,0,'2014-01-14 15:16:05',8,'Naruto06','Naruto06@kvucmail.in',10,'The_Copying_Ninja','<message here>','The_Copying_Ninja@kvucmail.in','no','yes'),(4,0,'2014-01-14 15:27:37',8,'Naruto06','Naruto06@kvucmail.in',8,'Naruto06','ghtyst','Naruto06@kvucmail.in','no','no');
/*!40000 ALTER TABLE `msgdtls` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `userdtls`
--

DROP TABLE IF EXISTS `userdtls`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `userdtls` (
  `user_id` int(11) NOT NULL,
  `user_name` char(50) NOT NULL,
  `name` char(50) NOT NULL,
  `email` char(50) NOT NULL,
  `password` char(50) NOT NULL,
  PRIMARY KEY (`user_id`),
  UNIQUE KEY `user_name` (`user_name`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `userdtls`
--

LOCK TABLES `userdtls` WRITE;
/*!40000 ALTER TABLE `userdtls` DISABLE KEYS */;
INSERT INTO `userdtls` VALUES (0,'msgdtls','message','msgdtls@kvucmail.in','kvuc'),(1,'suraj_06','suraj negi','suraj_06@kvucmail.in','kvuc'),(2,'naruto06','naruto uzumaki','naruto06@kvucmail.in','kvuc');
/*!40000 ALTER TABLE `userdtls` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2014-01-19  8:15:09
