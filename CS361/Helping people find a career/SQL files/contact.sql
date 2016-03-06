-- phpMyAdmin SQL Dump
-- version 2.11.9.4
-- http://www.phpmyadmin.net
--
-- Host: oniddb
-- Generation Time: Mar 01, 2016 at 04:57 PM
-- Server version: 5.5.47
-- PHP Version: 5.2.6-1+lenny16

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

--
-- Database: `walterer-db`
--

-- --------------------------------------------------------

--
-- Table structure for table `contact`
--

CREATE TABLE IF NOT EXISTS `contact` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `firstname` varchar(255) NOT NULL,
  `lastname` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `age` int(11) NOT NULL,
  `zipcode` int(11) NOT NULL,
  `careerid` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `careerid` (`careerid`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=21 ;

--
-- Dumping data for table `contact`
--

INSERT INTO `contact` (`id`, `firstname`, `lastname`, `email`, `age`, `zipcode`, `careerid`) VALUES
(1, 'Eric ', 'Walters', 'walterer@oregonstate.edu', 25, 44102, 3),
(2, 'John ', 'Smith', 'jsmith@gmail.com', 43, 32039, 3),
(3, 'Joe', 'Matthews', 'joematthews@gmail.com', 50, 34202, 4),
(4, 'Tim', 'Strasik', 'tstrasik@yahoo.com', 30, 10012, 4),
(5, 'Jessica', 'Moss', 'jmoss@gmail.com', 35, 22789, 1),
(6, 'Kelly', 'McCabe', 'kmcc@yahoo.com', 48, 60614, 1),
(7, 'Mary', 'March', 'mmarch@gmail.com', 27, 11349, 2),
(8, 'Emily', 'Ross', 'eross@yahoo.com', 29, 22984, 2),
(9, 'Jim', 'Rosenberg', 'jrose@gmail.com', 49, 44512, 5),
(10, 'Donna ', 'Jones', 'djones@gmail.com', 30, 67904, 5),
(11, 'Michael', 'Randle', 'mrandle@yahoo.com', 40, 90210, 6),
(12, 'Michelle', 'Jesko', 'mjesko@gmail.com', 26, 78940, 6),
(13, 'Janice', 'Franklin', 'jfranklin@yahoo.com', 59, 55409, 7),
(14, 'Howard', 'Drummond', 'hdr@yahoo.com', 56, 40593, 7),
(15, 'Robin', 'Smith', 'rsmith@gmail.com', 34, 39475, 8),
(16, 'Benjamin', 'Jones', 'bjones@yahoo.com', 38, 89483, 8),
(17, 'Fred', 'Norris', 'fnorris@gmail.com', 63, 39589, 9),
(18, 'Lisa', 'Dunn', 'ldunn@yahoo.com', 56, 44154, 9),
(19, 'Ashley', 'Wigley', 'awigley@yahoo.com', 33, 98587, 10),
(20, 'Chuck', 'Allen', 'callen@gmail.com', 60, 66094, 10);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `contact`
--
ALTER TABLE `contact`
  ADD CONSTRAINT `contact_ibfk_1` FOREIGN KEY (`careerid`) REFERENCES `career` (`id`);