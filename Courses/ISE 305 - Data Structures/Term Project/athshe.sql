-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 25, 2019 at 04:27 PM
-- Server version: 10.1.38-MariaDB
-- PHP Version: 7.3.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `athshe`
--

-- --------------------------------------------------------

--
-- Table structure for table `book`
--

CREATE TABLE `book` (
  `ID` int(11) NOT NULL,
  `name` varchar(40) NOT NULL,
  `year` int(4) DEFAULT NULL,
  `vote` int(11) NOT NULL DEFAULT '0',
  `rate` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=ascii;

--
-- Dumping data for table `book`
--

INSERT INTO `book` (`ID`, `name`, `year`, `vote`, `rate`) VALUES
(1, 'Suc ve Ceza', 1866, 2, 9.5),
(2, 'Gurur ve Onyargi', 1815, 1, 10),
(3, 'Kendine Ait Bir Oda', 1929, 0, 0),
(4, 'Emma', 1815, 0, 0),
(5, 'Notes From The Underground', 1864, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `fullbook`
--

CREATE TABLE `fullbook` (
  `bookID` int(11) NOT NULL,
  `writerID` int(11) NOT NULL,
  `publisherID` int(11) NOT NULL,
  `translatorID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=ascii;

--
-- Dumping data for table `fullbook`
--

INSERT INTO `fullbook` (`bookID`, `writerID`, `publisherID`, `translatorID`) VALUES
(1, 1, 1, 4),
(2, 3, 2, 5),
(3, 2, 3, 6),
(4, 3, 1, 7),
(5, 1, 4, 0);

-- --------------------------------------------------------

--
-- Table structure for table `person`
--

CREATE TABLE `person` (
  `ID` int(11) NOT NULL,
  `name` varchar(60) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=ascii;

--
-- Dumping data for table `person`
--

INSERT INTO `person` (`ID`, `name`) VALUES
(0, ''),
(1, 'Fyodor Mihaylovic Dostoyevski'),
(2, 'Virginia Woolf'),
(3, 'Jane Austen'),
(4, 'Sabri Gurses'),
(5, 'Hamdi Koc'),
(6, 'Sugra Oncu'),
(7, 'Nihal Yeginobali');

-- --------------------------------------------------------

--
-- Table structure for table `publisher`
--

CREATE TABLE `publisher` (
  `ID` int(11) NOT NULL,
  `name` varchar(60) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=ascii;

--
-- Dumping data for table `publisher`
--

INSERT INTO `publisher` (`ID`, `name`) VALUES
(1, 'Can Yayinlari'),
(2, 'Turkiye Is Bankasi Kultur Yayinlari'),
(3, 'Iletisim Yayincilik'),
(4, 'Tutku Yayinevi');

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `ID` int(11) NOT NULL,
  `name` varchar(40) NOT NULL,
  `email` varchar(60) NOT NULL,
  `password` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=ascii;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`ID`, `name`, `email`, `password`) VALUES
(0, 'admin', 'a', '*'),
(1, 'Hilal', 'hilal@mail.com', '12345yu.'),
(2, 'Selin', 'selin@mail.com', 'lokum'),
(3, 'Sinem', 'sinem@mail.com', 'salla1'),
(4, 'Elif', 'elif@mail.com', 'eelif'),
(5, 'gkc91', 'asd@asd.com', 'gkc93');

-- --------------------------------------------------------

--
-- Table structure for table `userbook`
--

CREATE TABLE `userbook` (
  `bookID` int(11) NOT NULL,
  `userID` int(11) NOT NULL,
  `type` varchar(30) NOT NULL,
  `rate` int(11) DEFAULT '-1',
  `comment` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=ascii;

--
-- Dumping data for table `userbook`
--

INSERT INTO `userbook` (`bookID`, `userID`, `type`, `rate`, `comment`) VALUES
(1, 1, 'Already Read', 9, NULL),
(1, 2, 'Want to Read', -1, ''),
(3, 3, 'Want to Read', -1, NULL),
(2, 3, 'Already Read', 10, 'great ^ ^'),
(2, 2, 'Now Reading', -1, ''),
(4, 3, 'Already Read', 10, ''),
(1, 3, 'Already Read', 10, '');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `book`
--
ALTER TABLE `book`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `name` (`name`);

--
-- Indexes for table `fullbook`
--
ALTER TABLE `fullbook`
  ADD KEY `bookID` (`bookID`),
  ADD KEY `writerID` (`writerID`),
  ADD KEY `publisherID` (`publisherID`),
  ADD KEY `translatorID` (`translatorID`);

--
-- Indexes for table `person`
--
ALTER TABLE `person`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `ID` (`ID`);

--
-- Indexes for table `publisher`
--
ALTER TABLE `publisher`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `ID` (`ID`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `unique` (`name`),
  ADD UNIQUE KEY `unique2` (`email`),
  ADD KEY `name` (`name`),
  ADD KEY `ID` (`ID`);

--
-- Indexes for table `userbook`
--
ALTER TABLE `userbook`
  ADD KEY `userID` (`userID`),
  ADD KEY `bookID` (`bookID`) USING BTREE;

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `book`
--
ALTER TABLE `book`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `person`
--
ALTER TABLE `person`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `publisher`
--
ALTER TABLE `publisher`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `fullbook`
--
ALTER TABLE `fullbook`
  ADD CONSTRAINT `fullbook` FOREIGN KEY (`bookID`) REFERENCES `book` (`ID`),
  ADD CONSTRAINT `fullbook_ibfk_1` FOREIGN KEY (`publisherID`) REFERENCES `publisher` (`ID`),
  ADD CONSTRAINT `fullbook_ibfk_2` FOREIGN KEY (`translatorID`) REFERENCES `person` (`ID`),
  ADD CONSTRAINT `fullbook_ibfk_3` FOREIGN KEY (`writerID`) REFERENCES `person` (`ID`);

--
-- Constraints for table `userbook`
--
ALTER TABLE `userbook`
  ADD CONSTRAINT `userbook` FOREIGN KEY (`bookID`) REFERENCES `book` (`ID`),
  ADD CONSTRAINT `userbook_ibfk_1` FOREIGN KEY (`userID`) REFERENCES `user` (`ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
