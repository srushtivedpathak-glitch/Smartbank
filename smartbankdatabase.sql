-- MySQL dump 10.13  Distrib 8.0.40, for Win64 (x86_64)
--
-- Host: localhost    Database: smartbank
-- ------------------------------------------------------
-- Server version	8.0.40

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `accounts`
--

DROP TABLE IF EXISTS `accounts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `accounts` (
  `account_no` bigint NOT NULL,
  `customer_id` int DEFAULT NULL,
  `Account_type` varchar(20) DEFAULT NULL,
  `balance` decimal(12,2) DEFAULT NULL,
  `opening_date` date DEFAULT NULL,
  `branch_id` int DEFAULT NULL,
  PRIMARY KEY (`account_no`),
  KEY `customer_id` (`customer_id`),
  KEY `fk_accounts_branch` (`branch_id`),
  CONSTRAINT `accounts_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`),
  CONSTRAINT `fk_accounts_branch` FOREIGN KEY (`branch_id`) REFERENCES `branches` (`branch_id`),
  CONSTRAINT `chk_savings_balance` CHECK (((`Account_type` <> _utf8mb4'Savings') or (`balance` >= 1000)))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `accounts`
--

LOCK TABLES `accounts` WRITE;
/*!40000 ALTER TABLE `accounts` DISABLE KEYS */;
INSERT INTO `accounts` VALUES (100001,101,'Savings',25000.00,'2025-06-15',1),(100002,101,'Current',50000.00,'2025-08-20',1),(100003,102,'Savings',15000.00,'2025-07-10',2),(100004,103,'Savings',32000.75,'2025-09-05',3),(100005,104,'Current',45000.00,'2025-10-12',2),(100006,105,'Savings',90000.00,'2025-12-01',1);
/*!40000 ALTER TABLE `accounts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `branches`
--

