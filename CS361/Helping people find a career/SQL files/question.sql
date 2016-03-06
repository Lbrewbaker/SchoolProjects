-- phpMyAdmin SQL Dump
-- version 2.11.9.4
-- http://www.phpmyadmin.net
--
-- Host: oniddb
-- Generation Time: Mar 01, 2016 at 04:59 PM
-- Server version: 5.5.47
-- PHP Version: 5.2.6-1+lenny16

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

--
-- Database: `walterer-db`
--

-- --------------------------------------------------------

--
-- Table structure for table `question`
--

CREATE TABLE IF NOT EXISTS `question` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `detail` varchar(8000) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=12 ;

--
-- Dumping data for table `question`
--

INSERT INTO `question` (`id`, `detail`) VALUES
(1, 'Do you enjoy working in teams?'),
(2, 'Would you say that you have an interest in technology?'),
(3, 'Do you have a passion for helping people?'),
(4, 'At work, do you prefer to work in solitude?'),
(5, 'Are you interested in financial markets?'),
(6, 'Do you enjoy teaching groups of people?'),
(7, 'Do you enjoy math?'),
(9, 'Are you interested in why people make certain buying decisions?'),
(10, 'Does the idea of raising money for large entities interest you?'),
(11, 'Would you be interested in identifying and developing talented people?');