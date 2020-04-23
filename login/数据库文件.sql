/*
Navicat MySQL Data Transfer

Source Server         : mysql
Source Server Version : 50729
Source Host           : localhost:3306
Source Database       : qg

Target Server Type    : MYSQL
Target Server Version : 50729
File Encoding         : 65001

Date: 2020-04-23 23:07:18
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `id` int(100) NOT NULL AUTO_INCREMENT,
  `userName` varchar(100) DEFAULT NULL,
  `password` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8mb4;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES ('3', 'uzi', 'uzi');
INSERT INTO `user` VALUES ('7', 'a', 'a');
INSERT INTO `user` VALUES ('8', 'b', 'b');
INSERT INTO `user` VALUES ('9', 'c', 'c');
INSERT INTO `user` VALUES ('10', 'd', 'd');
INSERT INTO `user` VALUES ('11', 'e', 'e');
INSERT INTO `user` VALUES ('12', 'f', 'f');
INSERT INTO `user` VALUES ('13', 'g', 'g');
INSERT INTO `user` VALUES ('14', 'h', 'h');
INSERT INTO `user` VALUES ('15', 'i', 'i');
