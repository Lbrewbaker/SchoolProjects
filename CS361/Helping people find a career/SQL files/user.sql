-- phpMyAdmin SQL Dump
-- version 2.11.9.4
-- http://www.phpmyadmin.net
--
-- Host: oniddb
-- Generation Time: Mar 01, 2016 at 05:00 PM
-- Server version: 5.5.47
-- PHP Version: 5.2.6-1+lenny16

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

--
-- Database: `walterer-db`
--

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE IF NOT EXISTS `user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `firstname` varchar(255) NOT NULL,
  `lastname` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `age` int(11) NOT NULL,
  `zipcode` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- Dumping data for table `user`
--