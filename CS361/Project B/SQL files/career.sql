-- phpMyAdmin SQL Dump
-- version 2.11.9.4
-- http://www.phpmyadmin.net
--
-- Host: oniddb
-- Generation Time: Mar 01, 2016 at 05:26 PM
-- Server version: 5.5.47
-- PHP Version: 5.2.6-1+lenny16

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

--
-- Database: `walterer-db`
--

-- --------------------------------------------------------

--
-- Table structure for table `career`
--

CREATE TABLE IF NOT EXISTS `career` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `description` varchar(1000) NOT NULL,
  `medianpay` int(11) NOT NULL,
  `shortDescription` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=11 ;

--
-- Dumping data for table `career`
--

INSERT INTO `career` (`id`, `name`, `description`, `medianpay`, `shortDescription`) VALUES
(1, 'Software Engineer', 'A software engineer is a person who applies the principles of software engineering to the design, development, maintenance, testing, and evaluation of the software and systems that make computers or anything containing software work.', 65000, 'Develop and Design Software'),
(2, 'Registered Nurse', 'Registered nurses are employed in a wide variety of professional settings, often specializing in their field of practice. They may be responsible for supervising care delivered by other healthcare workers including enrolled nurses, licensed practical nurses, unlicensed assistive personnel, nursing students, and less-experienced RNs.', 63000, 'Serve Patients'' Needs'),
(3, 'Investment Banker', 'An investment banker is an individual who works in a financial institution that is in the business primarily of raising capital for companies, governments and other entities, or who works in a large bank''s division that is involved with these activities, often called an investment bank.', 75000, 'Raise Capital For Organizations'),
(4, 'Therapist', 'Most therapists working with patients dealing with anxiety and depression use a blend of cognitive and behavioral therapy', 42000, 'Treat Mental Health Issues'),
(5, 'Market Researcher', ' Market research analysts study our habits as consumers and use those observations to counsel companies on how to package, brand and sell products.', 60000, 'Study Markets And Trends'),
(6, 'Accountant', ' Whether working with individuals, corporations or nonprofits, accountants must be detail-oriented, organized and skilled with numbers.', 65000, 'Measure And Validate Financials'),
(7, 'HR Manager', 'Human resource management is a function in organizations designed to maximize employee performance in service of employers strategic objectives.', 61000, 'Oversee Human Capital Within Organizations'),
(8, 'Engineer', 'An engineer is a practitioner of engineering, concerned with applying scientific knowledge, mathematics, and ingenuity to develop solutions for technical, societal and commercial problems.', 66000, 'Use Science And Math To Solve Problems'),
(9, 'Teacher', 'A Teacher provides education to students. The role of teacher is often formal and ongoing, carried out at a school or other place of formal education.', 40000, 'Develop Students'' Education'),
(10, 'Financial Advisor', 'Financial advisors typically provide clients/customers with financial products and services, depending on the licenses they hold and the training they have had.', 67000, 'Counsel Clients On Finance');