DROP TABLE IF EXISTS `branches`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `branches` (
  `branch_id` int NOT NULL,
  `branch_name` varchar(50) DEFAULT NULL,
  `city` varchar(50) DEFAULT NULL,
  `IFSC_code` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`branch_id`),
  UNIQUE KEY `IFSC_code` (`IFSC_code`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `branches`
--

LOCK TABLES `branches` WRITE;
/*!40000 ALTER TABLE `branches` DISABLE KEYS */;
INSERT INTO `branches` VALUES (1,'SMARTBANK Pune','PUNE','SMBK0001'),(2,'SMARTBANK Mumbai','MUMBAI','SMBK0002'),(3,'SMARTBANK Nashik','NASHIK','SMBK0003');
/*!40000 ALTER TABLE `branches` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `currentaccount`
--

DROP TABLE IF EXISTS `currentaccount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `currentaccount` (
  `account_no` bigint NOT NULL,
  `overdraft_limit` decimal(10,2) DEFAULT NULL,
  PRIMARY KEY (`account_no`),
  CONSTRAINT `currentaccount_ibfk_1` FOREIGN KEY (`account_no`) REFERENCES `accounts` (`account_no`),
  CONSTRAINT `chk_overdraft_limit` CHECK ((`overdraft_limit` >= 0))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `currentaccount`
--

LOCK TABLES `currentaccount` WRITE;
/*!40000 ALTER TABLE `currentaccount` DISABLE KEYS */;
INSERT INTO `currentaccount` VALUES (100002,50000.00),(100005,50000.00);
/*!40000 ALTER TABLE `currentaccount` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customer` (
  `customer_id` int NOT NULL,
  `Firstname` varchar(50) DEFAULT NULL,
  `Lastname` varchar(50) DEFAULT NULL,
  `Phoneno` varchar(15) DEFAULT NULL,
  `Email` varchar(50) DEFAULT NULL,
  `DOB` date DEFAULT NULL,
  `Address` varchar(255) DEFAULT NULL,
  `Gender` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`customer_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES (101,'SNEHA','KHALANE','9922560821','sk@gmail.com','2006-07-14','MOSHI','Female'),(102,'SRUSHTI','VEDPATHAK','7878978034','srush@gmail.com','2007-06-20','DHANORI','Female'),(103,'AKSHARA','SHELKE','8087698756','ash@gmail.com','2008-12-04','LOHGAON','Female'),(104,'SWARA','SHELAR','7890765890','sway@gmail.com','2009-06-24','ANANDNAGAR','Female'),(105,'SUSHANK','KHALANE','7730628451','sush@gmail.com','2001-10-06','MOSHI','male');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `loans`
--

DROP TABLE IF EXISTS `loans`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `loans` (
  `loan_id` int NOT NULL,
  `customer_id` int DEFAULT NULL,
  `loan_type` varchar(30) DEFAULT NULL,
  `loan_amount` decimal(12,2) DEFAULT NULL,
  `interest_rate` decimal(5,2) DEFAULT NULL,
  `loan_date` date DEFAULT NULL,
  `loan_status` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`loan_id`),
  KEY `customer_id` (`customer_id`),
  CONSTRAINT `loans_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`),
  CONSTRAINT `chk_loan_amount` CHECK ((`loan_amount` > 0)),
  CONSTRAINT `chk_loan_interest` CHECK ((`interest_rate` >= 0)),
  CONSTRAINT `chk_loan_status` CHECK ((`loan_status` in (_cp850'Active',_cp850'Pending')))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `loans`
--

LOCK TABLES `loans` WRITE;
/*!40000 ALTER TABLE `loans` DISABLE KEYS */;
INSERT INTO `loans` VALUES (2001,101,'home loan',500000.00,7.50,'2025-06-20','Active'),(2002,102,'educational loan',200000.00,6.50,'2025-07-15','Active'),(2003,103,'personal loan',100000.00,10.00,'2025-09-10','Active'),(2004,104,'car loan',350000.00,8.25,'2025-10-20','Pending'),(2005,105,'home loan',750000.00,7.25,'2025-12-05','Active');
/*!40000 ALTER TABLE `loans` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `savingaccount`
--

DROP TABLE IF EXISTS `savingaccount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `savingaccount` (
  `account_no` bigint NOT NULL,
  `Interest_Rate` decimal(5,2) DEFAULT NULL,
  PRIMARY KEY (`account_no`),
  CONSTRAINT `savingaccount_ibfk_1` FOREIGN KEY (`account_no`) REFERENCES `accounts` (`account_no`),
  CONSTRAINT `chk_interest_rate` CHECK ((`Interest_Rate` >= 0))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `savingaccount`
--

LOCK TABLES `savingaccount` WRITE;
/*!40000 ALTER TABLE `savingaccount` DISABLE KEYS */;
INSERT INTO `savingaccount` VALUES (100001,4.50),(100003,4.50),(100004,4.50),(100006,4.50);
/*!40000 ALTER TABLE `savingaccount` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transactions`
--

DROP TABLE IF EXISTS `transactions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transactions` (
  `transaction_id` int NOT NULL,
  `account_no` bigint NOT NULL,
  `transaction_type` varchar(20) DEFAULT NULL,
  `amount` decimal(12,2) DEFAULT NULL,
  `transaction_date` datetime DEFAULT NULL,
  PRIMARY KEY (`transaction_id`),
  KEY `account_no` (`account_no`),
  CONSTRAINT `transactions_ibfk_1` FOREIGN KEY (`account_no`) REFERENCES `accounts` (`account_no`),
  CONSTRAINT `chk_transaction_amount` CHECK ((`amount` > 0)),
  CONSTRAINT `chk_transaction_type` CHECK ((`transaction_type` in (_utf8mb4'Deposit',_utf8mb4'Withdrawal')))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transactions`
--

LOCK TABLES `transactions` WRITE;
/*!40000 ALTER TABLE `transactions` DISABLE KEYS */;
INSERT INTO `transactions` VALUES (1,100001,'Deposit',5000.00,'2025-12-05 10:30:00'),(2,100002,'Withdrawal',3000.00,'2025-12-06 12:15:00'),(3,100003,'Deposit',7500.00,'2025-12-07 09:45:00'),(4,100004,'Withdrawal',2500.00,'2025-12-08 14:20:00'),(5,100005,'Deposit',10000.00,'2025-12-10 11:00:00'),(6,100006,'Deposit',15000.00,'2025-12-12 16:30:00'),(7,100001,'Withdrawal',2000.00,'2025-12-15 13:10:00'),(8,100006,'Withdrawal',5000.00,'2025-12-18 10:00:00');
/*!40000 ALTER TABLE `transactions` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2026-09-06 20:52:52
